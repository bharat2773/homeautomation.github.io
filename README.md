# 🏠 Smart Home Automation System
### ESP32 + Tasmota + Home Assistant + MQTT

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Platform](https://img.shields.io/badge/platform-ESP32-green.svg)
![Status](https://img.shields.io/badge/status-active-success.svg)

---

## 📋 Table of Contents

- [Abstract](#abstract)
- [Introduction](#introduction)
- [System Architecture](#system-architecture)
- [Algorithm & Working](#algorithm--working)
- [Hardware Implementation](#hardware-implementation)
- [Software Setup](#software-setup)
  - [Tasmota Configuration](#tasmota-configuration)
  - [MQTT Broker Setup](#mqtt-broker-setup)
  - [Home Assistant Integration](#home-assistant-integration)
  - [Voice Assistant Integration](#voice-assistant-integration)
- [Automatic Mode Code](#automatic-mode-code)
- [Results & Inferences](#results--inferences)
- [Applications](#applications)
- [Conclusion & Future Scope](#conclusion--future-scope)

---

## 🎯 Abstract

This project implements a **Smart Home Automation system** using an ESP32 microcontroller, Tasmota firmware, MQTT protocol, and Home Assistant, enabling both automatic and manual voice-controlled operation of home appliances.

### Key Features

✅ Temperature-based automatic fan speed control  
✅ Manual control via Home Assistant dashboard  
✅ Voice commands through Alexa and Google Assistant  
✅ Real-time MQTT communication  
✅ Relay-based control of lights & fans  

This provides a convenient and accessible smart home ecosystem suitable even for elderly or physically challenged users.

---

## 🌟 Introduction

The **ESP32** is a powerful Wi-Fi-enabled microcontroller with dual-core processing and rich GPIO support.

### Technology Stack

| Technology | Purpose |
|------------|---------|
| **Tasmota Firmware** | Device configuration without coding |
| **Home Assistant** | Central smart home controller |
| **MQTT Protocol** | Lightweight IoT messaging |
| **ESP32** | Hardware controller + relay driver |

This combination creates a **scalable and cost-efficient** home automation solution.

---

## 🏗️ System Architecture

```
ESP32 → Tasmota → MQTT Broker → Home Assistant → Voice Assistants (Alexa / Google)
```

### Component Breakdown

| Component | Function |
|-----------|----------|
| **ESP32** | Hardware controller + relay driver |
| **Tasmota** | Firmware enabling GPIO control + MQTT |
| **MQTT Broker** | Messaging between Home Assistant & ESP32 |
| **Home Assistant** | Unified dashboard + automation engine |
| **Alexa / Google Home** | Voice control interface |

---

## ⚙️ Algorithm & Working

### 🌡️ Automatic Mode (Temperature-Based Fan Control)

1. **LM35 sensor** measures room temperature
2. **ESP32** (through Tasmota rules) adjusts fan speed using 4 relays:

| Temperature | Fan Speed |
|-------------|-----------|
| > 26°C | Maximum (Relay 1) |
| 24–26°C | Medium (Relay 2) |
| 22–24°C | Low (Relay 3) |
| 18–22°C | Minimum (Relay 4) |
| < 18°C | Off |

### 🎮 Manual Mode

Users can toggle devices through:
- **Home Assistant Dashboard**
- **Alexa App**
- **Google Home App**

**Flow:** User Command → MQTT → ESP32 → Relay → Device

---

## 🔧 Hardware Implementation

### Circuit Diagrams & Prototypes

#### 📌 LM35 Sensor Test (Proteus Simulation)
![LM35 Test](path/to/lm35-test.png)

#### 📌 Breadboard Testing With ESP32
![ESP32 Breadboard](path/to/breadboard-test.png)

#### 📌 Fan Speed Control Relay Logic
![Fan Relay Logic](path/to/fan-relay-logic.png)

#### 📌 Light Control Relay Logic
![Light Relay Logic](path/to/light-relay-logic.png)

#### 📌 Proteus Simulation – Relay System
![Proteus Simulation](path/to/proteus-simulation.png)

#### 📌 Final Hardware Prototype
![Final Prototype](path/to/final-prototype.png)

---

## 💻 Software Setup

### Tasmota Configuration

#### 1️⃣ Configure GPIOs
![Tasmota GPIO Config](path/to/tasmota-gpio.png)

#### 2️⃣ Tasmota Home Page
![Tasmota Home](path/to/tasmota-home.png)

#### 3️⃣ MQTT in Tasmota
![Tasmota MQTT](path/to/tasmota-mqtt.png)

#### 4️⃣ Tasmota Template Setup
![Tasmota Template](path/to/tasmota-template.png)

---

### MQTT Broker Setup

Using **broker.emqx.io** (public MQTT broker):

```yaml
Host: broker.emqx.io
Port: 1883
Username: DVES_USER
Password: ****
```

> **Note:** For production use, consider setting up a private MQTT broker using Mosquitto.

---

### Home Assistant Integration

#### Discovered Devices
![HA Devices](path/to/ha-devices.png)

#### Exposing Devices to Voice Assistants
![HA Expose](path/to/ha-expose.png)

#### Entity Configuration
![HA Entities](path/to/ha-entities.png)

---

### Voice Assistant Integration

#### 🗣️ Google Home
![Google Home Integration](path/to/google-home.png)

#### 🗣️ Alexa Integration
![Alexa Integration](path/to/alexa-integration.png)

---

## 📝 Automatic Mode Code

```cpp
#define vRef 3.30
#define ADC_Resolution 4095
#define LM35_Per_Degree_Volt 0.01
#define Zero_Deg_ADC_Value -89.00

int fan1 = 3, fan2 = 4, fan3 = 5, fan4 = 6;
const int lm35_pin = A0;

float _temperature, temp_val, ADC_Per_Degree_Val;
int temp_adc_val;

void setup() {
  Serial.begin(9600);
  ADC_Per_Degree_Val = (ADC_Resolution / vRef) * LM35_Per_Degree_Volt;
  
  pinMode(fan1, OUTPUT);
  pinMode(fan2, OUTPUT);
  pinMode(fan3, OUTPUT);
  pinMode(fan4, OUTPUT);
}

void loop() { 
  // Average 10 readings for stability
  temp_adc_val = 0;
  for (int i = 0; i < 10; i++) {
    temp_adc_val += analogRead(lm35_pin);
    delay(10);
  }
  temp_adc_val = temp_adc_val / 10.0;

  // Convert ADC value to temperature
  temp_adc_val = temp_adc_val - Zero_Deg_ADC_Value;
  temp_adc_val = (temp_adc_val / ADC_Per_Degree_Val);

  Serial.print(temp_adc_val);
  Serial.print("°C\n");

  delay(100);

  // Temperature-based fan control
  if (temp_adc_val > 26) {
    digitalWrite(fan1, HIGH); 
    digitalWrite(fan2, LOW); 
    digitalWrite(fan3, LOW); 
    digitalWrite(fan4, LOW);
  }
  else if (temp_adc_val > 24) {
    digitalWrite(fan2, HIGH); 
    digitalWrite(fan1, LOW); 
    digitalWrite(fan3, LOW); 
    digitalWrite(fan4, LOW);
  }
  else if (temp_adc_val > 22) {
    digitalWrite(fan3, HIGH); 
    digitalWrite(fan1, LOW); 
    digitalWrite(fan2, LOW); 
    digitalWrite(fan4, LOW);
  }
  else if (temp_adc_val > 18) {
    digitalWrite(fan4, HIGH); 
    digitalWrite(fan1, LOW); 
    digitalWrite(fan2, LOW); 
    digitalWrite(fan3, LOW);
  }
  else {
    digitalWrite(fan1, LOW); 
    digitalWrite(fan2, LOW); 
    digitalWrite(fan3, LOW); 
    digitalWrite(fan4, LOW);
  }
}
```

---

## 📊 Results & Inferences

### ✅ Achievements

- Successfully controlled **4 fan speeds + 2 lights**
- Automatic fan regulation improved comfort and reduced power usage
- All devices functioned seamlessly via:
  - Tasmota Web UI
  - Home Assistant Dashboard
  - Alexa App
  - Google Assistant
- MQTT communication confirmed **stable & low-latency**
- System is **modular**, allowing easy addition of more relays and sensors

---

## 🚀 Applications

✔️ **Smart homes** (lights, fans, appliances)  
✔️ **Elderly-friendly automation**  
✔️ **Energy-saving fan control**  
✔️ **Remote monitoring & control**  
✔️ **IoT-based home security expansion**  

---

## 🎓 Conclusion & Future Scope

### Challenges Faced

- Initial reliance on Tasmota alone required expensive smart speakers
- Home Assistant provided a **cost-free solution** for voice assistant integration

### 🔮 Future Enhancements

- [ ] Add motion sensors for presence detection
- [ ] Integrate light sensors for automatic lighting
- [ ] Implement smart energy metering
- [ ] ML-based activity prediction
- [ ] Design PCB for production-ready version
- [ ] Add overheat & fault detection mechanisms

---


## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

---


## ⭐ Show your support

Give a ⭐️ if this project helped you!

---

<p align="center">Made with ❤️ for Smart Homes</p>
