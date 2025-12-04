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
<img width="606" height="312" alt="image" src="https://github.com/user-attachments/assets/80ee249a-9433-4490-a240-70becb0221fa" />

#### 📌 Breadboard Testing With ESP32
<img width="236" height="421" alt="image" src="https://github.com/user-attachments/assets/4d040f7c-c76a-4dcb-8275-511b9ba5b4f7" />

#### 📌 Fan Speed Control Relay Logic
<img width="633" height="397" alt="image" src="https://github.com/user-attachments/assets/cac6d42a-06cb-4a22-a8be-1d03f0b99097" />

#### 📌 Light Control Relay Logic
<img width="463" height="289" alt="image" src="https://github.com/user-attachments/assets/dd0c61f8-deaf-4903-9141-4deaac76509c" />

#### 📌 Proteus Simulation – Relay System
<img width="713" height="719" alt="image" src="https://github.com/user-attachments/assets/77a3e05e-809f-422f-b08f-e35e93190f58" />


#### 📌 Final Hardware Prototype
<img width="372" height="660" alt="image" src="https://github.com/user-attachments/assets/739894c2-915a-4286-8ef7-e37b91207206" />

---

## 💻 Software Setup

### Tasmota Configuration

#### 1️⃣ Configure GPIOs
<img width="362" height="596" alt="image" src="https://github.com/user-attachments/assets/00f63b8c-26a2-4a87-a65b-d2aa1e2197fc" />

#### 2️⃣ Tasmota Home Page
<img width="758" height="410" alt="image" src="https://github.com/user-attachments/assets/4c3cbce0-b738-43c5-9a00-b5ef7eda57da" />

#### 3️⃣ MQTT in Tasmota
<img width="425" height="502" alt="image" src="https://github.com/user-attachments/assets/eb717d99-11c7-4be8-90bf-e4eea1009f73" />

#### 4️⃣ Tasmota Template Setup
<img width="425" height="502" alt="image" src="https://github.com/user-attachments/assets/cb0e22fd-94b7-4dd0-b435-e730159b8581" />

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
<img width="975" height="520" alt="image" src="https://github.com/user-attachments/assets/ccde5b2b-8def-42d2-bab4-5c3c2072171d" />

#### Discovered Devices
<img width="975" height="506" alt="image" src="https://github.com/user-attachments/assets/11220eb0-9f94-4cc2-84d6-32eee75a6efb" />

#### Exposing Devices to Voice Assistants
<img width="708" height="394" alt="image" src="https://github.com/user-attachments/assets/1e78a0f0-dd5d-489b-bde9-9d1bd69695a4" />

#### Entity Configuration
<img width="653" height="351" alt="image" src="https://github.com/user-attachments/assets/44443201-1a45-4d80-b7e3-07b0a44086bb" />
<img width="534" height="408" alt="image" src="https://github.com/user-attachments/assets/2a2a1040-cc8c-4ed2-977e-5792ae65ecc2" />

---

### Voice Assistant Integration

#### 🗣️ Google Home
<img width="481" height="1014" alt="image" src="https://github.com/user-attachments/assets/f1ac8b6f-8507-4330-bd7e-899dacb0c187" />



#### 🗣️ Alexa Integration
<img width="458" height="980" alt="image" src="https://github.com/user-attachments/assets/51948329-bd0d-4afb-a0f8-e6e6e2801265" />     

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
