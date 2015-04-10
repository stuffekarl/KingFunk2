/* ========================================
 *
 * Copyright Kristian Thomsen, 2015
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>
#include "menus.h"
#include "keypad.h"

#define CONVERT_TO_ASCII (0x30u)
#define TIMER_MAX 4294967296
//#define debugging1 //Show time for checking result from ADC
#define debugging2 //Show time for starting the timer

volatile uint8 running; //flag - false = 0, true != 0
uint16 V_new;
uint32 time;

//Prototypes
CY_ISR_PROTO(sw_int_ISR);
void print_measurement(uint32 time);
int8 updateBTN(void);

CY_ISR(sw_int_ISR){
    running = 1;
    LCD_ClearDisplay();
    LCD_PrintString("SW2 pressed");
    Timer_1_WriteCounter(0);
    B_press_Write(1);
    #ifdef debugging2
        Test_pin_Write(1);
    #endif
    
}

int main(){
    target = 30;
    Timer_1_Start();
    sw_int_StartEx(sw_int_ISR);
    B_press_Write(0);
    Opamp_Start();
    ADC_Start();
    ADC_StartConvert();
    LCD_Start();
    LCD_Position(0,0);
    LCD_PrintString("Initialized..");
    LCD_Position(1,7);
    LCD_PutChar(LCD_CUSTOM_0);
    LCD_PutChar(LCD_CUSTOM_1);
    LCD_PutChar(LCD_CUSTOM_2);
    LCD_PutChar(LCD_CUSTOM_4);
    LCD_PutChar(LCD_CUSTOM_5);
    
    CyGlobalIntEnable;
    
    while(1){
        if (running){
            #ifdef debugging1
                Test_pin_Write(1);
            #endif
            if(ADC_GetResult16(0) > target){
                time = Timer_1_ReadCounter();
                #ifdef debugging2
                    Test_pin_Write(0);
                #endif
                time = TIMER_MAX - time;
                Timer_1_Stop();
                running = 0;
                B_press_Write(0);
                print_measurement(time);
            }
            #ifdef debugging1
                Test_pin_Write(0);
            #endif
        }
        else{
            updateMenu();
        }
    }
}

void print_measurement(uint32 time){
    uint64 time_us = ((uint64)time * 125) / 3000;
    LCD_Position(1,0);
    LCD_PrintString("                ");
    LCD_Position(1,0);
    LCD_PrintString("t: ");
    LCD_PutChar(time_us/100000000u + CONVERT_TO_ASCII);
    time_us %= 100000000;
    LCD_PutChar(time_us/10000000u + CONVERT_TO_ASCII);
    time_us %= 10000000;
    LCD_PutChar(time_us/1000000u + CONVERT_TO_ASCII);
    time_us %= 1000000;
    LCD_PutChar(',');
    LCD_PutChar(time_us/100000u + CONVERT_TO_ASCII);
    time_us %= 100000;
    LCD_PutChar(time_us/10000u + CONVERT_TO_ASCII);
    time_us %= 10000;
    LCD_PutChar(time_us/1000u + CONVERT_TO_ASCII);
    time_us %= 1000;
    LCD_PutChar(',');
    LCD_PutChar(time_us/100u + CONVERT_TO_ASCII);
    time_us %= 100;
    LCD_PutChar(time_us/10u + CONVERT_TO_ASCII);
    time_us %= 10;
    LCD_PutChar(time_us + CONVERT_TO_ASCII);
    LCD_PrintString("us");
}