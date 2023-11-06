// Automatic Voice Assisted Wheelchair // 
const int trigPin = 4;
const int echoPin = 5;

char bt;
String voice;
void setup()
{
 Serial.begin(9600);
 Serial.println("test");
 
   
     pinMode(6,OUTPUT);
   digitalWrite(6,LOW);
    pinMode(8,OUTPUT);
   digitalWrite(8,LOW);
    pinMode(3,OUTPUT);
   digitalWrite(3,LOW);
    pinMode(2,OUTPUT);
   digitalWrite(2,LOW);
   
  
      
      delay(1000);      //Let system settle 
      analogReference(DEFAULT);
      //Wait rest of 1000ms recommended delay before
  
}

void loop()
{
 
      long duration, inches, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
;
  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
   


  Serial.print("cm =");
  Serial.print(cm);
  Serial.println(" in");
   Serial.print("  cm =");
  Serial.print(cm);
  Serial.println(" cm");
  if(cm<=20)   // ultra
  {
  
    Serial.println("stop it");
    digitalWrite(6,LOW);
        digitalWrite(8,LOW);
          digitalWrite(3,LOW);
            digitalWrite(2,LOW); //stop 
    
        
      
  }
   else  if(Serial.available()>0)
  {
    delay(10);
    String voice=Serial.readString();
    Serial.println(voice);
  
   if(voice == "right") 
{

 //Serial.println("r");
         digitalWrite(6,HIGH);
        digitalWrite(8,LOW);
          digitalWrite(3,LOW);
            digitalWrite(2,HIGH);
  delay(2000);
  digitalWrite(6,LOW);
        digitalWrite(8,LOW);
          digitalWrite(3,LOW);
            digitalWrite(2,LOW);
  
 

} 
   if(voice == "left")
  {
  // Serial.println("l");
          digitalWrite(6,LOW);
        digitalWrite(8,HIGH);
          digitalWrite(3,HIGH);
            digitalWrite(2,LOW);
  
      delay(2000);
  digitalWrite(6,LOW);
        digitalWrite(8,LOW);
          digitalWrite(3,LOW);
            digitalWrite(2,LOW);
         
}
   if(voice == "back") 
{
  //Serial.println("b");
         digitalWrite(6,LOW);
        digitalWrite(8,HIGH);
          digitalWrite(3,LOW);
            digitalWrite(2,HIGH); 
  delay(5000);
  digitalWrite(6,LOW);
        digitalWrite(8,LOW);
          digitalWrite(3,LOW);
            digitalWrite(2,LOW);
         
}
   if(voice == "forward") 
{
 // Serial.println("f");
         digitalWrite(6,HIGH);
        digitalWrite(8,LOW);
          digitalWrite(3,HIGH);
            digitalWrite(2,LOW);
  delay(5000);
  digitalWrite(6,LOW);
        digitalWrite(8,LOW);
          digitalWrite(3,LOW);
            digitalWrite(2,LOW);
         
}
   if(voice == "stop")
  {
  //  Serial.println("s");
       digitalWrite(6,LOW);
        digitalWrite(8,LOW);
          digitalWrite(3,LOW);
            digitalWrite(2,LOW);
        
    }
       
 if(voice.length()>0)
    {
    //  Serial.println(voice);
       voice="";
 
    }
    delay(1000);
     }

}
     long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
