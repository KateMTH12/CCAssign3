int button = 2;

int readingButton = 0;
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
  if (readingButton == 1) {

    delay(50);
    redValue -= 10;
    greenValue -= 10;
    blueValue -= 10;

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
