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
#include "menus.h"
#include "keypad.h"

uint16 lightMax = 0;
static gui currentMenu = INITIAL;
static gui oldMenu = INITIAL;

void clearLine(uint8 row);
void drawMenu(gui);

int8 updateMenu(){
    BTN_states press = getButton();
    if (currentMenu == MAIN){
        if (press == DOWN){
            currentMenu = CALIBRATION;
        }
        else if(press == UP){
            currentMenu = RESULTS;
        }
    }
    else if(currentMenu == CALIBRATION){
        if (press == DOWN){
            currentMenu = RESULTS;
        }
        else if(press == UP){
            currentMenu = MAIN;
        }
        else if(press == RIGHT){
            target++;
            oldMenu = INITIAL;
        }
        else if(press == LEFT){
            target--;
            oldMenu = INITIAL;
        }
    }
    else if(currentMenu == RESULTS){
        if (press == DOWN){
            currentMenu = MAIN;
        }
        else if(press == UP){
            currentMenu = CALIBRATION;
        }
    }
    else if(currentMenu == INITIAL){
        currentMenu = MAIN;
    }
    
    drawMenu(currentMenu);
    return 0;
}

void drawMenu(gui menu){
    if (menu == MAIN){
        int16 temp = ADC_GetResult16(0);
        
        if(menu != oldMenu){
            clearLine(0);
            LCD_PrintString("    <MAIN>     ");
        }        

        if (temp > lightMax || menu != oldMenu){
            lightMax = temp;
            clearLine(1);
            LCD_PrintString("Max: ");
            LCD_PrintNumber(lightMax);
        }
    }
    else if(menu == CALIBRATION){
        if(menu != oldMenu){
            clearLine(0);
            LCD_PrintString(" <CALIBRATION>  ");
            clearLine(1);
            LCD_PrintString("target: ");
        }
        LCD_Position(1,8);
        LCD_PrintNumber(target);
    }
    else if(menu == RESULTS){
        if(menu != oldMenu){
            clearLine(0);
            LCD_PrintString("   <RESULTS>    ");
            clearLine(1);
            LCD_PrintString("last timing: ");
        }
        LCD_Position(1,13);
        LCD_PrintNumber(123);
    }
    
    oldMenu = menu;
    CyDelay(15);
}

void clearLine(uint8 row){
    LCD_Position(row,0);
    LCD_PrintString("                ");
    LCD_Position(row,0);
}

/* Main menu:
|Press SW2 to run|
|N=x,avg=16.33 ms|

|      Blip!     |
|       {}       |
*/

/* Calibration menu:
|Press SLCT to   |
|calibrate sensor|

|Put sensor near |
|Fox & press SLCT|

|Calibrating...  |
|                |

|Testing...      |
|                |

|Calibration...  |
|COMPLETE!       |
OR
|Calibration...  |
|FAILURE!        |
*/


/*
|                |
|                |
*/