// Code for NodeMCU V3:

// Declaring pins of I/O:
//Input Pins:
#define pin_I0 D3
#define pin_I1 D2
#define pin_I2 D1
#define pin_I3 D0
//Output Pins:
#define pin_O0 D5
#define pin_O1 D6
#define pin_O2 D7
#define pin_O3 D8
// Logical Operators of input:
int I0;
int I1;
int I2;
int I3;

void setup() {
// Pin Mode for Input:
pinMode(pin_I0, INPUT);
pinMode(pin_I1, INPUT);
pinMode(pin_I2, INPUT);
pinMode(pin_I3, INPUT);
// Pin Mode for Output:
pinMode(pin_O0, OUTPUT);
pinMode(pin_O1, OUTPUT);
pinMode(pin_O2, OUTPUT);
pinMode(pin_O3, OUTPUT);
}

void loop() {
// Reading the input pins:


I0 = digitalRead(pin_I0);
I1 = digitalRead(pin_I1);
I2 = digitalRead(pin_I2);
I3 = digitalRead(pin_I3);

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
