#include "pitches.h"

int melody[] ={
          //1 //12  //캉캉
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
          
//          //1 //15 //환희의 송가
//        NOTE_E4,NOTE_E4,NOTE_F4,NOTE_G4, 
//        NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4, 
//        NOTE_C4,NOTE_C4,NOTE_D4,NOTE_E4, 
//        NOTE_E4,NOTE_D4,NOTE_D4,
//        //2 //15
//        NOTE_E4,NOTE_E4,NOTE_F4,NOTE_G4, 
//        NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4, 
//        NOTE_C4,NOTE_C4,NOTE_D4,NOTE_E4, 
//        NOTE_D4,NOTE_C4,NOTE_C4,
//        //3 //17
//        NOTE_D4,NOTE_D4,NOTE_E4,NOTE_C4, 
//        NOTE_D4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_C4, 
//        NOTE_D4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_D4, 
//        NOTE_C4,NOTE_D4,NOTE_D4,
//        //4 //15
//        NOTE_E4,NOTE_E4,NOTE_F4,NOTE_G4, 
//        NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4, 
//        NOTE_C4,NOTE_C4,NOTE_D4,NOTE_E4, 
//        NOTE_E4,NOTE_D4,NOTE_D4,
        
//        NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6,
};

int delay_time=200;
int music=12+14+12+12;

void setup() {
        Serial.begin(9600);
}
void loop() {
        int sensorVal = analogRead(A0);
//        Serial.println(sensorVal);
//        int stepMelody = map(sensorVal,500*4,100*2,0,7);
        if (sensorVal < 445 ){
          int start = 1;
          while(start < music) {              
              tone(8,melody[start%music], 100);
//              Serial.println(start%(66));
              delay(delay_time);
              start++;
          }
        }
//          tone(8, melody[stepMelody], 100);
//        delay(100);
}
