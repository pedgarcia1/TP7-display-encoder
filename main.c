/***************************************************************************//**
  @file     main.c
  @brief    Main file
  @author   Nicolï¿½s Magliola
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "system.h"
#include "button.h"
#include "gpio.h"
#include "encoder.h"
#include "board.h"
#include "isr.h"
#include "SSDisp.h"
#include "hardware.h"
#include "boardleds.h"

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

void AppInit (void);
void AppRun (void);
void checkOpen(void);

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/


/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
display_t display = {
        .psw_try = {0, 0, 0, 0},
        .active = 0
    };

const char PSW[] = {1,2,3,4}; //contraseña
uint8_t mistakes = 0;

void main (void)
{ // NO TOCAR

    systemInitFirst();
    boardInit();
    AppInit();
    systemInitLast();


    for(;;)
        AppRun();
} // NO TOCAR


void AppInit (void)
{
    // setup (se ejecuta 1 sola vez al comienzo)
    // TODO: COMPLETAR CON LA INICIALIZACIï¿½N DE DRIVERS Y APLICACIï¿½N

    setDisplay(display.psw_try);
    setActive(display.active);
    displayInit();
    encoderInit();
    buttonInit();
    ledsInit(mistakes);
}



void AppRun (void)
{
    // loop (se ejecuta constantemente en un ciclo infinito)
    // TODO: COMPLETAR CON EL FUNCIONAMIENTO DEL PROGRAMA
    uint8_t encoderFlag = encoderGetStatus();
    uint8_t buttonFlag = buttonGetStatus();
    switch (encoderFlag){
    case 1:
        encoderResetStatus();
        display.psw_try[display.active] = display.psw_try[display.active]+1;
        display.psw_try[display.active] %= 10;
        setDisplay(display.psw_try);
        break;
    case 2:
        encoderResetStatus();
        if (display.psw_try[display.active]==0)
            display.psw_try[display.active]=10;
        display.psw_try[display.active] = display.psw_try[display.active] -1;
        display.psw_try[display.active] %= 10;
        setDisplay(display.psw_try);
        break;
    }

    if(buttonFlag){
        buttonResetStatus();
        display.active++;

        if (display.active == 4)
                checkOpen();


        display.active %=4;
        setActive(display.active);
    }
}

void checkOpen(){
    int i;
    for(i=0; i<4; i++){
        if(PSW[i] != display.psw_try[i]){
            mistakes++;
            setLeds(mistakes);
            break;
        }
        if(i == 3){
            displayOpen();
            mistakes = 0;
            setLeds(mistakes);
        }
    }

    if (mistakes >= 3){
        displayLocked();
        __delay_cycles( DELAY_CYCLES );
        encoderResetStatus();
        buttonResetStatus();
        setDisplay(display.psw_try);
        mistakes = 2;
        setLeds(mistakes);
    }

}


/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

/******************************************************************************/
