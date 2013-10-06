
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

const int LED2 = 12;   //the pin for the LED
const int BUTTON2 = 4; //the input pin where
                      //pushbutton is connected
int val = 0;          // val will be used to store the state
                      //of the input pin
int val2 = 0;          // val will be used to store the state
                      //of the input pin
                      

void setup() {
  pinMode (LED, OUTPUT);    //tell Arduino LED is an output
  pinMode (BUTTON, INPUT);  //and BUTTON is an input
  digitalWrite(LED, ledState);
  
  pinMode (LED2, OUTPUT);
  pinMode (BUTTON2, INPUT);
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(BUTTON); //read input value and store it
  val2 = digitalRead(BUTTON2); //read input value of button 2 and store it
  //check whether the input is HIGH (button pressed)
  
  // If the switch changed, due to noise or pressing:
  if (val != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    
    // if the button state has changed:
    if ( val != buttonState) {
      buttonState = val;
      
      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
  
  digitalWrite(LED, ledState);
  Serial.println(0);
  
  // set the LED:
  lastButtonState = val;
  
//  if (val == HIGH) {
//    digitalWrite(LED, HIGH); //turn LED on
//    // check for length of button press
//    // if short:
//    Serial.println(0);
//    // if long:
//    // Serial.println(1)
//    // Serial.println("Button one pressed");
//    // debouncing code
//    // check for second button press
//    // if second button press:
//    // Serial.println("space")
//    
//  } else {
//    digitalWrite(LED, LOW);
//  }
  if (val2 == HIGH) {
    digitalWrite(LED2, HIGH); //turn LED on
    Serial.println(1);
    // Serial.println("Button two pressed");
    // if short:
    // Serial.println("|")
    // if long: 
    // Serial.println("*")
  } else {
    digitalWrite(LED2, LOW);
  }
}
  
  
  
