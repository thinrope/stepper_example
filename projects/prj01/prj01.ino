
//driver_signal Teensy_pin 
//      VDD     3.3V
#define MS1     2
#define MS2     3
#define MS3     4
#define SLEEP   5
#define STEP    6
#define DIR     7
#define ENABLE  8
#define RESET   9
//      GND     GND

void setup()
{
	pinMode(MS1,	OUTPUT); digitalWrite(MS1,	LOW);
	pinMode(MS2,	OUTPUT); digitalWrite(MS2,	LOW);
	pinMode(MS3,	OUTPUT); digitalWrite(MS3,	LOW);
	pinMode(SLEEP,	OUTPUT); digitalWrite(SLEEP,	HIGH);
	pinMode(STEP,	OUTPUT); digitalWrite(STEP,	LOW);
	pinMode(DIR,	OUTPUT); digitalWrite(DIR,	LOW);
	pinMode(ENABLE,	OUTPUT); digitalWrite(ENABLE,	LOW);
	pinMode(RESET,	OUTPUT); digitalWrite(RESET,	HIGH);
	
	//pinMode(13, OUTPUT);      digitalWrite(13, LOW);
}

void loop()
{
	digitalWrite(STEP, HIGH);
	delayMicroseconds(2);   // 1 us by dataasheet
	digitalWrite(STEP, LOW);
	delay(995); // TBC
}
