#define trigPin 12
#define echoPin 13
#include <Servo.h>
Servo myservo;

float duration, distance;

void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);

duration = pulseIn(echoPin,HIGH);

distance = (duration/2) * .0343;

Serial.println(distance);
//delay(500);
myservo.write(180);
//delay(5000);
if(distance < 30){
  
  myservo.write(80);
  delay(3000);
}
}
