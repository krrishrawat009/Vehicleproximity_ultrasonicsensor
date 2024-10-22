# Arduino Fixed-point Vehicle Proximity Detector 🚗

## Overview
This project implements a vehicle proximity detection system using Arduino UNO and ultrasonic sensors for enhanced parking safety. The system provides real-time visual feedback through LED indicators to help drivers avoid collisions during parking manoeuvres.

## Features
- Real-time distance measurement using HC-SR04 ultrasonic sensor
- Visual feedback through three LED indicators (Red, Yellow, Green)
- Configurable distance thresholds for different safety zones
- Serial monitor output for debugging
- Easy to install and customize

## Hardware Requirements
- Arduino UNO board
- HC-SR04 Ultrasonic Sensor
- 3x LEDs (Red, Yellow, Green)
- 3x 220Ω resistors (for LEDs)
- Breadboard and jumper wires
- USB cable for Arduino

## Pin Configuration
```
Arduino UNO     |     Component
----------------|-------------------
Pin 8           |     HC-SR04 Trigger
Pin 9           |     HC-SR04 Echo
Pin 11          |     Green LED
Pin 12          |     Yellow LED
Pin 13          |     Red LED
5V              |     HC-SR04 VCC
GND             |     HC-SR04 GND
```

## Installation
1. Clone this repository:
```bash
git clone https://github.com/yourusername/arduino-vehicle-proximity.git
```

2. Open `proximity_detector.ino` in the Arduino IDE

3. Connect your Arduino UNO and upload the sketch

## Circuit Diagram
```
                       HC-SR04
                    +----------+
                    |          |
Arduino Pin 8 ------|TRIG ECHO|------ Arduino Pin 9
                    |          |
        5V ---------|VCC  GND |------ GND
                    +----------+

        LED Configuration
        (with 220Ω resistors)
        
Arduino Pin 11 --[220Ω]--→ Green LED --→ GND
Arduino Pin 12 --[220Ω]--→ Yellow LED --→ GND
Arduino Pin 13 --[220Ω]--→ Red LED --→ GND
```

## Usage
1. Power up the Arduino board
2. The system will automatically start measuring distances
3. LED indicators will show:
   - Green: Safe distance (> 60 inches)
   - Yellow: Warning zone (6-60 inches)
   - Red: Danger zone (< 6 inches)
4. Monitor readings through Serial Monitor at 9600 baud (optional)

## Code Structure
```
/
├── LICENSE
├── README.md
├── proximity_detector.ino
├── docs/
│   ├── images/
│   │   ├── circuit_diagram.png
│   │   └── setup_photo.jpg
│   └── technical_details.md
└── tests/
    └── sensor_calibration.ino
```

## Contributing
1. Fork the repository
2. Create a new branch (`git checkout -b feature/improvement`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/improvement`)
5. Create a Pull Request

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Authors
- Krishna Rawat (RA2311030010088)
- Thasleem Sulthan (RA2311030010116)
- Abhinav K Anudath (RA2311030010066)

## Acknowledgments
- SRM Institute of Science and Technology
- College of Engineering and Technology
- Course: Computer Organization and Architecture (21CSS201T)
