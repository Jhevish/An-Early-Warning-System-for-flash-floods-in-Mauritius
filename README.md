# Flood-Risk-Monitoring-and-Early-Warning-System
Early Warning System for flash floods

# ABSTRACT
Flash floods are one of the most destructive natural hazards around the world including Mauritius
resulting in casualties, loss of lives and properties. This project aims at designing and
implementing an Early Warning System for flash floods in Mauritius which would help to alert
the residents about the catastrophe beforehand and lessen the loss of lives and property.The main
requirements of the system are low cost, effectiveness and reliability. The project entails both
monitoring the different parameters concerning flash flood and warning locals in the event of a
flash flood. Different sensors are chosen to monitor the parameters related to flash floods such as
temperature, moisture, water level and flow rate and data is transmitted through the Reyax
Module. The parameters are then displayed on Cayenne dashboards and the Blynk application.
The data is collected using an Arduino Uno and sent to the receiver consisting of a NodeMCU.
When a flash flood event is detected a trigger is sent to the user via SMS or email to warn them
about the imminent flooding. The Gumbel distribution is used to forecast flooding based on
historical rainfall data.

# Aims
The principal motive of this project is to design and implement an Early Warning System for
flash floods in Mauritius.
1.3.2 Objectives
The objectives are as follows:
i. Monitoring and storage of sensors’ data related to flash floods.
ii. Implementation of communication technology between transmitter and receiver.
iii. Flash flood prediction and notification.
iv. Use of Meteorological data to predict flash floods
1.4 Project Scope
The main features of the Early Warning System are:
1. Transmitter: The transmitter collects the real-time sensors’ data from the river and sends
it to the receiver for processing.
2. Receiver: The receiver processes the data and monitors it on dashboards.
3. Communication Technology: A proper communication link is established between the
transmitter and receiver to allow sending and receiving of data.
4. Data monitoring: The data collected from the receiver are monitored on dashboards.
5. Alarm: An alarm is sent to the residents in case of a flash flood warning.

<img width="561" height="659" alt="image" src="https://github.com/user-attachments/assets/6522b9d1-9614-4bf7-afa3-22b727dec4b8" />

<img width="585" height="551" alt="image" src="https://github.com/user-attachments/assets/8d0c0101-b0bd-4052-9051-e2ed8e8687bd" />

<img width="583" height="455" alt="image" src="https://github.com/user-attachments/assets/2c7600fc-0070-4ee4-a0fe-1eaf04adc4c9" />

<img width="599" height="466" alt="image" src="https://github.com/user-attachments/assets/bf94266f-030e-49cb-9504-49f40028589a" />

<img width="567" height="369" alt="image" src="https://github.com/user-attachments/assets/86abe9ea-c60f-4f74-ab87-904e390d4d2f" />

<img width="570" height="273" alt="image" src="https://github.com/user-attachments/assets/06e37be3-7841-42f4-b66a-396742c30bfb" />

<img width="599" height="696" alt="image" src="https://github.com/user-attachments/assets/3166a0d2-b18a-4371-a438-7f2ae6df1a27" />

<img width="490" height="498" alt="image" src="https://github.com/user-attachments/assets/3a5be4bc-401b-4457-94cb-fabd1f824ce0" />

<img width="534" height="449" alt="image" src="https://github.com/user-attachments/assets/c94dc1ec-eea6-4d1e-a62d-e7938fe26805" />


# Architecture

The Arduino Uno (microcontroller 1) collects the data from the sensors and converts it to a string
message. The gateway receives the string message through LoRa communication technology.
The string message received at the Node MCU (microcontroller 2) is then broken down into
individual variables to store the sensors’ data. The sensors’ data are then sent to the Cayenne and
Blynk dashboard. The data are displayed on gauges and graphs. The gauges are calibrated on the
dashboard to allow the user to identify the critical level of the measured parameters from the
sensors (red for critical, green for safe, yellow for warning). When the threshold values chosen
are exceeded, a message and an email are sent to the residents.

# Circuit Design

<img width="576" height="291" alt="image" src="https://github.com/user-attachments/assets/1d7e0750-b85d-4b2c-96f6-831187a808cb" />


# Continued

For the reyax Module, the connection is as follows: VCC-3V3, GND-GND
The TX pin of the arduino is connected to the RX pin through a potential divider since the TX
pin of the arduino is at 5V and the divider is used to drop the potential to about 3.4V.

