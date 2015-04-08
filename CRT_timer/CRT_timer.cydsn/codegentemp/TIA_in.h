/*******************************************************************************
* File Name: TIA_in.h  
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

#if !defined(CY_PINS_TIA_in_H) /* Pins TIA_in_H */
#define CY_PINS_TIA_in_H

#include "cytypes.h"
#include "cyfitter.h"
#include "TIA_in_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    TIA_in_Write(uint8 value) ;
void    TIA_in_SetDriveMode(uint8 mode) ;
uint8   TIA_in_ReadDataReg(void) ;
uint8   TIA_in_Read(void) ;
uint8   TIA_in_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TIA_in_DRIVE_MODE_BITS        (3)
#define TIA_in_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - TIA_in_DRIVE_MODE_BITS))

#define TIA_in_DM_ALG_HIZ         (0x00u)
#define TIA_in_DM_DIG_HIZ         (0x01u)
#define TIA_in_DM_RES_UP          (0x02u)
#define TIA_in_DM_RES_DWN         (0x03u)
#define TIA_in_DM_OD_LO           (0x04u)
#define TIA_in_DM_OD_HI           (0x05u)
#define TIA_in_DM_STRONG          (0x06u)
#define TIA_in_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define TIA_in_MASK               TIA_in__MASK
#define TIA_in_SHIFT              TIA_in__SHIFT
#define TIA_in_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TIA_in_PS                     (* (reg32 *) TIA_in__PS)
/* Port Configuration */
#define TIA_in_PC                     (* (reg32 *) TIA_in__PC)
/* Data Register */
#define TIA_in_DR                     (* (reg32 *) TIA_in__DR)
/* Input Buffer Disable Override */
#define TIA_in_INP_DIS                (* (reg32 *) TIA_in__PC2)


#if defined(TIA_in__INTSTAT)  /* Interrupt Registers */

    #define TIA_in_INTSTAT                (* (reg32 *) TIA_in__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define TIA_in_DRIVE_MODE_SHIFT       (0x00u)
#define TIA_in_DRIVE_MODE_MASK        (0x07u << TIA_in_DRIVE_MODE_SHIFT)


#endif /* End Pins TIA_in_H */


/* [] END OF FILE */
