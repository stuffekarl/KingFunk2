/*******************************************************************************
* File Name: cl_deb.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_cl_deb_H)
#define CY_CLOCK_cl_deb_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void cl_deb_StartEx(uint32 alignClkDiv);
#define cl_deb_Start() \
    cl_deb_StartEx(cl_deb__PA_DIV_ID)

#else

void cl_deb_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void cl_deb_Stop(void);

void cl_deb_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 cl_deb_GetDividerRegister(void);
uint8  cl_deb_GetFractionalDividerRegister(void);

#define cl_deb_Enable()                         cl_deb_Start()
#define cl_deb_Disable()                        cl_deb_Stop()
#define cl_deb_SetDividerRegister(clkDivider, reset)  \
    cl_deb_SetFractionalDividerRegister((clkDivider), 0u)
#define cl_deb_SetDivider(clkDivider)           cl_deb_SetDividerRegister((clkDivider), 1u)
#define cl_deb_SetDividerValue(clkDivider)      cl_deb_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define cl_deb_DIV_ID     cl_deb__DIV_ID

#define cl_deb_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define cl_deb_CTRL_REG   (*(reg32 *)cl_deb__CTRL_REGISTER)
#define cl_deb_DIV_REG    (*(reg32 *)cl_deb__DIV_REGISTER)

#define cl_deb_CMD_DIV_SHIFT          (0u)
#define cl_deb_CMD_PA_DIV_SHIFT       (8u)
#define cl_deb_CMD_DISABLE_SHIFT      (30u)
#define cl_deb_CMD_ENABLE_SHIFT       (31u)

#define cl_deb_CMD_DISABLE_MASK       ((uint32)((uint32)1u << cl_deb_CMD_DISABLE_SHIFT))
#define cl_deb_CMD_ENABLE_MASK        ((uint32)((uint32)1u << cl_deb_CMD_ENABLE_SHIFT))

#define cl_deb_DIV_FRAC_MASK  (0x000000F8u)
#define cl_deb_DIV_FRAC_SHIFT (3u)
#define cl_deb_DIV_INT_MASK   (0xFFFFFF00u)
#define cl_deb_DIV_INT_SHIFT  (8u)

#else 

#define cl_deb_DIV_REG        (*(reg32 *)cl_deb__REGISTER)
#define cl_deb_ENABLE_REG     cl_deb_DIV_REG
#define cl_deb_DIV_FRAC_MASK  cl_deb__FRAC_MASK
#define cl_deb_DIV_FRAC_SHIFT (16u)
#define cl_deb_DIV_INT_MASK   cl_deb__DIVIDER_MASK
#define cl_deb_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_cl_deb_H) */

/* [] END OF FILE */
