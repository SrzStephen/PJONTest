#include <PJON.h>
#define PJON_PIN D1
#define MASTER_BUS_ID 45
#define SLAVE_BUS_ID 44
#define BAUD_RATE 9600
#define SWBB_MODE 1
#define SWBB_RESPONSE_TIMEOUT 1500
// <Strategy name> bus(selected device id)
 
PJON<SoftwareBitBang> bus(MASTER_BUS_ID);
 
void setup() {
  bus.strategy.set_pin(PJON_PIN);
  bus.begin();
  Serial.begin(BAUD_RATE);
};
 
bool sendStringToBus(char* stringToSend){
//return true if slave acks it.
return (bus.send_packet(SLAVE_BUS_ID,stringToSend,strlen(stringToSend)) == PJON_ACK);
}
 
void loop() {
if(sendStringToBus("TESTING IN PROGRESS")){Serial.println("Message1Sent");}
delay(500);
if(sendStringToBus("HERE IS ANOTHER TEST.")){Serial.println("Message2Sent");}
delay(500);
if(sendStringToBus("THIS IS THE FINAL TEST!")){Serial.println("Message3Sent");}
delay(5000);
 
};
