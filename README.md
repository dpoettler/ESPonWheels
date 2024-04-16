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
   - Configure the project with Wi-Fi network credentials of your liking. (by default: SSID - ESPonWheels; Key - ESPonWheels; IP - 192.168.0.1)
   - Upload the code to the ESP8266 microcontroller.
   - Press Ctrl + Shift + P and select "Upload LittleFS to ..." (this can be done shortly after the Code was uploaded to the ESP)

2. **Access the Web Interface**:
   - Once the code is uploaded connect your device to the ESPs Network.
   - Open a web browser and enter the IP address of the ESP8266.
   - You should now see the web interface for controlling the car.

## Usage

1. **Customize Controls**: The controls for the car are defined in the `index.html` file and their behavior is controlled by the JavaScript code in `index.js`. There are three types of button interactions:

   - **Hold and Release**: These buttons trigger an action when pressed and another action when released. They are handled by the `handleButtonHold` function in `index.js`. To add a new button of this type, add a new `div` element with a unique `id` in `index.html` and call `handleButtonHold` with the `id` and a message in `index.js`.

   - **Click**: These buttons trigger an action when clicked. They are handled by the `handleButtonClick` function in `index.js`. To add a new button of this type, add a new `div` element with a unique `id` in `index.html` and call `handleButtonClick` with the `id` and a message in `index.js`.

   - **Toggle**: These buttons toggle between two states when clicked. They are handled by the `handleButtonToggle` function in `index.js`. To add a new button of this type, add a new `div` element with a unique `id` in `index.html` and call `handleButtonToggle` with the `id` and a message in `index.js`.

2. **Adding, Changing, and Removing Buttons**: To add a new button, add a new `div` element with a unique `id` in `index.html` and call the appropriate handler function (`handleButtonHold`, `handleButtonClick`, or `handleButtonToggle`) with the `id` and a message in `index.js`. To change the behavior of a button, change the handler function call in `index.js` to the desired type and update the message if necessary. To remove a button, remove the `div` element from `index.html` and the corresponding handler function call from `index.js`.

3. **Styling Buttons**: The appearance of the buttons is controlled by the CSS in `index.css`. Each button should have the `button` class, and additional classes and ids can be used to apply specific styles. For example, the `active` class is used to change the appearance of a button when it is in the active state.

## Contributing

Contributions to ESPonWheels are welcome! Whether you want to fix bugs, add features, or improve documentation, your help is appreciated.

## License

This project is licensed under the [GPL v3 License](https://github.com/dpoettler/ESPonWheels?tab=GPL-3.0-1-ov-file).

---
