
// Turn on LED while button is pressed
unsigned long timeStart;
unsigned long timeEnd;
unsigned long timePressed;

const int LED = 13;   //the pin for the LED
const int BUTTON = 7; //the input pin where pushbutton is connected
int buttonState = 0;          // val will be used to store the state of the input pin
int buttonStateLast = 0;
int shortPress = 100;
int longPress = 300;
int valStart = LOW;

const int LED2 = 12;   //the pin for the LED
const int BUTTON2 = 4; //the input pin where
                      //pushbutton is connected
int val2 = 0;          // val will be used to store the state
                      //of the input pin
int counter2 = 0;

void setup() {
  pinMode (LED, OUTPUT);    //tell Arduino LED is an output
  pinMode (BUTTON, INPUT);  //and BUTTON is an input
  pinMode (LED2, OUTPUT);
  pinMode (BUTTON2, INPUT);
  Serial.begin(9600);
}

void loop() {
  valStart = digitalRead(BUTTON); //read input value and store it
  if (valStart != buttonStateLast) 
//  Serial.println(valStart);
  {
   if (valStart == HIGH) {
     timeStart = millis(); 
   }
   
   if ( valStart == LOW) {
     timePressed = millis() - timeStart;
     digitalWrite(LED, LOW);
//       Serial.println("in valstart low");
//     Serial.println(timePressed);
     if (1 <= timePressed <= shortPress) {
//       digitalWrite(LED, HIGH);
       Serial.println('000|111|000');
       timePressed = 0;
     }

     if (shortPress <= timePressed <= longPress) {
       digitalWrite(LED2, HIGH);
//       Serial.println(1);
       timePressed = 0;
     }
   }
   
   buttonStateLast = valStart;
   }
  
}   
     
     
//  
//
////  Serial.println(timeStart);
//  valEnd = digitalRead(BUTTON);
//  Serial.println(valEnd);
//  timeEnd = millis();
//  Serial.println(timeEnd);
//  delay(1000);
////  Serial.println(valStart);
////  Serial.println(timeStart);
//  
////  Serial.println(timeEnd);
//  val2 = digitalRead(BUTTON2); //read input value of button 2 and store it
//  //check whether the input is HIGH (button pressed)
//  if (valStart == HIGH) {
//    digitalWrite(LED, HIGH); //turn LED on
//    // check for length of button press
//    // if short:
//   
//    // if long:
//    // Serial.println(1)
//    // Serial.println("Button one pressed");
//    // debouncing code
//    // check for second button press
//    // if second button press:
//    // Serial.println("space")
//    
//  }
//  else {
//    digitalWrite(LED, LOW);
//  }
//  
//  if (val2 == HIGH) {
//    digitalWrite(LED2, HIGH); //turn LED on
//    counter2 ++;
//    //Serial.println(1);
//    // Serial.println("Button two pressed");
//    // if short:
//    // Serial.println("|")
//    // if long: 
//    // Serial.println("*")
//  } 
//  else {
//    digitalWrite(LED2, LOW);
//  }
//}
  
  
  
