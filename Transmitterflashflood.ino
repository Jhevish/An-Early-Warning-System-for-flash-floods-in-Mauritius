
//////////////////////////////////////////include_libraries/////////////////////////////////
#include <DHT.h>
#include <DHT_U.h>
#include <RTClib.h>
#include <Wire.h>
#include <SoftwareSerial.h>


/////////////////////////////////////////define_pins////////////////////////////////////////

//#define Rainpin 3   //raingauge
//bool bucketPositionA = false; 
//const double bucketAmount = 0.2794; //1 tip= 0.2794 mm
//double hourlyRain = 0.0; 

#define DHTPIN 4    //temerature and humidity
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
float hum=0;
float temp=0;

long pMillis=0;

volatile int flow_frequency;    //flowmeter
double L_per_hr; 
int flowsensor = 2; 
unsigned long currentTime;
unsigned long cloopTime;
double times;
int soilmoisture= A3;  //soilmoisture
double soilmoisturevalue;
double soilmoisturepercentage;

int trigPin=11;   //ultrasonicsensor
int echoPin=10;
long duration;
double distanceCm=0;

int data_length;  //sending with AT commands
String sensorsdata;

int rain_anal=A1;
int rain_digital=7;
int rain_value;
int rain_percentage;
int rain_digit;
int rain_inverse;
///////////////////////////////////////interrupt_function_for_flowmeter////////////////////////

void flow () 
{ 
  flow_frequency++; 
}

//////////////////////////////////////void_setup_function//////////////////////////////////////

void setup(){
  
  //pinMode(Rainpin, INPUT);   //raingauge
   pinMode (trigPin, OUTPUT);  //ultrasonic sensor
   pinMode (echoPin, INPUT);

   pinMode(rain_anal, INPUT);
   pinMode(rain_digital, INPUT);
  pinMode(flowsensor, INPUT);  //flowmeter
  digitalWrite(flowsensor, HIGH); 
  Serial.begin(115200); 
  attachInterrupt(0, flow, RISING); 
  sei(); 
  currentTime = millis();
  cloopTime = currentTime;    
  dht.begin();  //temperature and humidity 
 }

//////////////////////////////////////void_loop_function///////////////////////////////////////

void loop() {
  
  MultipleSensors();
  send_data(sensorsdata , data_length); 
  delay(2000); 
  sensorsdata = ""; 
}

/////////////////////////////multiple_sensors to read sensor values//////////////////////////



void MultipleSensors()
{

//rainsensor////
rain_value=analogRead(rain_anal);
rain_percentage=map(rain_value,0,1023,99,1);
rain_inverse=digitalRead(rain_digital);
if (rain_inverse==1)
{rain_digit=0;}
else if(rain_inverse==0)
{rain_digit=1;}

 //temperature and humidity////////
 hum = dht.readHumidity();
 temp= dht.readTemperature();

 //flowmeter////////
  currentTime = millis();
  if(currentTime >= (cloopTime + 1000))
  { cloopTime = currentTime; // Updates cloopTime
    L_per_hr = (flow_frequency * 60/ 7.5);        //Take counted pulses in the last second and multiply by 2.25mL 
    flow_frequency = 0; }// Reset Counter

 //ultrasonicsensor/////////
  digitalWrite(trigPin,LOW);  // Clears the trigPin
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin, HIGH);   //To receive the reflected signal.
  distanceCm= 117- duration*0.0340/2; 

 //soilmoisture
 soilmoisturevalue=analogRead(soilmoisture);
 soilmoisturepercentage=map(soilmoisturevalue,1023,0,0,100);


 ///send
sensorsdata=sensorsdata+ hum + "%" + temp + "%" + distanceCm + "%" + L_per_hr+ "%" + soilmoisturepercentage+ "%" +rain_percentage + "%"+ rain_digit+ "%";
data_length=sensorsdata.length();
}

////////////////sending_data_using_AT_commands////////////////////////////////////////////////////

void send_data(String sensorvalue, int valuelength)
{
  String mymessage; 
  mymessage = mymessage + "AT+SEND=0" + "," + valuelength + "," + sensorvalue + "\r"; 
  Serial.println(mymessage);  
}
