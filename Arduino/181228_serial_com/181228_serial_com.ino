int sensorPin = 7; // sensorPin은 7번 값
int sensorValue = 0; // sensorValue는 0

void setup(){
  Serial.begin(9600); // 초당 전송할 수 있는 bit 수(bps)
}

void loop() {
  /*
  sensorValue = digitalRead(sensorPin);
  // sensorValue는 7번으로 입력되는 값(5v = 1, 0v = 0)
  Serial.println(sensorValue); // sensorValue 값을 화면에 출력
  delay(1000); // 1초 간격으로 전송
  */

  Serial.println('A');
  delay(500);
  Serial.println('B');
  delay(500);
  Serial.println('C');
  delay(500);
  Serial.println('D');
  delay(500);
  Serial.println('E');
  delay(500);
  Serial.println("ABCDE");
  delay(500);

}
