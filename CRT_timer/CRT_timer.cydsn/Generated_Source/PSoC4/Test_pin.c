/*******************************************************************************
* File Name: Test_pin.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Test_pin.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Test_pin_PC =   (Test_pin_PC & \
                                (uint32)(~(uint32)(Test_pin_DRIVE_MODE_IND_MASK << (Test_pin_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Test_pin_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Test_pin_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Test_pin_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Test_pin_DR & (uint8)(~Test_pin_MASK));
    drVal = (drVal | ((uint8)(value << Test_pin_SHIFT) & Test_pin_MASK));
    Test_pin_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Test_pin_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Test_pin_DM_STRONG     Strong Drive 
*  Test_pin_DM_OD_HI      Open Drain, Drives High 
*  Test_pin_DM_OD_LO      Open Drain, Drives Low 
*  Test_pin_DM_RES_UP     Resistive Pull Up 
*  Test_pin_DM_RES_DWN    Resistive Pull Down 
*  Test_pin_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Test_pin_DM_DIG_HIZ    High Impedance Digital 
*  Test_pin_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Test_pin_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Test_pin__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Test_pin_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Test_pin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Test_pin_Read(void) 
{
    return (uint8)((Test_pin_PS & Test_pin_MASK) >> Test_pin_SHIFT);
}


/*******************************************************************************
* Function Name: Test_pin_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Test_pin_ReadDataReg(void) 
{
    return (uint8)((Test_pin_DR & Test_pin_MASK) >> Test_pin_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Test_pin_INTSTAT) 

    /*******************************************************************************
    * Function Name: Test_pin_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Test_pin_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Test_pin_INTSTAT & Test_pin_MASK);
		Test_pin_INTSTAT = maskedStatus;
        return maskedStatus >> Test_pin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
