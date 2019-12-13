//intrupt pin esp32 is taken as 27
const int motionSensor = 36;
unsigned long lastTrigger=0;
int dimming=128;
void IRAM_ATTR detects_zc(){
 int dimtime = (75*dimming);    // For 60Hz =>65   
  delayMicroseconds(dimtime);    // Off cycle
  digitalWrite(12, HIGH);  
    digitalWrite(2, HIGH);// triac firing
  delayMicroseconds(10);         // triac On propagation delay (for 60Hz use 8.33)
  digitalWrite(12, LOW);  
   digitalWrite(2, LOW); // triac Off
  
}
void setup(){
  Serial.begin(115200);
  pinMode(12,OUTPUT);
   pinMode(2,OUTPUT);
  pinMode(motionSensor,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(motionSensor),detects_zc,RISING);
}

void loop(){
    for (int i=5; i <= 128; i++){
    dimming=i;
    delay(2000);
   }
}
