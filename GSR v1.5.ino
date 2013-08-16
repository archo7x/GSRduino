
// declare GSR variables
const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;
int led = 13;

void setup(){
  //Serial comm start
  Serial.begin(115200);
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0; 
     pinMode(led, OUTPUT);
}


void loop() {
  // subtract the last reading:
  total= total - readings[index];         
  // read from the sensor:  
  readings[index] = analogRead(inputPin); 
  // add the reading to the total:
  total= total + readings[index];       
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= numReadings)              
    // ...wrap around to the beginning: 
    index = 0;                           

  // calculate the average:
  average = total / numReadings;
 // scale analog output to digital 0-255 
  //average = map(readings[index],0,1023,0,255);  
  // send it to the computer as ASCII digits
  if (Serial.available() > 0) {

    byte inbyte=Serial.read();
    if(inbyte=='a'){
      Serial.print(average);
    }  
  delay(1);        // delay in between reads for stability            

}
if (average >= 200){
  
  digitalWrite(led, HIGH);
}
else  if (average <=200) {
  digitalWrite(led, LOW);  // turn the LED on (HIGH is the voltage level)               // wait for a second
     
}
}
