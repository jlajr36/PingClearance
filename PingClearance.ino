#include <NewPing.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     11  
#define MAX_DISTANCE 200

int distance = 0;
int distanceSum = 0;

int StopPin = 2;
int GoPin = 3;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(StopPin, OUTPUT);
  pinMode(GoPin, OUTPUT);
}

void loop() {
  distanceSum = 0;
  for (int i = 0; i < 10; i++) {
    distanceSum = distanceSum + sonar.ping_cm();
  }
  distance = distanceSum/10;
  if ((distance < 10) && (distance > 2)) {
    digitalWrite(StopPin, HIGH);
    digitalWrite(GoPin, LOW);
  } else {
    digitalWrite(StopPin, LOW);
    digitalWrite(GoPin, HIGH);
  }
}
