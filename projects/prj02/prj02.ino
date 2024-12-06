
//driver_signal MCU_pin 
//      VDD     3.3V
#define STEP    8
#define DIR     7
//      GND     GND
long int ppulse = 500;
long int npulse = 1500;
int direction = LOW;

void setup()
{
	Serial.begin(115200);
  Serial.println("starting...");

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); delay(1000); digitalWrite(LED_BUILTIN, LOW); //wait 1s before initializing

	pinMode(STEP,	OUTPUT); digitalWrite(STEP,	LOW);
	pinMode(DIR,	OUTPUT); digitalWrite(DIR,	direction);
	
  Serial.println("setup completed.");
  digitalWrite(LED_BUILTIN, HIGH); delay(2000); digitalWrite(LED_BUILTIN, LOW); //wait 2s before starting the loop
  Serial.println("DIR\tppulse\tnpulse");
}

void loop()
{
  Serial.print(direction); Serial.print("\t");
  Serial.print(ppulse); Serial.print("\t");
  Serial.println(npulse);

  digitalWrite(DIR, direction); delayMicroseconds(npulse);
  Serial.println("At start position");
  delay(5000);

  Serial.println("IGNITION!");
  for (int i=0; i<20; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(ppulse);
	  digitalWrite(STEP, LOW);
	  delayMicroseconds(npulse);
  }
  for (int i=0; i<30; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(ppulse);
	  digitalWrite(STEP, LOW);
	  delayMicroseconds(npulse*3);
  }
  Serial.println("...burning?...");
  delay(2000);

  Serial.println("down to the water");
	for (int i=0; i<50; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(ppulse);
	  digitalWrite(STEP, LOW);
	  delayMicroseconds(npulse*4);
  }
  delay(5000);

  Serial.println("finished. prepare next try.");

	for (int i=0; i<50; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(ppulse);
	  digitalWrite(STEP, LOW);
	  delayMicroseconds(npulse*2);
  }
  Serial.println("You have 10s to change the match...");
  delay(10000);
  Serial.println("Going back to start position...");
	for (int i=0; i<50; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(ppulse);
	  digitalWrite(STEP, LOW);
	  delayMicroseconds(npulse*2);
  }
  delay(10000);
//npulse += 100;
}
