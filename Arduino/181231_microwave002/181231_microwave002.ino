#define TRIG 2 // TRIG를 2번 핀으로
#define ECHO 3 // ECHO를 3번 핀으로

void setup() {
  pinMode(TRIG, OUTPUT); // TIRG로 출력
  pinMode(ECHO, INPUT); // ECHO로 입력
  Serial.begin(9600); // 9600보드레이트

}

void loop() {
  long duration, distance; // 64비트 정수 duration, distance 선언
  digitalWrite(TRIG, LOW); // TRIG가 0v일 때
  delayMicroseconds(2); // 2 마이크로초 지연
  digitalWrite(TRIG, HIGH); // TRIG가 5v일 때
  delayMicroseconds(10); // 10 마이크로초 지연
  digitalWrite(TRIG, LOW); // TRIG에 0v

  duration = pulseIn(ECHO, HIGH);
  // 64비트 정수 duration의 값은 ECHO가 5v인 시간
  distance = duration / 29 / 2;
  // 64비트 정수 distance의 값은 duration /29 /2
  // '/ 29' : 초음파 29us 를 1cm/s 바꾸기 위한 나눗셈
  // '/ 2' : 왕복거리를 편도거리로 바꾸기 위한 나눗셈

  if(distance < 100) // 만약 distance의 값이 100보다 작으면
    Serial.println(distance); // distance의 값을 출력

  delay(100); // 다음 출력까지 0.1초만큼 지연

}
