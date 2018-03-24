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
#include "project.h"

#include "led.h"
#include "main.h"
#include "BLE_Process.h"

void UpdateRGBLED(uint8* ledData, uint8 len)
{
    /* Local variables to store calculated color components */
    uint8 calc_red;
    uint8 calc_green;
    uint8 calc_blue;
    /* Check if the array has length equal to expected length for
    * RGB LED data */
    if(len == RGB_CHAR_DATA_LEN)
    {
        /* True color to be displayed is calculated on basis of color
        * and intensity value received */
        calc_red = (uint8)
        (((uint16)ledData[RED_INDEX]*ledData[INTENSITY_INDEX])/RGB_LED_MAX_VAL);
        calc_green = (uint8)
        (((uint16)ledData[GREEN_INDEX]*ledData[INTENSITY_INDEX])/RGB_LED_MAX_VAL);
        calc_blue = (uint8)
        (((uint16)ledData[BLUE_INDEX]*ledData[INTENSITY_INDEX])/RGB_LED_MAX_VAL);
        /* Update the density value of the PrISM module */
        PrISM_1_WritePulse0(RGB_LED_MAX_VAL - calc_red);
        PrISM_1_WritePulse1(RGB_LED_MAX_VAL - calc_green);
        PrISM_2_WritePulse0(RGB_LED_MAX_VAL - calc_blue);
    }
}
void UpdateRGBcharacteristic(uint8* ledData, uint8 len, uint16 attrHandle)
{
    /* 'rgbHandle' stores RGB control data parameters */
    CYBLE_GATT_HANDLE_VALUE_PAIR_T rgbHandle;
    /* Update RGB control handle with new values */
    rgbHandle.attrHandle = attrHandle;
    rgbHandle.value.val = ledData;
    rgbHandle.value.len = len;
    /* Update the RGB LED attribute value. This will allow
    * Client device to read the existing color values over
    * RGB LED characteristic */
     CyBle_GattsWriteAttributeValue(&rgbHandle,
    FALSE,
    &cyBle_connHandle,
    CYBLE_GATT_DB_PEER_INITIATED);
}
/* [] END OF FILE */
