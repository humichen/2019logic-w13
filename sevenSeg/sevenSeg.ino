byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 }   // = 9
};
int num = 0;
int button= 9;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
for (int thisLed = 2; thisLed < 9; thisLed++) {
    pinMode(thisLed, OUTPUT); 
  }
  pinMode(button, INPUT);
}
void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte seg = 0; seg < 7; seg++) {
    digitalWrite(pin, seven_seg_digits[digit][seg]);
    pin++;
  }
}
void loop() {
  // put your main code here, to run repeatedly:
    int buttonstate=digitalRead(button);
    if(buttonstate==LOW){
     sevenSegWrite(num); 
     Serial.println(num);
     delay(1000);
     num ++;
     if(num > 9){num = 0;}
      }
     else{num = 0;}
}
