
//driver_signal Teensy_pin 
//      VDD     3.3V
#define MS1     21
#define MS2     20
#define MS3     19
#define SLEEP   18
#define STEP    17
#define DIR     16
#define ENABLE  15
#define RESET   14
//      GND     GND

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
  for (int i=0; i < 3; i++) // blink 3 times
  {
    digitalWrite(LED_BUILTIN, HIGH); delay(50); digitalWrite(LED_BUILTIN, LOW); delay(150);
  }
  digitalWrite(LED_BUILTIN, HIGH); delay(1000); digitalWrite(LED_BUILTIN, LOW); //wait 1s before initializing

	pinMode(MS1,	OUTPUT); digitalWrite(MS1,	LOW);
	pinMode(MS2,	OUTPUT); digitalWrite(MS2,	LOW);
	pinMode(MS3,	OUTPUT); digitalWrite(MS3,	LOW);
	pinMode(SLEEP,	OUTPUT); digitalWrite(SLEEP,	LOW);
	pinMode(STEP,	OUTPUT); digitalWrite(STEP,	LOW);
	pinMode(DIR,	OUTPUT); digitalWrite(DIR,	LOW);
	pinMode(ENABLE,	OUTPUT); digitalWrite(ENABLE,	LOW);
	pinMode(RESET,	OUTPUT); digitalWrite(RESET,	HIGH);
	
  for (int i=0; i < 3; i++) // blink 3 times slowly
  {
    digitalWrite(LED_BUILTIN, HIGH); delay(200); digitalWrite(LED_BUILTIN, LOW); delay(800);
  }
  digitalWrite(LED_BUILTIN, HIGH); delay(2000); digitalWrite(LED_BUILTIN, LOW); //wait 2s before starting the loop
  digitalWrite(SLEEP, HIGH); delay(2);
}

void loop()
{
	digitalWrite(STEP, HIGH);
	delayMicroseconds(10);   // 1 us by dataasheet
	digitalWrite(STEP, LOW);
	delay(999); // TBC
}
