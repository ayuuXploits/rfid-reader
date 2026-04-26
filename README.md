____  _____ ___ ____     ____  _____    _    ____  _____ ____  
|  _ \|  ___|_ _|  _ \   |  _ \| ____|  / \  |  _ \| ____|  _ \ 
| |_) | |_   | || | | |  | |_) |  _|   / _ \ | | | |  _| | |_) |
|  _ <|  _|  | || |_| |  |  _ <| |___ / ___ \| |_| | |___|  _ < 
|_| \_\_|   |___|____/   |_| \_\_____/_/   \_\____/|_____|_| \_\
   +----------+          +---------+
   |  MFRC522 |  ))) ((( | ARDUINO |
   |  [======]| ~~~>>>~~~ |  UNO R3 |
   |  RFID TAG| - - - - - | [~][~]  |
   +----------+  SPI BUS  +---------+

> Scan. Identify. Act...

## 📡 About

An Arduino-based RFID reader built with the **MFRC522** module and the 
**MFRC522 Arduino library**. Tap any compatible RFID card or key fob to 
read its unique UID, authenticate it against a stored list, and trigger 
actions — like unlocking a door, logging an event, or toggling an LED.

Simple enough for beginners, extensible enough for real-world access 
control systems.

## ⚡ Features

- Read UID from MIFARE Classic / MIFARE Ultralight cards
- Authenticate cards against a whitelist stored in EEPROM
- Serial monitor output for debugging and logging
- LED + buzzer feedback on scan (access granted / denied)
- Easy to extend with relay modules, LCDs, or web logging


## 🛠️ Built With

- Arduino Uno / Nano
- MFRC522 RFID Module
- C++ (Arduino framework)
## 🚀 Getting Started

1. Clone this repo
2. Install the MFRC522 library via Arduino Library Manager
3. Wire up the module as shown above
4. Upload `rfid_reader.ino` to your Arduino
5. Open Serial Monitor at 9600 baud and scan a card!

 © 2026 ayuuXploits — All Rights Reserved
