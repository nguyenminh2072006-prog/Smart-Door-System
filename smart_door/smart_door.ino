#include <Keypad.h>
#include <Servo.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] ={5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

Servo myServo;
int servoPin = 11;
int buzzer = 12;

String password = "1234";
String input = "";

void setup() {
  myServo.attach(servoPin);
  pinMode(buzzer, OUTPUT);
  myServo.write(180); 
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '*') {
      input = "";
    }
    else if (key == '#') {
      if (input == password) {
        myServo.write(90);
        delay(5000);
        myServo.write(180);
      } 
      else {
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
      }

      input = ""; 
    }
    else {
      input += key;
    }
  }
}