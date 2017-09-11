#include <Bounce2.h> // to access the bounce lib we added
#include <Keyboard.h> // access the built in keyboard library

#define BUTTON_PIN 3

const char key = ' '; // going to press the space key
Bounce button = Bounce(); // create bounce button called button

void setup() {
  // put your setup code here, to run once:

  // use arduino as a keyboard
  Keyboard.begin();

  // set button pin to be an input
  // activate pull up resistor
  pinMode( BUTTON_PIN , INPUT_PULLUP);

  // setup the button
  button.attach( BUTTON_PIN );
  button.interval(5);
}

void loop() {
  // put your main code here, to run repeatedly:

  // button.update is true if button state has changed.
  if (button.update()) {

    // if button went from 1 to 0 - ie. was pressed
    if(button.fell()) {
      Keyboard.press(key); // press key down
    }
    // if button went went from 0 to 1 - ie. was released
    else if (button.rose()) {
      Keyboard.release(key); // release key
    }
  }
  
  // OR - for hold down key, but then kill down the upper code

  // if(button.update()) {
    // if(button.fell()) {
      // Keyboard.write(key); // send 1 keypress |
    
   // }
  }
 
