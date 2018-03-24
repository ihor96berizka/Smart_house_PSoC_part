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

void InitializeSystem(void)
{
    /* Enable Global Interrupt Mask */
    CyGlobalIntEnable;
    /* Start BLE stack and register the event callback function. */
    CyBle_Start(GeneralEventHandler);
    /* Start PrISM modules for LED control */
    PrISM_1_Start();
    PrISM_2_Start();
    /* Switch off the RGB LEDs through PrISM modules */
    PrISM_1_WritePulse0(RGB_LED_OFF);
    PrISM_1_WritePulse1(RGB_LED_OFF);
    PrISM_2_WritePulse0(RGB_LED_OFF);
    /* Set Drive modes of the output pins to Strong */
    RED_SetDriveMode(RED_DM_STRONG);
    GREEN_SetDriveMode(GREEN_DM_STRONG);
    BLUE_SetDriveMode(BLUE_DM_STRONG);
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    InitializeSystem();
    
    for(;;)
    {
       /* Process BLE Events. This generates events in the callback function */
        CyBle_ProcessEvents();
    }
}

/* [] END OF FILE */
