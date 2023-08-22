int acPin = 9;
int virgrd = 10;
int analogIn = A0;
double val = 0;
double readVal = 0;
int freq1 = 100;
int freq2 = 10;
double t = 0;
const double pi = 3.1415;
const double fs = 1000; // arduino has a 16MHz clk, meaning the loop takes 1600 processing cycles 
 
void setup() {

    pinMode(acPin, OUTPUT);
    pinMode(virgrd, OUTPUT);
    // pinMode(analogIn, INPUT);
    Serial.begin(9600);

}

void loop() {

    t = millis();
    // val = (127*sin(2*pi*(freq1/fs)*t) + 127*sin(2*pi*(freq2/fs)*t))/2 + 127; // freq/fs discretizes/normalizes the frequency into f/1000 cycles/sample. 2.5V peak AC voltage between pin 9 and 10 
    val = 127*sin(2*pi*(freq1/fs)*t) + 127;
    Serial.print(val);Serial.print(",");
    // why 127? -> analogWrite values range from 0-255 which map from 0 to 5V hence 127 corresponds to 2.5V
    analogWrite(acPin, val);
    analogWrite(virgrd, 127); 

    // this produces a square wave, would need to lowpass on breadboard to generate a sine wave
    readVal = analogRead(analogIn); // values from 0 - 1023, scale by 1/4 to 0 - 255
    Serial.println(readVal/4);

}
