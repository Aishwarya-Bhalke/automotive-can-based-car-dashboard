/*
 * File:   dkps.c
 * Author: Hp
 *
 * Created on 7 October, 2025, 5:48 PM
 */


#include "dkps.h"
#include <xc.h>

unsigned char switch_read(unsigned char option) //function for level and edge trigger
{
    if(option == EDGE)
    {
        static unsigned char once = 1;
        if((PORTC & 0x0F) != 0x0F && once)
        {
            once = 0;
            return (PORTC & 0x0F);
        }
        else if((PORTC & 0x0F) == 0x0F)
        {
            once = 1;
            return 0x0F;
        }
    }
    else if(option == LEVEL)
    {
        return PORTC & 0x0F;
    }
    return 0x0F;
}
