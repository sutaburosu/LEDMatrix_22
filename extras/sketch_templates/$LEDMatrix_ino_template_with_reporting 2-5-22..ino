
//template example for LEDMatrix_22

//NOTE: This example will run on any size matrix panel

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

/* DEBUGGING REPORT - sent to the serial terminal
To run report define RUN_REPORT, the Report Generator code will be included
below AFTER all the paramters are defined. Compile and upload this sketch
then run_report(); will execute at then end of setup.

>>>> Report Generator.cpp MUST BE INCLUDED BELOW just before sewtup()
after all parameters are defined <<<
*/
//#define RUN_REPORT      //will open Serial.pprint when started in setup
											 
/*------------------- create the total matrix panel array -------------------
If using led panels like 4x4 or 8x8 the you must define HAS_TILES and configure panel sizes in configuration_22.h
the Class "leds" can be changed to whatever you choose. Example: "myLeds" and all calls are "myLeds." as in myLeds.addLeds();
*/

cLEDMatrix leds;
CRGB* pleds = leds.cLED;   //pointer to your leds[] array to access directly

//if run report is defined, the report_Generator.cpp code will be included
//>>>> the code MUST BE INCLUDED HERE after all parameters are defined
#ifdef RUN_REPORT
  #include ".\utility\report_Generator\report_Generator.cpp"
#endif

//------------------------ Setup and loop ------------------------
  void setup() {
	      //if run report is defined, the report_Generator.cpp code will be included
    #ifdef RUN_REPORT
      Serial.begin(115200); //select your speed
      delay(1000);
      run_report();       //also open Serial port
    #endif
    leds.addLeds();       //initiate LEDMatrix

}

void loop() {


}
