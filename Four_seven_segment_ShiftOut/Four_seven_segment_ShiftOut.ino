/*The goal of this program is to use 74HC595 to display 4 different digits on a
7 segment display,  using the Arduino function ShiftOut

74HC595, ShiftOut, 
*/
#include "ShiftOut.h"


ShiftOut test(2,0,0,1);

void setup() {
 	//define pins as outputs
 	test.init();
}
void loop() {
 	//call the function to print the number
test.print_num(); //the digits has to be passed to the function
 	
}
