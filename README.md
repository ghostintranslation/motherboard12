# MOTHERBOARD12
MOTHERBOARD12 is a 12 controls Teensy 4 + audio board platform. (This is still a work in progress)

MOTHERBOARD6, MOTHERBOARD9 and MOTHERBOARD12 allows for any combination of pushbuttons, potentiometers and encoders, in addition to leds. The footprints of those 3 type of components are stacked together so that only one pcb can be used for many different modules.

The MOTHERBOARDs come with 2 boards, one on which the inputs and leds are soldered to, and one on which the Teensy and other components are soldered to. Both boards are attached by multiple pin headers.

## Limitations

Due to the use of the audio board, the available pins are very limited. Looking at the Teensy audio board page (https://www.pjrc.com/store/teensy3_audio.html) we can see only pins 0, 1, 2, 3, 4, 5, 9, 14, 16, 17, 22 are available. Also looking at Teensy pins (https://www.pjrc.com/store/teensy40.html), only 14, 16 and 17 from this subset are analog inputs.

So the use of multiplexers is required to be able to read pushbuttons, potentiometers, encoders or to lit leds. In addition, a matrix design is used for the encoders to reduce the number of inputs required as each of them has 3 inputs.

On this design, pin 22 will switch from input to output very fast to lit the leds and read the inputs.

### Notes

I need to replace the Teensy 3.2 with a 4.0 in the schematics. I didn't have the library when I did them but pins number used are the one available for Teensy 4.0.

## Design rules

I made up design rules so that I can create many modules that will reuse the same back boards to lower the cost, and to make it look nice too. 

Some of the rules are:

* 1 column is 4HP width
* 1 column has up to 3 leds + 3 controls.

TODO: Design rules guide image.

## Historic 

I still need to test the current schematics.

Rev 3 (current) using more multiplexers because of the limited available pins.

Rev 2 added multiplexers, but wasn't taking in account the forbidden pins from the use of the audio board.

Rev 1 was using matrices for potentiometers, which doesn't work.