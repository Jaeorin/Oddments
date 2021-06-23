#include <SoftwareSerial.h> // 아두이노에 SoftwareSerial을 포함시킴
#define TRIG 2
#define ECHO 3
#define BT_RX 6
#define BT_TX 7
#define LED 9  

SoftwareSerial BTSerial(BT_TX, BT_RX);

void setup(){
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(LED, OUTPUT);

}

void loop(){
  if(BTSerial.available()){
    char cData = BTSerial.read();
    if('1' == cData){
      digitalWrite(LED, HIGH);
      
    }else if('2' == cData){
      long duration, distance;
      digitalWrite(TRIG, LOW);
      delayMicroseconds(2);
      digitalWrite(TRIG, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIG, LOW);

      duration = pulseIn(ECHO, HIGH);
      distance = duration / 29 / 2;

      if(distance < 100){
        BTSerial.println(distance);
        delay(100);
      }
      
    }else if('3' == cData){
      for(int x = 1; x < 100; x = x + 1){
        for(int y = 1; y < 255; y = y + 10){
          analogWrite(LED, y);
          delay(25);
                  
        }        
        
      }
      
    }else{
      digitalWrite(LED, LOW);
      
    }

  }

}
