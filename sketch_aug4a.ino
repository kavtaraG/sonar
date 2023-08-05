const int trig = 9;
const int echo = 10;

long duration;
double distance;

int green_led = 3;
int red_led = 2;


void setup() {
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
 pinMode(green_led, OUTPUT);
 pinMode(red_led, OUTPUT);
 Serial.begin(9600);
};

void red_digital(){
  digitalWrite(red_led, 1);
  delay(50);
  digitalWrite(red_led, 0);
  delay(50);
};

void green_analog(){
  analogWrite(green_led,1);
  delay(30);
  analogWrite(green_led,0);
  delay(30);
};

void sonar(){
  digitalWrite(trig, 0);
  delay(10);

  digitalWrite(trig, 1);
  delay(10);
  digitalWrite(trig, 0);

  duration = pulseIn(echo, 1);
  distance = ((duration/2)/29.7);

if(distance < 100){
  green_analog();
  Serial.println("Distance: ");
  Serial.println(distance);
  Serial.println(" cm");
};

if(distance > 100){
  red_digital();
  Serial.println("Distance: ");
  Serial.println(distance/100);
  Serial.println(" m");
}

};

void loop() {
  sonar();
};
