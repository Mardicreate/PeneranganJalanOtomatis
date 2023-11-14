const int pinSensor = A2;
const int pinled = 6;
const int sensorpir = 4;
int data ;
int statuspir = 0;

//brightness = 0;

void setup() {
  pinMode(pinSensor, INPUT);
  pinMode(sensorpir, INPUT);
  pinMode(pinled, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  data = analogRead(pinSensor);
  statuspir = digitalRead (sensorpir);
  Serial.println(data);

  if (data>= 500){
    analogWrite(pinled, LOW);
//    if(statuspir == HIGH){
//      digitalWrite(pinled, HIGH);
//      Serial.println("ada gerakan");
//    }
//    else{
//      digitalWrite(pinled, LOW);
//      Serial.println("tidak ada gerakan");
//    }
    
  }

  else if (data<= 500){
    if(statuspir == HIGH){
      analogWrite(pinled, HIGH);
      Serial.println("ada gerakan");
    }
    else{
      analogWrite(pinled, LOW);
      Serial.println("tidak ada gerakan");
    }
    
//      digitalWrite(pinled, HIGH);

  }
  delay(1000);
}

