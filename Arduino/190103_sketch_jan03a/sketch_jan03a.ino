              #include <SoftwareSerial.h>
#include <Servo.h>

#define TXD 4
#define RXD 5
#define servoPin 8

Servo servo;
SoftwareSerial BTSerial(TXD, RXD);

int angle = 0;

void setup(){ 
  servo.attach(servoPin);
  Serial.begin(9600);
  BTSerial.begin(9600);

} 

void loop(){
  
  servo.write(angle);
  
  if(BTSerial.available()){
    char cData = BTSerial.read();
    if('1' == cData){
      angle = angle + 180;
      servo.write(angle);
      if(angle >= 180){
      delay(2500);
      angle = 0;
      servo.write(angle);
      }

    }

  }

}
