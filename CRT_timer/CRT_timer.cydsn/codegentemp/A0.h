/*******************************************************************************
* File Name: A0.h  
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

#if !defined(CY_PINS_A0_H) /* Pins A0_H */
#define CY_PINS_A0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "A0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    A0_Write(uint8 value) ;
void    A0_SetDriveMode(uint8 mode) ;
uint8   A0_ReadDataReg(void) ;
uint8   A0_Read(void) ;
uint8   A0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define A0_DRIVE_MODE_BITS        (3)
#define A0_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - A0_DRIVE_MODE_BITS))

#define A0_DM_ALG_HIZ         (0x00u)
#define A0_DM_DIG_HIZ         (0x01u)
#define A0_DM_RES_UP          (0x02u)
#define A0_DM_RES_DWN         (0x03u)
#define A0_DM_OD_LO           (0x04u)
#define A0_DM_OD_HI           (0x05u)
#define A0_DM_STRONG          (0x06u)
#define A0_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define A0_MASK               A0__MASK
#define A0_SHIFT              A0__SHIFT
#define A0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define A0_PS                     (* (reg32 *) A0__PS)
/* Port Configuration */
#define A0_PC                     (* (reg32 *) A0__PC)
/* Data Register */
#define A0_DR                     (* (reg32 *) A0__DR)
/* Input Buffer Disable Override */
#define A0_INP_DIS                (* (reg32 *) A0__PC2)


#if defined(A0__INTSTAT)  /* Interrupt Registers */

    #define A0_INTSTAT                (* (reg32 *) A0__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define A0_DRIVE_MODE_SHIFT       (0x00u)
#define A0_DRIVE_MODE_MASK        (0x07u << A0_DRIVE_MODE_SHIFT)


#endif /* End Pins A0_H */


/* [] END OF FILE */
