/*******************************************************************************
* File Name: RS.h  
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

#if !defined(CY_PINS_RS_H) /* Pins RS_H */
#define CY_PINS_RS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RS_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    RS_Write(uint8 value) ;
void    RS_SetDriveMode(uint8 mode) ;
uint8   RS_ReadDataReg(void) ;
uint8   RS_Read(void) ;
uint8   RS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RS_DRIVE_MODE_BITS        (3)
#define RS_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RS_DRIVE_MODE_BITS))

#define RS_DM_ALG_HIZ         (0x00u)
#define RS_DM_DIG_HIZ         (0x01u)
#define RS_DM_RES_UP          (0x02u)
#define RS_DM_RES_DWN         (0x03u)
#define RS_DM_OD_LO           (0x04u)
#define RS_DM_OD_HI           (0x05u)
#define RS_DM_STRONG          (0x06u)
#define RS_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define RS_MASK               RS__MASK
#define RS_SHIFT              RS__SHIFT
#define RS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RS_PS                     (* (reg32 *) RS__PS)
/* Port Configuration */
#define RS_PC                     (* (reg32 *) RS__PC)
/* Data Register */
#define RS_DR                     (* (reg32 *) RS__DR)
/* Input Buffer Disable Override */
#define RS_INP_DIS                (* (reg32 *) RS__PC2)


#if defined(RS__INTSTAT)  /* Interrupt Registers */

    #define RS_INTSTAT                (* (reg32 *) RS__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define RS_DRIVE_MODE_SHIFT       (0x00u)
#define RS_DRIVE_MODE_MASK        (0x07u << RS_DRIVE_MODE_SHIFT)


#endif /* End Pins RS_H */


/* [] END OF FILE */
