#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // Change this to your Ethernet shield's MAC address
IPAddress server(127, 0, 0, 1); // Localhost or 127.0.0.1
EthernetClient client;

void setup() {
  Ethernet.begin(mac);
  Serial.begin(9600);

  delay(1000);

  Serial.println("Connecting...");

  if (client.connect(server, 80)) {
    Serial.println("Connected to server");
    client.println("GET /path_to_php_script/script.php?data=your_data HTTP/1.1");
    client.println("Host: localhost");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("Connection failed");
  }
}

void loop() {
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("Disconnecting.");
    client.stop();

    while (true);
  }
}
