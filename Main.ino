//Var_Declare
uint8_t LDR = A2,uint8_t pinled = 6,uint8_t sensorpir = 4;
uint32_t data;
bool PIR = 0;

void setup() {
  
  pinMode(pinled, INPUT);
  pinMode(sensorpir, INPUT);
  pinMode(pinled, OUTPUT);
  digitalWrite(pinled,LOW);
  Serial.begin(9600);

}

void loop(){

  //SENSOR_READING---------------------
  PIR= (bool) digitalRead(sensorpir);
  data=analogRead(LDR);
  //-----------------------------------

  Serial.println(PIR);  
  Serial.println(data);
  //LOGIC_SECTION-----------
  if(PIR==1 && data<=500){
    digitalWrite(pinled,HIGH);    
  }else digitalWrite(pinled,LOW);

 
}

