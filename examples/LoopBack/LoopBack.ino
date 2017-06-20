#include <PulseEvent.h>
//#include "EventObjects.h"
// Simple loopback test: create 1 output to transmit
// test pulses, and 1 input to receive the pulses
PulseEventOutput myOut;
PulseEventInput myIn;

int count=0;
void EventFunction(EventBaseObject ThisFunctionsInfo){

  int i, num;
	Serial.print("EventFunction: ");
  // Every time new data arrives, simply print it
  // to the Arduino Serial Monitor.
  num = myIn.available();
  if (num > 0) {
    count = count + 1;
    Serial.print("EventFunction: ");
    Serial.print(count);
    Serial.print(" :  ");
    for (i=1; i <= num; i++) {
      float val = myIn.read(i);
      Serial.print(val);
      Serial.print("  ");
    }
    Serial.println();
  }else{
  Serial.println("num==0");
  }


}

void setup() {while(!Serial){};delay(200);Serial.println("setting off A");
  myOut.begin(9);  // connect pins 9 and 10 together...
  myIn.begin(10,EventFunction);
  myOut.write(1, 600.03);
  myOut.write(2, 1500);
  myOut.write(3, 759.24);
  // slots 4 and 5 will default to 1500 us
  myOut.write(6, 1234.56);
  
  Serial.println("setting off B");
}



void loop() {
//Serial.println("going");
}
