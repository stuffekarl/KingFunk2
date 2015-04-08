/*******************************************************************************
* File Name: GND.h  
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

#if !defined(CY_PINS_GND_H) /* Pins GND_H */
#define CY_PINS_GND_H

#include "cytypes.h"
#include "cyfitter.h"
#include "GND_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    GND_Write(uint8 value) ;
void    GND_SetDriveMode(uint8 mode) ;
uint8   GND_ReadDataReg(void) ;
uint8   GND_Read(void) ;
uint8   GND_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GND_DRIVE_MODE_BITS        (3)
#define GND_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - GND_DRIVE_MODE_BITS))

#define GND_DM_ALG_HIZ         (0x00u)
#define GND_DM_DIG_HIZ         (0x01u)
#define GND_DM_RES_UP          (0x02u)
#define GND_DM_RES_DWN         (0x03u)
#define GND_DM_OD_LO           (0x04u)
#define GND_DM_OD_HI           (0x05u)
#define GND_DM_STRONG          (0x06u)
#define GND_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define GND_MASK               GND__MASK
#define GND_SHIFT              GND__SHIFT
#define GND_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GND_PS                     (* (reg32 *) GND__PS)
/* Port Configuration */
#define GND_PC                     (* (reg32 *) GND__PC)
/* Data Register */
#define GND_DR                     (* (reg32 *) GND__DR)
/* Input Buffer Disable Override */
#define GND_INP_DIS                (* (reg32 *) GND__PC2)


#if defined(GND__INTSTAT)  /* Interrupt Registers */

    #define GND_INTSTAT                (* (reg32 *) GND__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define GND_DRIVE_MODE_SHIFT       (0x00u)
#define GND_DRIVE_MODE_MASK        (0x07u << GND_DRIVE_MODE_SHIFT)


#endif /* End Pins GND_H */


/* [] END OF FILE */
