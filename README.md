# Gesture-Based Music Controller

### Overview
**Gesture-Based Music Controller** is a touchless media interface built on the **ESP32** platform. It allows users to control music playback and system volume through intuitive hand gestures. By emulating a **Bluetooth HID (Human Interface Device)**, the controller works natively with any modern OS.

### Key Features
* **Gesture Recognition:** Supports Swipe (Left/Right) and Volume adjustment via Rotation.
* **Universal Compatibility:** Acts as a standard "Magic Keyboard" for Spotify, YouTube, and more.
* **Planned Hybrid Interface:** Future updates will include physical buttons for precise manual control.

### Technical Stack
* **Core:** ESP32 (Dual-core processor).
* **Sensor:** PAJ7620 Gesture Sensor (**I2C Interface**).
* **Protocol:** Bluetooth Low Energy (BLE) via the **NimBLE** stack.



### How It Works
1. **Sensing:** The PAJ7620 sensor detects infrared reflections from the user's hand.
2. **Processing:** The ESP32 polls the sensor via **I2C** and interprets the movement data.
3. **Command Mapping:** Specific gestures are mapped to HID Media Keys (e.g., `KEY_MEDIA_NEXT_TRACK`).
4. **Execution:** The command is sent wirelessly to the paired device, which executes the media action instantly.

### Known Issues & Future Work
* **Accuracy:** The current PAJ7620 sensor can be inconsistent. I am evaluating **ToF (Time-of-Flight)** sensors as a potential upgrade for better precision.
* **Buttons:** Physical tactile buttons are currently in the design phase and will be added in the next hardware revision.

### Installation
1. Connect PAJ7620: **SDA to GPIO 21, SCL to GPIO 22**.
2. Upload `TestareConectareBluetooth.ino` using Arduino IDE.
3. Pair your device with **"Magic Keyboard"**.
