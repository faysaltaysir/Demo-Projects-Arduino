/*
 * This program is property of SME Dehradun. for any query related to this program, 
 * contact us at www.smedehradn.com
 * if your want any soluiton related for any IoT Customized Boards and Sensor, 
 * then contact to www.nuttyengineer.com 
 */
// Fill-in information from your Blynk Template here

#define BLYNK_TEMPLATE_ID "TMPLpQs99aVp"
#define BLYNK_DEVICE_NAME "servo"

#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#include "BlynkEdgent.h"
#include <ESP32Servo.h>

Servo myservo;

int servoPin = 4;
BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); 
  myservo.write(s0);
  delay(5000);
  Serial.println(s0);
  Blynk.virtualWrite(V1, s0);
}

void setup()
{
 /* ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);*/    // standard 50 hz servo
  myservo.attach(servoPin);
  Serial.begin(9600);
  //myservo.attach(18);
  BlynkEdgent.begin();
  delay(2000); 
}

void loop() 
{
  BlynkEdgent.run();
}
