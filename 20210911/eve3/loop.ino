void loop() {
  touchState = digitalRead(hit);
  Serial.println(touchState);

  if (touchState == 1) {  // 안 닿아있으면
    printShape(0);
  }
  else {                  // 닿아있으면
    printShape(1);
  }

//  countHit(); // 닿은 횟수 세기 (0~9, 10번 닿으면 펑!)

//  printNumber(3); // 원하는 숫자 출력하기
//
//for (int j = 0; j < 9; j++) {
//  printShape(j);
//  delay(1000);
//}

//  printShape(6); // 원하는 모양 출력하기
//  delay(1000);
//  printShape(7);
//  delay(1000);
//  printShape(8);
//  delay(1000);
//  printShape(9);
//  delay(1000);
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
//  printShape(count);
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
     case 0 : printShape(0);
      delay(100);
      break;
    case 1 : printShape(1);
      delay(100);
      break;
    case 2 : printShape(2);
      delay(100);
      break;
    case 3 : printShape(3);
      delay(100);
      break;
    case 4 : printShape(4);
      delay(100);
      break;
    case 5 : printShape(5);
      delay(100);
      break;
    case 6 : printShape(6);
      delay(100);
      break;
    case 7 : printShape(7);
      delay(100);
      break;
    case 8 : printShape(8);
      delay(100);
      break;
    case 9 : printShape(9);
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
