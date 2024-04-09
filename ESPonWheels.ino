#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "LittleFS.h"

ESP8266WebServer server(80);

char *ssid = "ESPonWheels";
const char *password = "ESPonWheels";
IPAddress ip(192, 168, 0, 1); // Set the desired IP address
IPAddress gateway(192, 168, 1, 1); // Set the gateway IP address
IPAddress subnet(255, 255, 255, 0); // Set the subnet mask

void handleButtonPress(const String &buttonId)
{
    // Convert button press into PWM output
    // ...
    Serial.print("Button '");
    Serial.print(buttonId);
    Serial.print("' pressed\n");
    server.send(200, "text/plain", "OK");
}

void handleButtonRelease(const String &buttonId)
{
    // Convert button release into PWM output
    // ...
    Serial.print("Button '");
    Serial.print(buttonId);
    Serial.print("' released\n");
    server.send(200, "text/plain", "OK");
}

void handleSetSpeed(String speedStr)
{
    float speed = speedStr.toFloat();
    Serial.print("Speed set to ");
    Serial.print(speed);
    Serial.print("\n");
    // Convert speed into PWM output
    // ...
    server.send(200, "text/plain", "OK");
}

void handleSFX(const String &buttonId)
{
    // Set lights
    // ...
    Serial.print("SFX button '");
    Serial.print(buttonId);
    Serial.print("' pressed\n");
    server.send(200, "text/plain", "OK");
}

void setup()
{
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(ip, gateway, subnet);
    WiFi.softAP(ssid, password);
    Serial.begin(115200);

    if (!LittleFS.begin())
    {
        Serial.println("An Error has occurred while mounting LittleFS");
        return;
    }

    server.on("/", []()
              { 
                File html = LittleFS.open("/index.html", "r");
                if (!html) {
                    Serial.println("Failed to open file for reading");
                    return;
                }
                server.send(200, "text/html", html); });

    server.on("/index.js", []()
              { 
                File js = LittleFS.open("/index.js", "r");
                if (!js) {
                    Serial.println("Failed to open file for reading");
                    return;
                }
                server.send(200, "text/javascript", js); });
    server.on("/index.css", []()
              { 
                File css = LittleFS.open("/index.css", "r");
                if (!css) {
                    Serial.println("Failed to open file for reading");
                    return;
                }
                server.send(200, "text/css", css); });

    server.on("/forward/press", []()
              { handleButtonPress("forward"); });
    server.on("/backward/press", []()
              { handleButtonPress("backward"); });
    server.on("/left/press", []()
              { handleButtonPress("left"); });
    server.on("/right/press", []()
              { handleButtonPress("right"); });
    server.on("/sfx3/press", []()
              { handleButtonPress("horn"); });

    server.on("/forward/release", []()
              { handleButtonRelease("forward"); });
    server.on("/backward/release", []()
              { handleButtonRelease("backward"); });
    server.on("/left/release", []()
              { handleButtonRelease("left"); });
    server.on("/right/release", []()
              { handleButtonRelease("right"); });
    server.on("/sfx3/release", []()
              { handleButtonRelease("horn"); });

    server.on("/set-speed", []()
              {
        if (server.hasArg("speed")) {
            String speed = server.arg("speed");
            handleSetSpeed(speed);
            server.send(200, "text/plain", "OK");
        } else {
          server.send(204, "text/plain", "No content");
        } });

    server.on("/sfx0", []()
              { handleSFX("sfx0"); });
    server.on("/sfx1", []()
              { handleSFX("sfx1"); });
    server.begin();
}

void loop()
{
    server.handleClient();
}
