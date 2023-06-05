/***************************************************************************//**
  @file     SS_Disp.c
  @brief    Seven Segment Driver
  @author   Tristan Gonzalez Branca
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <msp430.h>
#include "gpio.h"
#include "SSDisp.h"
#include "board.h"
#include "isr.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/


/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/


/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/
const int digitArray[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/
uint8_t display_show[4];
uint8_t display_active;
uint8_t frame;
uint16_t flag_active;
uint8_t show[4];
/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
/**
 * @brief Escribe un digito en una posicion
 * @param val es el digito a imprimir
 * @param pos es la posicion
 * @param dp es para indicar si se enciende el punto decimal
 */

void displayInit(){
        gpioMode (Disp_a, OUTPUT);
        gpioMode (Disp_b, OUTPUT);
        gpioMode (Disp_c, OUTPUT);
        gpioMode (Disp_d, OUTPUT);
        gpioMode (Disp_e, OUTPUT);
        gpioMode (Disp_f, OUTPUT);
        gpioMode (Disp_g, OUTPUT);
        gpioMode (Disp_sel0, OUTPUT);
        gpioMode (Disp_sel1, OUTPUT);

        send_to_isr(displayISR,70);
}

void printDigit(int pos){

    //P1OUT = digitArray[val];
    //P2OUT = pos;

    gpioWrite(Disp_a,display_show[pos]&1<<0);
    gpioWrite(Disp_b,display_show[pos]&1<<1);
    gpioWrite(Disp_c,display_show[pos]&1<<2);
    gpioWrite(Disp_d,display_show[pos]&1<<3);
    gpioWrite(Disp_e,display_show[pos]&1<<4);
    gpioWrite(Disp_f,display_show[pos]&1<<5);
    gpioWrite(Disp_g,display_show[pos]&1<<6);

    gpioWrite(Disp_sel0,pos&1<<0);
    gpioWrite(Disp_sel1,pos&1<<1);

}

void displayOpen(){
    display_show[0] = 0x3F;
    display_show[1] = 0x73;
    display_show[2] = 0x79;
    display_show[3] = 0x54;

}

void displayLocked(){
    display_show[0] = 0x38;
    display_show[1] = 0x39;
    display_show[2] = 0x74;
    display_show[3] = 0x5E;
}


void displayISR(){
    if (frame>3)
        frame=0;
    flag_active = flag_active + BLINK_SPEED;

    if (flag_active > BLINK_LIMIT && frame == display_active)
        printOff(frame);
    else
        printDigit(frame);

    frame ++;

}

void printOff(int pos){
    gpioWrite(Disp_a,0);
    gpioWrite(Disp_b,0);
    gpioWrite(Disp_c,0);
    gpioWrite(Disp_d,0);
    gpioWrite(Disp_e,0);
    gpioWrite(Disp_f,0);
    gpioWrite(Disp_g,0);

    gpioWrite(Disp_sel0,pos&1<<0);
    gpioWrite(Disp_sel1,pos&1<<1);
}

void setDisplay(uint8_t show[]){
    digit2hexa(show[0],0);
    digit2hexa(show[1],1);
    digit2hexa(show[2],2);
    digit2hexa(show[3],3);

}

void setActive(uint8_t active){
    display_active = active;
}

void digit2hexa(int val, int pos){
    display_show[pos] = digitArray[val];
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/


/******************************************************************************/

