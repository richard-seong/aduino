int buttonPin = 2;

int cnt;

void setup() {
        pinMode(buttonPin, INPUT_PULLUP);
        Serial.begin(9600);
}

void loop() {
        if(cnt<99)      cnt ++;
        else    cnt = 0;
        
        int sensorVal = digitalRead(buttonPin);
        if (sensorVal == 0)        tone(8,map(cnt,0,99,0,2000),20);

        delay(constrain(map(analogRead(A0),50,320,1,20),1,20));
        
}
