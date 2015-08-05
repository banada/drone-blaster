#include <IRremote.h>

#define KILLCODE 625479

int ir_pin = 11;
int power_pin = 9;

IRrecv receiver(ir_pin);
decode_results code;
void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
  pinMode(power_pin, OUTPUT);
  analogWrite(power_pin, 255);
}

void loop() {
  if (receiver.decode(&code)) {
    if (code.value == KILLCODE) {
      Serial.println("drone off");
      analogWrite(power_pin, 0);
    }
    receiver.resume();
  }
}
