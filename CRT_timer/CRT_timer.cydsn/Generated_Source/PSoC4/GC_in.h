/*******************************************************************************
* File Name: GC_in.h  
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

#if !defined(CY_PINS_GC_in_H) /* Pins GC_in_H */
#define CY_PINS_GC_in_H

#include "cytypes.h"
#include "cyfitter.h"
#include "GC_in_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    GC_in_Write(uint8 value) ;
void    GC_in_SetDriveMode(uint8 mode) ;
uint8   GC_in_ReadDataReg(void) ;
uint8   GC_in_Read(void) ;
uint8   GC_in_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GC_in_DRIVE_MODE_BITS        (3)
#define GC_in_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - GC_in_DRIVE_MODE_BITS))

#define GC_in_DM_ALG_HIZ         (0x00u)
#define GC_in_DM_DIG_HIZ         (0x01u)
#define GC_in_DM_RES_UP          (0x02u)
#define GC_in_DM_RES_DWN         (0x03u)
#define GC_in_DM_OD_LO           (0x04u)
#define GC_in_DM_OD_HI           (0x05u)
#define GC_in_DM_STRONG          (0x06u)
#define GC_in_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define GC_in_MASK               GC_in__MASK
#define GC_in_SHIFT              GC_in__SHIFT
#define GC_in_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GC_in_PS                     (* (reg32 *) GC_in__PS)
/* Port Configuration */
#define GC_in_PC                     (* (reg32 *) GC_in__PC)
/* Data Register */
#define GC_in_DR                     (* (reg32 *) GC_in__DR)
/* Input Buffer Disable Override */
#define GC_in_INP_DIS                (* (reg32 *) GC_in__PC2)


#if defined(GC_in__INTSTAT)  /* Interrupt Registers */

    #define GC_in_INTSTAT                (* (reg32 *) GC_in__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define GC_in_DRIVE_MODE_SHIFT       (0x00u)
#define GC_in_DRIVE_MODE_MASK        (0x07u << GC_in_DRIVE_MODE_SHIFT)


#endif /* End Pins GC_in_H */


/* [] END OF FILE */
