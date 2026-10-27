#include "WiFi.h"
#include "ThingSpeak.h"

const char* WIFI_Name = "Wokwi-GUEST";
const char* WIFI_Pass = "";

const int channelNumber = 3554248;
const char* apiKey = "4ST2MZRGI5WK6QWV";

WiFiClient clientObject;

void setup(){

  pinMode(26, INPUT_PULLUP);

  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_Name,WIFI_Pass);

  while(WiFi.status()!= WL_CONNECTED){
    Serial.println("Status: Not Connected");
    delay(1000);
  }
  Serial.println("Status: Connected");
  ThingSpeak.begin(clientObject);
}
void loop(){

 int status=digitalRead(26);
 Serial.println( status);

 ThingSpeak.setField(1,status);
 int stat=ThingSpeak.writeFields(channelNumber,apiKey);

 if(stat==200){
  Serial.println("Data sent to ThingSpeak");
 }
}