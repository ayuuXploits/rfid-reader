#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5   // SDA pin
#define RST_PIN 21 // RST pin
#define RELAY_PIN 13 // GPIO pin to control the relay

MFRC522 rfid(SS_PIN, RST_PIN); // Create MFRC522 instance
MFRC522::MIFARE_Key key;

// Store the authorized UID of your keychain here (e.g., "bd31152b")
// You'll get this value from the Serial Monitor in the "Get UID" step below.
String masterCardUID = "52930c5c"; 

bool lightState = false; // Initial state of the light

void setup() {
  Serial.begin(115200);
  SPI.begin();       // Init SPI bus
  rfid.PCD_Init();   // Init RC522 module

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, lightState); // Initialize light state (LOW for OFF)

  Serial.println("Scan a PICC (card/keychain) to toggle the light.");
}

void loop() {
  // Look for new cards
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    
    // Get the UID of the card
    String cardUID = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      if (rfid.uid.uidByte[i] < 0x10) {
        cardUID += "0";
      }
      cardUID += String(rfid.uid.uidByte[i], HEX);
    }
    
    Serial.print("Scanned UID: ");
    Serial.println(cardUID);

    // Check if the scanned card is the master card
    if (cardUID == masterCardUID) {
      lightState = !lightState; // Toggle the state
      digitalWrite(RELAY_PIN, lightState); // Update relay output
      Serial.print("Light state toggled to: ");
      Serial.println(lightState ? "ON" : "OFF");
    } else {
      Serial.println("Unauthorized card!");
    }

    // Halt PICC
    rfid.PICC_HaltA();
    // Stop encryption on PCD
    rfid.PCD_StopCrypto1();
  }
}
