// Define pins and variable for input sensor and output led and buzzer
const int mq135_aqi_sensor = A1;
int flame_sensor_pin = 4;    
const int red_led = 2;
int led_pin = 10;                // initializing the pin 2 as the led pin
 
int flame_pin = HIGH;    
// Set threshold for AQI
int aqi_ppm = 0;

void setup() {
  // Set direction of input-output pins
  pinMode (mq135_aqi_sensor, INPUT);
  pinMode (red_led, OUTPUT);
  pinMode(flame_sensor_pin, INPUT);     // declaring sensor pin as input pin for Arduino
  pinMode(led_pin, OUTPUT);             // declaring led pin as output pin

  digitalWrite(red_led, LOW);

  // Initiate serial and lcd communication
  Serial.begin (9600);
  delay(1000);
}

void loop() {
  aqi_ppm = analogRead(mq135_aqi_sensor);
  flame_pin = digitalRead(flame_sensor_pin); 
  Serial.print("Air Quality: ");
  Serial.println(aqi_ppm);
  Serial.print("Fire: ");
  Serial.println(aqi_ppm);
  
  if ((aqi_ppm >= 0) && (aqi_ppm <= 80))
  {
    Serial.println("AQI Good");
    digitalWrite(red_led, LOW);
  }
  else if ((aqi_ppm >= 80) && (aqi_ppm <= 100))
  {
    Serial.println("AQI Moderate");
    digitalWrite(red_led, HIGH);
  }

  else if ((aqi_ppm >= 101) && (aqi_ppm <= 200))
  {
    Serial.println("AQI Unhealthy");
    digitalWrite(red_led, HIGH);
  }
  else if ((aqi_ppm >= 201) && (aqi_ppm <= 300))
  {
    Serial.println("AQI V. Unhealthy");
    digitalWrite(red_led, HIGH);
  }
  else if (aqi_ppm >= 301)
  {
    Serial.println("AQI Hazardous");
    digitalWrite(red_led, HIGH);
  }         // reading from the sensor
  if (flame_pin == LOW)                               // checks whether there is flame, as flame present = sensor output low
  {
    Serial.println("FLAME, FLAME, FLAME");
    digitalWrite(led_pin, HIGH);                                      // play a melody on the buzzer
  }
  else
  {
    Serial.println("no flame");
    digitalWrite(led_pin, LOW);                              // stop playing any tone
  }
  
  delay (700);
}