/**
 * @file     encoder.h
 * @brief    encoder driver header file
 * @author   Teo Nicoletti
 */

#ifndef _ENCODER_H_
#define _ENCODER_H_    

/* INCLUDE HEADER FILES */

#include "common.h"

/* CONSTANT AND MACRO DEFINITIONS USING #DEFINE */




/* ENUMERATIONS AND STRUCTURES AND TYPEDEFS */

typedef enum{
    IDLE,
    CW,
    CCW
} encoderStatus_t;

/* VARIABLES WITH GLOBAL SCOPE 
 * +ej: unsigned int anio_actual;*/

/* FUNCTION PROTOTYPES WITH GLOBAL SCOPE */

/**
 * @brief Inicia el driver del encoder
*/
void encoderInit(void);


/**
 * @brief Devuelve el estado del encoder
 * @return IDLE (=0) si no se movio, CW (=1) si se movio a la clockwise, CCW (=2) si se movio counter clockwise
*/
encoderStatus_t encoderISR(void);
encoderStatus_t encoderGetStatus(void);
void encoderResetStatus(void);

/**
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/


// +ej: char lcd_goto (int fil, int col);+

#endif // _ENCODER_H_
