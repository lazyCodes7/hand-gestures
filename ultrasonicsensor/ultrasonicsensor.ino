const int trigPin1 = 9; // the number of the trigger output pin ( sensor 1 )
const int echoPin1 = 10; // the number of the echo input pin ( sensor 1 )     
const int trigPin2 = 5;  // the number of the trigger output pin ( sensor 2 ) 
const int echoPin2 = 4;  // the number of the echo input pin ( sensor 2 ) 

////////////////////////////////// variables used for distance calculation 
long durationSensor1,durationSensor2;                               
int distance1, distance2; 
float r1,r2;
unsigned long temp=0;
int temp1=0;
int l=0;
////////////////////////////////

void cal_distance(){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  durationSensor1 = pulseIn(echoPin1, HIGH, 5000);
  r1 = 3.4 * durationSensor1 / 2;                  // calculation to get the measurement in cm using the time returned by the pulsein function.     
  distance1 = r1 / 100.00;
  
  Serial.print("Distance1: ");
  Serial.println(distance1);
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  durationSensor2 = pulseIn(echoPin2, HIGH, 5000);
  r2 = 3.4 * durationSensor2 / 2;     
  distance2 = r2 / 100.00;

  Serial.print("Distance2: ");
  Serial.println(distance2);

  delay(2000);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); // initialize the trigger and echo pins of both the sensor as input and output:
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  delay (1000);
    
}

void loop()
{
  cal_distance();
  if ((distance1<40 && distance1>30) && (distance2<40 && distance2>30)){
    Serial.println("Play/Pause"); 
    delay (500);
  }
  else if(distance1<40 && distance1>20){
    Serial.println("previous");
    delay(500);
  }
  else if(distance2<40 && distance2>20){
    Serial.println("next");
  }
  
}
