/*******************************************************************************
* File Name: D6.c  
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
#include "D6.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        D6_PC =   (D6_PC & \
                                (uint32)(~(uint32)(D6_DRIVE_MODE_IND_MASK << (D6_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (D6_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: D6_Write
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
void D6_Write(uint8 value) 
{
    uint8 drVal = (uint8)(D6_DR & (uint8)(~D6_MASK));
    drVal = (drVal | ((uint8)(value << D6_SHIFT) & D6_MASK));
    D6_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: D6_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  D6_DM_STRONG     Strong Drive 
*  D6_DM_OD_HI      Open Drain, Drives High 
*  D6_DM_OD_LO      Open Drain, Drives Low 
*  D6_DM_RES_UP     Resistive Pull Up 
*  D6_DM_RES_DWN    Resistive Pull Down 
*  D6_DM_RES_UPDWN  Resistive Pull Up/Down 
*  D6_DM_DIG_HIZ    High Impedance Digital 
*  D6_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void D6_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(D6__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: D6_Read
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
*  Macro D6_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 D6_Read(void) 
{
    return (uint8)((D6_PS & D6_MASK) >> D6_SHIFT);
}


/*******************************************************************************
* Function Name: D6_ReadDataReg
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
uint8 D6_ReadDataReg(void) 
{
    return (uint8)((D6_DR & D6_MASK) >> D6_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(D6_INTSTAT) 

    /*******************************************************************************
    * Function Name: D6_ClearInterrupt
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
    uint8 D6_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(D6_INTSTAT & D6_MASK);
		D6_INTSTAT = maskedStatus;
        return maskedStatus >> D6_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
