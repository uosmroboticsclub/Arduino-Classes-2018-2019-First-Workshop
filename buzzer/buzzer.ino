/*
 * Author : Chia Tze Hank
 * Instructions: 
 * 1) Upload the code
 * 2) Press the programmable button, right below the RESET Button,HOLD the button
 * 3) A different melody will play
*/

#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978

#define melodyPin 8

// Nokia Ringtone –> Melody
int melody1[] = {NOTE_C6, NOTE_C6, NOTE_C6, 0, NOTE_C6, NOTE_C6, 0, NOTE_C6, NOTE_C6, NOTE_C6};

// Main tempo of ‘Nokia Ringtone’
int tempo1[] = {16, 16, 16, 8, 8, 8, 8, 16, 16, 16};

// Depressing Ringtone –> Melody
int melody2[] = {NOTE_FS3, NOTE_F3, NOTE_FS3, NOTE_D3, NOTE_CS3};

// Main tempo of ‘Depressing Ringtone’
int tempo2[] = {8, 8, 8, 8, 1};

// Happy Birthday Ringtone -> Melody
int melody3[] = {NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4};

// Main tempo of ‘Happy Birthday’
int tempo3[] = {8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 4, 4, 8, 8, 4, 4, 4, 2};

void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(2, INPUT_PULLUP); //enable pull up on programmable button
}

void loop()
{
  int sensorVal = digitalRead(2); //pin 2 is programmable button
  if(sensorVal==LOW)
  {
    sing(1);
  }
  else
  {
    sing(2);
  }
}

void sing(int s)
{
  if (s == 1)
  {
    int size = sizeof(melody1) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++)
    {
      int noteDuration = 1000 / tempo1[thisNote];
      buzz(melodyPin, melody1[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(melodyPin, 0, noteDuration);
    }
  }

  if (s == 2)
  {
    int size = sizeof(melody2) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++)
    {
      int noteDuration = 1000 / tempo2[thisNote];
      buzz(melodyPin, melody2[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(melodyPin, 0, noteDuration);
    }
  }

  if (s == 3)
  {
    int size = sizeof(melody3) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++)
    {
      int noteDuration = 1000 / tempo3[thisNote];
      buzz(melodyPin, melody3[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(melodyPin, 0, noteDuration);
    }
  }

}

void buzz(int targetPin, long frequency, long length)
{
  digitalWrite(9, HIGH);
  long delayValue = 1000000 / frequency / 2.5;
  long numCycles = frequency * length / 1000;
  for (long i = 0; i < numCycles; i++)
  {
    digitalWrite(targetPin, HIGH);
    delayMicroseconds(delayValue);
    digitalWrite(targetPin, LOW);
    delayMicroseconds(delayValue);
  }
  digitalWrite(9, LOW);
}
