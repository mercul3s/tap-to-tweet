#include <LiquidCrystal.h>

const int LED = 13;         
const int BUTTON = 7;      
int ledState = LOW;         // the default state of the output pin
int buttonState;            // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin, defaults to LOW

// the following variables are long because the time, measured in milliseconds,
// will quickly become a bigger number than can be stored in an int.

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 100;   // the debounce time; increase if the output flickers

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode (LED, OUTPUT);
  pinMode (BUTTON, INPUT);
  digitalWrite(LED, ledState);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  Serial.begin(9600);       // Console output for debugging and sending
                            // data to wrapper script
}

void loop() {
 int current_state = digitalRead(BUTTON); // read the input value of the button
  
  // check to see if we pressed the button (ie, the state has changed to HIGH)
  // if so, turn on the LED and print a message to the LCD
  if (current_state != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    if (current_state != buttonState) {
      buttonState = current_state;   
      if (buttonState == HIGH) {
        ledState = !ledState;
        digitalWrite(LED, buttonState); 
        lcd.print("hello, world!");
        delay(1000);
        lcd.clear();
      }
    }
  }

  digitalWrite(LED, ledState);
  lastButtonState = current_state;
}
