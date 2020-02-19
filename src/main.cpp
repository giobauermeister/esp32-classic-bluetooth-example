#include <Arduino.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

uint8_t c;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(2, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {
    c = SerialBT.read();
    Serial.write(c);
    if(c=='1'){
      digitalWrite(2, HIGH);
    } else if (c=='0'){
      digitalWrite(2, LOW);
    }
  }
  delay(20);
}