#include <Keyboard.h>

#define SPEED_HISTORY_SIZE 5
#define THRESHOLD 2

#define hall_1 2
#define hall_2 3
#define left 4
#define right 5
#define brakes 6
#define nitro 7

#define KEY_RIGHT 0x64  // D 
#define KEY_LEFT 0x61  // A
#define KEY_UP 0x77  // W
#define KEY_DOWN 0x73  // S
#define KEY_NITRO 0x20  // Space

/*
  #define KEY_RIGHT KEY_RIGHT_ARROW
  #define KEY_LEFT KEY_LEFT_ARROW
  #define KEY_UP KEY_UP_ARROW
  #define KEY_DOWN KEY_DOWN_ARROW
  #define KEY_NITRO KEY_RIGHT_CTRL
*/

int counter;
int oldState;
int threshold;
int speedHistory[SPEED_HISTORY_SIZE];
bool boolspeed = false;

/* Time */
int time = 0;
int seconds() {
  return int((millis() / 1000.0) * 2);
}

void setup() {
  Serial.begin(9600);

  pinMode(left, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);

  // Wheel
  pinMode(hall_1, INPUT);
  oldState = digitalRead(hall_1);
  counter = 0;
  threshold = THRESHOLD;
  for (int i = 0; i < SPEED_HISTORY_SIZE; ++i) {
    speedHistory[i] = 0;
  }

  Keyboard.begin();
}

void loop() {
  // Buttons
  if (not digitalRead(left)) {
    Keyboard.press(KEY_LEFT);
  } else {
    Keyboard.release(KEY_LEFT);
  }
  if (not digitalRead(right)) {
    Keyboard.press(KEY_RIGHT);
  } else {
    Keyboard.release(KEY_RIGHT);
  }
  /*if(not digitalRead(brakes)) {
    Keyboard.press(KEY_DOWN);
    } else {
    Keyboard.release(KEY_DOWN);
    }
    if(not digitalRead(nitro)) {
    Keyboard.press(KEY_NITRO);
    } else {
    Keyboard.release(KEY_NITRO);
    }*/

  int newState = digitalRead(hall_1);

  if (newState != oldState) {
    counter = counter + 1;
  }
  oldState = newState;

  // Each half-second, put the current speedCounter in the speedHistory
  if (seconds() != time) {
    time = seconds();
    speedHistory[time % SPEED_HISTORY_SIZE] = counter;
    counter = 0;
  }

  int speed;
  for (int i = 0; i < SPEED_HISTORY_SIZE; ++i) {
    speed += speedHistory[i];
  }
  speed = speed / SPEED_HISTORY_SIZE;

  if (speed >= threshold and not boolspeed) {
    boolspeed = true;
    Keyboard.press(KEY_UP);
  }

  if (speed < threshold and boolspeed) {
    boolspeed = false;
    Keyboard.release(KEY_UP);
  }

  Serial.print("gottaGoFast? ");
  for(int i = 0; i < speed; ++i) {
    Serial.print("█");
  }
  Serial.print(speed);
  Serial.print("/");
  Serial.println(threshold);

  delay(10);
}
