#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

SoftwareSerial s(8,9);   //(Rx,Tx)


 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   // initialize the library by associating any needed LCD interface pin with the arduino pin number it is connected to
 int data;    


void setup() {
  // put your setup code here, to run once:
  s.begin(9600);
  analogWrite(6,90);          //to control the contrast of LCD screen
  lcd.begin(16, 2);           //to begin the display on LCD
  // Print a message to the LCD.
  lcd.print("IOT PROJECT");   //to print the Heading on LCD Screen

  
  Serial.begin(9600);

  pinMode(7,OUTPUT);         //LED-1 at digital pin 7 of Arduino uno board
  digitalWrite(7,LOW);
  pinMode(10,OUTPUT);        //LED-2 at digital pin 10 of Arduino uno board
  digitalWrite(10,LOW);
  pinMode(13,OUTPUT);        //LED-3 at digital pin 13 of Arduino uno board
  digitalWrite(13,LOW);      
}

void loop() {
  // put your main code here, to run repeatedly:
  s.write(100);
  

  if(s.available()>0){
    data=s.read();           //to read the data sent from node mcu

    int data2=data%10;       //to extract the states of three LED from
    data=data/10;            //the recived data
    int data1=data%10;
    data=data/10;
    int data0=data;

    Serial.print("LED-1");     
    Serial.print('\t');
    Serial.print("LED-2");
    Serial.print('\t');
    Serial.println("LED-3");

    
    Serial.print(data0);     //to print the states of all three LED in serial monitor 
    Serial.print('\t');
    Serial.print(data1);
    Serial.print('\t');
    Serial.println(data2);

    //in the following code State of the LED is assigned according to the recieved data
    //and their State is displayed on the LCD screen accordingly 

    if(data0>=1&&data1>=1&&data2>=1){
      digitalWrite(7,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(13,HIGH);
      
      lcd.setCursor(0, 1);
      lcd.print("ALL ON");
    }
    else{
      if(data0>=1){
      digitalWrite(7,HIGH);
      lcd.setCursor(0, 1);
      lcd.print("LED1-ON");
    }
    if(data0==0){
      digitalWrite(7,LOW);
    }
    if(data1>=1){
      digitalWrite(10,HIGH);
      lcd.setCursor(0, 1);
      lcd.print("LED2-ON");
    }
    if(data1==0){
      digitalWrite(10,LOW);

    }
    if(data2>=1){
      digitalWrite(13,HIGH);
      lcd.setCursor(0, 1);
      lcd.print("LED3-ON");
    }
    if(data2==0){
      digitalWrite(13,LOW);
    }
    if(data0==0&&data1==0&&data2==0){
      lcd.setCursor(0, 1);
      lcd.print("ALL OFF");
    } 
    }
  }
  
}
