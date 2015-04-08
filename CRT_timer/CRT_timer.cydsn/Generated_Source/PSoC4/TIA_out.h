/*******************************************************************************
* File Name: TIA_out.h  
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

#if !defined(CY_PINS_TIA_out_H) /* Pins TIA_out_H */
#define CY_PINS_TIA_out_H

#include "cytypes.h"
#include "cyfitter.h"
#include "TIA_out_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    TIA_out_Write(uint8 value) ;
void    TIA_out_SetDriveMode(uint8 mode) ;
uint8   TIA_out_ReadDataReg(void) ;
uint8   TIA_out_Read(void) ;
uint8   TIA_out_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TIA_out_DRIVE_MODE_BITS        (3)
#define TIA_out_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - TIA_out_DRIVE_MODE_BITS))

#define TIA_out_DM_ALG_HIZ         (0x00u)
#define TIA_out_DM_DIG_HIZ         (0x01u)
#define TIA_out_DM_RES_UP          (0x02u)
#define TIA_out_DM_RES_DWN         (0x03u)
#define TIA_out_DM_OD_LO           (0x04u)
#define TIA_out_DM_OD_HI           (0x05u)
#define TIA_out_DM_STRONG          (0x06u)
#define TIA_out_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define TIA_out_MASK               TIA_out__MASK
#define TIA_out_SHIFT              TIA_out__SHIFT
#define TIA_out_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TIA_out_PS                     (* (reg32 *) TIA_out__PS)
/* Port Configuration */
#define TIA_out_PC                     (* (reg32 *) TIA_out__PC)
/* Data Register */
#define TIA_out_DR                     (* (reg32 *) TIA_out__DR)
/* Input Buffer Disable Override */
#define TIA_out_INP_DIS                (* (reg32 *) TIA_out__PC2)


#if defined(TIA_out__INTSTAT)  /* Interrupt Registers */

    #define TIA_out_INTSTAT                (* (reg32 *) TIA_out__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define TIA_out_DRIVE_MODE_SHIFT       (0x00u)
#define TIA_out_DRIVE_MODE_MASK        (0x07u << TIA_out_DRIVE_MODE_SHIFT)


#endif /* End Pins TIA_out_H */


/* [] END OF FILE */