<img width="548" height="265" alt="image" src="https://github.com/user-attachments/assets/fd926bc5-d160-47be-9da7-852a94b5f659" />

## Flowchart for Transmitter and Receiver side

<img width="419" height="487" alt="image" src="https://github.com/user-attachments/assets/c5526f3d-7eda-4b53-a94c-a8d49ac8d85a" />

<img width="531" height="611" alt="image" src="https://github.com/user-attachments/assets/5e4d3d5a-0593-496c-8771-b0095d9bd93b" />

# System Design on TinkerCad

<img width="538" height="546" alt="image" src="https://github.com/user-attachments/assets/0142b17d-1dbf-437e-b5f7-c1b218930cd9" />

<img width="426" height="614" alt="image" src="https://github.com/user-attachments/assets/25370b77-0df2-4c35-89b2-40f3dba1f3d3" />

# Components Deisgn

<img width="544" height="317" alt="image" src="https://github.com/user-attachments/assets/9db5cd24-8dc4-4907-bc48-9aa04f07adcb" />

## Microcontrollers

The microcontrollers used are:
1. Arduino Uno for the transmitter side
2. NodeMCU for the receiver side

 Arduino Uno
The Arduino Uno is a micro-controller board based 8-bit ATmega328P microcontroller. It has 14
digital pins (input and output) among which 6 can be used as PWM outputs and 6 analog input
pins. Each pin operates at 5V and can provide or receive a maximum current of 40mA. The
different sensors (ultrasonic, DHT, rain sensor, flow-meter) are connected to the Arduino board
and the data can be sent through the Lora module to the node MCU.
 NodeMCU (ESP8266)
The Node MCU is an open source IoT platform consisting of an inbuilt WiFi module. It consists
of 4 MB of storage and 128 kB of memory. It can be easily programmed using the Arduino IDE.
It operates at 3.3V and has 13 GPIO (General Purpose Input Output) pins. The node MCU is a
gateway which is connected to the Blynk application and MQTT application (CAYENNE) and it
displays the sensors’ values in an appropriate format. It also serves to alert the concerned people
about any potential flash flood through messages and emails.


<img width="570" height="656" alt="image" src="https://github.com/user-attachments/assets/dbe4d748-4967-4bf4-aa4a-013eee21ca84" />

# Communication Technology

<img width="548" height="670" alt="image" src="https://github.com/user-attachments/assets/679b742a-a26f-40d7-874b-1625ab7564f6" />

# Overall System Implementation and Testing

<img width="578" height="428" alt="image" src="https://github.com/user-attachments/assets/80cdef73-a6ee-4a6d-8e5f-21e120165578" />

<img width="522" height="509" alt="image" src="https://github.com/user-attachments/assets/22e2dddf-14c1-4f1b-bb39-5e0c821304cb" />

<img width="576" height="301" alt="image" src="https://github.com/user-attachments/assets/3c8e9c2c-7674-4116-9768-2227cc75207e" />

<img width="595" height="472" alt="image" src="https://github.com/user-attachments/assets/2b43f0be-fdfc-4ab2-a9dd-3833a3ddf616" />

<img width="560" height="548" alt="image" src="https://github.com/user-attachments/assets/0195f556-4245-4812-b65c-8e04661503b6" />

<img width="587" height="635" alt="image" src="https://github.com/user-attachments/assets/2eea9e98-ec0a-43dd-9e3b-fc9768c0d74d" />

<img width="477" height="638" alt="image" src="https://github.com/user-attachments/assets/16eccb86-0c6e-4027-9030-bd939d4908ec" />

# Alarm system

Three methods are chosen for predicting flash floods.
(i) Choosing a threshold value for the water level
(ii) Choosing a threshold value for the flow rate
(iii) Choosing a threshold value for the soil moisture
When the threshold values are exceeded, an SMS is sent from cayenne.The threshold value
chosen during testing was 52 cm. When the water level exceeded this predefined value an SMS
was sent as shown below.

<img width="285" height="377" alt="image" src="https://github.com/user-attachments/assets/a99fb3d7-d553-46a8-9ff8-2b7d27868ec0" />

# RESULTS AND DISCUSSIONS

<img width="538" height="508" alt="image" src="https://github.com/user-attachments/assets/7601b9d9-962c-4cec-a4a3-205f5ae4be8f" />

