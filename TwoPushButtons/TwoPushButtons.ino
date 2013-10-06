
// Turn on LED while button is pressed

const int LED = 13;   //the pin for the LED
const int BUTTON = 7; //the input pin where
                      //pushbutton is connected
int val = 0;          // val will be used to store the state
                      //of the input pin
const int LED2 = 12;   //the pin for the LED
const int BUTTON2 = 4; //the input pin where
                      //pushbutton is connected
int val2 = 0;          // val will be used to store the state
                      //of the input pin

void setup() {
  pinMode (LED, OUTPUT);    //tell Arduino LED is an output
  pinMode (BUTTON, INPUT);  //and BUTTON is an input
  pinMode (LED2, OUTPUT);
  pinMode (BUTTON2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Starting output");
}

void loop(){
  val = digitalRead(BUTTON); //read input value and store it
  val2 = digitalRead(BUTTON2); //read input value of button 2 and store it
  //check whether the input is HIGH (button pressed)
  if (val == HIGH) {
    digitalWrite(LED, HIGH); //turn LED on
    // check for length of button press
    // if short:
    // Serial.println(0)
    // if long:
    // Serial.println(1)
    Serial.println("Button one pressed");
    // debouncing code
    // check for second button press
    // if second button press:
    // Serial.println("space")
    
  } else {
    digitalWrite(LED, LOW);
  }
  if (val2 == HIGH) {
    digitalWrite(LED2, HIGH); //turn LED on
    Serial.println("Button two pressed");
  } else {
    digitalWrite(LED2, LOW);
  }
}
  
  
  
