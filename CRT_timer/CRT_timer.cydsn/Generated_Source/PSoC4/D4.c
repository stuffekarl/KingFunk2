/*******************************************************************************
* File Name: D4.c  
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
#include "D4.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        D4_PC =   (D4_PC & \
                                (uint32)(~(uint32)(D4_DRIVE_MODE_IND_MASK << (D4_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (D4_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: D4_Write
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
void D4_Write(uint8 value) 
{
    uint8 drVal = (uint8)(D4_DR & (uint8)(~D4_MASK));
    drVal = (drVal | ((uint8)(value << D4_SHIFT) & D4_MASK));
    D4_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: D4_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  D4_DM_STRONG     Strong Drive 
*  D4_DM_OD_HI      Open Drain, Drives High 
*  D4_DM_OD_LO      Open Drain, Drives Low 
*  D4_DM_RES_UP     Resistive Pull Up 
*  D4_DM_RES_DWN    Resistive Pull Down 
*  D4_DM_RES_UPDWN  Resistive Pull Up/Down 
*  D4_DM_DIG_HIZ    High Impedance Digital 
*  D4_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void D4_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(D4__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: D4_Read
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
*  Macro D4_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 D4_Read(void) 
{
    return (uint8)((D4_PS & D4_MASK) >> D4_SHIFT);
}


/*******************************************************************************
* Function Name: D4_ReadDataReg
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
uint8 D4_ReadDataReg(void) 
{
    return (uint8)((D4_DR & D4_MASK) >> D4_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(D4_INTSTAT) 

    /*******************************************************************************
    * Function Name: D4_ClearInterrupt
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
    uint8 D4_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(D4_INTSTAT & D4_MASK);
		D4_INTSTAT = maskedStatus;
        return maskedStatus >> D4_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
