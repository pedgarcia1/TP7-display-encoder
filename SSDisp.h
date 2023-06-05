/***************************************************************************//**
  @file     SSDisp.h
  @brief    Seven Segment Driver
  @author   Tristan Gonzalez Branca
 ******************************************************************************/

#ifndef _SSDisp_H_
#define _SSDisp_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "common.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define BLINK_SPEED 500
#define BLINK_LIMIT 32768
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
uint8_t status2;
/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Configures the specified pin to behave as a GPIO
 * @param pin The pin id whose mode you wish to set (according PORTNUM2PIN)
 * @param mode INPUT, OUTPUT, INPUT_PULLUP or INPUT_PULLDOWN.
 */
void printDigit(int pos);

void displayOpen(void);

void setDisplay(uint8_t show[]);

void setActive(uint8_t active);

void displayISR(void);

void displayInit(void);

void printOff(int pos);

void displayLocked(void);

void digit2hexa(int val, int pos);
/*******************************************************************************
 ******************************************************************************/

#endif // _SSDisp_H_
