/*int water; //random variable
void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);// output pin for relay board,this will sent signal to the relay 
  pinMode(6,INPUT);//input pin coming from soil sensor
}

void loop() {
  // put your main code here, to run repeatedly:
  water = digitalRead(6); //reading the coming signal from the soil sensor 
  if(water == HIGH) //if water level is full then cut the relay
  {
    digitalWrite(3,LOW); //low is to cut the relay
  }
  else
  {
    digitalWrite(3,HIGH); //high to continue proving signal and water supply
  }
  delay(400);


} */

int motorPin = 3;   // Relay control pin (connected to the motor)
int sensorPin = A0; // Soil moisture sensor pin (analog)
int moistureValue;  // Stores soil moisture level
int threshold = 500; // Adjust this value based on your soil and sensor readings

void setup() {
    pinMode(motorPin, OUTPUT);  // Set motor pin as output
    Serial.begin(9600);         // Start serial communication for debugging
}

void loop() {
    moistureValue = analogRead(sensorPin); // Read moisture level
    Serial.print("Soil Moisture Level: ");
    Serial.println(moistureValue); // Print sensor value for debugging

    if (moistureValue < threshold) {  // If soil is dry (value below threshold)
        digitalWrite(motorPin, HIGH); // Turn on motor
    } else {  // If soil is wet (value above threshold)
        digitalWrite(motorPin, LOW);  // Turn off motor
    }

    delay(1000); // Delay to avoid rapid switching
}

