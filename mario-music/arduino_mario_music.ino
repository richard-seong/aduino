/*      Encoder Library - Basic Example
        http://www.pjrc.com/teensy/td_libs_Encoder.html

        This example code is in the public domain.
*/

#include "pitches.h"

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(4, 5);
//   avoid using pins with LEDs attached

int buzzerPin = 14;

int melody[] = {

        //1
        NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G3,
        //2
        NOTE_C5, NOTE_G4, NOTE_E4, NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
        NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,
        //3
        //        NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_C5, NOTE_D5, NOTE_B4,
        //4
        NOTE_C5, NOTE_G4, NOTE_E4, NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
        //5
        NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,
        //6
        NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5,
        //7
        NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5, NOTE_C6, NOTE_C6, NOTE_C6,
        //8
        NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5,
        //9
        NOTE_DS5, NOTE_D5, NOTE_C5,
        //10
        NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5,
        //11
        NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5, NOTE_C6, NOTE_C6, NOTE_C6,
        //12
        NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_D5,
        //13
        NOTE_DS5, NOTE_D5, NOTE_C5,
        //14
        NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_A3, NOTE_G3,
        //15
        NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, //NOTE_G3,NOTE_C3, NOTE_G3,
        //16
        NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_A3, NOTE_G3,
        //17
        NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G3,
        //18
        NOTE_C5, NOTE_G4, NOTE_E4, NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
        //19
        NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,
        //20
        NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
        NOTE_B4, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
        NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
        //22
        NOTE_E5, NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
        NOTE_B3, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
        //
        NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
        //21
        NOTE_E4, NOTE_C4, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_F4, NOTE_F4, NOTE_A3,
        //22
        NOTE_B3, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_A3, NOTE_G3,
        NOTE_E4, NOTE_C4, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_F4, NOTE_F4, NOTE_A3,
        NOTE_B3, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4,
        //
        NOTE_C4, NOTE_E4, NOTE_E4, NOTE_C4,
        NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_A3, NOTE_G3,
        NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,
        //NOTE_G4,NOTE_C4, NOTE_G4,
        NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_A3, NOTE_G3,
        NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G3,
        NOTE_E4, NOTE_C4, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_F4, NOTE_F4, NOTE_A3,
        NOTE_B3, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_A3, NOTE_G3,
        NOTE_E4, NOTE_C4, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_F4, NOTE_F4, NOTE_A3,
        NOTE_B3, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4,
};

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
                tone(buzzerPin,melody[newPosition%8],50);
        }
}
