#include <SoftwareSerial.h> // 아두이노에 SoftwareSerial을 포함시킴
#define BT_TX 7
#define BT_RX 6
#define led 8

SoftwareSerial BTSerial(BT_TX, BT_RX);

void setup(){
  BTSerial.begin(9600);
  pinMode(8, OUTPUT);

}

void loop(){
  if(BTSerial.available()){
    if('1' == BTSerial.read()){
      digitalWrite(8, HIGH);

    }else{
      digitalWrite(8, LOW);

    }
    
  }

}
