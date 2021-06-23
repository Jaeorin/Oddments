#include <ESP8266WiFi.h>

const char* ssid = "IT 404";
const char* password = "bitc5600";

WiFiServer server(80);

int LED_pin = 16;
int turn_on = 0;
int turn_off = 1;

void setup()
{
  Serial.begin(115200);

  delay(10);

  pinMode(LED_pin, OUTPUT);
  digitalWrite(LED_pin, turn_off);
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
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

void loop()
{
  WiFiClient client = server.available();

  if (!client)
  {
    return;
  }

  Serial.println("new client");

  while(!client.available())
  {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  int value = turn_off;

  if (request.indexOf("/LED=ON") != -1)
  {
    digitalWrite(LED_pin, turn_on);
    value = turn_on;
  }

  if (request.indexOf("/LED=OFF") != -1)
  {
    digitalWrite(LED_pin, turn_off);
    value = turn_off;
  }

 
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led pin is now: ");

  if(value == turn_on)
  {
    client.print("On");
  }
  else
  {
    client.print("Off");
  }

  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn Off </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn ON </button></a><br />"); 
  client.println("</html>");

  delay(1);

  Serial.println("Client disonnected");
  Serial.println("");
}
