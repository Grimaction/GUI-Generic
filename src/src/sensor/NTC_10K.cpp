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
#include "NTC_10K.h"

namespace Supla {
namespace Sensor {
NTC10K::NTC10K(int8_t pin) : pin(pin) {
}

double NTC10K::getValue() {
  int adc = AdcRead(pin, 2);
  // Steinhart-Hart equation for thermistor as temperature sensor:
  // double Rt = (adc * Adc[idx].param1 * MAX_ADC_V) / (ANALOG_RANGE * ANALOG_V33 - (double)adc * MAX_ADC_V);
  // MAX_ADC_V in ESP8266 is 1
  // MAX_ADC_V in ESP32 is 3.3
#ifdef ESP8266
  double Rt =
      (adc * ANALOG_NTC_BRIDGE_RESISTANCE) / (ANALOG_RANGE * ANALOG_V33 - (double)adc);  // Shelly param1 = 32000 (ANALOG_NTC_BRIDGE_RESISTANCE)
#else
  double Rt = (adc * ANALOG_NTC_BRIDGE_RESISTANCE) / (ANALOG_RANGE - (double)adc);
#endif
  double BC = (double)ANALOG_NTC_B_COEFFICIENT;                                      // Shelly param3 = 3350 (ANALOG_NTC_B_COEFFICIENT)
  double T = BC / (BC / ANALOG_T0 + TaylorLog(Rt / (double)ANALOG_NTC_RESISTANCE));  // Shelly param2 = 10000 (ANALOG_NTC_RESISTANCE)
  return (double)TO_CELSIUS(T);
}

double NTC10K::TaylorLog(double x) {
  double z = (x + 1) / (x - 1);                             // We start from power -1, to make sure we get the right power in each iteration;
  double step = ((x - 1) * (x - 1)) / ((x + 1) * (x + 1));  // Store step to not have to calculate it each time
  double totalValue = 0;
  double powe = 1;
  double y;
  for (uint32_t count = 0; count < 10; count++) {  // Experimental number of 10 iterations
    z *= step;
    y = (1 / powe) * z;
    totalValue = totalValue + y;
    powe = powe + 2;
  }
  totalValue *= 2;
  return totalValue;
}

uint16_t NTC10K::AdcRead(uint32_t pin, uint32_t factor) {
  // factor 1 = 2 samples
  // factor 2 = 4 samples
  // factor 3 = 8 samples
  // factor 4 = 16 samples
  // factor 5 = 32 samples
  uint32_t samples = 1 << factor;
  uint32_t analog = 0;
  for (uint32_t i = 0; i < samples; i++) {
    analog += analogRead(pin);
    delay(1);
  }
  analog >>= factor;
  return analog;
}

void NTC10K::onInit() {
  channel.setNewValue(getValue());
}
}  // namespace Sensor
}  // namespace Supla