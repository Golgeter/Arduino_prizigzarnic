
const int led1Pin = 6;
const int led2Pin = 7;
const int b1Pin = 2;
const int b2Pin = 3;
const int b3Pin = 4;
const int b4Pin = 5;

bool led1State = false;
bool led2State = false;

bool lastB1 = HIGH;
bool lastB2 = HIGH;
bool lastB3 = HIGH;
bool lastB4 = HIGH;

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);

  pinMode(b1Pin, INPUT_PULLUP);
  pinMode(b2Pin, INPUT_PULLUP);
  pinMode(b3Pin, INPUT_PULLUP);
  pinMode(b4Pin, INPUT_PULLUP);

  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
}

void loop() {
  bool b1 = digitalRead(b1Pin);
  bool b2 = digitalRead(b2Pin);
  bool b3 = digitalRead(b3Pin);
  bool b4 = digitalRead(b4Pin);

  if (b3 == LOW && lastB3 == HIGH) {
    led1State = false;
    led2State = false;
    delay(200);
  }
  else if (b1 == LOW && lastB1 == HIGH && !led2State) {
    led1State = true;
    led2State = false;
    delay(200);
  }
  else if (b2 == LOW && lastB2 == HIGH && !led1State) {
    led2State = true;
    led1State = false;
    delay(200);
  }
  else if (b4 == LOW && lastB4 == HIGH) {
    if (led1State) {
      led1State = false;
      led2State = true;
    } else if (led2State) {
      led2State = false;
      led1State = true;
    }
    delay(200);
  }

  digitalWrite(led1Pin, led1State ? HIGH : LOW);
  digitalWrite(led2Pin, led2State ? HIGH : LOW);

  lastB1 = b1;
  lastB2 = b2;
  lastB3 = b3;
  lastB4 = b4;
}
