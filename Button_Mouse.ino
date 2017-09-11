#include <Bounce2.h> // to access the bounce lib we added
#include <Mouse.h> // access the built in mouse library


#define BUTTON_PIN 3

Bounce button = Bounce(); // create bounce button called button

void setup() {
  // put your setup code here, to run once:

  // use arduino as a mouse
  Mouse.begin();

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
      Mouse.press(); // press left click down
    }
    // if button went went from 0 to 1 - ie. was released
    else if (button.rose()) {
      Mouse.release(); // release left click
    }
  }
}
 
