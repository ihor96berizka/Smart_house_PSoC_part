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

#include "BLE_Process.h"

void GeneralEventHandler(uint32 event, void * eventParam)
{
    /* Structure to store data written by Client */
    CYBLE_GATTS_WRITE_REQ_PARAM_T *wrReqParam;
    /* 'RGBledData[]' is an array to store 4 bytes of RGB LED data*/
    uint8 RGBledData[RGB_CHAR_DATA_LEN];
    switch(event)
     {
        case CYBLE_EVT_STACK_ON:
        /* This event is generated when BLE stack is ON */
        CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
        break;
        
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
        /* This event is generated at GAP disconnection. */
        /* Reset the color values*/
        RGBledData[RED_INDEX] = FALSE;
        RGBledData[GREEN_INDEX] = FALSE;
        RGBledData[BLUE_INDEX] = FALSE;
        RGBledData[INTENSITY_INDEX] = FALSE;
        /* Switch off LEDs */
        UpdateRGBLED(RGBledData, sizeof(RGBledData));
        /* Register the new color in GATT DB*/
        UpdateRGBcharacteristic(RGBledData,
        sizeof(RGBledData),
        CYBLE_RGB_LED_RGB_LED_CONTROL_CHAR_HANDLE);

        CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
        
        break;
        
        case CYBLE_EVT_GATTS_WRITE_REQ:
        /* This event is generated when the connected Central */
        /* device sends a Write request. */
        /* The parameter ‘eventParam’ contains the data written */
        wrReqParam = (CYBLE_GATTS_WRITE_REQ_PARAM_T *) eventParam;
        /* If the attribute handle of the characteristic written to
        * is equal to that of RGB_LED characteristic, then extract
        * the RGB LED data */
        if(CYBLE_RGB_LED_RGB_LED_CONTROL_CHAR_HANDLE ==
        wrReqParam->handleValPair.attrHandle)
        {
            /* Store RGB LED data in local array */
             RGBledData[RED_INDEX] =
             wrReqParam->handleValPair.value.val[RED_INDEX];
             RGBledData[GREEN_INDEX] =
             wrReqParam->handleValPair.value.val[GREEN_INDEX];
             RGBledData[BLUE_INDEX] =
             wrReqParam->handleValPair.value.val[BLUE_INDEX];
             RGBledData[INTENSITY_INDEX] =
             wrReqParam->handleValPair.value.val[INTENSITY_INDEX];
             UpdateRGBLED(RGBledData, sizeof(RGBledData));
            /* Update the GATT DB for RGB LED read characteristics*/
             UpdateRGBcharacteristic(RGBledData,
             sizeof(RGBledData),
             CYBLE_RGB_LED_RGB_LED_CONTROL_CHAR_HANDLE);
        }
        CyBle_GattsWriteRsp(cyBle_connHandle);
        break;

        default:
        break;
    }
}
/* [] END OF FILE */
