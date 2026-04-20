#include <WiFi.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WiFiServer server(80);

// Relay connected to GPIO 4
int relayPin = 4;

void setup() {
  Serial.begin(115200);

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);   // Relay OFF (active LOW)

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.println("New Client Connected");

    String request = client.readStringUntil('\r');
    client.flush();

    // Relay ON
    if (request.indexOf("/ON") != -1) {
      digitalWrite(relayPin, LOW);
    }

    // Relay OFF
    if (request.indexOf("/OFF") != -1) {
      digitalWrite(relayPin, HIGH);
    }

    // Web Page
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();

    client.println("<html><head><title>Home Automation</title></head>");
    client.println("<body style='text-align:center;font-family:Arial;'>");
    client.println("<h1>HOME AUTOMATION</h1>");
    client.println("<a href='/ON'><button style='padding:15px 30px;font-size:20px;'>ON</button></a>");
    client.println("<br><br>");
    client.println("<a href='/OFF'><button style='padding:15px 30px;font-size:20px;'>OFF</button></a>");
    client.println("</body></html>");

    client.println();
    delay(1);
    client.stop();

    Serial.println("Client Disconnected");
  }
}
