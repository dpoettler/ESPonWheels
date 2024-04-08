#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

char *ssid = "ESPonWheels";
const char *password = "ESPonWheels";



const char *html =
    "<!DOCTYPE html>\n"
    "<html>\n"
    "\n"
    "<head>\n"
    "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, maximum-scale=1.0\" />\n"
    "    <title>ESPonWheels</title>"
    "    <meta name=\"author\" content=\"dpoettler\">"
    "    <meta name=\"description\" content=\"Webinterface for controlling a car with an ESP8266\">"
    "    <style>\n"
    "        body {\n"
    "            display: flex;\n"
    "            justify-content: center;\n"
    "            align-items: center;\n"
    "            height: 100vh;\n"
    "            margin: 0;\n"
    "            background-color: #f0f0f0;\n"
    "            font-family: Arial, sans-serif;\n"
    "        }\n"
    "\n"
    "        #controller {\n"
    "            display: grid;\n"
    "            grid-template-columns: 100px 100px 100px;\n"
    "            grid-template-rows: 100px 100px 100px;\n"
    "            gap: 10px;\n"
    "            justify-items: center;\n"
    "            align-items: center;\n"
    "        }\n"
    "\n"
    "        #controller button {\n"
    "            width: 100px;\n"
    "            height: 100px;\n"
    "        }\n"
    "\n"
    "        #speed-slider {\n"
    "            position: absolute;\n"
    "            bottom: 20px;\n"
    "            width: 80%;\n"
    "        }\n"
    "\n"
    "        #top-buttons {\n"
    "            position: absolute;\n"
    "            top: 20px;\n"
    "            display: flex;\n"
    "            gap: 10px;\n"
    "        }\n"
    "\n"
    "        button {\n"
    "            padding: 10px;\n"
    "            /* Adjust as needed */\n"
    "            position: relative;\n"
    "            /* Ensures the SVG is positioned relative to the button */\n"
    "        }\n"
    "\n"
    "        button svg {\n"
    "            width: 100%;\n"
    "            height: 100%;\n"
    "            position: absolute;\n"
    "            top: 0;\n"
    "            left: 0;\n"
    "        }\n"
    "    </style>\n"
    "</head>\n"
    "\n"
    "<body>\n"
    "    <div id=\"top-buttons\">\n"
    "    </div>\n"
    "    <div id=\"controller\">\n"
    "        <div></div>\n"
    "        <button id=\"forward\">\n"
    "            <svg xmlns=\"http://www.w3.org/2000/svg\"\n"
    "                viewBox=\"0 0 384 512\"><!--!Font Awesome Free 6.5.1 by @fontawesome - https://fontawesome.com License - https://fontawesome.com/license/free Copyright 2024 Fonticons, Inc.-->\n"
    "                <path\n"
    "                    d=\"M214.6 41.4c-12.5-12.5-32.8-12.5-45.3 0l-160 160c-12.5 12.5-12.5 32.8 0 45.3s32.8 12.5 45.3 0L160 141.2V448c0 17.7 14.3 32 32 32s32-14.3 32-32V141.2L329.4 246.6c12.5 12.5 32.8 12.5 45.3 0s12.5-32.8 0-45.3l-160-160z\" />\n"
    "            </svg>\n"
    "        </button>\n"
    "        <div></div>\n"
    "        <button id=\"left\">\n"
    "            <svg xmlns=\"http://www.w3.org/2000/svg\"\n"
    "                viewBox=\"0 0 448 512\"><!--!Font Awesome Free 6.5.1 by @fontawesome - https://fontawesome.com License - https://fontawesome.com/license/free-->\n"
    "                <path\n"
    "                    d=\"M9.4 233.4c-12.5 12.5-12.5 32.8 0 45.3l160 160c12.5 12.5 32.8 12.5 45.3 0s12.5-32.8 0-45.3L109.2 288 416 288c17.7 0 32-14.3 32-32s-14.3-32-32-32l-306.7 0L214.6 118.6c12.5-12.5 12.5-32.8 0-45.3s-32.8-12.5-45.3 0l-160 160z\" />\n"
    "            </svg>\n"
    "        </button>\n"
    "        <button id=\"backward\">\n"
    "            <svg xmlns=\"http://www.w3.org/2000/svg\"\n"
    "                viewBox=\"0 0 384 512\"><!--!Font Awesome Free 6.5.1 by @fontawesome - https://fontawesome.com License - https://fontawesome.com/license/free-->\n"
    "                <path\n"
    "                    d=\"M169.4 470.6c12.5 12.5 32.8 12.5 45.3 0l160-160c12.5-12.5 12.5-32.8 0-45.3s-32.8-12.5-45.3 0L224 370.8 224 64c0-17.7-14.3-32-32-32s-32 14.3-32 32l0 306.7L54.6 265.4c-12.5-12.5-32.8-12.5-45.3 0s-12.5 32.8 0 45.3l160 160z\" />\n"
    "            </svg>\n"
    "        </button>\n"
    "        <button id=\"right\">\n"
    "            <svg xmlns=\"http://www.w3.org/2000/svg\"\n"
    "                viewBox=\"0 0 448 512\"><!--!Font Awesome Free 6.5.1 by @fontawesome - https://fontawesome.com License - https://fontawesome.com/license/free-->\n"
    "                <path\n"
    "                    d=\"M438.6 278.6c12.5-12.5 12.5-32.8 0-45.3l-160-160c-12.5-12.5-32.8-12.5-45.3 0s-12.5 32.8 0 45.3L338.8 224 32 224c-17.7 0-32 14.3-32 32s14.3 32 32 32l306.7 0L233.4 393.4c-12.5 12.5-12.5 32.8 0 45.3s32.8 12.5 45.3 0l160-160z\" />\n"
    "            </svg>\n"
    "        </button>\n"
    "        <button id=\"light-front\">Light Front</button>\n"
    "        <button id=\"light-back\">Light Back</button>\n"
    "        <button id=\"horn\">\n"
    "            <svg xmlns=\"http://www.w3.org/2000/svg\"\n"
    "                viewBox=\"0 0 640 512\"><!--!Font Awesome Free 6.5.1 by @fontawesome - https://fontawesome.com License - https://fontawesome.com/license/free-->\n"
    "                <path\n"
    "                    d=\"M533.6 32.5C598.5 85.2 640 165.8 640 256s-41.5 170.7-106.4 223.5c-10.3 8.4-25.4 6.8-33.8-3.5s-6.8-25.4 3.5-33.8C557.5 398.2 592 331.2 592 256s-34.5-142.2-88.7-186.3c-10.3-8.4-11.8-23.5-3.5-33.8s23.5-11.8 33.8-3.5zM473.1 107c43.2 35.2 70.9 88.9 70.9 149s-27.7 113.8-70.9 149c-10.3 8.4-25.4 6.8-33.8-3.5s-6.8-25.4 3.5-33.8C475.3 341.3 496 301.1 496 256s-20.7-85.3-53.2-111.8c-10.3-8.4-11.8-23.5-3.5-33.8s23.5-11.8 33.8-3.5zm-60.5 74.5C434.1 199.1 448 225.9 448 256s-13.9 56.9-35.4 74.5c-10.3 8.4-25.4 6.8-33.8-3.5s-6.8-25.4 3.5-33.8C393.1 284.4 400 271 400 256s-6.9-28.4-17.7-37.3c-10.3-8.4-11.8-23.5-3.5-33.8s23.5-11.8 33.8-3.5zM301.1 34.8C312.6 40 320 51.4 320 64V448c0 12.6-7.4 24-18.9 29.2s-25 3.1-34.4-5.3L131.8 352H64c-35.3 0-64-28.7-64-64V224c0-35.3 28.7-64 64-64h67.8L266.7 40.1c9.4-8.4 22.9-10.4 34.4-5.3z\" />\n"
    "            </svg>\n"
    "        </button>\n"
    "    </div>\n"
    "    <input type=\"range\" min=\"0\" max=\"1\" step=\"0.01\" value=\"0.5\" id=\"speed-slider\">\n"
    "    <script>\n"
    "        let buttonHoldInterval;\n"
    "        let speedMultiplier = document.getElementById('speed-slider').value;\n"
    "        document.getElementById('speed-slider').addEventListener('change', function () {\n"
    "            speedMultiplier = this.value;\n"
    "            console.log('Speed multiplier set to ' + speedMultiplier);\n"
    "            fetch('/set-speed?speed=' + encodeURIComponent(speedMultiplier));\n"
    "        })\n"
    "        function handleButtonHold(buttonId, message) {\n"
    "            document.getElementById(buttonId).addEventListener('mousedown', function () {\n"
    "                console.log(message + ' button pressed');\n"
    "                fetch('/' + buttonId + '/press');\n"
    "            })\n"
    "            document.getElementById(buttonId).addEventListener('mouseup', function () {\n"
    "                console.log(message + ' button released');\n"
    "                fetch('/' + buttonId + '/release');\n"
    "                clearInterval(buttonHoldInterval);\n"
    "            })\n"
    "        };\n"
    "        function handleButtonClick(buttonId, message) {\n"
    "            document.getElementById(buttonId).addEventListener('click', function () {\n"
    "                console.log(message + ' button clicked');\n"
    "                fetch('/' + buttonId);\n"
    "            });\n"
    "        }\n"
    "        handleButtonHold('forward', 'Forward');\n"
    "        handleButtonHold('backward', 'Backward');\n"
    "        handleButtonHold('left', 'Left');\n"
    "        handleButtonHold('right', 'Right');\n"
    "        handleButtonHold('horn', 'Horn');\n"
    "        handleButtonClick('light-front', 'Light Front');\n"
    "        handleButtonClick('light-back', 'Light Back');\n"
    "    </script>\n"
    "</body>\n"
    "\n"
    "</html>";

