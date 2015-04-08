/*******************************************************************************
* File Name: B_press.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_B_press_H) /* Pins B_press_H */
#define CY_PINS_B_press_H

#include "cytypes.h"
#include "cyfitter.h"
#include "B_press_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    B_press_Write(uint8 value) ;
void    B_press_SetDriveMode(uint8 mode) ;
uint8   B_press_ReadDataReg(void) ;
uint8   B_press_Read(void) ;
uint8   B_press_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define B_press_DRIVE_MODE_BITS        (3)
#define B_press_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - B_press_DRIVE_MODE_BITS))

#define B_press_DM_ALG_HIZ         (0x00u)
#define B_press_DM_DIG_HIZ         (0x01u)
#define B_press_DM_RES_UP          (0x02u)
#define B_press_DM_RES_DWN         (0x03u)
#define B_press_DM_OD_LO           (0x04u)
#define B_press_DM_OD_HI           (0x05u)
#define B_press_DM_STRONG          (0x06u)
#define B_press_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define B_press_MASK               B_press__MASK
#define B_press_SHIFT              B_press__SHIFT
#define B_press_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define B_press_PS                     (* (reg32 *) B_press__PS)
/* Port Configuration */
#define B_press_PC                     (* (reg32 *) B_press__PC)
/* Data Register */
#define B_press_DR                     (* (reg32 *) B_press__DR)
/* Input Buffer Disable Override */
#define B_press_INP_DIS                (* (reg32 *) B_press__PC2)


#if defined(B_press__INTSTAT)  /* Interrupt Registers */

    #define B_press_INTSTAT                (* (reg32 *) B_press__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define B_press_DRIVE_MODE_SHIFT       (0x00u)
#define B_press_DRIVE_MODE_MASK        (0x07u << B_press_DRIVE_MODE_SHIFT)


#endif /* End Pins B_press_H */


/* [] END OF FILE */
