/*
 * Author : Chia Tze Hank
 * Instructions: 
 * 1) Upload the code
 * 2) At void loop, add in printletter(a); and shake the maker uno real quick!
 * 3) A love shape will appear!
*/
int a[] = {0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0};
int letterSpace = 20000;   // defining the space between the letters (ms)
int dotTime = 2500;// defining how long the led is lit (ms)
void setup(){
  // setting the ports of the leds to OUTPUT
  for ( int i = 2; i < 14 ; i++ )
  { pinMode(i, OUTPUT);     // 13 Led pins in total
  }
}
void printLetter(int letter[])
{
  int y;
  // printing the first y row of the letter
  for (y = 0; y < 12; y++)
  {
    digitalWrite(y + 2, letter[y]);               // pinmode begins at pin 2 to pin 9 . letter[y] begins to iterate through the high and lows of the letter assigned in the first place  
  }                                               // for the first 8 PWMS, example: when y=0, pin is 2, letter[0] if is NUMBER8[0] would give 0 value, which is Low, led in pin 2 will not light up.
  delayMicroseconds(dotTime);
  // printing the second y row of the letter
  for (y = 0; y < 12; y++)
  {
    digitalWrite(y + 2, letter[y + 12]);            // begins reading at the 9th position of the letter to 17th
  }
  delayMicroseconds(dotTime);
  // printing the third y row of the letter         // begins reading at the 17th to 26th
  for (y = 0; y < 12; y++)
  {
    digitalWrite(y + 2, letter[y + 24]);
  }
  delayMicroseconds(dotTime);
  for (y = 0; y < 12; y++) {
    digitalWrite(y + 2, letter[y + 36]);
  }
  delayMicroseconds(dotTime*2);
  for (y = 0; y < 12; y++) {
    digitalWrite(y + 2, letter[y + 48]);
  }
  delayMicroseconds(dotTime);
  for (y = 0; y < 12; y++) {
    digitalWrite(y + 2, letter[y + 60]);
  }
  delayMicroseconds(dotTime*1.3);
  for (y = 0; y < 12; y++) {
    digitalWrite(y + 2, letter[y + 72]);
  }
  delayMicroseconds(dotTime);
  for (y = 0; y < 12; y++) {
    digitalWrite(y + 2, letter[y + 84]);
  }
  delayMicroseconds(dotTime*2);
  for (y = 0; y < 12; y++) {
    digitalWrite(y + 2, letter[y + 96]);
  }
  delayMicroseconds(dotTime);
  for (y = 0; y < 12; y++) {
    digitalWrite(y + 2, letter[y + 108]);
  }
  delayMicroseconds(dotTime);
  for (y = 0; y < 12; y++) {
    digitalWrite(y + 2, letter[y + 120]);
  }
  delayMicroseconds(dotTime);
  /*
  for (y = 0; y < 12; y++) {
    digitalWrite(y + 2, letter[y + 132]);
  }
  delayMicroseconds(dotTime);
  // printing the sspace between the letters
*/
  for (y = 0; y < 12; y++)
  {
    digitalWrite(y + 2, 0);
  }
  delayMicroseconds(letterSpace);

}

void loop()
{
  printLetter (a);
}
