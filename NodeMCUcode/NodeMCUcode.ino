#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
 
SoftwareSerial s(D6,D5);  //(Rx,Tx)


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "4ztfftDtp3UqqMNpZ7UbfLhyLqt2JhSu";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Ayush";
char pass[] = "ayush123";

void setup()
{
  // Debug console
  s.begin(9600);

  
  Serial.begin(9600);
  

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();

  int data0=digitalRead(D0);  //reading the input for LED-1
  int data1=digitalRead(D1);  //reading the input for LED-2
  int data2=digitalRead(D2);  //reading the input for LED-3

  int data=data0*100+data1*10+data2;   //converting all three states in one integer to send it to arduino board
  
  if(s.available()>0){
    s.write(data);   //sending the data to arduino board
  }

}
