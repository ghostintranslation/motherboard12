/*
 __    _  _____   ___      ___ _  _     __    _ ______ _    
/__|_|/ \(_  |     | |\|    | |_)|_||\|(_ |  |_| |  | / \|\|
\_|| |\_/__) |    _|_| |    | | \| || |__)|__| | | _|_\_/| |

If you enjoy my work and music please consider donating.

https://www.ghostintranslation.com/
https://ghostintranslation.bandcamp.com/
https://www.instagram.com/ghostintranslation/
https://www.youtube.com/channel/UCcyUTGTM-hGLIz4194Inxyw
https://github.com/ghostintranslation
*/

/**
 * This is an example sketch
 * The first led switch on when a midi note on is received and 
 * switch off when a midi note off is received.
 */

#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE(); // MIDI library init

#include "Motherboard12.h"

Motherboard12 * device = Motherboard12::getInstance();

void setup() {
  Serial.begin(115200);
  
  while (!Serial && millis() < 2500); // wait for serial monitor

  // Starting sequence
  Serial.println("Ready!");
  // 0 = empty, 1 = button, 2 = potentiometer, 3 = encoder
  byte controls[12] = {1,1,1,1, 1,1,1,1, 3,3,3,3};
  device->init(controls);
  
  MIDI.setHandleNoteOn(onNoteOn);
  MIDI.setHandleNoteOff(onNoteOff);
  MIDI.begin(device->getMidiChannel());
  
  usbMIDI.setHandleNoteOn(onNoteOn);
  usbMIDI.setHandleNoteOff(onNoteOff);

  device->setHandlePressUp(0, onButton1Press);
  device->setHandleLongPressUp(0, onButton1LongPress);
  device->setHandleLongPressDown(1, onButton2Press);
  device->setHandlePressUp(8, onRotary8Press);
  device->setHandleLongPressUp(8, onRotary8LongPress);
  device->setHandlePressDown(9, onRotary9Press);
  device->setHandleRotaryChange(9, onRotary9Change);

}

void loop() {
  device->update();
  
  MIDI.read(device->getMidiChannel());
  usbMIDI.read(device->getMidiChannel());
}


// TODO: The following should be handled by Motherboard9

/**
 * Midi note on callback
 */
void onNoteOn(byte channel, byte note, byte velocity) {
  device->setLED(0, 1);
}

/**
 * Midi note off callback
 */
void onNoteOff(byte channel, byte note, byte velocity) {
  device->setLED(0, 0);
}


void onButton1Press(byte inputIndex){
  Serial.println("onButton1Press");
}
void onButton2Press(byte inputIndex){
  Serial.println("onButton2Press");
}
void onButton1LongPress(byte inputIndex){
  Serial.println("onButton1LongPress");
}
void onRotary8Press(byte inputIndex){
  Serial.println("onRotary8Press");
}
void onRotary8LongPress(byte inputIndex){
  Serial.println("onRotary8LongPress");
}
void onRotary9Press(byte inputIndex){
  Serial.println("onRotary9Press");
}

void onRotary9Change(bool value){
  if(value){
    Serial.println("onRotary9Change increment");
  }else{
    Serial.println("onRotary9Change decrement");
  }
}
