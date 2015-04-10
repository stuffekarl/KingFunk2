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

/* [] END OF FILE */

#include <project.h>
#include "keypad.h"

BTN_states btn_old = UNPRESSED;

BTN_states getButton(void){
    BTN_states btn;
    uint16 temp = ADC_GetResult16(1); //A0
    
    if (temp == 0xFFFF || temp <= 5)
        btn = RIGHT;
    else if(temp <= 20)
        btn = UP;
    else if(temp <= 40)
        btn = DOWN;
    else if(temp <= 60)
        btn = LEFT;
    else if(temp <= 100)
        btn = SELECT;
    else
        btn = UNPRESSED;
    
    if (btn_old != btn)
        return btn_old = btn;
    else
        return UNPRESSED;
}