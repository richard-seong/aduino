#include <LedControl.h> // LedControl 헥사파일을 선언

LedControl dot = LedControl(7, 6, 5, 1); // (DIN, CLK, CS, 모듈 개수)
int hit = 2;
int touchState;
int flag;
int count = 0;


void setup() {
  dot.shutdown(0, false); // 절전모드 (첫번째 모듈, 절전모드를 하지 않는다) 
  dot.setIntensity(0, 5); // 밝기조절 (첫번째 모듈, 1~15 밝기)
  dot.clearDisplay(0);    // LED 초기화 (첫번째 모듈)

  Serial.begin(9600);
  pinMode(hit, INPUT_PULLUP);
}
