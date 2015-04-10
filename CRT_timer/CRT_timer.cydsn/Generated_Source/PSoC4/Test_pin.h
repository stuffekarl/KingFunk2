/*******************************************************************************
* File Name: Test_pin.h  
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

#if !defined(CY_PINS_Test_pin_H) /* Pins Test_pin_H */
#define CY_PINS_Test_pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Test_pin_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Test_pin_Write(uint8 value) ;
void    Test_pin_SetDriveMode(uint8 mode) ;
uint8   Test_pin_ReadDataReg(void) ;
uint8   Test_pin_Read(void) ;
uint8   Test_pin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Test_pin_DRIVE_MODE_BITS        (3)
#define Test_pin_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Test_pin_DRIVE_MODE_BITS))

#define Test_pin_DM_ALG_HIZ         (0x00u)
#define Test_pin_DM_DIG_HIZ         (0x01u)
#define Test_pin_DM_RES_UP          (0x02u)
#define Test_pin_DM_RES_DWN         (0x03u)
#define Test_pin_DM_OD_LO           (0x04u)
#define Test_pin_DM_OD_HI           (0x05u)
#define Test_pin_DM_STRONG          (0x06u)
#define Test_pin_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Test_pin_MASK               Test_pin__MASK
#define Test_pin_SHIFT              Test_pin__SHIFT
#define Test_pin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Test_pin_PS                     (* (reg32 *) Test_pin__PS)
/* Port Configuration */
#define Test_pin_PC                     (* (reg32 *) Test_pin__PC)
/* Data Register */
#define Test_pin_DR                     (* (reg32 *) Test_pin__DR)
/* Input Buffer Disable Override */
#define Test_pin_INP_DIS                (* (reg32 *) Test_pin__PC2)


#if defined(Test_pin__INTSTAT)  /* Interrupt Registers */

    #define Test_pin_INTSTAT                (* (reg32 *) Test_pin__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Test_pin_DRIVE_MODE_SHIFT       (0x00u)
#define Test_pin_DRIVE_MODE_MASK        (0x07u << Test_pin_DRIVE_MODE_SHIFT)


#endif /* End Pins Test_pin_H */


/* [] END OF FILE */
