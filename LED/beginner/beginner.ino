/*
 * Author : Del
 * Instructions: 
 * 1) Upload the code
 * 2) increase the time taken to better see the effects.
 */
int time_taken = 25;
void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
// or another way
for (int i = 2; i < 14 ; i++){
  pinMode(i,OUTPUT);
}


}

void loop() {
for (int y =2; y<14 ; y++){                  // begins turning on leds for 1 sec from pin 2 to pin 9
  digitalWrite(y,HIGH);
  delay(time_taken);
  digitalWrite(y,LOW); 
}

for (int x = 14; x>2 ; x--){                              // begins turning on leds for 1 sec from pin 9 to pin 2
  digitalWrite(x,HIGH);
  delay(time_taken);
  digitalWrite(x,LOW);
}
}
