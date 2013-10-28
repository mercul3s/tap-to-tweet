#include <LiquidCrystal.h>

const int LED = 13;         
const int BUTTON = 2;      
int ledState = LOW;         // the default state of the output pin
int buttonState;            // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin, defaults to LOW
int begin_loop
int morse_code[] = {
  // Alphabet
  ".-",     // A
  "-...",   // B
  "-.-.",   // C
  "-..",    // D
  ".",      // E
  "..-.",   // F
  "--.",    // G
  "....",   // H
  "..",     // I
  ".---",   // J
  "-.-",    // K
  ".-..",   // L
  "--",     // M
  "-.",     // N
  "---",    // O
  ".--.",   // P
  "--.-",   // Q
  ".-.",    // R
  "...",    // S
  "-",      // T
  "..-",    // U
  "...-",   // V
  ".--",    // W
  "-..-",   // X
  "-.--",   // Y
  "--..",   // Z
  // Numbers
  "-----",  // 0
  ".----",  // 1
  "..---",  // 2
  "...--",  // 3
  "....-",  // 4
  ".....",  // 5
  "-....",  // 6 
  "--...",  // 7
  "---..",  // 8
  "----.",  // 9
  // Punctuation
  "·----",  // .
  "---...", // :
  "-.-.-.", // ;
  "-...-",  // =
  "..--..", // ?
  ".--._.", // @
}

// the following variables are long because the time, measured in milliseconds,
// will quickly become a bigger number than can be stored in an int.

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 100;   // the debounce time; increase if the output flickers

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

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
  // get the time at the start of the loop
  begin_loop = micros();

  // check to see if enough time (10ms) has elapsed before looping again
  // if (begin_loop + 10000) 
  int current_state = digitalRead(BUTTON); // read the input value of the button
  
  // check to see if we pressed the button (ie, the state has changed to HIGH)
  // if so, turn on the LED and print a message to the LCD
  // we don't need debouncing code here! we need an ISR - interrupt service routine
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

  lastButtonState = current_state;
}

// boolean subroutine for true/false return if button state is on or off
