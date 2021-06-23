#include <SoftwareSerial.h>

#define TRIG 2
#define ECHO 3
#define TXD 4
#define RXD 5
#define BUZZER 6
#define LED 7

SoftwareSerial BTSerial(TXD, RXD);

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);

}

void loop() {

  long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration / 29 / 2;


  if(distance > 50){
    noTone(BUZZER);
  }else{
    tone(BUZZER, 80);
    delay(100);
    noTone(BUZZER);
    delay(100);
    tone(BUZZER, 80);
    delay(100);
    noTone(BUZZER);
    delay(100);
    for(int z = 0; z < 100; z++){
      if(BTSerial.available()){
        char cData = BTSerial.read();
          if('1' == cData){
            tone(BUZZER, 100);
            delay(500);
            noTone(BUZZER);
            delay(100);

// 이곳에 문 열림 소스 삽입

            z = 100;
            
          }else if('2' == cData){
            tone(BUZZER, 60);
            delay(250);
            noTone(BUZZER);
            delay(100);
            tone(BUZZER, 60);
            delay(250);
            noTone(BUZZER);
            delay(100);

// 이곳에 문 열지 않는 소스 삽입

            z = 100;
            
          }
          
      }else{
        digitalWrite(LED, HIGH);
        delay(150);
        digitalWrite(LED, LOW);
        delay(150);

        z = 0;

      }
    }

    tone(BUZZER, 40);
    delay(300);
    tone(BUZZER, 60);
    delay(300);
    tone(BUZZER, 80);
    delay(300);
    tone(BUZZER, 100);
    delay(300);
    noTone(BUZZER);
    delay(100);
  }

}
