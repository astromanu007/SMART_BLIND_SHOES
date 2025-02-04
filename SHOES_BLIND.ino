#define TRIG 9
#define ECHO 10
#define VIBRATOR 6
#define BUZZER 7

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(VIBRATOR, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Send ultrasonic pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Read the echo time
  duration = pulseIn(ECHO, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Check distance and activate feedback
  if (distance > 0 && distance <= 100) { // Adjust range as needed
    digitalWrite(VIBRATOR, HIGH);
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(VIBRATOR, LOW);
    digitalWrite(BUZZER, LOW);
  }

  delay(100);
}