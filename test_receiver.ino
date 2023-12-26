#include <ESP8266SSDP.h>
#include <SimpleTimer.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#define CAYENNE_PRINT Serial     
#include <CayenneMQTTESP8266.h>

char username[] = "95504a80-977f-11eb-a2e4-b32ea624e442";
char password[] = "52b603e8f731142a2ba9c75e66bb975c82c7cc9d";
char clientID[] = "72759300-c2b1-11eb-883c-638d8ce4c23d";

char auth[] = "lSMMaDOph3_onwZ0lLjIyj8bbDkC0D0R";
char ssid[] = "Telecom-HFVF"; //Telecom-bKL7
char pass[] = "4qak6qsH";//7g4QYAJ3

SimpleTimer timer;


String myString; 
String garbage;
char data;
int q1, r1, s1, t1, u1, v1, w1;

void setup(){
Serial.begin(115200); 
Serial.print("AT\r\n");
Blynk.begin(auth,ssid,pass);
Cayenne.begin(username, password, clientID, ssid, pass);

}

void loop() {
  Receiveddata();
  Blynk.run();
  Cayenne.loop();
  timer.run();
  }

void Receiveddata(){
  if ( Serial.available() > 0 )
{
  garbage = Serial.readString(); // consists of the +ERR=2 ERROR. 
  myString = Serial.readString(); 
  Serial.println(myString);   

String l = getValue(myString, ',', 0); // address
String m = getValue(myString, ',', 1); // data length
String n = getValue(myString, ',', 2); // data
String o = getValue(myString, ',', 3); //RSSI
String p = getValue(myString, ',', 4); //SNR

String q = getValue(n, '%', 0); // sensor1
Serial.print("Soil Moisture:");
Serial.println(q);
int q1=q.toInt();
Blynk.virtualWrite(V50, q1);
Cayenne.virtualWrite(V51, q1);

 myString = ""; 
}}


String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";

    //5 datas
}
