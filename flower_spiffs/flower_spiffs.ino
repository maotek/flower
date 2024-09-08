/*====================================================================================
  Created by MaoTek
  Credits for Bodmer 23rd Mar 2019 - Tested in Arduino IDE 1.8.0 esp8266 Core 2.4.2
  ==================================================================================*/

//====================================================================================
//                                  Libraries
//====================================================================================
//Call up the SPIFFS FLASH filing system
#include <FS.h>

#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

//====================================================================================
//                                    Setup
//====================================================================================
void setup()
{
  // Serial.begin(115200); // Used for messages

  tft.begin();
  tft.setRotation(0);  // 0 & 2 Portrait. 1 & 3 landscape
  tft.fillScreen(TFT_BLACK);

  if (!SPIFFS.begin()) {
    // Serial.println("SPIFFS initialisation failed!");
    while (1) yield(); // Stay here twiddling thumbs waiting
  }
  // Serial.println("\r\nInitialisation done.");
}

//====================================================================================
//                                    Loop
//====================================================================================
void loop()
{
  uint8_t i = random(1, 22);
  String file = "/" + String(i) + ".raw";
  drawRaw(file.c_str());
  delay(10000);
}
