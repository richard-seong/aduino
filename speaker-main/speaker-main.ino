
#include "pitches.h"

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(5, 4);
//   avoid using pins with LEDs attached

int modeBtn = 2;
int setMode, flag;

int setMelody[8][8] = {

        {NOTE_C4, NOTE_D4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_B4, NOTE_C5,},//off
        {NOTE_C4, NOTE_D4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_B4, NOTE_C5,},//rise
        {NOTE_C5, NOTE_C5, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_C4,},//falling
        {NOTE_A5, NOTE_C5, NOTE_A5, NOTE_E5, NOTE_A5, NOTE_D5, NOTE_A5, NOTE_F5,},//tention
        {NOTE_G5, NOTE_F5, NOTE_G5,       0, NOTE_E5, NOTE_F5, NOTE_D5,       0,},//bridge
        {NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G3,},
        {NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G3,},
        {NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G3,},

};

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

unsigned long oldMillis = 0, diffTime = 0;

void setup() {
        Serial.begin(9600);
        Serial.println("Basic Encoder Test:");
        pinMode(modeBtn, INPUT_PULLUP);
}

long oldPosition  = -999;

int melodyCnt;

void loop() {
        MODE_SET();
        unsigned long currentMillis = millis() / 5;

        long newPosition = myEnc.read() / 2;
        if (newPosition != oldPosition) {
                if (oldPosition - newPosition < 0)
                {
                        if (melodyCnt < 224) melodyCnt++;
                        else              melodyCnt = 0;
                }
                else
                {
                        if (melodyCnt > 0) melodyCnt--;
                        else              melodyCnt = 224;
                }
                Serial.println(newPosition);
                diffTime = currentMillis - oldMillis;
                oldMillis = currentMillis;

                oldPosition = newPosition;
                //Serial.println(currentMillis);
                if (diffTime > 100)  diffTime = 100;
                if (setMode == 0)
                        tone(8, melody[melodyCnt], 103 - diffTime);
                else
                {
                        switch (setMode) {
                          case 0:
                            tone(8, setMelody[setMode][melodyCnt % 8], 103 - diffTime);
                          case 1:
                            tone(8, setMelody[setMode][melodyCnt % 8], 103 - diffTime);
                          case 2:
                            tone(8, setMelody[setMode][melodyCnt % 8], 103 - diffTime);
                          case 3:
                            tone(8, setMelody[setMode][melodyCnt % 8], 103 - diffTime);
                          case 4:
                            tone(8, setMelody[setMode][melodyCnt % 8], 103 - diffTime);
                          case 5:
                            tone(8, setMelody[setMode][melodyCnt % 8], 103 - diffTime);
                          case 6:
                            tone(8, setMelody[setMode][melodyCnt % 8], 103 - diffTime);
                          case 7:
                            tone(8, (melodyCnt % 56) * 70, 101 - diffTime);
                        }                        
                }
                delay(105 - diffTime);
                noTone(8);
                //Serial.println(diffTime);
        }
}

void MODE_SET()
{
        if (digitalRead(modeBtn) == LOW)
        {
                if (!flag)
                {
                        flag = 1;

                        if (setMode < 7) setMode++;
                        else          setMode = 0;
                }

        }
        else
        {
                flag = 0;
        }
}
