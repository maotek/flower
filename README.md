## Instructions esp8266

1. Setup tft_eSPI library and pin connections
2. Create data folder
3. Convert images at http://www.rinkydinkelectronics.com/_t_doimageconverter565.php and put it in the data folder
4. Make the .bin image using `mkspiffs.exe -c data -b 8192 -p 256 -s 3112960 image.bin`
5. Flash the esp8266 using `esptool.exe -p COM3 --chip esp8266 --port COM3 --baud 921600 write_flash  0x100000 image.bin`
6. Upload Arduino code
