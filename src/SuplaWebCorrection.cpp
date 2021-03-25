#include "SuplaWebCorrection.h"
#include "SuplaDeviceGUI.h"

void createWebCorrection() {
  WebServer->httpServer->on(getURL(PATH_CORRECTION), [&]() {
    if (!WebServer->isLoggedIn()) {
      return;
    }

    if (WebServer->httpServer->method() == HTTP_GET)
      handleCorrection();
    else
      handleCorrectionSave();
  });
}

void handleCorrection(int save) {
  String correction;

  WebServer->sendHeaderStart();

  webContentBuffer += SuplaSaveResult(save);
  webContentBuffer += SuplaJavaScript(PATH_CORRECTION);

  addForm(webContentBuffer, F("post"), PATH_CORRECTION);

  addFormHeader(webContentBuffer, F("Korekta dla kanałów"));
  for (auto element = Supla::Element::begin(); element != nullptr; element = element->next()) {
    if (element->getChannel()) {
      auto channel = element->getChannel();

      if (channel->getChannelType() == SUPLA_CHANNELTYPE_THERMOMETER) {
        correction = ConfigManager->get(KEY_CORRECTION_TEMP)->getElement(channel->getChannelNumber());

        addNumberBox(webContentBuffer, getInput(INPUT_CORRECTION_TEMP, channel->getChannelNumber()),
                     String(F("Temperatura: ")) + channel->getChannelNumber(), F("wartość korekty"), false, correction);
      }

      if (channel->getChannelType() == SUPLA_CHANNELTYPE_HUMIDITYANDTEMPSENSOR) {
        correction = ConfigManager->get(KEY_CORRECTION_TEMP)->getElement(channel->getChannelNumber()).toDouble();
        addNumberBox(webContentBuffer, getInput(INPUT_CORRECTION_TEMP, channel->getChannelNumber()),
                     String(F("Temperatura: ")) + channel->getChannelNumber(), F("wartość korekty"), false, correction);

        correction = ConfigManager->get(KEY_CORRECTION_HUMIDITY)->getElement(channel->getChannelNumber()).toDouble();
        addNumberBox(webContentBuffer, getInput(INPUT_CORRECTION_HUMIDITY, channel->getChannelNumber()),
                     String(F("Wilgotność: ")) + channel->getChannelNumber(), F("wartość korekty"), false, correction);
      }
    }
  }
  addFormHeaderEnd(webContentBuffer);

  addButtonSubmit(webContentBuffer, S_SAVE);
  addFormEnd(webContentBuffer);
  addButton(webContentBuffer, S_RETURN, PATH_DEVICE_SETTINGS);

  WebServer->sendHeaderEnd();
}

void handleCorrectionSave() {
  if (!WebServer->isLoggedIn()) {
    return;
  }

  double correction;

  for (auto element = Supla::Element::begin(); element != nullptr; element = element->next()) {
    if (element->getChannel()) {
      auto channel = element->getChannel();

      if (channel->getChannelType() == SUPLA_CHANNELTYPE_THERMOMETER) {
        correction = WebServer->httpServer->arg(getInput(INPUT_CORRECTION_TEMP, channel->getChannelNumber())).toDouble();
        ConfigManager->setElement(KEY_CORRECTION_TEMP, channel->getChannelNumber(), correction);
      }

      if (channel->getChannelType() == SUPLA_CHANNELTYPE_HUMIDITYANDTEMPSENSOR) {
        correction = WebServer->httpServer->arg(getInput(INPUT_CORRECTION_TEMP, channel->getChannelNumber())).toDouble();
        ConfigManager->setElement(KEY_CORRECTION_TEMP, channel->getChannelNumber(), correction);

        correction = WebServer->httpServer->arg(getInput(INPUT_CORRECTION_HUMIDITY, channel->getChannelNumber())).toDouble();
        ConfigManager->setElement(KEY_CORRECTION_HUMIDITY, channel->getChannelNumber(), correction);
      }
    }
  }

  switch (ConfigManager->save()) {
    case E_CONFIG_OK:
      handleCorrection(1);
      break;
    case E_CONFIG_FILE_OPEN:
      handleCorrection(2);
      break;
  }
}
