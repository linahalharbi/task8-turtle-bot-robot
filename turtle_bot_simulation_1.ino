// encoder connected to count turns 
int turnCount = 0;
int setPoint = 20;
int rotationencoder =2;
int val = 0;     // store reading value 



int right4 = 4;       //Right motion of  motor
int left5 = 5;       //left motion of  motor
int back6 = 6;      //back motion of motor
int fwd7 = 7;      //ForWarD motion of  motor

int trig = 9;      // trig pin of ultrasonic 
int echo = 10;     // Echo pin of ultrasonic




long duration, distance;

void setup() {
  
  delay(random(600,1000));   // delay for random time
  Serial.begin(9600);
  pinMode(right4, OUTPUT);      // set Motor pins as output
  pinMode(left5, OUTPUT);
  pinMode(back6, OUTPUT);
  pinMode(fwd7, OUTPUT);
  
  pinMode(trig, OUTPUT);         // set trig pin as output
  pinMode(echo, INPUT);          //set echo pin as input 
pinMode(rotationencoder, INPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);   
  digitalWrite(trig, HIGH);     
  delayMicroseconds(10);
  duration = pulseIn(echo, HIGH); 
  distance = duration / 58.2;   // convert to distance
  delay(10);
   
  if (distance > 20)   //set distance to 20         
  {
    digitalWrite(fwd7, HIGH);                    // move forward
    digitalWrite(back6, LOW);
    digitalWrite(left5, HIGH);                                
    digitalWrite(right4, LOW);                                                       
  }

  if (distance < 20)
  {
    digitalWrite(fwd7, LOW);  //Stop                
    digitalWrite(back6, LOW);
    digitalWrite(left5, LOW);                                
    digitalWrite(right4, LOW);
    delay(500);
    digitalWrite(fwd7, LOW);      //movebackword         
    digitalWrite(back6, HIGH);
    digitalWrite(left5, HIGH);       // TURN LEFT                          
    digitalWrite(right4, HIGH);     // turn right 
    delay(500);
    digitalWrite(fwd7, LOW);  //Stop                
    digitalWrite(back6, LOW);
    digitalWrite(left5, LOW);                                
    digitalWrite(right4, LOW);  
    delay(100);  
    digitalWrite(fwd7, HIGH);       
    digitalWrite(back6, LOW);   
    digitalWrite(left5, LOW);                                 
    digitalWrite(right4, LOW);  
    delay(500);
  }
 val = digitalRead(rotationencoder);   // read the input pin
 
  if(val == HIGH) // encoder is connected to 5 v means in moving state 
    {
      turnCount = turnCount + 1;
      Serial.println(turnCount);
    }
    if(val == LOW) // encoder is 0v means in stop state 
    {
      //turnCount = turnCount + 1;
      Serial.println("Low");
    }
delay(1000);
}
