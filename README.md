# A stepper example

## Introduction

A stepper motor is a brushless DC motor that rotates in "angular steps", usually
1.8 degree per full step (200 steps = 360degrees = 1 turn). Most common stepper
motors have 2 separate coils (labeled A and B) and 4 wires (A+, A-, B+. B-) on
which voltage is to be applied. Applying voltage to one of the coils will lock
the motor onto the next (or previous) step depending on the polarity. To
continue with the rotation, voltage has to be applied onto the other coil with
the right polarity and timing.

A driver board tries to simplify the task of controlling a stepper by
abstracting the voltage switching and timing. The driver is connected to the 4
wires of the stepper and to a power supply (PSU) for the motor on one side. On
the other it connects to a microcontroller (MCU) and communicates via logic
pulses (usually 3-6 V ) on specific pins. Most drivers have pins to make a step
(STEP), set the direction (DIR) of the rotation as well as various power modes
(RESET, SLEEP, ENABLE) and micro steeping controls (e.g. MS1, MS2, MS3). The
driver board is connected to the MCU board's VDD and GND.

The MCU should some digital pins as OUTPUT, then set most to HIGH or LOW, then
issue a train of positive pulses onto the STEP pin of the driver with a
specific timing and the stepper should start turning.

## Some prerequisites and warnings

- Due to the high inductance of the circuit, no wire connections should be
  broken or made while the PSU is on, or it may burn some of the elements
  irreversibly! Note that there is often a large filter output capacitor on the
  PSU, so you need to wait some seconds until it is discharged! It might be a
  good idea to add a tiny indicator bulb across the PSU to show when it is still
  powered.
- Some drivers (e.g. A4988) have a limiting circuit that must be matched to the
  stepper maximum rated current by rotating a trim-pot. Failure to do so may
  quickly burn the stepper or the driver.
- Make always sure that no component heats above their rated values due to large
  current.
- Physically overloading the shaft of the stepper can easily damage it.
