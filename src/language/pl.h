
#ifndef _LANGUAGE_PL_S_H_
#define _LANGUAGE_PL_S_H_

#define S_SETTING_FOR                                          "Ustawienia dla"
#define S_SETTING_WIFI_SSID                                    "Ustawienia WIFI"
#define S_WIFI_SSID                                            "Nazwa sieci"
#define S_WIFI_PASS                                            "Hasło"
#define S_HOST_NAME                                            "Nazwa modułu"
#define S_SETTING_SUPLA                                        "Ustawienia SUPLA"
#define S_SUPLA_SERVER                                         "Adres serwera"
#define S_SUPLA_EMAIL                                          "Email"
#define S_SETTING_ADMIN                                        "Ustawienia administratora"
#define S_LOGIN                                                "Login"
#define S_LOGIN_PASS                                           "Hasło"
#define S_ROLLERSHUTTERS                                       "Rolety"
#define S_SAVE                                                 "Zapisz"
#define S_DEVICE_SETTINGS                                      "Ustawienia urządzenia"
#define S_TOOLS                                                "Narzędzia"
#define S_SAVE_CONFIGURATION                                   "Zapisz konfigurację"
#define S_LOAD_CONFIGURATION                                   "Wczytaj konfigurację"
#define S_RESTORE_FACTORY_SETTING                              "Przywróć ustawienia fabryczne"
#define S_UPDATE                                               "Aktualizacja"
#define S_RESTART                                              "Restart"
#define S_RETURN                                               "Powrót"
#define S_TEMPLATE_BOARD                                       "Szablony płytek"
#define S_TYPE                                                 "Rodzaj"
#define S_RELAYS                                               "PRZEKAŹNIKI"
#define S_BUTTONS                                              "PRZYCISKI"
#define S_SENSORS_1WIRE                                        "1WIRE"
#define S_SENSORS_I2C                                          "I2C"
#define S_SENSORS_SPI                                          "SPI"
#define S_SENSORS_OTHER                                        "INNE"
#define S_LED_BUTTON_CFG                                       "KONFIGURACJA"
#define S_CFG_MODE                                             "Tryb"
#define S_QUANTITY                                             "ILOŚĆ"
#define S_GPIO_SETTINGS_FOR_RELAYS                             "Ustawienie GPIO dla przekaźników"
#define S_RELAY                                                "PRZEKAŹNIK"
#define S_RELAY_NR_SETTINGS                                    "Ustawienia przekaźnika nr"
#define S_NO_RELAY_NR                                          "Brak przekaźnika nr"
#define S_STATE_CONTROL                                        "Załączany stanem"
#define S_REACTION_AFTER_RESET                                 "Reakcja po resecie"
#define S_GPIO_SETTINGS_FOR_BUTTONS                            "Ustawienie GPIO dla przycisków"
#define S_BUTTON                                               "PRZYCISK"
#define S_BUTTON_NR_SETTINGS                                   "Ustawienia przycisku nr"
#define S_NO_BUTTON_NR                                         "Brak przycisku nr"
#define S_REACTION_TO                                          "Reakcja na"
#define S_ACTION                                               "Akcja"
#define S_GPIO_SETTINGS_FOR_LIMIT_SWITCH                       "Ustawienie GPIO dla cz. otwarcia"
#define S_LIMIT_SWITCH                                         "KRAŃCÓWKA"
#define S_GPIO_SETTINGS_FOR                                    "Ustawienie GPIO dla"
#define S_FOUND                                                "Znalezione"
#define S_NO_SENSORS_CONNECTED                                 "Brak podłączonych czujników"
#define S_SAVE_FOUND                                           "Zapisz znalezione"
#define S_TEMPERATURE                                          "Temperatura"
#define S_NAME                                                 "Nazwa"
#define S_ALTITUDE_ABOVE_SEA_LEVEL                             "Wysokość m n.p.m."
#define S_GPIO_SETTINGS_FOR_CONFIG                             "Ustawienie GPIO dla CONFIG"
#define S_SOFTWARE_UPDATE                                      "Aktualizacja oprogramowania"
#define S_DATA_SAVED                                           "Dane zapisane"
#define S_RESTART_MODULE                                       "Restart modułu"
#define S_DATA_ERASED_RESTART_DEVICE                           "Dane wymazane - należy zrobić restart urządzenia"
#define S_WRITE_ERROR_UNABLE_TO_READ_FILE_FS_PARTITION_MISSING "Błąd zapisu - nie można odczytać pliku - brak partycji FS."
#define S_DATA_SAVED_RESTART_MODULE                            "Dane zapisane - restart modułu."
#define S_WRITE_ERROR_BAD_DATA                                 "Błąd zapisu - złe dane."

