/*******************************************************************************
* File Name: sw_int.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_sw_int_H)
#define CY_ISR_sw_int_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void sw_int_Start(void);
void sw_int_StartEx(cyisraddress address);
void sw_int_Stop(void);

CY_ISR_PROTO(sw_int_Interrupt);

void sw_int_SetVector(cyisraddress address);
cyisraddress sw_int_GetVector(void);

void sw_int_SetPriority(uint8 priority);
uint8 sw_int_GetPriority(void);

void sw_int_Enable(void);
uint8 sw_int_GetState(void);
void sw_int_Disable(void);

void sw_int_SetPending(void);
void sw_int_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the sw_int ISR. */
#define sw_int_INTC_VECTOR            ((reg32 *) sw_int__INTC_VECT)

/* Address of the sw_int ISR priority. */
#define sw_int_INTC_PRIOR             ((reg32 *) sw_int__INTC_PRIOR_REG)

/* Priority of the sw_int interrupt. */
#define sw_int_INTC_PRIOR_NUMBER      sw_int__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable sw_int interrupt. */
#define sw_int_INTC_SET_EN            ((reg32 *) sw_int__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the sw_int interrupt. */
#define sw_int_INTC_CLR_EN            ((reg32 *) sw_int__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the sw_int interrupt state to pending. */
#define sw_int_INTC_SET_PD            ((reg32 *) sw_int__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the sw_int interrupt. */
#define sw_int_INTC_CLR_PD            ((reg32 *) sw_int__INTC_CLR_PD_REG)



#endif /* CY_ISR_sw_int_H */


/* [] END OF FILE */
