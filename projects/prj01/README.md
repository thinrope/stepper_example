# prj01

## Components:
- stepper: Two Trees 17HS4401-22B (NEMA17, 6L-4W, 12V/1.5A, 2-phase, 0.14Nm)
- driver: Olimex BB-A4983 (Allegro A4983)
- MCU: Teensy 3.1
- PSU: Seanen KSA-24W-120200VE (12V/2.0A)

## Open questions
1. Is the PSU 12v/2A powerfull enough, or do I need 12V/3A (2 coils x 1.5A)?
2. What is the current limit of the driver, given that sense resistors R4/R5 are 0 Ω?

## Schematic
```
             +-----+                                                             
     +-------| USB |----------+                                                  
     |       +-----+          |                                                  
  +----[x]GND          Vin[ ] |                                                  
  |  |                        |                                                  
  |  | [ ]0       [ ] AGND[ ] |                                                  
  |  |                        | brown                                            
  |  | [ ]1           3.3V[x]----------------+                                   
  |  |                        |              |                                   
  |  | [ ]2       [ ]   23[ ] |              | +---------------+        -----    
  |  |                        |              | |               | red   /     \   
  |  | [ ]3       [ ]   22[ ] |              +---[x]1    B2[x]---------|  S  |   
  |  |                        | white          |               | black |  T  |   
  |  | [ ]4       [ ]   21[x]--------------------[x]2    A2[x]---------|  E  |   
  |  |                        | gray           |               |       |  P  |   
  |  | [ ]5             20[x]--------------------[x]3          |       |  P  |   
  |  |                        | purple         |               | blue  |  E  |   
  |  | [ ]6             19[x]--------------------[x]4    A1[x]---------|  R  |   
  |  |                        | blue           |               | green |     |   
  |  | [ ]7             18[x]--------------------[x]5    B1[x]---------\     /   
  |  |                        | green          |               |        -----    
  |  | [ ]8             17[x]--------------------[x]6          |                 
  |  |                        | yellow         |               | black +------+  
  |  | [ ]9    M C U    16[x]--------------------[x]7  PWR-[x]---------|      |  
  |  |                        | orange         |               | red   |  PSU |  
  |  | [ ]10            15[x]--------------------[x]8  PWR+[x]---------|      |  
  |  |                        | red            |               |       +------+  
  |  | [ ]11            14[x]--------------------[x]9          |                 
  |  |                        |                |               |                 
  |  | [ ]12 [][][][][] 13[ ] |              +---[x]10         |                 
  |  |                        |              | |               |                 
  |  +------------------------+              | | [ ]           |                 
  |                             black        | | [ ]   DRIVER  |                 
  +------------------------------------------+ +---------------+                 

```                                                                                 

## Setup
```
//      signal  pin     //  STATE
//      VDD     3.3V    //  HIGH
#define MS1     2       //  LOW
#define MS2     3       //  LOW
#define MS3     4       //  LOW
#define SLEEP   5       //  HIGH
#define STEP    6       //  LOW
#define DIR     7       //  LOW for CW
#define ENABLE  8       //  LOW
#define RESET   9       //  HIGH
//      GND     GND     //  LOW

void setup()
{
	pinMode(MS1, OUTPUT);     digitalWrite(MS1, LOW);
	pinMode(MS2, OUTPUT);     digitalWrite(MS2, LOW);
	pinMode(MS3, OUTPUT);     digitalWrite(MS3, LOW);
	pinMode(SLEEP, OUTPUT);   digitalWrite(SLEEP, HIGH);
	pinMode(STEP, OUTPUT);    digitalWrite(STEP, LOW);
	pinMode(DIR, OUTPUT);     digitalWrite(DIR, LOW);
	pinMode(ENABLE, OUTPUT);  digitalWrite(ENABLE, LOW);
	pinMode(RESET, OUTPUT);   digitalWrite(RESET, HIGH);
	
	//pinMode(13, OUTPUT);      digitalWrite(13, LOW);
}
```

## loop to make 1 step each second
```
void loop()
{
    digitalWrite(STEP, HIGH);
    delayMicroseconds(2);   // 1 us by dataasheet
    digitalWrite(STEP, LOW);
    delay(995); // TBC
}
```
