/*====================================================================================

   There is no clipping so images that don't fit within the screen boundaries will
   appear corrupted. Crop the image (in say Paint on Windows OS) before converting to
   16 bit, or position image so it does not go off the screen.

  Created by Bodmer 23rd Mar 2019
  ==================================================================================*/
#define PIXEL_BUFFER_SIZE 512 // Must be an integer multiple of 4, must be more than 54

//====================================================================================
//   This function renders the raw (16 bit, 565 RGB pixels) image file onto the TFT
//====================================================================================
void drawRaw(const char *filename) {
  File     imageFile;
  // Check file exists, open it if it does
  if ((imageFile = SPIFFS.open(filename, "r")) == 0) { // Open for reading
    // Serial.print("ERROR: File \""); Serial.print(filename); Serial.println ("\" not found!");
    return;
  }

  uint8_t  pixelBuffer[PIXEL_BUFFER_SIZE];   // Pixel buffer
  uint32_t fs = imageFile.size();

  // Prepare the TFT screen area to receive the data, the SPI chip select will stay low
  tft.setAddrWindow(0, 0, 240, 240);

  // Work out how many whole pixel buffers but we need to read file based on the file size!
  // See comments below about closing file early!

  uint32_t nr = fs / PIXEL_BUFFER_SIZE;
  tft.startWrite();
  while (nr--) {
    // SPIFFS supports the Stream Class member functions
    imageFile.read(pixelBuffer, PIXEL_BUFFER_SIZE);
    SPI.writeBytes(pixelBuffer, PIXEL_BUFFER_SIZE);
  }

  // Work out remining byte count
  nr = fs % PIXEL_BUFFER_SIZE;

  // Send any partial pixel buffer
  if (nr) {
    imageFile.read(pixelBuffer, nr);   // Get pixels
    tft.pushColors(pixelBuffer, nr);

    //yield(); // Uncomment if a really slow SPI clock is used (to stop watchdog timeout)
  }

  tft.endWrite();
  // Close the file, must have reched end or processor throws an exception!
  imageFile.close();
}