#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 11  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

byte last[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

#define RED_PEAK 10

uint16_t green = matrix.Color333(0, 255, 0);
uint16_t red = matrix.Color333(255, 0, 0);
uint16_t black = matrix.Color333(0, 0, 0);
uint16_t blue = matrix.Color333(0, 0, 255);

String sep = ":";

void setup() {
  Serial.begin(57600);
  matrix.begin();
  Serial.println("Starting");
}

void loop() {
  while(Serial.available() > 0) {
    String in = Serial.readStringUntil('\n');

    int f = in.substring(0, in.indexOf(sep)).toInt();
    int ff = in.substring(in.indexOf(sep) + sep.length()).toInt();
  
    if (f < 31 && ff < 16) {  
      int x0 = f;
      
    Serial.print(f);
    Serial.print(' ');
    Serial.println(ff);
  
      uint16_t color;
  
      if (ff > last[f]) {      
        for(int y = last[f]; y <= ff; y++) {
          color = y > RED_PEAK ? red : blue;
          matrix.drawPixel(31 - x0, y - 1, color);  
        }
      } else if (last[f] > ff) {
        color = black;
        
        for(int y = last[f]; y > ff; y--) {
          matrix.drawPixel(31 - x0, y - 1, color);
        }
      }
  
      last[f] = ff;
    }
  }
}