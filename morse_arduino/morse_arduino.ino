#include <LiquidCrystal.h>


int lastButtonState = LOW;                  // the previous reading from the input pin, defaults to LOW
bool buttonPress = false;                   // this variable holds the state of the button
// the following variables are long because the time, measured in milliseconds,
// will quickly become a bigger number than can be stored in an int.
// May not need the debounce variables.
long lastDebounceTime = 0;                  // the last time the output pin was toggled
long debounceDelay = 100;                   // the debounce time; increase if the output flickers
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int begin_loop;
// taking out the morse code array for now; need to figure out a better way of doing it

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  attachInterrupt(0, printLCD, RISING);     // when the button is pressed, call the function to print the lcd
  // attachInterrupt(0, clearLCD, FALLING);    // when the button is released, call the function to clear the lcd
  Serial.begin(9600);                       // Console output for debugging and sending
                                            // data to wrapper script
}

void loop() {
  // get the time at the start of the loop
  begin_loop = micros();
  // check to see if enough time (10ms) has elapsed before looping again
  // if ((begin_loop + 10000) > 10000) {
  //   lcd.clear();
  // } 
  delay(10000);
  clearLCD;
  // int current_state = digitalRead(BUTTON); // read the input value of the button
  
  // // check to see if we pressed the button (ie, the state has changed to HIGH)
  // // if so, turn on the LED and print a message to the LCD
  // // we don't need debouncing code here! we need an ISR - interrupt service routine
  // if (current_state != lastButtonState) {
  //   lastDebounceTime = millis();
  // }
  
  // if ((millis() - lastDebounceTime) > debounceDelay) {
    
  //   if (current_state != buttonState) {
  //     buttonState = current_state;   
  //     if (buttonState == HIGH) {
  //       ledState = !ledState;
  //       digitalWrite(LED, buttonState); 
  //       lcd.print("hello, world!");
  //       delay(1000);
  //       lcd.clear();
  //     }
  //   }
  // }

  // lastButtonState = current_state;
}

void printLCD() {
  buttonPress = true;
  lcd.print("Hello, world!");
}

void clearLCD() {
  buttonPress = false;
  lcd.clear();
}
// boolean subroutine for true/false return if button state is on or off
