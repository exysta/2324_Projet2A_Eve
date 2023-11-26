/*
 * crc.h
 *
 *  Created on: Nov 21, 2023
 *      Author: Lucas
 */

#ifndef INC_CRC_H_
#define INC_CRC_H_

unsigned short update_crc(unsigned short crc_accum, unsigned char *data_blk_ptr, unsigned short data_blk_size);
#endif /* INC_CRC_H_ */
