int micIn=A0;
int led=11;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(micIn,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int micVal=digitalRead(micIn);
Serial.println(micVal);
if(micVal==1){
  digitalWrite(led,HIGH);
}
else{
  digitalWrite(led,LOW);
}
  
  

}
