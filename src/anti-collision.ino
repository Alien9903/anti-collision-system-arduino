#define TRIG_PIN 9
#define ECHO_PIN 10

#define LED_GREEN 2
#define LED_YELLOW 3
#define LED_RED 4

#define BUZZER_PIN 6
#define POT_PIN A0

float measureDistance() {
  long duration;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;

  return duration * 0.034 / 2;
}

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  float distance = 0;
  int valid = 0;

  for (int i = 0; i < 5; i++) {
    float d = measureDistance();
    if (d > 0 && d < 400) {
      distance += d;
      valid++;
    }
    delay(30);
  }

  if (valid > 0) distance /= valid;
  else distance = -1;

  int potValue = analogRead(POT_PIN);
  float criticalDistance = map(potValue, 0, 1023, 30, 45);

  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);

  if (distance < 0 || distance > criticalDistance * 1.5) {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
  } 
  else if (distance > criticalDistance) {
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
  } 
  else {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(20);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(100);
}
