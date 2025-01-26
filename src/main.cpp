#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5
#define RST_PIN 22

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("RFID scanner ready.");
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) {
    Serial.println("Card detected!");
  } else {
    Serial.println("No card...");
  }
  
}
