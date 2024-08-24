# Garbage Monitoring and Controlling with Smart Segregation of Dry and Wet Waste

## Project Description
This project implements an automated system for garbage monitoring and controlling with smart segregation of dry and wet waste using Arduino. The system detects waste type, manages bin levels, and provides real-time feedback through an LCD display and buzzer, thereby promoting efficient waste management.

## Features
- Automatic detection and segregation of dry and wet waste.
- Real-time monitoring of waste levels in bins using ultrasonic sensors.
- Notifications via buzzer and LCD display when bins are full.
- Reduced manual labor and health risks for waste workers.

## Hardware Requirements
- Arduino UNO
- IR Proximity Sensor
- Moisture Sensor
- Ultrasonic Sensor (2 units)
- Servo Motor
- 16x2 LCD Display
- Buzzer
- 10K Potentiometer
- 4 x AA Battery Holder Case

## Software Requirements
- Arduino IDE
- Libraries: 
  - `Servo.h`
  - `LiquidCrystal.h`
  - `Ultrasonic.h`

## Wiring Diagram
![Wiring Diagram](Wiring_diagram.png)

## Installation

1. **Setup Hardware:**
   - Connect the components to the Arduino UNO as per the wiring diagram:
     - IR Proximity Sensor to pin 6
     - Moisture Sensor to analog pin A0
     - Ultrasonic Sensors to pins 1 & 2 (wet bin) and pins 4 & 3 (dry bin)
     - Servo Motor to pin 5
     - Buzzer to pin 7
     - LCD Display to pins 8, 9, 10, 11, 12, 13
     - Potentiometer to adjust LCD contrast

2. **Arduino IDE:**
   - Install the Arduino IDE from the [Arduino official website](https://www.arduino.cc/en/Main/Software).
   - Install the required libraries using the Library Manager:
     - `Servo` for controlling the servo motor
     - `LiquidCrystal` for interacting with the LCD display
     - `Ultrasonic` for measuring distances with the ultrasonic sensors

3. **Upload Code:**
   - Open the Arduino IDE and paste the provided code into a new sketch.
   - Connect your Arduino UNO to your computer via USB.
   - Select the appropriate board and port from the Tools menu.
   - Click the upload button to upload the code to your Arduino UNO.

## Usage

1. Power the system using the 4 x AA Battery Holder Case.
2. The system detects the presence of waste using the IR Proximity Sensor.
3. The Moisture Sensor determines whether the waste is dry or wet.
4. The Servo Motor directs the waste to the appropriate bin.
5. Ultrasonic Sensors monitor the levels in both bins.
6. The LCD Display shows the current status of the bins, and the Buzzer alerts when a bin is full.

## Code Overview

- **Setup:** Initializes sensors, servo motor, LCD display, and serial communication.
- **Loop:** Continuously reads sensor values, determines the waste type, directs it to the correct bin, and checks bin levels. Provides real-time feedback on the LCD and triggers the buzzer when bins are full.

## Applications

- **Residential:** Helps households manage waste segregation.
- **Commercial:** Useful for waste management in restaurants, hotels, and offices.
- **Industrial:** Assists factories and warehouses with waste sorting.
- **Municipal:** Supports municipalities in efficient waste collection and management.

## Advantages

- Reduces waste sent to landfills.
- Encourages recycling and proper waste disposal.
- Minimizes health risks for waste workers.
- Enhances waste management efficiency.

## Limitations

- Initial setup and hardware costs.
- Requires ongoing maintenance and monitoring.
- Dependent on sensor accuracy and reliability.

## Future Scope

- IoT integration for remote monitoring and control.
- Advanced algorithms for improved waste segregation.
- Expansion to include additional waste types and features.

## Contributing
Feel free to contribute to this project by submitting issues, suggestions, or improvements via GitHub.

For any additional questions or support, please contact [Shreyas P](mailto:shreyasp182002@gmail.com).
