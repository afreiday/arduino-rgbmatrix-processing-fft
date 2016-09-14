# arduino-rgbmatrix-processing-fft
Arduino-Processing Fast Fourier Transform (FFT) "Equalizer" with a 16x32 RGB LED matrix

This project contains a [Processing](https://processing.org/) sketch that runs a fast fourier transform on live, captured audio, which communicates with an Arduino Mega via serial connection. The Arduino sketch very simply translates the serial data it receives and displays it as a graphic equalizer on an RGB LED matrix.

## Requirements

- [Processing](https://processing.org/)
- [Arduino IDE](https://www.arduino.cc/en/Main/Software) of your choice
- [Arduino Mega](https://www.arduino.cc/en/Main/arduinoBoardMega) -- though it probably works with an [Arduino Uno](https://www.arduino.cc/en/Main/ArduinoBoardUno) just fine
- [16x32 RGB LED Matrix](https://www.adafruit.com/product/420)
