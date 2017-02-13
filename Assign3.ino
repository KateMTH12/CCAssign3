int button = 2;

int readingButton = 0;

long counter = 0;
int tooLong = 10000;
long now = 0;

int greenLED = 9;
int redLED = 11;
int blueLED = 10;

int redSensor = A2;
int greenSensor = A1;
int blueSensor = A0;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

}

void loop() {
  readingButton = digitalRead(button);
  now = millis();
  if (readingButton == 1) {
    redValue = analogRead(redSensor);
    delay(5);
    greenValue = analogRead(greenSensor);
    delay(5);
    blueValue = analogRead(blueSensor);
    analogWrite(redLED, redValue);
    analogWrite(greenLED, greenValue);
    analogWrite(blueLED, blueValue);
  }
  if (now - counter > tooLong && readingButton == 1) {
    redValue = 0;
    greenValue = 0;
    blueValue = 0;
    analogWrite(redLED, redValue);
    analogWrite(greenLED, greenValue);
    analogWrite(blueLED, blueValue);
    delay(100);
    redValue = analogRead(redSensor);
    delay(5);
    greenValue = analogRead(greenSensor);
    delay(5);
    blueValue = analogRead(blueSensor);
    delay(100);
    analogWrite(redLED, redValue);
    analogWrite(greenLED, greenValue);
    analogWrite(blueLED, blueValue);
    counter = millis();
    Serial.print(millis() - counter);

  } if (now - counter > 2 * tooLong && readingButton == 1) {

    redSensorValue -= 5;
    greenSensorValue -= 5;
    blueSensorValue -= 5;

  } if (now - counter > 3 * tooLong && readingButton == 1) {
    redValue = 255;
    greenValue = 0;
    blueValue = 0;
    analogWrite(redLED, redValue);
    analogWrite(greenLED, greenValue);
    analogWrite(blueLED, blueValue);
  }
  if (readingButton == 0) {
    redValue = 0;
    greenValue = 0;
    blueValue = 0;
    analogWrite(redLED, redValue);
    analogWrite(greenLED, greenValue);
    analogWrite(blueLED, blueValue);
  }
}
  /*redValue = map(redValue, 0 , 1023, 0, 255);
  greenValue = map(greenValue, 0 , 1023, 0, 255);
  blueValue = map(blueValue, 0 , 1023, 0, 255);
  this would convert the values to normal RGB values but it doesn't have any practical use in my code
}
*/


