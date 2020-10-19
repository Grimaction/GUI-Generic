/*
  Copyright (C) krycha88

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "SuplaSensorDS18B20.h"

OneWireBus::OneWireBus(uint8_t pinNumberConfig)
    : oneWire(pinNumberConfig), pin(pinNumberConfig), nextBus(nullptr), lastReadTime(0) {
  supla_log(LOG_DEBUG, "Initializing OneWire bus at pin %d", pinNumberConfig);
  sensors.setOneWire(&oneWire);
  sensors.begin();
  if (sensors.isParasitePowerMode()) {
    supla_log(LOG_DEBUG, "OneWire(pin %d) Parasite power is ON", pinNumberConfig);
  } else {
    supla_log(LOG_DEBUG, "OneWire(pin %d) Parasite power is OFF", pinNumberConfig);
  }

  supla_log(LOG_DEBUG, "OneWire(pin %d) Found %d devices:", pinNumberConfig,
            sensors.getDeviceCount());

  // report parasite power requirements

  DeviceAddress address;
  char strAddr[64];
  for (int i = 0; i < sensors.getDeviceCount(); i++) {
    if (!sensors.getAddress(address, i)) {
      supla_log(LOG_DEBUG, "Unable to find address for Device %d", i);
    } else {
      /*sprintf(
        strAddr,
        "{0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X}",
        address[0],
        address[1],
        address[2],
        address[3],
        address[4],
        address[5],
        address[6],
        address[7]);
      supla_log(LOG_DEBUG, "Index %d - address %s", i, strAddr);*/
      sensors.setResolution(address, 12);
    }
    delay(0);
  }
  sensors.setWaitForConversion(true);
  sensors.requestTemperatures();
  sensors.setWaitForConversion(false);
}

int8_t OneWireBus::getIndex(uint8_t *deviceAddress) {
  DeviceAddress address;
  for (int i = 0; i < sensors.getDeviceCount(); i++) {
    if (sensors.getAddress(address, i)) {
      bool found = true;
      for (int j = 0; j < 8; j++) {
        if (deviceAddress[j] != address[j]) {
          found = false;
        }
      }
      if (found) {
        return i;
      }
    }
  }
  return -1;
}

DS18B20::DS18B20(uint8_t pin, uint8_t *deviceAddress) {
  OneWireBus *bus = oneWireBus;
  OneWireBus *prevBus = nullptr;
  address[0] = 0;
  lastValidValue = TEMPERATURE_NOT_AVAILABLE;
  retryCounter = 0;

  if (bus) {
    while (bus) {
      if (bus->pin == pin) {
        myBus = bus;
        break;
      }
      prevBus = bus;
      bus = bus->nextBus;
    }
  }

  // There is no OneWire bus created yet for this pin
  if (!bus) {
    supla_log(LOG_DEBUG, "Creating OneWire bus for pin: %d", pin);
    myBus = new OneWireBus(pin);
    if (prevBus) {
      prevBus->nextBus = myBus;
    } else {
      oneWireBus = myBus;
    }
  }
  if (deviceAddress == nullptr) {
    supla_log(LOG_DEBUG, "Device address not provided. Using device from index 0");
  } else {
    memcpy(address, deviceAddress, 8);
  }
}

void DS18B20::iterateAlways() {
  if (myBus->lastReadTime + 10000 < millis()) {
    myBus->sensors.requestTemperatures();
    myBus->lastReadTime = millis();
  }
  if (myBus->lastReadTime + 5000 < millis() && (lastReadTime != myBus->lastReadTime)) {
    channel.setNewValue(getValue());
    lastReadTime = myBus->lastReadTime;
  }
}

double DS18B20::getValue() {
  double value = TEMPERATURE_NOT_AVAILABLE;
  if (address[0] == 0) {
    value = myBus->sensors.getTempCByIndex(0);
  } else {
    value = myBus->sensors.getTempC(address);
  }

  if (value == DEVICE_DISCONNECTED_C || value == 85.0) {
    value = TEMPERATURE_NOT_AVAILABLE;
  }

  if (value == TEMPERATURE_NOT_AVAILABLE) {
    retryCounter++;
    if (retryCounter > 3) {
      retryCounter = 0;
    } else {
      value = lastValidValue;
    }
  } else {
    retryCounter = 0;
  }
  lastValidValue = value;

  return value;
}

void DS18B20::onInit() {
  channel.setNewValue(getValue());
}

uint8_t DS18B20::getPin() {
  return myBus->pin;
}

OneWireBus *DS18B20::oneWireBus = nullptr;
