//***CODE TEMPESCOPE****//////
 */***souhaila Houissa***/

#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
const int capteur_D = 5;
const int capteur_A = A0;
int val_analogique;
int ldr=2;// for LDR.
int led1=6;  //for ldr 
int led2=7; //for ldr
int value=0;
int mistmaker=8;
//DHT11 dht11 ;  
int moteur=9;

void setup()
{
    pinMode(capteur_D, INPUT);
    pinMode(capteur_A, INPUT);
    Serial.begin(9600);
    pinMode(9,OUTPUT);
    //DHT11************************
    Serial.begin(9600);
    Serial.println("ready.");
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(10,OUTPUT); //run
    pinMode(11,OUTPUT); //run
    dht.begin();
}

void loop()
{
  LDR () ;
  humiditee();
  captPluie ();
  
}
 
  void captPluie () {
    if(digitalRead(capteur_D) == LOW) 
    {
        Serial.println("Digital value : wet"); 
    } else {
        Serial.println("Digital value : dry");    
    }
    val_analogique = analogRead(capteur_A); 
    Serial.print("Analog value : ");
    Serial.println(val_analogique); 
    Serial.println("");
    delay(1000);
      if (val_analogique < 200){
    digitalWrite(9,LOW);} 
    else{
    digitalWrite(9,HIGH); 
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);}}
  
    void LDR () {
    value=analogRead(ldr);//Reads the Value of LDR(light).
    Serial.println("LDR value is :");//Prints the value of LDR to Serial Monitor.
    Serial.println(value);
    if(value>200)
    {
    digitalWrite(6,HIGH);//Makes the LED glow in Dark.
    digitalWrite(7,HIGH);
    }
    else
    {
    digitalWrite(6,LOW);//Turns the LED OFF in Light.
     digitalWrite(7,LOW);
    }} 
    void humiditee() {
     float h = dht.readHumidity();
     Serial.println(h);
     if (h > 30){
     h = dht.readHumidity();
     digitalWrite(8,HIGH);}
     else { 
      digitalWrite(8,LOW);}
     delay(1000);
  }
