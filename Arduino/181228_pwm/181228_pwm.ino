// 전류 흐른 시간을 이용하여 LED 조명 밝기 변환

void setup(){
  pinMode(6, OUTPUT); // 6번으로 출력
}

void loop(){
  for(int i = 10; i < 255; i = i + 10){
    analogWrite(6, i);
    delay(50);
  }
}
