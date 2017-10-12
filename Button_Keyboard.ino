// Beispiel Code für einen Arduino Pro Micro und zwei Arcade-Button die beim drücken Tastaturbefehle senden.
// Per USB an einen Computer angeschlossen, kann so ein einfacher GameController gebaut werden.

#include <Bounce2.h> // Bindet die Bounce2-Bibliothek ein
#include <Keyboard.h> // Bindet die Tatstur-Bibliothek ein

// Definiert, an welchen digitalen Anschlüssen des Arduinos die Buttons angeschlossen sind:
#define BUTTON_ONE 8
#define BUTTON_TWO 9

// Definiert, welcher Buchstabe beim drücken geschrieben wird:
const char key_one = 'x'; // hier x für button_one
const char key_two = ' '; // hier die LEERTASTE für button_two
// char key_two = KEY_RETURN; // hier RETURN (mehr Infos: https://www.arduino.cc/en/Reference/KeyboardModifiers)

// Definiert die beiden Buttons als Bounce Buttons
Bounce button_one = Bounce();
Bounce button_two = Bounce();

void setup()
{
  // Setup Code, wierd beim Start einmal aufgerufen:

  // Richtet den Arduino als Tastatur ein:
  Keyboard.begin();

  // Richtet die digitalen Anschlüssen, an denen die Buttons angeschlossen sind, als Input einund aktiviert den Pullup-Wiederstand
  pinMode( BUTTON_ONE , INPUT_PULLUP);
  pinMode( BUTTON_TWO , INPUT_PULLUP);

  // Richtet die Buttons ein:
  button_one.attach( BUTTON_ONE );
  button_two.attach( BUTTON_TWO );
  button_one.interval(5);
  button_two.interval(5);
}

void loop()
{
  // Haupteil des Programmes, dieser Code wird immer wiederholt:

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
  }
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
  } 
 }
 
