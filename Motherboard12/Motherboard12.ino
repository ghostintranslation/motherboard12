#include "Motherboard12.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthSimpleDrum     drum1;          //xy=431,197
AudioMixer4              mixer1;         //xy=737,265
AudioOutputI2S           i2s1;           //xy=979,214
AudioConnection          patchCord3(drum1, 0, mixer1, 0);
AudioConnection          patchCord5(mixer1, 0, i2s1, 0);
AudioConnection          patchCord6(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=930,518
// GUItool: end automatically generated code



// 0 = empty, 1 = button, 2 = potentiometer, 3 = encoder
byte controls[12] = {2,2,2,2, 2,2,2,2, 3,1,1,1};
Motherboard12 device(controls);

elapsedMillis clockDrum;
    
void setup() {
  // audio library init
  AudioMemory(15);

 drum1.frequency(60);
  drum1.length(1500);
  drum1.secondMix(0.0);
  drum1.pitchMod(0.55);

    
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);

  
  Serial.begin(115200);
  
  while (!Serial && millis() < 2500); // wait for serial monitor

  // Starting sequence
  Serial.println("Ready!");
  
  device.init();
}

void loop() {
  device.update();
//
//  device.setDisplay(0, 1);
//  device.setDisplay(1, 2);
//  device.setDisplay(2, 3);
//  device.setDisplay(3, 1);
//  device.setDisplay(4, 2);
//  device.setDisplay(5, 3);
//  device.setDisplay(6, 1);
//  device.setDisplay(7, 2);
//  device.setDisplay(8, 3);
//  device.setDisplay(9, 1);
//  device.setDisplay(10, 2);
//  device.setDisplay(11, 3);
  
  if(clockDrum > 250 + device.getInput(2)*10){
  device.setDisplay(8, 4);
    drum1.frequency(map(device.getInput(0), 0, 1023, 30, 300));
    drum1.noteOn();
    clockDrum = 0;
  }
}
