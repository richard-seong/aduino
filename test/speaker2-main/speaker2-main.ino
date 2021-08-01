
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

int Melody1[] = {

//  캉캉 12+14+12+12
          //1 //12  
          NOTE_C4,NOTE_C4, 
          NOTE_D4,NOTE_F4,NOTE_E4,NOTE_D4, 
          NOTE_G4,NOTE_D4, 
          NOTE_G4,NOTE_A4,NOTE_E4,NOTE_F4,
          //2 //14
          NOTE_D4,NOTE_D4, 
          NOTE_D4,NOTE_F4,NOTE_E4,NOTE_D4, 
          NOTE_C4,NOTE_C5,NOTE_B4,NOTE_A4, 
          NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4,
          //3 //12
          NOTE_C4,NOTE_C4, 
          NOTE_D4,NOTE_F4,NOTE_E4,NOTE_D4, 
          NOTE_G4,NOTE_G4, 
          NOTE_G4,NOTE_A4,NOTE_E4,NOTE_F4,
          //4 //12
          NOTE_D4,NOTE_D4, 
          NOTE_D4,NOTE_F4,NOTE_E4,NOTE_D4, 
          NOTE_C4,NOTE_G4,NOTE_D4,NOTE_E4, 
          NOTE_C4,NOTE_C5,

         };

int Melody2[] = {
          //1 //15 //환희의 송가
        NOTE_E4,NOTE_E4,NOTE_F4,NOTE_G4, 
        NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4, 
        NOTE_C4,NOTE_C4,NOTE_D4,NOTE_E4, 
        NOTE_E4,NOTE_D4,NOTE_D4,
        //2 //15
        NOTE_E4,NOTE_E4,NOTE_F4,NOTE_G4, 
        NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4, 
        NOTE_C4,NOTE_C4,NOTE_D4,NOTE_E4, 
        NOTE_D4,NOTE_C4,NOTE_C4,
        //3 //17
        NOTE_D4,NOTE_D4,NOTE_E4,NOTE_C4, 
        NOTE_D4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_C4, 
        NOTE_D4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_D4, 
        NOTE_C4,NOTE_D4,NOTE_D4,
        //4 //15
        NOTE_E4,NOTE_E4,NOTE_F4,NOTE_G4, 
        NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4, 
        NOTE_C4,NOTE_C4,NOTE_D4,NOTE_E4, 
        NOTE_E4,NOTE_D4,NOTE_D4,
         };
         
//        {NOTE_C5, NOTE_C5, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_C4,},//falling
//        {NOTE_A5, NOTE_C5, NOTE_A5, NOTE_E5, NOTE_A5, NOTE_D5, NOTE_A5, NOTE_F5,},//tention
//        {NOTE_G5, NOTE_F5, NOTE_G5,       0, NOTE_E5, NOTE_F5, NOTE_D5,       0,},//bridge
//        {NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G3,},
//        {NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G3,},
//        {NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G3,},
//
//};

unsigned long oldMillis = 0, diffTime = 0;

void setup() {
        Serial.begin(9600);
        Serial.println("Basic Encoder Test:");
        pinMode(modeBtn, INPUT_PULLUP);
}

long oldPosition  = -999;

int melodyCnt;
int delay_time=150;

void loop() {

        int sensorVal = analogRead(A0);
        Serial.println(sensorVal);

  
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

                int music=0;
                
                
                switch (setMode) {
                case 0:
                  music=12+14+12+12;
                  if (sensorVal < 370 ){
                    int start = 1;
                    while(start < music) {              
                      tone(8,Melody1[start%music], 100);
                      delay(delay_time);
                      start++;
                    }
                  }
                case 1:
                  music=15+15+17+15;
                  if (sensorVal < 370 ){
                    int start = 1;
                    while(start < music) {              
                      tone(8,Melody2[start%music], 100);
                      delay(delay_time);
                      start++;
                    }
                  }
//                case 2:
//                  music=;
//                  mode=2;
//                case 3:
//                  music=;
//                  mode=3;
//                case 4:
//                  music=;
//                  mode=4;
//                case 5:
//                  music=;
//                  mode=5;
//                case 6:
//                  music=;
//                  mode=6;
//                case 7:
//                  music=;
//                  mode=7;
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

                        if (setMode < 2) setMode++;
                        else          setMode = 0;
                }

        }
        else
        {
                flag = 0;
        }
}
