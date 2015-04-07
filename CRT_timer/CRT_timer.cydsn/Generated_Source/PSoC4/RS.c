/*******************************************************************************
* File Name: RS.c  
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
#include "RS.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        RS_PC =   (RS_PC & \
                                (uint32)(~(uint32)(RS_DRIVE_MODE_IND_MASK << (RS_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (RS_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: RS_Write
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
void RS_Write(uint8 value) 
{
    uint8 drVal = (uint8)(RS_DR & (uint8)(~RS_MASK));
    drVal = (drVal | ((uint8)(value << RS_SHIFT) & RS_MASK));
    RS_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: RS_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  RS_DM_STRONG     Strong Drive 
*  RS_DM_OD_HI      Open Drain, Drives High 
*  RS_DM_OD_LO      Open Drain, Drives Low 
*  RS_DM_RES_UP     Resistive Pull Up 
*  RS_DM_RES_DWN    Resistive Pull Down 
*  RS_DM_RES_UPDWN  Resistive Pull Up/Down 
*  RS_DM_DIG_HIZ    High Impedance Digital 
*  RS_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void RS_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(RS__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: RS_Read
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
*  Macro RS_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 RS_Read(void) 
{
    return (uint8)((RS_PS & RS_MASK) >> RS_SHIFT);
}


/*******************************************************************************
* Function Name: RS_ReadDataReg
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
uint8 RS_ReadDataReg(void) 
{
    return (uint8)((RS_DR & RS_MASK) >> RS_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(RS_INTSTAT) 

    /*******************************************************************************
    * Function Name: RS_ClearInterrupt
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
    uint8 RS_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(RS_INTSTAT & RS_MASK);
		RS_INTSTAT = maskedStatus;
        return maskedStatus >> RS_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
