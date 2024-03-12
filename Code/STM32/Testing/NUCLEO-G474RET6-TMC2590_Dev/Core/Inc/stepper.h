/*
 * stepper.h
 *
 *  Created on: Dec 5, 2023
 *      Author: arthur,
 */

#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_


typedef struct Stepper{
	int stepperID;
	int velocity;
	int angularPosition;
	int angularPositionMax;
} Stepper;




void stepper_Init(Stepper * stepper);


#endif /* INC_STEPPER_H_ */
