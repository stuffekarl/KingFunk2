/*******************************************************************************
* File Name: TIA_out.c  
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
#include "TIA_out.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        TIA_out_PC =   (TIA_out_PC & \
                                (uint32)(~(uint32)(TIA_out_DRIVE_MODE_IND_MASK << (TIA_out_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (TIA_out_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: TIA_out_Write
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
void TIA_out_Write(uint8 value) 
{
    uint8 drVal = (uint8)(TIA_out_DR & (uint8)(~TIA_out_MASK));
    drVal = (drVal | ((uint8)(value << TIA_out_SHIFT) & TIA_out_MASK));
    TIA_out_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: TIA_out_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  TIA_out_DM_STRONG     Strong Drive 
*  TIA_out_DM_OD_HI      Open Drain, Drives High 
*  TIA_out_DM_OD_LO      Open Drain, Drives Low 
*  TIA_out_DM_RES_UP     Resistive Pull Up 
*  TIA_out_DM_RES_DWN    Resistive Pull Down 
*  TIA_out_DM_RES_UPDWN  Resistive Pull Up/Down 
*  TIA_out_DM_DIG_HIZ    High Impedance Digital 
*  TIA_out_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void TIA_out_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(TIA_out__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: TIA_out_Read
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
*  Macro TIA_out_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TIA_out_Read(void) 
{
    return (uint8)((TIA_out_PS & TIA_out_MASK) >> TIA_out_SHIFT);
}


/*******************************************************************************
* Function Name: TIA_out_ReadDataReg
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
uint8 TIA_out_ReadDataReg(void) 
{
    return (uint8)((TIA_out_DR & TIA_out_MASK) >> TIA_out_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TIA_out_INTSTAT) 

    /*******************************************************************************
    * Function Name: TIA_out_ClearInterrupt
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
    uint8 TIA_out_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(TIA_out_INTSTAT & TIA_out_MASK);
		TIA_out_INTSTAT = maskedStatus;
        return maskedStatus >> TIA_out_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
