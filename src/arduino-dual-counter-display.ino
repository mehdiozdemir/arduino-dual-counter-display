byte segment1[] = {2, 3, 4, 5}; // A, B, C, D
byte segment2[] = {6, 7, 8, 9};
byte green = 11;
byte red = 10;

byte speedPin = A0;
byte directionPin = A1;

int speed;
int direction;

int counter = 0;
int currentDigit[3] = {0, 0, 0}; 

void setup() {
  for (byte i = 0; i < 4; i++) {
    pinMode(segment1[i], OUTPUT);
    pinMode(segment2[i], OUTPUT);
    
  }
  pinMode(speedPin, INPUT);
  pinMode(directionPin, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  updatePotentiometerValues();
  if (direction < 512) {
    countDown();
  } else {
    countUp();
  }
}

void updatePotentiometerValues() {
  speed = analogRead(speedPin);
  direction = analogRead(directionPin);
  Serial.print("Speed: ");
  Serial.print(speed);
  Serial.print(", Direction: ");
  Serial.println(direction);
}

void countDown() {
  int delayTime = map(speed, 0, 1023, 1, 5);

  counter--;
  if (counter < 0) {
    counter = 0;
  }
  
  digitalWrite(green , LOW);
  digitalWrite(red , HIGH);
  

  separateDigits(counter, currentDigit);

  displayNumber(currentDigit);
  delay(delayTime * 200);
}

void countUp() {
  int delayTime = map(speed, 0, 1023, 1, 5);

  counter++;
  if (counter > 99) {
    counter = 99;
  }
  
  digitalWrite(green , HIGH);
  digitalWrite(red , LOW);

  separateDigits(counter, currentDigit);

  displayNumber(currentDigit);
  delay(delayTime * 200);
}

void separateDigits(int number, int digits[]) {           
  digits[1] = number / 10;  
  digits[2] = number % 10;  
}

void displayNumber(int digits[]) {
  for (int digit = 1; digit < 3; digit++) {
    byte* currentSegmentPins;
     if (digit == 1) {
      currentSegmentPins = segment2; 
    } else {
      currentSegmentPins = segment1; 
    }

    for (int segment = 0; segment < 4; segment++) {
      digitalWrite(currentSegmentPins[segment], digits[digit] & (1 << segment));
    }
  }
}
