int VRx = A0; // initializing the pin for the x axis input of the joystick
int VRy = A1; // initializing the pin for the y axis input of the joystick


int xPosition = 0; //this variabe will hold the value for the input of the joysick for the x axis
int yPosition = 0; //this variabe will hold the value for the input of the joysick for the y axis

int mapX = 0; // these values will later allow us to get the desired numerical outputs we want from our joystick
int mapY = 0; // these values will later allow us to get the desired numerical outputs we want from our joystick

const int buttonPin = 4;     // initializing the number of the pushbutton pin
int buttonPosition = 1; // initiaizing the position of the button
int forward = 0; // initializing the variable to move the ship forward
int rotateRight = 0;// initializing the variable to move the ship right
int rotateLeft = 0; // initializing the variable to move the ship left


int buttonState = LOW;  // variable for reading the pushbutton status





void setup() {
  Serial.begin(9600); //this is key for serial communication
  
  pinMode(VRx, INPUT); // makes sure x axis values of joystick are inputs
  pinMode(VRy, INPUT); // makes sure y axis values of joystick are inputs
  pinMode(buttonPin, INPUT); // initialize the pushbutton pin as an input

}

void loop() {
  xPosition = analogRead(VRx); //we can now read the values coming from the joystick inputs on the x axis
  yPosition = analogRead(VRy); //we can now read the values coming from the joystick inputs on the y axis
 
  mapX = map(xPosition, 0, 1023, -512, 512);//we then map the incoming values from the joystick of 0 to 1023 to now -512 to 512 
  mapY = map(yPosition, 0, 1023, -512, 512);//we then map the incoming values from the joystick of 0 to 1023 to now -512 to 512

  //you can uncomment these values to have them print to your serial monitor to test and see if your controller is working!
  
  //Serial.print("X: ");
  //Serial.print(mapX);
  //Serial.print(" | Y: ");
  //Serial.print(mapY);
  //Serial.print(" | Button: ");
  //Serial.println(buttonPosition);

  
   shipMovementFunction(); //here we call a function that will later allow movement for the ship
   buttonState = digitalRead(buttonPin);//this reads the input for the button

  
  
  if (buttonState == HIGH) {//if the button is not pressed...
    buttonPosition = 2;
    Serial.write(buttonPosition);//write "1" to the serial monitor
    
  } 
  else if(buttonState == LOW) {//if the button is pressed...
    shipMovementFunction();
    buttonPosition = 1;
     Serial.write(buttonPosition);//write "2" to the serial monitor
  }

}

int shipMovementFunction(){ //function created for moving the ship

if (mapY > -220 && mapY <= -512){ // if the y values of the joystick input are between -220 and -512...
    forward = 3; 
    Serial.write(forward);//write "3" to the serial monitor
  }
  if(mapX > 220 && mapX <= 512){// if the x values of the joystick input are between 220 and 512...
    rotateRight = 5;
    Serial.write(rotateRight); //write "5" to the serial monitor
  }
  if(mapX < -220 && mapX >= -512){ // if the x values of the joystick input are between -220 and -512...
    rotateLeft = 4; 
    Serial.write(rotateLeft); //write "4" to the serial monitor
  }

  
}
