//Cylon_strip.ino
//useful for debugging
#define pt(msg)     Serial.println(msg);    //Serial.println MACRO
#define ptt(msg)     Serial.print(msg);    //Serial.printl MACRO

/* Configuring this library and FastLED requires a number of parameters and #defines
Configure your LED array in myConfiguration.h located in the  library folder.
This way you can reuse your configuration file(s) across all your sketches.
Consider renaming your configurations (and changing the #include "myConfiguration.h"
in the library folder.
*/

#include <LEDMatrix_22.h> 
#include <gfxfont.h>
#include <glcdfont.c>

/* DEBUGGING REPORT - sent to the serial terminal
To run report define RUN_REPORT, the Report Generator code will be included
below AFTER all the paramters are defined. Compile and upload this sketch
then run_report(); will execute at then end of setup.

>>>> Report Generator.cpp MUST BE INCLUDED BELOW just before sewtup()
after all parameters are defined <<<
*/
//#define RUN_REPORT      //will open Serial.pprint when started in setup

/*------------------- create the total matrix panel array -------------------
If using led panels like 4x4 or 8x8 the you must define HAS_BLOCKS and configure panel sizes in configuration_22.h
the Class "leds" can be changed to whatever you choose. Example: "myLeds" and all calls are "myLeds." as in myLeds.addLeds();
*/

cLEDMatrix leds;

//if run report is defined, the report_Generator.cpp code will be included
//>>>> the code MUST BE IMCLUDED HERE after all parameters are defined
#ifdef RUN_REPORT
    #include <.\report_Generator\report_Generator.cpp>
#endif
CRGB* pleds = leds.cLED;   //pointer to your leds[] array to access directly

//------------------------ Setup and loop ------------------------
void setup() {
    //if run report is defined, the report_Generator.cpp code will be included
#ifdef RUN_REPORT
    Serial.begin(115200); //select your speed
    delay(1000);
    run_report();       //also open Serial port
#endif
    //use only if hardware extender is configured anf active
    //leds.ExtInit(NUM_LEDS, NUM_BANKS, NUM_STRIPS, BRIGHTNESS);      //Extender - init params for Extender functions
}



void loop() { 
	static uint8_t hue = 0;
  int16_t value = 3000;  //default 250 ..8(xx) higher = more fade
	Serial.print("x");
	// First slide the led in one direction
	for(int i = 0; i < NUM_LEDS; i++) {
		// Set the i'th led to red 
		leds.cLED[i] = CHSV(hue++, 255, 255);
		// Show the leds
		 leds.LEDShow();   //for Extender - replace FastLED.show() 
		// now that we've shown the leds, reset the i'th led to black
		// leds[i] = CRGB::Black;
		leds.fadeAll(value);
		// Wait a little bit before we loop around and do it again
		delay(10);
	}
	Serial.print("x");

	// Now go in the other direction.  
	for(int i = (NUM_LEDS)-1; i >= 0; i--) {
		// Set the i'th led to red 
		leds.cLED[i] = CHSV(hue++, 255, 255);
		// Show the leds
		 leds.LEDShow();   //for Extender - replace FastLED.show()
		// now that we've shown the leds, reset the i'th led to black
		// leds[i] = CRGB::Black;
		leds.fadeAll(value);
		// Wait a little bit before we loop around and do it again
		delay(10);
	}
}
