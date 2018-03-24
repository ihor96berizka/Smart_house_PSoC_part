/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef _LED_H
#define _LED_H

#include "project.h"
    
/* LED Color and status related Macros */
#define RGB_LED_MAX_VAL 0xFF
#define RGB_LED_OFF 0xFF
#define RGB_LED_ON 0x00

/* Index values in array where respective color coordinates
* are saved */
#define RED_INDEX 0x00
#define GREEN_INDEX 0x01
#define BLUE_INDEX 0x02
#define INTENSITY_INDEX 0x03

void UpdateRGBcharacteristic(uint8* ledData, uint8 len, uint16 attrHandle);
void UpdateRGBLED(uint8* ledData, uint8 len);
#endif
/* [] END OF FILE */
