/*
 * send_dynamixel.h
 *
 *  Created on: Nov 23, 2023
 *      Author: Lucas
 */

#ifndef INC_SEND_DYNAMIXEL_H_
#define INC_SEND_DYNAMIXEL_H_

void send_dynamixel(uint8_t* instruction, size_t array_size);
void ToggleLed(int status);

void RotateToPosition(float angleInDeg);

#endif /* INC_SEND_DYNAMIXEL_H_ */
