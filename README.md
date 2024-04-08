# ESPonWheels w/out LittleFS

ESPonWheels is a fun project aimed at controlling a car using a web interface. It utilizes the ESP8266 microcontroller to establish a connection between the car and the controlling device.
The Project was initially made for a school project.

## Features

- **Web Interface**: Control the car easily through a user-friendly web interface accessible from any device with a browser.
- **Customizable**: Modify and expand the project to suit your preferences and needs.
- **Easy Setup**: Set up the project quickly with detailed instructions provided below.

## Requirements

- ESP8266 microcontroller
- A car that can use the ESP
- A browser :)

## Installation and Setup

1. **Software Setup**:
   - Clone this repository to your local machine.
   - Open the project in your preferred Arduino IDE.
   - Configure the project with Wi-Fi network credentials of your liking. (by default: SSID - ESPonWheels, Key - ESPonWheels)
   - Upload the code to the ESP8266 microcontroller.

2. **Access the Web Interface**:
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

**Note: This branch is useable without LittleFS. For this reason it is harder to maintain and will be discontinued.
