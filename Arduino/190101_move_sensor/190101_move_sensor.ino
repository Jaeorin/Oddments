#define HUMAN 7

void setup() {
  // put your setup code here, to run once:
  pinMode(HUMAN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(HUMAN) == HIGH){
    Serial.println("HIGH");
    delay(100);
    Serial.println("LOW");
    
  }
}
