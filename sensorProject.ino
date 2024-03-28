// Define pins and variable for input sensor and output led and buzzer
int mq135_aqi_sensor = A1;
int flame_sensor_pin = 4;    
int red_led = 2;
int led_pin = 10;                // initializing the pin 2 as the led pin
int buzzer_pin = 6;
const int NOTE_C4 = 262;
const int NOTE_E4 = 330;
const int NOTE_G4 = 392;
const int NOTE_C5 = 523;
const int NOTE_B4 = 494;
const int NOTE_A4 = 440;
const int NOTE_F4 = 349;
const int NOTE_E5 = 659;
const int NOTE_D5 = 587;
const int NOTE_D4 = 294;


int flame_pin = HIGH;    
// Set threshold for AQI
int aqi_ppm = 0;

void setup() {
  // Set direction of input-output pins
  pinMode (mq135_aqi_sensor, INPUT);
  pinMode (red_led, OUTPUT);
  pinMode(flame_sensor_pin, INPUT);     // declaring sensor pin as input pin for Arduino
  pinMode(led_pin, OUTPUT);             // declaring led pin as output pin
  pinMode(buzzer_pin, OUTPUT);          // declaring buzzer pin as output pin

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
    digitalWrite(led_pin, HIGH);                                     
    playMelody();                                     // play a melody on the buzzer
  }
  else
  {
    Serial.println("no flame");
    digitalWrite(led_pin, LOW);                              
    noTone(buzzer_pin);                               // stop playing any tone
  }
  
  delay (700);
}
void playMelody()
{
  // tone(buzzer_pin, NOTE_F4, 200); // C4
  // delay(200);
  // tone(buzzer_pin, NOTE_C5, 200); // E4
  // delay(200);
  // tone(buzzer_pin, NOTE_A4, 200); // G4
  // delay(200);
  // tone(buzzer_pin, NOTE_C5, 200); // C5 (double duration)
  // delay(200);
  // tone(buzzer_pin, NOTE_G4, 200); // B4
  // delay(200);
  // tone(buzzer_pin, NOTE_A4, 200); // A4
  // delay(200);
  // tone(buzzer_pin, NOTE_G4, 200); // G4 (double duration)
  // delay(200);
  // tone(buzzer_pin, NOTE_F4, 400); // F4
  // delay(400);
  // tone(buzzer_pin, NOTE_F4, 200); // C4
  // delay(200);
  // tone(buzzer_pin, NOTE_C5, 200); // E4
  // delay(200);
  // tone(buzzer_pin, NOTE_A4, 200); // G4
  // delay(200);
  // tone(buzzer_pin, NOTE_C5, 200); // C5 (double duration)
  // delay(200);
  // tone(buzzer_pin, NOTE_G4, 200); // B4
  // delay(200);
  // tone(buzzer_pin, NOTE_A4, 200); // A4
  // delay(200);
  // tone(buzzer_pin, NOTE_G4, 200); // G4 (double duration)
  // delay(200);
  // tone(buzzer_pin, NOTE_F4, 400); // F4
  // delay(400);
  tone(buzzer_pin, NOTE_C4, 200); // C4
  delay(200);
  tone(buzzer_pin, NOTE_D4, 200); // D4
  delay(200);
  tone(buzzer_pin, NOTE_E4, 400); // E4 (double duration)
  delay(400);
  tone(buzzer_pin, NOTE_C4, 200); // C4
  delay(200);
  tone(buzzer_pin, NOTE_D4, 200); // D4
  delay(200);
  tone(buzzer_pin, NOTE_E4, 400); // E4 (double duration)
  delay(400);
  tone(buzzer_pin, NOTE_D4, 200); // D4
  delay(200);
  tone(buzzer_pin, NOTE_C4, 400); // C4 (double duration)
  delay(400);
  
}