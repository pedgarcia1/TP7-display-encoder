/***************************************************************************//**
  @file     isr.h
  @brief    Interrupt driver
  @author   Grupo 5
 ******************************************************************************/

#ifndef _ISR_H_
#define _ISR_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "common.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/



/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/




/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: extern unsigned int anio_actual;+


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Sends function to be executed in the interrupt service routine
 * @param function Pointer to function to be executed 
 * @param period period of the function execution in times of interruptions. (ej: 1 = every interruption, 2 = every 2 interruptions, etc)
*/
void send_to_isr(void (*function)(void), unsigned int period);

// +ej: char lcd_goto (int fil, int col);+


/*******************************************************************************
 ******************************************************************************/

#endif // _ISR_H_
