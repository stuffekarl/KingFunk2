/*******************************************************************************
* File Name: D7.h  
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

#if !defined(CY_PINS_D7_H) /* Pins D7_H */
#define CY_PINS_D7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "D7_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    D7_Write(uint8 value) ;
void    D7_SetDriveMode(uint8 mode) ;
uint8   D7_ReadDataReg(void) ;
uint8   D7_Read(void) ;
uint8   D7_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define D7_DRIVE_MODE_BITS        (3)
#define D7_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - D7_DRIVE_MODE_BITS))

#define D7_DM_ALG_HIZ         (0x00u)
#define D7_DM_DIG_HIZ         (0x01u)
#define D7_DM_RES_UP          (0x02u)
#define D7_DM_RES_DWN         (0x03u)
#define D7_DM_OD_LO           (0x04u)
#define D7_DM_OD_HI           (0x05u)
#define D7_DM_STRONG          (0x06u)
#define D7_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define D7_MASK               D7__MASK
#define D7_SHIFT              D7__SHIFT
#define D7_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define D7_PS                     (* (reg32 *) D7__PS)
/* Port Configuration */
#define D7_PC                     (* (reg32 *) D7__PC)
/* Data Register */
#define D7_DR                     (* (reg32 *) D7__DR)
/* Input Buffer Disable Override */
#define D7_INP_DIS                (* (reg32 *) D7__PC2)


#if defined(D7__INTSTAT)  /* Interrupt Registers */

    #define D7_INTSTAT                (* (reg32 *) D7__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define D7_DRIVE_MODE_SHIFT       (0x00u)
#define D7_DRIVE_MODE_MASK        (0x07u << D7_DRIVE_MODE_SHIFT)


#endif /* End Pins D7_H */


/* [] END OF FILE */
