/*
 * File:   dkp.c
 * Author: Hp
 *
 * Created on 16 October, 2025, 4:26 PM
 */


#include <xc.h>
#include "dkp.h"
#include "matrix.h"

extern unsigned char gear;
unsigned char gear1[8];

void dkp()
{
        unsigned char key, once=0;
        short int i = 0;
        
        key = read_switches(STATE_CHANGE);
        
        if(key == 10 && i<6)
        {
            if(once)
            {
                i = -1;
             //   RB0 = 0;
                once = 0;
            }
            i++;
            gear = gear1[i];
            
        }
        else if(key == 11 && i>0)
        {
            if(once)
            {
                i = 1;
               // RB0 = 0;
                once = 0;
            }
            i--;
            gear = gear1[i];
            
        }
        else if(key == 12)
        {
            once = 1;
           // RB0 = 1;
            i = 1;
            gear = gear1[7];
        }
}