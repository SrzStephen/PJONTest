#define SWBB_MODE 1
#define SWBB_RESPONSE_TIMEOUT 1500
#include <PJON.h>
#define SLAVE_BUS_ID 44
#define PJON_PIN D1
#define BAUD_RATE 9600
 
PJON<SoftwareBitBang> bus(SLAVE_BUS_ID);
 
void SlaveCallback(uint8_t *payload, uint16_t length, const PJON_Packet_Info &packet_info) {
    for (int ii=0; ii<(sizeof(payload)/sizeof(payload[0]));ii++){
    Serial.print(payload[ii]);
    }
    Serial.println();
}
 
 
void setup() {
  bus.strategy.set_pin(PJON_PIN);
  bus.begin();
  bus.set_receiver(SlaveCallback);
  Serial.begin(BAUD_RATE);
};
 
 
 
void loop() {
bus.receive(1000);
};
