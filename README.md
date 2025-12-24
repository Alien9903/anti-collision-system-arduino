# anti-collision-system-arduino
Low-cost anti-collision assistance system for motorcycles and old vehicles using Arduino and ultrasonic sensor.

# Anti-Collision Assistance System (Arduino)
- This project is a low-cost embedded system designed to help prevent collisions on motorcycles and old vehicles that lack modern safety assistance.
- It uses an ultrasonic sensor to measure the distance to obstacles and provides real-time visual and sound alerts to the driver.

# Objectives
- Improve road safety for old vehicles and motorcycles
- Provide a simple, affordable, and local solution
- Demonstrate a complete embedded system workflow

# System Features
- Real-time distance measurement (HC-SR04)
- Adjustable safety distance using potentiometer
- Visual alerts (Blue / Green / Red LEDs)
- Sound alerts with progressive warning buzzer
- Noise filtering for stable measurements

# System Architecture
- Arduino Uno (Main controller)
- HC-SR04 Ultrasonic Sensor
- LEDs (Blue, Green, Red)
- Active Buzzer
- Potentiometer (User-adjus- table threshold)
# Wiring Overview
| Component     | Arduino Pin |
| ------------- | ----------- |
| HC-SR04 Trig  | D9          |
| HC-SR04 Echo  | D10         |
| Green LED     | D2          |
| Yellow LED    | D3          |
| Red LED       | D4          |
| Buzzer        | D6          |
| Potentiometer | A0          |

# Media
Photos and demo video are available in the media/ folder.

# Future Improvements
- Bluetooth connectivity (ESP32 version)
- Vibration feedback system
- Mobile app integration
- Weather-resistant enclosure
# Author
Ali
Embedded Systems & Electronics Enthusiast
