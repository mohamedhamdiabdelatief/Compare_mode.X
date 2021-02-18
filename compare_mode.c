/*
 * File:   compare_mode.c
 * Author: Mohamed Hamdi
 * please visit my youtube channel:https://www.youtube.com/channel/UCzt_0MFbJiT93KSR74pW6Jw
 */

#include <xc.h>
#include "config.h"
#include <stdint.h>
#define _XTAL_FREQ 4000000
//counter for event matching
uint8_t x = 0;
void main(void)
{
   //Making RC output pin
   TRISCbits.TRISC4 = 0;
   //set initial state for Rc pin
   PORTCbits.RC4 = 0;
   //configure timer 1 in timer mode
   TMR1 = 0;
   T1CKPS0 = 0;
   T1CKPS1 = 0;
   TMR1CS = 0;
   TMR1ON = 1;
   //pre loaded value to making interrupt after 0.5 sec
   CCPR1 = 50000;
   //configure CCP1 module in compare mode
   CCP1M0 = 1;
   CCP1M1 = 1;
   CCP1M2 = 0;
   CCP1M3 = 1;
   //enable CCP1 interrupt
   CCP1IE = 1;
   PEIE = 1;
   GIE = 1;
   while (1)
   {
   }
   return;
}
void __interrupt() isr(void)
{
   if (CCP1IF)
   {
      x++;
      if (x == 10)
      {
         //Do What you want
      }
      CCP1IF = 0;
   }
}