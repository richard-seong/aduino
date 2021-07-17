#include "pitches.h"

int melody[] ={

// mario 8+15+7+10+11+8+11+3+11+8+11+3+9+6+9+7+7+10+17+18+8+24+19+49
//        //1 //8  
//        NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, 
//        NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G3,
//        
//        //2 //15
//        NOTE_C5, NOTE_G4, NOTE_E4, NOTE_A4, 
//        NOTE_B4, NOTE_AS4, NOTE_A4,
//        NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, 
//        NOTE_G5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,
//        //3
//        //        NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_C5, NOTE_D5, NOTE_B4,
//        
//        //4 //7
//        NOTE_C5, NOTE_G4, NOTE_E4, NOTE_A4, 
//        NOTE_B4, NOTE_AS4, NOTE_A4,
//        
//        //5 //10
//        NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, 
//        NOTE_F5, NOTE_G5, NOTE_E5, NOTE_C5, 
//        NOTE_D5, NOTE_B4,
//        
//        //6 //11
//        NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, 
//        NOTE_E5, NOTE_G4, NOTE_A4, NOTE_C5, 
//        NOTE_A4, NOTE_C5, NOTE_D5,
//        
//        //7 //8
//        NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, 
//        NOTE_E5, NOTE_C6, NOTE_C6, NOTE_C6,
//        
//        //8 //11
//        NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, 
//        NOTE_E5, NOTE_G4, NOTE_A4, NOTE_C5, 
//        NOTE_A4, NOTE_C5, NOTE_D5,
//        
//        //9 //3
//        NOTE_DS5, NOTE_D5, NOTE_C5,
//        
//        //10 //11
//        NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, 
//        NOTE_E5, NOTE_G4, NOTE_A4, NOTE_C5, 
//        NOTE_A4, NOTE_C5, NOTE_D5,
//        
//        //11 //8
//        NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, 
//        NOTE_E5, NOTE_C6, NOTE_C6, NOTE_C6,
//        
//        //12 //11
//        NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, 
//        NOTE_E5, NOTE_G4, NOTE_A4, NOTE_C5, 
//        NOTE_A4, NOTE_C5, NOTE_D5,
//        
//        //13 //3
//        NOTE_DS5, NOTE_D5, NOTE_C5,
//        
//        //14 //9
//        NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, 
//        NOTE_D4, NOTE_E4, NOTE_C4, NOTE_A3, 
//        NOTE_G3,
//        
//        //15 //6
//        NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, 
//        NOTE_D4, NOTE_E4, 
//        //NOTE_G3,NOTE_C3, NOTE_G3,
//        
//        //16 //9
//        NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, 
//        NOTE_D4, NOTE_E4, NOTE_C4, NOTE_A3, 
//        NOTE_G3,
//        
//        //17 //7
//        NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4, 
//        NOTE_E4, NOTE_G4, NOTE_G3,
//        
//        //18 //7
//        NOTE_C5, NOTE_G4, NOTE_E4, NOTE_A4, 
//        NOTE_B4, NOTE_AS4, NOTE_A4,
//        
//        //19 //10
//        NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, 
//        NOTE_F5, NOTE_G5, NOTE_E5, NOTE_C5, 
//        NOTE_D5, NOTE_B4,
//        
//        //20 //17
//        NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_A4, 
//        NOTE_F5, NOTE_F5, NOTE_A4,
//        NOTE_B4, NOTE_A5, NOTE_A5, NOTE_A5, 
//        NOTE_G5, NOTE_F5,
//        NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
//        
//        //22 //18
//        NOTE_E5, NOTE_C5, NOTE_G4, NOTE_GS4, 
//        NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
//        NOTE_B3, NOTE_F5, NOTE_F5, NOTE_F5, 
//        NOTE_E5, NOTE_D5,        
//        NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
//        
//        //21 //8
//        NOTE_E4, NOTE_C4, NOTE_G3, NOTE_GS3, 
//        NOTE_A3, NOTE_F4, NOTE_F4, NOTE_A3,
//        
//        //22 //24
//        NOTE_B3, NOTE_A4, NOTE_A4, NOTE_A4, 
//        NOTE_G4, NOTE_F4, NOTE_E4, NOTE_C4, 
//        NOTE_A3, NOTE_G3, NOTE_E4, NOTE_C4, 
//        NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_F4, 
//        NOTE_F4, NOTE_A3, NOTE_B3, NOTE_F4, 
//        NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4,
//        
//        //23 //19
//        NOTE_C4, NOTE_E4, NOTE_E4, NOTE_C4,
//        NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, 
//        NOTE_D4, NOTE_E4, NOTE_C4, NOTE_A3, 
//        NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, 
//        NOTE_C4, NOTE_D4, NOTE_E4,
//        
//        //24 //49
//        NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, 
//        NOTE_D4, NOTE_E4, NOTE_C4, NOTE_A3, 
//        NOTE_G3, NOTE_E4, NOTE_E4, NOTE_E4, 
//        NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G3,
//        NOTE_E4, NOTE_C4, NOTE_G3, NOTE_GS3, 
//        NOTE_A3, NOTE_F4, NOTE_F4, NOTE_A3,
//        NOTE_B3, NOTE_A4, NOTE_A4, NOTE_A4, 
//        NOTE_G4, NOTE_F4, NOTE_E4, NOTE_C4, 
//        NOTE_A3, NOTE_G3, NOTE_E4, NOTE_C4, 
//        NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_F4, 
//        NOTE_F4, NOTE_A3, NOTE_B3, NOTE_F4, 
//        NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4, 
//        NOTE_C4,


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

int delay_time=150;
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
