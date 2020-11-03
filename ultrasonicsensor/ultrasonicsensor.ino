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
  r1 = 3.4 * durationSensor1 / 2;   
  distance1 = r1 / 100.00;
  
  if(distance1>50){
    distance1=50;
  }
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  durationSensor2 = pulseIn(echoPin2, HIGH, 5000);
  r2 = 3.4 * durationSensor2 / 2;     
  distance2 = r2 / 100.00;

  if(distance2>50){
    distance2=50;
  }

  delay(2000);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); 
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  delay (1000);
    
}

void loop()
{
  cal_distance();
  if ((distance1<50 && distance2<50) && (distance1>40 && distance2>40)){
    Serial.println("Play/Pause"); 
    delay (500);
  }
  if(distance1>=13 && distance1>=17){
     delay(100); 
    cal_distance();
    if (distance1>=13 && distance1<=17)
    {
      Serial.println("Left Locked");
      while(distance1<=40)
      {
        cal_distance();
        if (distance1<10) 
        { 
          Serial.println ("Vup"); 
          delay (300);
          
        }
        
        if (distance1>20) 
        {
          Serial.println ("Vdown"); 
          delay (300);
        }
        
      }
      
    }
      
  }
  if (distance2>=13 && distance2<=17)
  {
      delay(100); 
      cal_distance();
      if (distance2>=13 && distance2<=17)
      {
        Serial.println("Right Locked");
        while(distance2<=40)
        {
          cal_distance();
          if (distance2<10) 
          {
            Serial.println ("Rewind"); 
            delay (300);
          }
          if (distance2>20) 
          {
            Serial.println ("Forward"); 
            delay (300);
          }
      }
      
    }
  }
  
  
}
