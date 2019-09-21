#define LED 2
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid     = "COMQ";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "huudat99";     // The password of the Wi-Fi network


void setup() {
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');


  // put your setup code here, to run once:
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }
  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer

  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    HTTPClient http;
    //connect server
    //http.begin(String("http://luyentap.000webhostapp.com/trang1/213/test.php"));
    http.begin(String("http://10.45.57.30:3000/hello"));
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    //send post
    int httpCode = http.POST(String("DV_ID=LED13"));
    // get response
    String payload = http.getString();
    http.end();
    //if send successful
    if (httpCode == 200) {
      // int n[10];
      Serial.println(payload);
      if (payload == "0") {
        Serial.println("Turn OFF led");
        digitalWrite(2, HIGH);
      }
      if (payload == "1") {
        Serial.println("Turn ON led");
        digitalWrite(2, LOW);
      }
    }
    else {
      Serial.println("fail");
    }
  }
  delay(3000);
}
