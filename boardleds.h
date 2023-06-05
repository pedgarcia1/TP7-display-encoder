/**
 * @file     encoder.h
 * @brief    encoder driver header file
 * @author   Teo Nicoletti
 */

#ifndef _LEDS_H_
#define _LEDS_H_

/* INCLUDE HEADER FILES */

#include "common.h"

/* CONSTANT AND MACRO DEFINITIONS USING #DEFINE */




/* ENUMERATIONS AND STRUCTURES AND TYPEDEFS */


/* VARIABLES WITH GLOBAL SCOPE 
 * +ej: unsigned int anio_actual;*/

/* FUNCTION PROTOTYPES WITH GLOBAL SCOPE */

/**
 * @brief Inicia el driver del encoder
*/
void ledsInit(uint8_t mistakes);

void setLeds(uint8_t mistakes);

#endif // _LEDS_H_
