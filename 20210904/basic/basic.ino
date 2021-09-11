void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//    digitalWrite(13,HIGH);
//    delay(1000);
//    
//    digitalWrite(13,LOW);
//    delay(1000);

  Serial.println(digitalRead(4));
  delay(20);

  if (digitalRead(4) == 1) {
    digitalWrite(13,LOW);
    digitalWrite(7,HIGH);
  }
  else {
    digitalWrite(13,HIGH);
    digitalWrite(7,LOW);
  }
   
}
