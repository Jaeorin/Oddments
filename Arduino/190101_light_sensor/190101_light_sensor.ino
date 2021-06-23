int BRIGHT_SENSOR = A0;
int LED = 7;
int threshold = 1022;
int Sensor_value;

void setup() {
  Serial.begin(9600);
  pinMode(BRIGHT_SENSOR, INPUT);
  pinMode(LED, OUTPUT);

}     

void loop() {
  Sensor_value = analogRead(A0);
  Serial.println(Sensor_value);
  delay(10);

}
