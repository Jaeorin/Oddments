int SOUND_SENSOR = A0;
int led = 7;
int threshold = 1022; // 모니터에 표시되는 감도를 보고 조절
int Sensor_value;

void setup() {
  Serial.begin(9600); // 9600보드레이트
  pinMode(SOUND_SENSOR, INPUT); // SOUND_SENSOR에 값을 입력
  pinMode(led, OUTPUT); // led로 값을 출력

}     

void loop() {
  Sensor_value = analogRead(A0);
  // 아날로그 핀(AO)의 값을 Sensor_value에 저장
  Serial.println(Sensor_value); // 모니터에 감도 표시
  delay(10); // 0.1초 간격으로 출력

  if(Sensor_value <= threshold){
  // 만약 아날로그 핀(A0)으로 입력된 값이 마이크센서 감도보다 클 경우
    digitalWrite(led, HIGH);
    delay(2000);
    // led에 약 2초간 5v
  }
  else{
    digitalWrite(led, LOW);
  // 아니면 led에 0v
  }

}
