/*
 * Arduino Frequency/Period counter
 * for Sweep/Function Generator (20Hz...200kHz)
 * Elektor PT nº70 - Oct.1990
 * Arduino Nano Pro - ATmega328P 5v 16MHz
 * OLED 0.49" 64x32 SSD1306
 * XR2206 output pin 11 - trough 100KOhm
 * Arduino Input pin D5
 * Mortymore - Feb.2020
 */

#include <Wire.h>   
#include <U8g2lib.h>                        //https://github.com/olikraus/u8g2
                                            //https://github.com/olikraus/u8g2/wiki
#include <FreqCount.h>                      //https://github.com/PaulStoffregen/FreqCount
                                            
U8G2_SSD1306_64X32_1F_F_HW_I2C u8g2(U8G2_R0, /*resetPIN*/ U8X8_PIN_NONE);   //SSD1306 setup

void setup()   {                
  u8g2.begin();
  delay(1000);
  u8g2.setFont(u8g2_font_5x7_tf);           // 4fun  
  u8g2.drawStr(0, 6, "-- elektor --");      // 4fun
  u8g2.drawStr(20, 16, "SWEEP");            // 4fun
  u8g2.drawStr(12, 24, "FUNCTION");         // 4fun
  u8g2.drawStr(10, 32, "GENERATOR");        // 4fun
  u8g2.sendBuffer();                        // 4fun
  delay(3000);                              // 4fun
  FreqCount.begin(1000);
}

void FRange() 
{ 
  float freq = FreqCount.read();
  long lowfreq = freq;
  if (FreqCount.read() < 1000) {              // input under 1kHz
    u8g2.print(lowfreq);
    u8g2.setFont(u8g2_font_5x7_tf);           // size6  
    u8g2.drawStr(55, 20, "Hz");               // print the units to buffer   
    }
  else {                                      // input over 1kHz
    u8g2.print(freq/1000);                
    u8g2.setFont(u8g2_font_5x7_tf);           // size6  
    u8g2.drawStr(50, 20, "kHz");              // print the units to buffer  
    }
}

void TRange() 
{ 
  float freq = FreqCount.read();
  float period = (1/freq);
  if (FreqCount.read() < 1){                  // if there's no input
    u8g2.clearBuffer(); 
    u8g2.setFont(u8g2_font_5x7_tf);           // size6  
    u8g2.drawStr(0, 6, "- FREQUENCY -"); 
    u8g2.setFont(u8g2_font_6x13_tf);          // size9
    u8g2.drawStr(8, 25, "NO INPUT"); 
    //u8g2.sendBuffer();
    }
  else if (FreqCount.read() < 1000) {         // input under 1kHz (1ms)
    u8g2.print(period*1000);
    u8g2.setFont(u8g2_font_5x7_tf);           // size6  
    u8g2.drawStr(55, 32, "ms");               // print the units to buffer    
    }
  else {                                      // input over 1kHz (1ms)
    u8g2.print(period*1000000);
    u8g2.setFont(u8g2_font_5x7_tf);           // size6  
    u8g2.drawStr(55, 32, "us");               // print the units to buffer    
    }
}

void loop() { 
  u8g2.clearBuffer();                       // clear the internal memory
  u8g2.setFont(u8g2_font_5x7_tf);           // size6  
  u8g2.drawStr(0, 6, "- AUDIO.GEN -");
    
  if (FreqCount.available()) {                   

    //u8g2.setFont(u8g2_font_6x13_tf);        // size9 
    u8g2.setFont(u8g2_font_t0_16_tf);         // size10         
    u8g2.setCursor(0, 20);
    FRange();
   
    u8g2.setFont(u8g2_font_t0_14_tf);         // size9 
    //u8g2.setFont(u8g2_font_t0_16_tf);       // size10  
    u8g2.setCursor(0, 32);
    TRange();    
    u8g2.sendBuffer(); // transfer internal memory to the display                         
  }

}
