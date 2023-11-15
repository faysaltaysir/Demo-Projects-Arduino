#include <ESP8266WiFi.h>

const char* ssid = "সাত দিয়ে ভাগ";
const char* password = "csewreboys22";

void setup() {
  Serial.begin(115200);
  //Serial.setDebugOutput(true);
  Serial.println();
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


  Serial.print("IP Address: 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10000);
}
