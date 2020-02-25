# Arduino-freq.meter-for-XR2206
Ardunino frequency measurement for Elektor Sweep Function Generator based on XR2206

Built this meter in 1994 ans thought it was about time to provide a display fo the frequency outputed by the generator. An arduino and a small LCD display seemed a good option. The display had to be tiny though. This 0.49" LCD was found to be good fit for the job.

 * Arduino Frequency/Period counter
 * for Sweep/Function Generator (20Hz...200kHz)
 * Elektor PT nº70 - Oct.1990
 * Arduino Nano Pro - ATmega328P 5v 16MHz
 * OLED 0.49" 64x32 SSD1306
 * XR2206 output pin 11 - trough 100KOhm
 * Arduino Input pin D5
 * Mortymore - Feb.2020


Library for SSD1306 display and aditional info: U8g2lib.h

https://github.com/olikraus/u8g2

https://github.com/olikraus/u8g2/wiki
                                            
Library for frequency measurement: FreqCount.h

https://github.com/PaulStoffregen/FreqCount
