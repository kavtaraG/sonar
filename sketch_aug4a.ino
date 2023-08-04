int trig = 9;
int echo = 10;

long duration;
double distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
};



void loop() {
  
    digitalWrite(trig, 0);
    delay(10);

    digitalWrite(trig, 1);
    delay(10);
    digitalWrite(trig,0);

    duration = pulseIn(echo,1);
    distance = ((duration/2)/29.7)/100;
    if(distance < 100){
      Serial.println("Distance ");
      Serial.println(distance);  
      Serial.println(" cm");
      if(distance > 100){
        Serial.println("dude");
      }else{
        Serial.println("Distance ");
        Serial.println(distance);  
        Serial.println(" M");
      }
    }

    
    

    


}
