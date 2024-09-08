## Instructions esp8266

1. Setup tft_eSPI library and pin connections
2. Upload Arduino code
3. Create data folder
4. Convert images at http://www.rinkydinkelectronics.com/_t_doimageconverter565.php or https://github.com/ivanseidel/UTFT/blob/master/Tools/ImageConverter565.exe and put it in the data folder
5. Make the .bin image using `mkspiffs.exe -c data -b 8192 -p 256 -s 3145728 image.bin`, you can also use other sizes such as `2097152`
6. Flash the esp8266 using `esptool.exe -p COM3 --chip esp8266 --port COM3 --baud 921600 write_flash  0x100000 image.bin`
