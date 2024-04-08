# ESPonWheels 🚗

ESPonWheels is a fun project aimed at controlling a car using a web interface. It utilizes the ESP8266 microcontroller to establish a connection between the car and the controlling device.
The Project was initially made for a school project.

## Features

- **Web Interface**: Control the car easily through a user-friendly web interface accessible from any device with a browser.
- **Customizable**: Modify and expand the project to suit your preferences and needs.
- **Easy Setup**: Set up the project quickly with detailed instructions provided below.
- **Uses Little FS**: This project uses Little FS to make it easier to edit HTML Code and clean up the .ino file

## Requirements

- ESP8266 microcontroller
- A car that can use the ESP
- A browser :)

## Installation and Setup

1. **Software Setup**:
   - Download the LittleFS-Uploader from [GitHub](https://github.com/earlephilhower/arduino-littlefs-upload/releases/tag/1.0.0)
   - Put the downloaded File in a newly created folder called "plugins" inside your ".arduinoIDE" folder. (usually under C:\Users\username\)
   - Clone this repository to your local machine.
   - Open the project in Arduino IDE 2 or higher.
   - Press Ctrl + Shift + P and select "Upload LittleFS to ..."
   - Configure the project with Wi-Fi network credentials of your liking. (by default: SSID - ESPonWheels; Key - ESPonWheels; IP - 192.168.0.1)
   - Upload the code to the ESP8266 microcontroller.

3. **Access the Web Interface**:
   - Once the code is uploaded connect your device to the ESPs Network.
   - Open a web browser and enter the IP address of the ESP8266.
   - You should now see the web interface for controlling the car.

## Usage

- Use the directional controls on the web interface to move the car forward, backward, left, and right.
- Experiment with different speeds and use and/or edit SFX Buttons, like the HORN or the Lights.
- Have fun customizing and extending the project according to your interests!

## Contributing

Contributions to ESPonWheels are welcome! Whether you want to fix bugs, add features, or improve documentation, your help is appreciated.

## License

This project is licensed under the [GPL v3 License](https://github.com/dpoettler/ESPonWheels?tab=GPL-3.0-1-ov-file).

---
