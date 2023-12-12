/*
 * stepper.h
 *
 *  Created on: Dec 5, 2023
 *      Author: arthu
 */

#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_


typedef struct Stepper{
	int stepperID;
	int velocity;
	int angularPosition;
	int angularPostionMax;
} Stepper;

extern Stepper* stepper1;
extern Stepper* stepper2;
extern Stepper* stepper3;

void stepper_Init(Stepper *stepper1);


#endif /* INC_STEPPER_H_ */
