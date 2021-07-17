/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>
#include "pitches.h"


int melody[] = {

//          //1 //12  //캉캉
//          NOTE_C4,NOTE_C4, 
//          NOTE_D4,NOTE_F4,NOTE_E4,NOTE_D4, 
//          NOTE_G4,NOTE_D4, 
//          NOTE_G4,NOTE_A4,NOTE_E4,NOTE_F4,
//          //2 //14
//          NOTE_D4,NOTE_D4, 
//          NOTE_D4,NOTE_F4,NOTE_E4,NOTE_D4, 
//          NOTE_C4,NOTE_C5,NOTE_B4,NOTE_A4, 
//          NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4,
//          //3 //12
//          NOTE_C4,NOTE_C4, 
//          NOTE_D4,NOTE_F4,NOTE_E4,NOTE_D4, 
//          NOTE_G4,NOTE_G4, 
//          NOTE_G4,NOTE_A4,NOTE_E4,NOTE_F4,
//          //4 //12
//          NOTE_D4,NOTE_D4, 
//          NOTE_D4,NOTE_F4,NOTE_E4,NOTE_D4, 
//          NOTE_C4,NOTE_G4,NOTE_D4,NOTE_E4, 
//          NOTE_C4,NOTE_C5,

        //1 //16 //환희의 송가
        NOTE_E4,NOTE_E4,NOTE_F4,NOTE_G4, 
        NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4, 
        NOTE_C4,NOTE_C4,NOTE_D4,NOTE_E4, 
        NOTE_E4,NOTE_D4,NOTE_D4,0,
        //2 //16
        NOTE_E4,NOTE_E4,NOTE_F4,NOTE_G4, 
        NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4, 
        NOTE_C4,NOTE_C4,NOTE_D4,NOTE_E4, 
        NOTE_D4,NOTE_C4,NOTE_C4,0,
        //3 //18
        NOTE_D4,NOTE_D4,NOTE_E4,NOTE_C4, 
        NOTE_D4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_C4, 
        NOTE_D4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_D4, 
        NOTE_C4,NOTE_D4,NOTE_D4,0,
        //4 //16
        NOTE_E4,NOTE_E4,NOTE_F4,NOTE_G4, 
        NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4, 
        NOTE_C4,NOTE_C4,NOTE_D4,NOTE_E4, 
        NOTE_E4,NOTE_D4,NOTE_D4,0,

//
//        //1 //작은별
//        NOTE_C4,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4,
//        //2
//        NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
//        //3
//        NOTE_C4,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4,0,
//        
};


// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(5, 4);
//   avoid using pins with LEDs attached


void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
}

long oldPosition  = -999;

void loop() {
  long newPosition = myEnc.read()/2;
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
    tone(8,melody[newPosition%(16+16+18+16)],100);
  }
}
