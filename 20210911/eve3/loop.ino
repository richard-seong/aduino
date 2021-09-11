void loop() {
  touchState = digitalRead(hit);
  Serial.println(touchState);

  if (touchState == 1) {  // 안 닿아있으면
    printNumber(0);
  }
  else {                  // 닿아있으면
    printNumber(1);
  }

  //countHit(); // 닿은 횟수 세기 (0~9, 10번 닿으면 펑!)

  //printNumber(5); // 원하는 숫자 출력하기

  //printShape(0); // 원하는 모양 출력하기

}






void printNumber(int number) {
  for (int j = 0; j < 8; j++) {
    dot.setRow(0, j, digits[number][j]);
  }
}

void printShape(int shape) {
  for (int j = 0; j < 8; j++) {
    dot.setRow(0, j, customShape[shape][j]);
  }
}

void printAll(int on1off0) {
  for (int j = 0; j < 8; j++) {
    dot.setRow(0, j, bomb[on1off0][j]);
  }
}

void countHit() {
  printNumber(count);
  if (touchState == 0) {
    if (flag == 0) {
      if (count < 11) {
        count ++;
      }
      flag = 1;
    }
  }
  else {
    flag = 0;
  }
  switch (count) {
    case 1 : printNumber(1);
      delay(100);
      break;
    case 2 : printNumber(2);
      delay(100);
      break;
    case 3 : printNumber(3);
      delay(100);
      break;
    case 4 : printNumber(4);
      delay(100);
      break;
    case 5 : printNumber(5);
      delay(100);
      break;
    case 6 : printNumber(6);
      delay(100);
      break;
    case 7 : printNumber(7);
      delay(100);
      break;
    case 8 : printNumber(8);
      delay(100);
      break;
    case 9 : printNumber(9);
      delay(100);
      break;
    case 10 : printAll(0);
      delay(200);
      printAll(1);
      delay(200);
      printAll(0);
      delay(200);
      printAll(1);
      delay(200);
      printAll(0);
      delay(200);
      printAll(1);
      delay(200);
      count = 0;
      break;
  }
}
