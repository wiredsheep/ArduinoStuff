// find x
// Robert Church 2014-12
//

#include <LiquidCrystal.h>

const int b1pin = 10; // Yellow (up)
const int b2pin = 9;  // Blue   (down)
const int b3pin = 8;  // Red    (submit)
const int b4pin = 7;  // Green  (Reset)

int submitState  = HIGH;
int minusState   = HIGH;
int plusState    = HIGH;
int resetState   = HIGH;
int psubmitState = HIGH;
int pplusState   = HIGH;
int pminusState  = HIGH;
int presetState  = HIGH;
int number = 50;
int answer = rand() % 100 + 1;
int high   = 0;
int low    = 0;

LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  pinMode(b1pin, INPUT);
  pinMode(b2pin, INPUT);
  pinMode(b3pin, INPUT);
  pinMode(b4pin, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("f(x) =");
}

void loop()
{
  submitState = digitalRead(b1pin);
  minusState  = digitalRead(b2pin);
  plusState   = digitalRead(b3pin);
  resetState  = digitalRead(b4pin);

  if(resetState != presetState)
  {
    lcd.begin(16, 2);
    lcd.clear();
    lcd.print("f(x) =");
    lcd.setCursor(0,1);
    lcd.print("Find X!");
    answer = rand() % 100 + 1;
    number = 50;
  }

  if(minusState != pminusState)
  {
    if(number - 1 >= 0)
    {
      number = number - 1;
    }
    lcd.begin(16, 2);
    lcd.clear();
    lcd.print("f(x) =");
    lcd.setCursor(7,0);
    lcd.print(number);
    delay(275);
  }

  if(plusState != pplusState)
  {
    if(number + 1 <= 100)
    {
      number = number + 1;
    }
    lcd.begin(16, 2);
    lcd.clear();
    lcd.print("f(x) =");
    lcd.setCursor(7,0);
    lcd.print(number);
    delay(275);
  }

  if(submitState != psubmitState)
  {
    // Validate if number matches
    if(number == 100)
    {
      lcd.setCursor(11,0);
    } else if (number < 10) {
      lcd.setCursor(9,0);
    } else {
      lcd.setCursor(10,0);
    }

    if(number > answer)
    {
      lcd.print("> x");
    } else if (number < answer) {
      lcd.print("< x");
    } else if (number == answer) {
      lcd.setCursor(0,1);
      lcd.print("You guessed it!");
    }
  }
  psubmitState = submitState;
}
