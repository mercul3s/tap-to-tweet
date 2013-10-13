#include <LiquidCrystal.h>

// Turn on LED while button is pressed
const int LED = 13;       //the pin for the LED
const int BUTTON = 7;     //the input pin where
                          //pushbutton is connected
int ledState = LOW;     // the current state of the output pin
int buttonState;            // the current reading from the input pin
int lastButtonState = LOW; // the previous reading from the input pin

// the following variables are long's because the time, measured in milliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;   // the debounce time; increase if the output flickers
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode (LED, OUTPUT);
  pinMode (BUTTON, INPUT);
  digitalWrite(LED, ledState);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  Serial.begin(9600);
}

void loop() {
 int reading = digitalRead(BUTTON); // read the input value of the button
  
  // check to see if we pressed the button (ie, the state has changed to HIGH)
  // if so, 
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    if (reading != buttonState) {
      buttonState = reading;   
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  digitalWrite(LED, ledState);
  lastButtonState = reading;
}
