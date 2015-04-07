/*******************************************************************************
* File Name: D6.h  
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

#if !defined(CY_PINS_D6_H) /* Pins D6_H */
#define CY_PINS_D6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "D6_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    D6_Write(uint8 value) ;
void    D6_SetDriveMode(uint8 mode) ;
uint8   D6_ReadDataReg(void) ;
uint8   D6_Read(void) ;
uint8   D6_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define D6_DRIVE_MODE_BITS        (3)
#define D6_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - D6_DRIVE_MODE_BITS))

#define D6_DM_ALG_HIZ         (0x00u)
#define D6_DM_DIG_HIZ         (0x01u)
#define D6_DM_RES_UP          (0x02u)
#define D6_DM_RES_DWN         (0x03u)
#define D6_DM_OD_LO           (0x04u)
#define D6_DM_OD_HI           (0x05u)
#define D6_DM_STRONG          (0x06u)
#define D6_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define D6_MASK               D6__MASK
#define D6_SHIFT              D6__SHIFT
#define D6_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define D6_PS                     (* (reg32 *) D6__PS)
/* Port Configuration */
#define D6_PC                     (* (reg32 *) D6__PC)
/* Data Register */
#define D6_DR                     (* (reg32 *) D6__DR)
/* Input Buffer Disable Override */
#define D6_INP_DIS                (* (reg32 *) D6__PC2)


#if defined(D6__INTSTAT)  /* Interrupt Registers */

    #define D6_INTSTAT                (* (reg32 *) D6__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define D6_DRIVE_MODE_SHIFT       (0x00u)
#define D6_DRIVE_MODE_MASK        (0x07u << D6_DRIVE_MODE_SHIFT)


#endif /* End Pins D6_H */


/* [] END OF FILE */
