/*******************************************************************************
* File Name: TIA_output.h  
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

#if !defined(CY_PINS_TIA_output_H) /* Pins TIA_output_H */
#define CY_PINS_TIA_output_H

#include "cytypes.h"
#include "cyfitter.h"
#include "TIA_output_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    TIA_output_Write(uint8 value) ;
void    TIA_output_SetDriveMode(uint8 mode) ;
uint8   TIA_output_ReadDataReg(void) ;
uint8   TIA_output_Read(void) ;
uint8   TIA_output_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TIA_output_DRIVE_MODE_BITS        (3)
#define TIA_output_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - TIA_output_DRIVE_MODE_BITS))

#define TIA_output_DM_ALG_HIZ         (0x00u)
#define TIA_output_DM_DIG_HIZ         (0x01u)
#define TIA_output_DM_RES_UP          (0x02u)
#define TIA_output_DM_RES_DWN         (0x03u)
#define TIA_output_DM_OD_LO           (0x04u)
#define TIA_output_DM_OD_HI           (0x05u)
#define TIA_output_DM_STRONG          (0x06u)
#define TIA_output_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define TIA_output_MASK               TIA_output__MASK
#define TIA_output_SHIFT              TIA_output__SHIFT
#define TIA_output_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TIA_output_PS                     (* (reg32 *) TIA_output__PS)
/* Port Configuration */
#define TIA_output_PC                     (* (reg32 *) TIA_output__PC)
/* Data Register */
#define TIA_output_DR                     (* (reg32 *) TIA_output__DR)
/* Input Buffer Disable Override */
#define TIA_output_INP_DIS                (* (reg32 *) TIA_output__PC2)


#if defined(TIA_output__INTSTAT)  /* Interrupt Registers */

    #define TIA_output_INTSTAT                (* (reg32 *) TIA_output__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define TIA_output_DRIVE_MODE_SHIFT       (0x00u)
#define TIA_output_DRIVE_MODE_MASK        (0x07u << TIA_output_DRIVE_MODE_SHIFT)


#endif /* End Pins TIA_output_H */


/* [] END OF FILE */
