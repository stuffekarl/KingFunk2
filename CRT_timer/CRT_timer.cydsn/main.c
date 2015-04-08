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

#define CONVERT_TO_ASCII (0x30u)
#define TIMER_MAX 4294967296

enum BTN_states{ UNPRESSED, SELECT, LEFT, DOWN, UP, RIGHT };
volatile uint8 running; //flag - false = 0, true != 0
uint16 V_start;
uint16 V_new;
uint32 time;
uint16 lcdBtnOld;
volatile enum BTN_states BTN;

//Prototypes
CY_ISR_PROTO(sw_int_ISR);
void puts_measurement(uint32 time);
void print_measurement(uint32 time);
int8 updateBTN(void);

CY_ISR(sw_int_ISR){
    char temp[60];
    running = 1;
    V_start = ADC_GetResult16(0);
    sprintf(temp, "Starting new measurement, current voltage: %d mV\n\r", ADC_CountsTo_mVolts(0, V_start));
    LCD_ClearDisplay();
    LCD_PrintString("SW2 pressed");
    UART_1_UartPutString(temp);
    Timer_1_WriteCounter(0);
    Timer_1_Start();
    B_press_Write(1);
}

int main(){
    int16 lightMax = -1;
    
    Timer_1_Start();
    UART_1_Start();
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
    

    UART_1_UartPutString("CRT_timer initialized..\n\r");
    CyGlobalIntEnable;
    
    while(1){
        CyDelay(50);
        if (running){
            V_new = ADC_GetResult16(0);
             if(V_new > 1024){
                time = TIMER_MAX - Timer_1_ReadCounter();
                Timer_1_Stop();
                running = 0;
                B_press_Write(0);
                puts_measurement(time);
                print_measurement(time);
            }
        }
        else{
            int16 temp = ADC_GetResult16(0);
            if (temp > lightMax)
                lightMax = temp;
            LCD_Position(0,0);
            LCD_PrintString("                ");
            LCD_Position(0,0);
            LCD_PrintNumber(temp);
            LCD_Position(0,5);
            LCD_PrintString("max: ");
            LCD_PrintNumber(lightMax);
            if (updateBTN()){
                if (BTN == SELECT){
                    LCD_Position(1,0);
                    LCD_PrintString("                ");
                    LCD_Position(1,0);
                    LCD_PrintString("Select pressed");
                }
                else if(BTN == LEFT){
                    LCD_Position(1,0);
                    LCD_PrintString("                ");
                    LCD_Position(1,0);
                    LCD_PrintString("Left pressed");
                }
                else if(BTN == RIGHT){
                    LCD_Position(1,0);
                    LCD_PrintString("                ");
                    LCD_Position(1,0);
                    LCD_PrintString("Right pressed");
                }
                else if(BTN == UP){
                    LCD_Position(1,0);
                    LCD_PrintString("                ");
                    LCD_Position(1,0);
                    LCD_PrintString("Up pressed");
                }
                else if(BTN == DOWN){
                    LCD_Position(1,0);
                    LCD_PrintString("                ");
                    LCD_Position(1,0);
                    LCD_PrintString("Down pressed");
                }
            }
        }
    }
}

void puts_measurement(uint32 time){
    uint64 time_us = ((uint64)time * 125) / 3000;
    UART_1_UartPutString("Timer stopped, measured time was: ");
    UART_1_UartPutChar(time/1000000000u + CONVERT_TO_ASCII);
    time %= 1000000000;
    UART_1_UartPutChar(time/100000000u + CONVERT_TO_ASCII);
    time %= 100000000;
    UART_1_UartPutChar(time/10000000u + CONVERT_TO_ASCII);
    time %= 10000000;
    UART_1_UartPutChar(time/1000000u + CONVERT_TO_ASCII);
    time %= 1000000;
    UART_1_UartPutChar(time/100000u + CONVERT_TO_ASCII);
    time %= 100000;
    UART_1_UartPutChar(time/10000u + CONVERT_TO_ASCII);
    time %= 10000;
    UART_1_UartPutChar(time/1000u + CONVERT_TO_ASCII);
    time %= 1000;
    UART_1_UartPutChar(time/100u + CONVERT_TO_ASCII);
    time %= 100;
    UART_1_UartPutChar(time/10u + CONVERT_TO_ASCII);
    time %= 10;
    UART_1_UartPutChar(time + CONVERT_TO_ASCII);
    UART_1_UartPutString(" counts or ");
    UART_1_UartPutChar(time_us/100000000u + CONVERT_TO_ASCII);
    time_us %= 100000000;
    UART_1_UartPutChar(time_us/10000000u + CONVERT_TO_ASCII);
    time_us %= 10000000;
    UART_1_UartPutChar(time_us/1000000u + CONVERT_TO_ASCII);
    time_us %= 1000000;
    UART_1_UartPutChar(',');
    UART_1_UartPutChar(time_us/100000u + CONVERT_TO_ASCII);
    time_us %= 100000;
    UART_1_UartPutChar(time_us/10000u + CONVERT_TO_ASCII);
    time_us %= 10000;
    UART_1_UartPutChar(time_us/1000u + CONVERT_TO_ASCII);
    time_us %= 1000;
    UART_1_UartPutChar(',');
    UART_1_UartPutChar(time_us/100u + CONVERT_TO_ASCII);
    time_us %= 100;
    UART_1_UartPutChar(time_us/10u + CONVERT_TO_ASCII);
    time_us %= 10;
    UART_1_UartPutChar(time_us + CONVERT_TO_ASCII);
    UART_1_UartPutString(" us.\n\r");
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

int8 updateBTN(void){
    uint16 temp = ADC_GetResult16(1); //A0
    if (lcdBtnOld != temp){
        if (temp == 0xFFFF || temp <= 5)
            BTN = RIGHT;
        else if(temp <= 20)
            BTN = UP;
        else if(temp <= 40)
            BTN = DOWN;
        else if(temp <= 60)
            BTN = LEFT;
        else if(temp <= 100)
            BTN = SELECT;
        else
            BTN = UNPRESSED;
        lcdBtnOld = temp;
        return 1;
    }
    return 0;
}