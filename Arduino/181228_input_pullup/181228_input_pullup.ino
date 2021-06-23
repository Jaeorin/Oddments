#define LED 12 // LED를 12번 핀으로 연결
#define BUTTON 7 // 버튼을 7번 핀으로 연결

void setup() {
  pinMode(LED, OUTPUT); // LED로 출력
  pinMode(BUTTON, INPUT_PULLUP); // BUTTON으로 풀업이 적용된 입력
}

void loop() {
  if(digitalRead(BUTTON) == LOW){ // 만약 버튼에 0v가 흐르면
    digitalWrite(LED, HIGH); // LED에 5v를 흘린다
    delay(2000); // 2초동안
    digitalWrite(LED, LOW); // LED에 0v를 흘린다
  }
}
