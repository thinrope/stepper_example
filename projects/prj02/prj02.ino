
//driver_signal MCU_pin 
//      VDD     3.3V
#define STEP    8
#define DIR     9
//      GND     GND
#define BTN1    12
// LED_BUILTIN  13

long int ppulse = 20;
long int npulse = 2000;
int direction = LOW;

boolean btn1_prev_state = LOW;
int experiment_no = 0;

void setup()
{
	Serial.begin(115200);
  Serial.println("\n\n\n\n\n\n===============================================");
  
  pinMode(BTN1, INPUT);
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

	pinMode(STEP,	OUTPUT); digitalWrite(STEP,	LOW);
	pinMode(DIR,	OUTPUT); digitalWrite(DIR,	direction);
	
  Serial.printf("Setup completed. Using %d/%d (in us) pulses.\n", ppulse, npulse);
}

void loop()
{
  boolean btn1_state = digitalRead(BTN1);
  if (btn1_state == HIGH && btn1_prev_state == LOW)
  {
    delay (100);
    Serial.println("NOTE: BTN1 pressed!");
    ignition();
  }
  btn1_prev_state = btn1_state;
}

void rotate()
{
  for (int i=0; i<200; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(ppulse);
	  digitalWrite(STEP, LOW);
	  delayMicroseconds(npulse);
  }
}

void ignition()
{
  experiment_no++;
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.printf("===|experiement %02d|===\n", experiment_no);

  digitalWrite(DIR, direction); delayMicroseconds(npulse);

  Serial.printf("\tExperiment %02d, step1: lighting\n", experiment_no);
  for (int i=0; i<20; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(ppulse);
	  digitalWrite(STEP, LOW);
	  delayMicroseconds(npulse);
  }

  Serial.printf("\tExperiment %02d, step2: moving to the side\n", experiment_no);
  for (int i=0; i<30; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(ppulse);
	  digitalWrite(STEP, LOW);
	  delayMicroseconds(npulse*2);
  }

  Serial.printf("\tExperiment %02d, step3: burning\n", experiment_no);
  delay(2000);

  Serial.printf("\tExperiment %02d, step4: down into the water\n", experiment_no);
	for (int i=0; i<50; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(ppulse);
	  digitalWrite(STEP, LOW);
	  delayMicroseconds(npulse*2);
  }
  delay(5000);

  Serial.printf("\tExperiment %02d, step5: out of the water\n", experiment_no);
	for (int i=0; i<50; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(ppulse);
	  digitalWrite(STEP, LOW);
	  delayMicroseconds(npulse*2);
  }
  Serial.printf("===|experiement %02d finished|===\n", experiment_no);
  Serial.println("Change the match, position the arrow and press the button!");
  blink_fast(5);
  digitalWrite(LED_BUILTIN, LOW);
}

void blink_slow(int times)
{
  digitalWrite(LED_BUILTIN, LOW);
  for (int i=0; i<times; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH); delay(500);
    digitalWrite(LED_BUILTIN, LOW); delay(500);
  }
}

void blink_fast(int times)
{
  digitalWrite(LED_BUILTIN, LOW);
  for (int i=0; i<times; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH); delay(100);
    digitalWrite(LED_BUILTIN, LOW); delay(100);
  }
}

