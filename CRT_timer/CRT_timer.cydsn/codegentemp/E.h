/*******************************************************************************
* File Name: E.h  
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

#if !defined(CY_PINS_E_H) /* Pins E_H */
#define CY_PINS_E_H

#include "cytypes.h"
#include "cyfitter.h"
#include "E_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    E_Write(uint8 value) ;
void    E_SetDriveMode(uint8 mode) ;
uint8   E_ReadDataReg(void) ;
uint8   E_Read(void) ;
uint8   E_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define E_DRIVE_MODE_BITS        (3)
#define E_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - E_DRIVE_MODE_BITS))

#define E_DM_ALG_HIZ         (0x00u)
#define E_DM_DIG_HIZ         (0x01u)
#define E_DM_RES_UP          (0x02u)
#define E_DM_RES_DWN         (0x03u)
#define E_DM_OD_LO           (0x04u)
#define E_DM_OD_HI           (0x05u)
#define E_DM_STRONG          (0x06u)
#define E_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define E_MASK               E__MASK
#define E_SHIFT              E__SHIFT
#define E_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define E_PS                     (* (reg32 *) E__PS)
/* Port Configuration */
#define E_PC                     (* (reg32 *) E__PC)
/* Data Register */
#define E_DR                     (* (reg32 *) E__DR)
/* Input Buffer Disable Override */
#define E_INP_DIS                (* (reg32 *) E__PC2)


#if defined(E__INTSTAT)  /* Interrupt Registers */

    #define E_INTSTAT                (* (reg32 *) E__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define E_DRIVE_MODE_SHIFT       (0x00u)
#define E_DRIVE_MODE_MASK        (0x07u << E_DRIVE_MODE_SHIFT)


#endif /* End Pins E_H */


/* [] END OF FILE */