//#### SuplaConfigESP.cpp ####
#define S_ALREADY_INITIATED                            "Już zainicjalizowane"
#define S_NOT_ASSIGNED_CB                              "Nie przypisane CB"
#define S_INVALID_GUID_OR_DEVICE_REGISTRATION_INACTIVE "Nieprawidłowy identyfikator GUID lub rejestracja urządzeń NIEAKTYWNA"
#define S_UNKNOWN_SEVER_ADDRESS                        "Nieznany adres serwera"
#define S_UNKNOWN_ID                                   "Nieznany identyfikator ID"
#define S_INITIATED                                    "Zainicjowany"
#define S_CHANNEL_LIMIT_EXCEEDED                       "Przekroczono limit kanałów"
#define S_DISCONNECTED                                 "Rozłączony"
#define S_REGISTRATION_IS_PENDING                      "Rejestracja w toku"
#define S_VARIABLE_ERROR                               "Błąd zmiennej"
#define S_PROTOCOL_VERSION_ERROR                       "Błąd wersji protokołu"
#define S_BAD_CREDENTIALS                              "Złe poświadczenia"
#define S_TEMPORARILY_UNAVAILABLE                      "Tymczasowo niedostępne"
#define S_LOCATION_CONFLICT                            "Konflikt lokalizacji"
#define S_CHANNEL_CONFLICT                             "Konflikt kanałów"
#define S_REGISTERED_AND_READY                         "Zarejestrowany i gotowy"
#define S_DEVICE_IS_DISCONNECTED                       "Urządzenie jest rozłączone"
#define S_LOCATION_IS_DISABLED                         "Lokalizacja jest wyłączona"
#define S_DEVICE_LIMIT_EXCEEDED                        "Przekroczono limit urządzeń"

//#### SuplaCommonPROGMEM.h ####
#define S_OFF                 "WYŁĄCZ"
#define S_ON                  "ZAŁĄCZ"
#define S_TOGGLE              "PRZEŁĄCZ"
#define S_LOW                 "LOW"
#define S_HIGH                "HIGH"
#define S_POSITION_MEMORY     "PAMIĘTAJ STAN"
#define S_REACTION_ON_PRESS   "WCIŚNIĘCIE"
#define S_REACTION_ON_RELEASE "ZWOLNIENIE"
#define S_REACTION_ON_CHANGE  "ZMIANA STANU"
#define S_CFG_10_PRESSES      "10 WCIŚNIĘĆ"
#define S_5SEK_HOLD           "WCIŚNIĘTY 5 SEKUND"
#define S_NORMAL "NORMALNE"
#define S_SLOW "WOLNE"
#define S_MANUALLY "RĘCZNE"
#define S_ON_CH_VAL_OFF_HEATING "ON < wartość kanału > OFF - ogrzewanie"
#define S_ON_CH_VAL_OFF_COOLING "ON > wartość kanału < OFF - chłodzenie"
#define S_ON_2CH_VAL_OFF_HUMIDIFICATION "ON < 2 wartość kanału > OFF - nawilżanie"
#define S_ON_2CH_VAL_OFF_DRYING "ON > 2 wartość kanału < OFF - osuszanie"

//#### SuplaWebServer.cpp ####
#define S_LIMIT_SWITCHES "KRAŃCÓWKI"

//#### SuplaTemplateBoard.h ####
#define S_ABSENT "BRAK"

//#### SuplaWebPageSensor.cpp ####
#define S_IMPULSE_COUNTER                  "Licznik impulsów"
#define S_IMPULSE_COUNTER_DEBOUNCE_TIMEOUT "Limit czasu"
#define S_IMPULSE_COUNTER_RAISING_EDGE     "Zbocze rosnące"
#define S_IMPULSE_COUNTER_PULL_UP          "Podciąganie do VCC"
#define S_IMPULSE_COUNTER_CHANGE_VALUE     "Zmień wartość"
#define S_IMPULSE_COUNTER_SETTINGS_NR      "Ustawienia IC nr"
#define S_CONTROL                          "Sterowanie"
#define S_OLED_BUTTON                      "Przycisk OLED"
#define S_SCREEN                           "Ekran"
#define S_BACKLIGHT_S                      "Podświetlenie [s]"
#define S_ADDRESS_BMPE280                  "Adres BME280"

//#### SuplaWebPageUpload.cpp ####
#define S_GENERATE_GUID_AND_KEY "Generuj GUID & AUTHKEY"
#define S_UPLOAD "Prześlij"

//#### SuplaWebPageControl.cpp ####
#define S_SETTINGS_FOR_BUTTONS "Ustawienia dla przycisków"
#define S_REVERSE_LOGIC "Odwrócona logika"
#define S_INTERNAL_PULL_UP "Wewnętrzny pull-up"

//#### SuplaWebPageOther.cpp ####
#define S_CALIBRATION "Kalibracja"
#define S_CALIBRATION_SETTINGS "Ustawienia kalibracji"
#define S_BULB_POWER_W "Moc żarówki [W]"
#define S_VOLTAGE_V "Napięcie [V]"
#define S_DEPTH_CM "Głębokość [cm]"
#define S_SENSOR_READING_DISTANCE "maksymalna odległość odczytu czujnika"

//#### SuplaWebPageRelay.cpp ####
#define S_RELAY_ACTIVATION_STATUS "Status załączenia przekaźnika"
#define S_STATE "Stan"
#define S_MESSAGE "Wiadomość"
#define S_DIRECT_LINKS "Linki bezpośrednie"
#define S_CONDITIONING "Warunkowanie"
#define S_SENSOR "Czujnik"
#define S_CONDITION "Warunek"
#define S_SWITCH_ON_VALUE "wartość włączenia"
#define S_SWITCH_OFF_VALUE "wartość wyłączenia"
#define S_SETTINGS_FOR_RELAYS "Ustawienia dla przekaźników"

#endif  // _LANGUAGE_PL_S_H_
