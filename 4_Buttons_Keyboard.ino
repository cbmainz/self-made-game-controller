// Beispiel Code für einen Arduino Pro Micro und vier Arcade-Buttons die beim drücken Tastaturbefehle senden.
// Per USB an einen Computer angeschlossen, kann so der Arduino Pro Micro als einfacher GameController mit vier Arcade-Buttons benutzt werden.

#include <Bounce2.h> // Bindet die Bounce2-Bibliothek ein
#include <Keyboard.h> // Bindet die Tastatur-Bibliothek ein

// Definiert, an welchen digitalen Anschlüssen des Arduinos die Buttons angeschlossen sind:
#define BUTTON_ONE 6
#define BUTTON_TWO 7
#define BUTTON_THREE 8
#define BUTTON_FOUR 9 

// Definiert, welcher Buchstabe beim drücken geschrieben wird:
const char key_one = 'x'; // hier x für button_one
const char key_two = ' '; // hier die LEERTASTE für button_two
const char key_three = 'y';
const char key_four = 'c';
// char key_two = KEY_RETURN; // hier RETURN (mehr Infos: https://www.arduino.cc/en/Reference/KeyboardModifiers)

// Definiert die beiden Buttons als Bounce Buttons
Bounce button_one = Bounce();
Bounce button_two = Bounce();
Bounce button_three = Bounce();
Bounce button_four = Bounce();

// Setup Code, wird beim Start einmal aufgerufen:
void setup() {

  // Richtet den Arduino als Tastatur ein:
  Keyboard.begin();

  // Richtet die digitalen Anschlüssen, an denen die Buttons angeschlossen sind, als Input einund aktiviert den Pullup-Wiederstand
  pinMode( BUTTON_ONE , INPUT_PULLUP);
  pinMode( BUTTON_TWO , INPUT_PULLUP);
  pinMode( BUTTON_THREE , INPUT_PULLUP);
  pinMode( BUTTON_FOUR , INPUT_PULLUP);

  // Richtet die Buttons ein:
  button_one.attach( BUTTON_ONE );
  button_two.attach( BUTTON_TWO );
  button_three.attach( BUTTON_THREE );
  button_four.attach( BUTTON_FOUR );
  button_one.interval(5);
  button_two.interval(5);
  button_three.interval(5);
  button_four.interval(5);
} // Ende vom Setup

// Haupteil des Programmes, dieser Code wird immer wiederholt
void loop() {
  
  // Wenn-Abfrage für den ersten Button:
  // button_one.update ist Wahr, wenn sich der Staus von button_one ändert.
  if (button_one.update()) {

    // Wenn sich der Wert des Buttons von 1 auf 0 ändert - bspw., wenn er gedrückt wurde
    if(button_one.fell()) {
      Keyboard.press(key_one);
    }
    // Wenn sich der Wert des Buttons von 0 auf 1 ändert - bspw., wenn er wieder losgelassen wurde
    else if (button_one.rose()) {
      Keyboard.release(key_one);
    }
  } // Ende der Wenn-Abfrage für den ersten Button
  
  // Wenn-Abfrage für den zweiten Button:
  // button_two.update ist Wahr, wenn sich der Staus von button_two ändert.
  if (button_two.update()) {

    // Wenn sich der Wert des Buttons von 1 auf 0 ändert - bspw., wenn er gedrückt wurde
    if(button_two.fell()) {
      Keyboard.press(key_two);
    }
    // Wenn sich der Wert des Buttons von 0 auf 1 ändert - bspw., wenn er wieder losgelassen wurde
    else if (button_two.rose()) {
      Keyboard.release(key_two);
    }
  } // Ende der Wenn-Abfrage für den zweiten Button
  
  // Wenn-Abfrage für den dritten Button:
  // button_three.update ist Wahr, wenn sich der Staus von button_three ändert.
  if (button_three.update()) {

    // Wenn sich der Wert des Buttons von 1 auf 0 ändert - bspw., wenn er gedrückt wurde
    if(button_three.fell()) {
      Keyboard.press(key_three);
    }
    // Wenn sich der Wert des Buttons von 0 auf 1 ändert - bspw., wenn er wieder losgelassen wurde
    else if (button_three.rose()) {
      Keyboard.release(key_three);
    }
  } // Ende der Wenn-Abfrage für den dritten Button
  
  // Wenn-Abfrage für den vierten Button:
  // button_four.update ist Wahr, wenn sich der Staus von button_four ändert.
  if (button_four.update()) {

    // Wenn sich der Wert des Buttons von 1 auf 0 ändert - bspw., wenn er gedrückt wurde
    if(button_four.fell()) {
      Keyboard.press(key_four);
    }
    // Wenn sich der Wert des Buttons von 0 auf 1 ändert - bspw., wenn er wieder losgelassen wurde
    else if (button_four.rose()) {
      Keyboard.release(key_four);
    }
  } // Ende der Wenn-Abfrage für den vierten Button
  
 } // Ende vom Loop
