Home Automation using ESP32

📌 Project Overview

This project is a smart home automation system developed using ESP32, 4-channel relay module(used in 1 channel) and a web-based mobile interface.
The user can control electrical appliances such as bulbs, fans, or other devices through a smartphone connected to the same WiFi network.

The ESP32 hosts a web server and provides ON/OFF buttons on a webpage. When the user presses a button, the connected appliance turns ON or OFF through the relay module.

---

🚀 Features

- Control appliances using mobile phone
- WiFi based home automation
- Web browser interface (no app required)
- Low-cost and easy to build
- Expandable for multiple appliances

---

🛠 Components Required

- ESP32 Development Board
- 4 Channel Relay Module(used in 1 channel )
- Bulb 
- Jumper Wires
- Breadboard (optional)
- Mobile Phone
- WiFi Hotspot / Router
- Power Supply

---

🔌 Circuit Connections

Relay Module to ESP32

- IN1 → GPIO 4
- VCC → 5V
- GND → GND

Bulb Connection

- AC Live wire → Relay COM
- Relay NO → Bulb
- Neutral wire → Direct Bulb

«⚠️ Warning: Handle AC mains carefully.»

---

💻 Working Principle

1. ESP32 connects to WiFi network.
2. ESP32 starts a local web server.
3. Mobile phone opens ESP32 IP address in browser.
4. ON/OFF buttons appear on screen.
5. When button is pressed, relay switches appliance ON/OFF.

---

📱 Output

- Mobile controlled bulb switching
- Real-time appliance control through browser

---

🔮 Future Scope

- Google Assistant control
- Voice control
- IoT cloud monitoring
- Sensor based automation
- Energy monitoring system

