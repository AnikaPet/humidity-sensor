#include <PubSubClient.h>  // include library we included
#include <ESP8266WiFi.h>
#include <stdlib.h>
#include <DHT.h>

#define DPIN 4
#define DTYPE DHT11

DHT dht(DPIN,DTYPE);

const char *ssid = "***";  // replace with your wifi ssid and wpa2 key
const char *pass = "***";  //WiFi Password

WiFiClient client;
PubSubClient pubsub_client(client);

void setup() {
  Serial.begin(9600);
  dht.begin();

  delay(10);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  pubsub_client.setServer("demo.thingsboard.io", 1883);

  while (!pubsub_client.connect("***", "***", NULL)) {
    delay(500);
  Serial.print(".");
}
  Serial.println("");
  Serial.println("Thingsboard connected");
}

void loop() {
  delay(2000);

  /*
  String payload = "{";
  payload += "\"rssi\":"; payload += strptr;
  payload += "}";
  Serial.println(payload);

  if(pubsub_client.publish("v1/devices/me/telemetry",payload.c_str()))
    Serial.println("Published");

  */
}