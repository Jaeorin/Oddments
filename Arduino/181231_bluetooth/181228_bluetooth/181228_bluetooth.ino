#include <SoftwareSerial.h> // 아두이노에 SoftwareSerial을 포함시킴
#define BT_TX 7
#define BT_RX 6

SoftwareSerial BTSerial(BT_TX, BT_RX); // SoftwareSerial의 이름은 BTSerial
// BTSerial은 블루투스 기기

void setup(){
  Serial.begin(9600); // 아두이노를 9600포트레이트에 연결
  BTSerial.begin(9600); // BTSerial을 9600포트레이트에 연결

}

void loop(){
  if(BTSerial.available()){ // 만약 BTSerial에서 값이 들어오면
    // Serial.write("[");
    Serial.write(BTSerial.read()); // 아두이노 모니터에 출력
    // Serial.write("]\n");
    // 위 아래 주석문은 대괄호 및 띄우기
  }
  if(Serial.available()){ // 만약 아두이노에서 값이 들어오면
    BTSerial.write(Serial.read()); // 블루투스기기에 출력
  }

}