On the 6th of May there was heavy rainfall at Bel-Air and flash floods at several places in
Mauritius which resulted in the water level rising as shown from the diagram. This heavy rainfall
resulted in noticeable changes in the water level, soil moisture and flow rate. However there was
no noticeable change in temperature and humidity.
The sensors used in the project are certified and accurate. For example the ultrasonic sensors data
were tested by actually measuring the level using a measuring tape and the results obtained were
almost similar.
The threshold value of the water level was already chosen. Therefore threshold values of soil
moisture and flow rate could be identified using an interpolation method.

The graph of water level against flow rate and water level against soil moisture was plotted on
matlab and the results are depicted below.


<img width="453" height="393" alt="image" src="https://github.com/user-attachments/assets/7b4030a4-8895-472f-b3d2-21dcce930f7a" />


<img width="445" height="94" alt="image" src="https://github.com/user-attachments/assets/fb73bf53-2c68-49c7-940a-0b923a754b57" />

The graph of water level against flow rate is shown below.

<img width="483" height="403" alt="image" src="https://github.com/user-attachments/assets/77e72c56-d88e-4392-8eba-522bcbebbb1c" />

<img width="432" height="139" alt="image" src="https://github.com/user-attachments/assets/bf66b33a-0d8c-476c-bc89-73b265f9c052" />

# Flood Prediction using rainfall data Available from meteo


<img width="560" height="524" alt="image" src="https://github.com/user-attachments/assets/25244d07-75ed-4df9-b29c-2f2a3ef4645c" />

The graph below shows the variation of monthly rainfall for the year 2013-2020. Series 1
corresponds to the year 2013 and series 8 to 2020.


<img width="455" height="400" alt="image" src="https://github.com/user-attachments/assets/f8e192fd-8f87-4ac5-a753-d2221c096f72" />

## Rainfall frequency Analysis using Gumbel Distribution

The total annual rainfall for the year 2013-2020 is depicted in the graph below.


<img width="431" height="252" alt="image" src="https://github.com/user-attachments/assets/63091b9c-a28e-4eca-98df-5ab81200a2e2" />


<img width="328" height="322" alt="image" src="https://github.com/user-attachments/assets/89ae2685-9178-4b42-a6b1-59a5b3a32be7" />


<img width="427" height="662" alt="image" src="https://github.com/user-attachments/assets/43171f31-a5f2-4e48-83e2-0c224bc0818e" />


<img width="557" height="606" alt="image" src="https://github.com/user-attachments/assets/30fde38f-0d53-4fc5-a483-f110968273b0" />


<img width="432" height="329" alt="image" src="https://github.com/user-attachments/assets/076dda83-a3d1-4816-a7d4-5e4a4c42d66e" />

The Gumbel distribution method can be used to predict long term floods and can be used to
create flood risk mapping. Annual Rainfall data obtained from the meteomauritius was used to
find the return period of rain occurring during a current year. Flash floods in Mauritius are
usually associated with heavy rainfall. This rainfall data can be used to predict the year in which
similar rainfall might occur. For example a certain flash flood which occurred during a certain
year x brought a high level of rainfall and the return period was found as r years. There is a high
possibility of such flood to occur in year x+r.

# Conclusion

Flash floods can be predicted using different flood parameters. During flash floods, the river
banks overflow and the water flows into the residences of many locals and damages their
property. This project successfully monitors the water level and associated parameters that vary
with flash floods such as soil moisture and flow rate on Cayenne and Blynk and sets thresholds
values for the changing parameters. Once the parameter is exceeded, Cayenne sends an email and
an SMS to the concerned people.
The reyax module allows communication of sensors’ data collected from the river to the
dashboards. The dashboards are user friendly and threshold values are set on the gauges to allow
the users to identify a potential flash flood. When the gauge value exceeds the predefined value,
the gauge reading turns red.
The results obtained for the month of May can be compared with past results. When there is an
increase in rainfall, the water level also increases. From usgs.gov, the variation of flow rate and
rainfall were reviewed. As the rainfall increased, the flowrate also increased. Therefore, an
increase in water level also results in an increase in flow rate during rainy conditions. The
variation of water level against flow rate from the results adhered to past literature and we were
able to derive a linear relationship between them. Tesař, Fiedler and Dvořák discussed the
variation of soil permeability versus soil texture. Soil whether in the sand, clay, or silt form
always absorbs water. The water absorbed causes the soil to become moist. As water level rises,
more water is absorbed on the river banks and from the results a linear relationship was derived
to show the soil moisture variation with water level.

