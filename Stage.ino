int x;

int endstop_1 = 12; 
float pos_x = 0;
int pitch = 5; //mm
float stepAngle = 1.8; //degrees per step
int ppr = 1600; //current config of pulses per rev


void setup() {
  pinMode(endstop_1, INPUT);
  pinMode(9,OUTPUT); // pul+ motor 1
  pinMode(8,OUTPUT); // dir+ motor 1
  pinMode(7, OUTPUT); // pul+ motor 2
  pinMode(6, OUTPUT); // dir+ motor 2
  Serial.begin(9600);
}



void loop() {

  digitalWrite(8,HIGH); //direction
    //digitalWrite(6,HIGH);

  for(x = 0; x < 3200; x++){
    if(digitalRead(endstop_1) == LOW){
      Serial.println("endstop pressed");
      digitalWrite(9, LOW);
      digitalWrite(7, LOW);
      delay(50);
    }
    else{
      digitalWrite(9,HIGH);
      //digitalWrite(7, HIGH);
      delayMicroseconds(500);

      digitalWrite(9,LOW);
      //digitalWrite(7,LOW);
      delayMicroseconds(500);
    }
  }
  delay(1000);
  
 
  /*
  digitalWrite(8,LOW);
  digitalWrite(6,LOW);

  for(x = 0; x < 4000; x++){

    digitalWrite(9,HIGH);
    digitalWrite(7,HIGH);

    delayMicroseconds(500);

    digitalWrite(9,LOW);
    digitalWrite(7,LOW);

    delayMicroseconds(500);
  }
  delay(1000);
  */
}