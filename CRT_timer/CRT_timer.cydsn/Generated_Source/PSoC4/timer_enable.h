/*******************************************************************************
* File Name: timer_enable.h  
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

#if !defined(CY_PINS_timer_enable_H) /* Pins timer_enable_H */
#define CY_PINS_timer_enable_H

#include "cytypes.h"
#include "cyfitter.h"
#include "timer_enable_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    timer_enable_Write(uint8 value) ;
void    timer_enable_SetDriveMode(uint8 mode) ;
uint8   timer_enable_ReadDataReg(void) ;
uint8   timer_enable_Read(void) ;
uint8   timer_enable_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define timer_enable_DRIVE_MODE_BITS        (3)
#define timer_enable_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - timer_enable_DRIVE_MODE_BITS))

#define timer_enable_DM_ALG_HIZ         (0x00u)
#define timer_enable_DM_DIG_HIZ         (0x01u)
#define timer_enable_DM_RES_UP          (0x02u)
#define timer_enable_DM_RES_DWN         (0x03u)
#define timer_enable_DM_OD_LO           (0x04u)
#define timer_enable_DM_OD_HI           (0x05u)
#define timer_enable_DM_STRONG          (0x06u)
#define timer_enable_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define timer_enable_MASK               timer_enable__MASK
#define timer_enable_SHIFT              timer_enable__SHIFT
#define timer_enable_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define timer_enable_PS                     (* (reg32 *) timer_enable__PS)
/* Port Configuration */
#define timer_enable_PC                     (* (reg32 *) timer_enable__PC)
/* Data Register */
#define timer_enable_DR                     (* (reg32 *) timer_enable__DR)
/* Input Buffer Disable Override */
#define timer_enable_INP_DIS                (* (reg32 *) timer_enable__PC2)


#if defined(timer_enable__INTSTAT)  /* Interrupt Registers */

    #define timer_enable_INTSTAT                (* (reg32 *) timer_enable__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define timer_enable_DRIVE_MODE_SHIFT       (0x00u)
#define timer_enable_DRIVE_MODE_MASK        (0x07u << timer_enable_DRIVE_MODE_SHIFT)


#endif /* End Pins timer_enable_H */


/* [] END OF FILE */
