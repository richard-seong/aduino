void setup() {
        Serial.begin(9600);
}

void loop() {
        int sensorVal = analogRead(A0);
        Serial.println(sensorVal);
        if(sensorVal<390)       
        tone(8,sensorVal,20);
        delay(20);
}