void handleButtonPress(const String &buttonId)
{
    // Convert button press into PWM output
    // ...
    server.send(200, "text/plain", "OK");
}

void handleButtonRelease(const String &buttonId)
{
    // Convert button release into PWM output
    // ...
    server.send(200, "text/plain", "OK");
}

void handleSetSpeed(String speedStr)
{
    float speed = speedStr.toFloat();
    // Convert speed into PWM output
    // ...
    server.send(200, "text/plain", "OK");
}

void handleLight(const String &buttonId)
{
    // Set lights
    // ...
    server.send(200, "text/plain", "OK");
}

void setup()
{
    WiFi.softAP(ssid, password);

    server.on("/", []()
              { server.send(200, "text/html", html); });

    server.on("/forward/press", []()
              { handleButtonPress("forward"); });
    server.on("/backward/press", []()
              { handleButtonPress("backward"); });
    server.on("/left/press", []()
              { handleButtonPress("left"); });
    server.on("/right/press", []()
              { handleButtonPress("right"); });
    server.on("/horn/press", []()
              { handleButtonPress("horn"); });

    server.on("/forward/release", []()
              { handleButtonRelease("forward"); });
    server.on("/backward/release", []()
              { handleButtonRelease("backward"); });
    server.on("/left/release", []()
              { handleButtonRelease("left"); });
    server.on("/right/release", []()
              { handleButtonRelease("right"); });
    server.on("/horn/release", []()
              { handleButtonRelease("horn"); });

    server.on("/set-speed", []() {
        if (server.hasArg("speed")) {
            String speed = server.arg("speed");
            handleSetSpeed(speed);
            server.send(200, "text/plain", "OK");
        } else {
          server.send(204, "text/plain", "No content");
        }
    });

    server.on("/light-front", []()
              { handleLight("front"); });
    server.on("/light-back", []()
              { handleLight("back"); });
    server.begin();
}

void loop()
{
    server.handleClient();
}
