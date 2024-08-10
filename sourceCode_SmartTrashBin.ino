// library sensor dan alat
#include <NewPing.h>
#include <Wire.h>         
#include <Servo.h> 
#include <LiquidCrystal_I2C.h>
//define variable sensor
const int trigPin = A0;
const int echoPin = A1;
const int max_distance = 200;


//library dfplayer suara
#include <DFPlayer_Mini_Mp3.h>        
#include <SoftwareSerial.h>

//define motor servo
Servo servoAne;
NewPing jarakCm(trigPin, echoPin, max_distance );
//inisialisasi pin dfplayer
SoftwareSerial mySerial(4, 5);


void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  //kode servo
  Serial.begin(9600);
  servoAne.attach(6);            //inisialisasi pin servo
  servoAne.write(0);
  mySerial.begin(9600);
  //set pin sensor, dfplayer & servo
  mp3_set_serial (mySerial);
  mp3_set_volume (100);           //pengaturan volume (0-30)
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(mySerial, OUTPUT);
  pinMode(mySerial, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Rumus
  delay(50);
  int x = jarakCm.ping_cm() ;
  Serial.print("sampah : ");
  Serial.print(x);
  Serial.println("cm ");
  delay(3500);

  if(x <= 20){
    servoAne.write(180);            //posisikan servo di 180 derajat
    mp3_play(1);
    delay (4000);
    mp3_stop();
  }
  else{
    servoAne.write(0);
  }
}



