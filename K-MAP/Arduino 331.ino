// Code for Arduino Uno R3:

// Declaring pins of I/O:
//Input Pins: Output Pins:
int pin_I3 = 11; int pin_O3 = 4;
int pin_I2 = 10; int pin_O2 = 5;
int pin_I1 = 9; int pin_O1 = 6;
int pin_I0 = 8; int pin_O0 = 7;

// Logical Operators of input:
int I3 = 0;
int I2 = 0;
int I1 = 0;
int I0 = 0;

void setup() {
// Pin Mode for Input: Pin Mode for Outut:
pinMode(pin_I3, INPUT); pinMode(pin_O3, OUTPUT);
pinMode(pin_I2, INPUT); pinMode(pin_O2, OUTPUT);
pinMode(pin_I1, INPUT); pinMode(pin_O1, OUTPUT);
pinMode(pin_I0, INPUT); pinMode(pin_O0, OUTPUT);
}

void loop() {
// Reading the input pins:
I3 = digitalRead(pin_I3);
I2 = digitalRead(pin_I2);
I1 = digitalRead(pin_I1);
I0 = digitalRead(pin_I0);

// Applying the logical expressions for output:
// For O3=!I3I1!I0+!I3I2I0+I2!I1I0+I3!I1!i0+I3!I2I1
if ( (!I3&&I1&&!I0)||(!I3&&I2&&I0)||(I2&&!I1&&I0)||(I3&&!I1&&!I0)||(I3&&!I2&&I1 )){

digitalWrite(pin_O3, HIGH);
}
else{
digitalWrite(pin_O3, LOW);
}
// For O2= !I2!I1!I0+!I3!I2I0+I2I1I0+I3I2!I1
if ( (!I2&&!I1&&!I0)||(!I3&&!I2&&I0)||(I2&&I1&&I0)||(I3&&I2&&!I1 )){
digitalWrite(pin_O2, HIGH);
}
else{
digitalWrite(pin_O2, LOW);
}
// For O1= !I2I1!I0+!I3I2!I1+!I3I2I0+I3!I1I0
if ( (!I2&&I1&&!I0)||(!I3&&I2&&!I1)||(!I3&&I2&&I0)||(I3&&!I1&&I0) ){
digitalWrite(pin_O1, HIGH);
}
else{
digitalWrite(pin_O1, LOW);
}
// For O0= !I2!I1I0+!I3I1!I0+I3!I2!I1+I3!I1I0
if ( (!I2&&!I1&&I0)||(!I3&&I1&&!I0)||(I3&&!I2&&!I1)||(I3&&!I1&&I0)){
digitalWrite(pin_O0, HIGH);
}
else{
digitalWrite(pin_O0, LOW);
}
}
