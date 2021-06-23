#include <ESP8266WiFi.h>

 

const char* ssid = "IT 404";

const char* password = "bitc5600";

 

WiFiServer server(80);

 

void setup() {

  Serial.begin(115200);

  delay(10);


  Serial.println();

  Serial.println();

  Serial.print("Connecting to ");

  Serial.println(ssid);

 

  WiFi.begin(ssid, password);

 

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  }

  Serial.println("");

  Serial.println("WiFi connected");

 

  server.begin();

  Serial.println("Server started");

 

  Serial.print("Use this URL to connect: ");

  Serial.print("http://");

  Serial.print(WiFi.localIP());

  Serial.println("/");

 

}

 

void loop() {

  WiFiClient client = server.available();

  if (!client) {

    return;

  }


  Serial.println("new client");

  while(!client.available()){

    delay(1);

  }


  String request = client.readStringUntil('\r');

  Serial.println(request);

  client.flush();

  client.println("HTTP/1.1 200 OK");

  client.println("Content-Type: text/html");

  client.println(""); //  do not forget this one

  client.println("<!DOCTYPE HTML>");

  client.println("<html>");

  client.print("HELLO WORLD!");

  client.println("</html>");

 

  delay(1);

  Serial.println("Client disonnected");

  Serial.println("");

}
