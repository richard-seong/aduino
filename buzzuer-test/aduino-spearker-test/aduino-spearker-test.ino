#include "pitches.h"

int melody1[] ={

//  NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,
//  NOTE_A4,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5,
//  NOTE_F5,NOTE_G5,NOTE_A5,NOTE_B5,NOTE_C6,
  // 곰세마리 12+12+18+18
  //1 //12
  NOTE_C4,NOTE_C4,NOTE_C4,NOTE_C4,NOTE_C4,0,
  NOTE_E4,NOTE_G4,NOTE_G4,NOTE_E4,NOTE_C4,0,
  //2 //12
  NOTE_G4,NOTE_G4,NOTE_E4,0,
  NOTE_G4,NOTE_G4,NOTE_E4,0,
  NOTE_C4,NOTE_C4,NOTE_C4,0,
  //3 //18
  NOTE_G4,NOTE_G4,NOTE_E4,NOTE_C4,0,
  NOTE_G4,NOTE_G4,NOTE_G4,0,
  NOTE_G4,NOTE_G4,NOTE_E4,NOTE_C4,0,
  NOTE_G4,NOTE_G4,NOTE_G4,0,
  //4 //18
  NOTE_G4,NOTE_G4,NOTE_E4,NOTE_C4,0,
  NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,0,
  NOTE_C5,NOTE_G4,NOTE_C5,NOTE_G4,
  NOTE_E4,NOTE_D4,NOTE_C4,
};

int melody2[] ={
  
//  캉캉 12+14+12+12
          //1 //12  
          NOTE_C4,NOTE_C4,NOTE_D4,NOTE_F4,
          NOTE_E4,NOTE_D4,NOTE_G4,NOTE_D4, 
          NOTE_G4,NOTE_A4,NOTE_E4,NOTE_F4,
          //2 //14
          NOTE_D4,NOTE_D4,NOTE_D4,NOTE_F4,
          NOTE_E4,NOTE_D4,NOTE_C4,NOTE_C5,
          NOTE_B4,NOTE_A4,NOTE_G4,NOTE_F4,
          NOTE_E4,NOTE_D4,
          //3 //12
          NOTE_C4,NOTE_C4,NOTE_D4,NOTE_F4,
          NOTE_E4,NOTE_D4,NOTE_G4,NOTE_G4, 
          NOTE_G4,NOTE_A4,NOTE_E4,NOTE_F4,
          //4 //12
          NOTE_D4,NOTE_D4,NOTE_D4,NOTE_F4,
          NOTE_E4,NOTE_D4,NOTE_C4,NOTE_G4,
          NOTE_D4,NOTE_E4,NOTE_C4,NOTE_C5,

};

int melody3[] ={

//  환희의 송가 15+15+17+15
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
        NOTE_D4,NOTE_E4,NOTE_F4,NOTE_E4,
        NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,
        NOTE_E4,NOTE_D4,NOTE_C4,NOTE_D4,
        NOTE_D4,
        //4 //15
        NOTE_E4,NOTE_E4,NOTE_F4,NOTE_G4, 
        NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4, 
        NOTE_C4,NOTE_C4,NOTE_D4,NOTE_E4, 
        NOTE_E4,NOTE_D4,NOTE_D4,
        
};

//int delay_time=150;
int delay_time=random(120,250);
//int music1=15;
int music1=12+12+18+18; 
int music2=12+14+12+12; 
int music3=15+15+17+15; 

int modeBtn = 2;
int setMode, flag;
int led_R = 3;
int led_G = 6;
int led_B = 9;

void setup() {
        Serial.begin(9600);
        pinMode(led_R, OUTPUT);
        pinMode(led_G, OUTPUT);
        pinMode(led_B, OUTPUT);
        pinMode(modeBtn,INPUT_PULLUP);
}
void loop() {
        MODE_SET();
        int sensorVal = analogRead(A0);
//        Serial.println(sensorVal);
        if (sensorVal < 150 ){
          int start = 0;
          Serial.println(start);
          switch (setMode) {
              case 0: 
                while(start < music1) { 
                  tone(8,melody1[start%music1], 100); 
                  delay(210);
                  analogWrite(led_R,start%2);
                  analogWrite(led_G,start%3);
                  analogWrite(led_B,start%5);
                  start++;
                };
                break;
              case 1:
                while(start < music2) { 
                  tone(8,melody2[start%music2], 100); 
                  delay(delay_time);
                  analogWrite(led_R,start%3);
                  analogWrite(led_G,start%5);
                  analogWrite(led_B,start%2);
                  start++;
                };
                break;
              case 2:
                while(start < music3) { 
                  tone(8,melody3[start%music3], 100); 
                  delay(delay_time);
                  analogWrite(led_R,start%5);
                  analogWrite(led_G,start%2);
                  analogWrite(led_B,start%3);
                  start++;
                };
                break;
            }
              
          }
          analogWrite(led_R,0);
          analogWrite(led_G,0);
          analogWrite(led_B,0);
}

void MODE_SET()
{
        if (digitalRead(modeBtn) == LOW)
        {
                if (!flag)
                {
                        flag = 1;

                        if (setMode < 2) setMode++;
                        else setMode = 0;
                }

        }
        else
        {
                flag = 0;
        }
}
