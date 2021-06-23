#include <SoftwareSerial.h>
#include <Servo.h>

#define TRIG 8
#define ECHO 9
#define RXD 2
#define TXD 3
#define BUZZER 5
#define LED 4
#define OPENLED 12
#define CLOSELED 13
#define SERVO 6
#define TRIG2 10
#define ECHO2 111

SoftwareSerial BTSerial(TXD, RXD);
Servo servo;

int angle = 0;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(OPENLED, OUTPUT);
  pinMode(CLOSELED, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
  servo.attach(SERVO);

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

  long duration2, distance2;
  digitalWrite(TRIG2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2, LOW);

  duration2 = pulseIn(ECHO2, HIGH);
  distance2 = duration2 / 29 / 2;

  servo.write(angle);
  digitalWrite(OPENLED, LOW);
  digitalWrite(CLOSELED, HIGH);

    Serial.println(distance);
    Serial.println(distance2);

  if(distance > 20){
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

    Serial.println("문을 여시겠습니까?  1.예  2.아니오");

    for(int z = 0; z < 100; z++){
      BTSerial.available();
      char cData = BTSerial.read();
      if('1' == cData){
            tone(BUZZER, 100);
            delay(500);
            noTone(BUZZER);
            delay(100);
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

            z = 100;

            Serial.println("문을 엽니다.");

            digitalWrite(OPENLED, HIGH);
            digitalWrite(CLOSELED, LOW);
            
            angle = angle + 180;
            servo.write(angle);

            // 사람 있을때 대기하도록 소스

            delay(2500);

            digitalWrite(OPENLED, LOW);
            digitalWrite(CLOSELED, HIGH);
            
            angle = 0;
            servo.write(angle);
            
            delay(2500);
            
            
          }else if('2' == cData){
            tone(BUZZER, 60);
            delay(250);
            noTone(BUZZER);
            delay(100);
            tone(BUZZER, 60);
            delay(250);
            noTone(BUZZER);
            delay(100);

            z = 100;

            Serial.println("문을 열지 않습니다.");

          }else{
            digitalWrite(LED, HIGH);
            delay(150);
            digitalWrite(LED, LOW);
            delay(150);
    
            z = 0;

      }
      
    }


    
  }

  if(distance2 > 20){

    Serial.println("경보를 끄려면 3번을 누르세요.");

    for(int y = 0; y < 100; y++){
      BTSerial.available();
      char cData = BTSerial.read();
      if('3' == cData){
            tone(BUZZER, 100);
            delay(500);
            noTone(BUZZER);
            delay(100);

            y = 100;

            Serial.println("경보를 끕니다.");

      }else{
        tone(BUZZER, 80);
        delay(300);
        tone(BUZZER, 100);
        delay(300);

        y = 0;
        
      }
      
    }

  }

}
