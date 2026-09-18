/*  ANURAJ R
      25005_010
      25005B
      11 NOV 25
      PROJECT : CAN_DASHBOARD
*/
/*
 * File:   main.c
 * Author: Hp
 *
 * Created on 22 October, 2025, 3:34 PM
 */


#include <xc.h>
#include "can.h"
#include "clcd.h"
#include "main.h"

char *str[4] = {"<-  ","->  ","<-->","    "};

void itoa(int value,char* str)
{
    int i = 0;
    
    if(value == 0)
    {
        str[i++] = 48;
        str[i] = '\0';
        return;
    }
    
    while(value != 0)
    {
        str[i++] = (value % 10) + 48;
        value /= 10;
    }
    str[i] = '\0';
    
    int index = i-1;
    i=0;
    
    while(i < index)
    {
        int temp = str[i];
        str[i] = str[index];
        str[index] = temp;
        i++;
        index--;
    }
    return;
}

void init_config()
{
    TRISB = 0x00;
    PORTB = 0x00;
    
    init_clcd();
    init_can();
}

void main(void) {
    
    init_config();
    char button = 3, prev_ind;
    int delay = 0;
    uint16_t msg_id;
    uint8_t data[8], length;
    
    clcd_print("RPM:", LINE2(0));
    clcd_print("SPEED:", LINE1(0));
    clcd_print("GEAR:", LINE1(10));
    clcd_print("IND:", LINE2(8));
    
    while(1)
    {
        can_receive(&msg_id, data, &length);
        
        if(msg_id == RPM_MSG_ID)
        {
            short rpm = ((unsigned int)data[1] << 8) | (unsigned int)data[0];

            char buff[5] = {0};
            itoa(rpm,buff);
    
            if(rpm < 1000 && rpm >100)
            {
             buff[3] = ' ';
            }
            else if(rpm >10 && rpm < 100)
            {
             buff[2] = ' ';
             buff[3] = ' ';
            }
            else if(rpm >-1 && rpm < 10)
            {
             buff[1] = ' ';
             buff[2] = ' ';
             buff[3] = ' ';
            }
            clcd_print(buff, LINE2(4));
        }
        else if(msg_id == IND_MSG_ID)
        {
            button = data[0];  //ind
            clcd_print(str[button], LINE2(12));
        }
        else if(msg_id == SPEED_MSG_ID)
        {
          int speed = (int)data[0];
         
         char buff[4] = {0};
         itoa(speed,buff);
    
         if(speed < 100 && speed > 9)
         {
          buff[2] = ' ';
         }
         else if(speed > -1 && speed < 10)
         {
          buff[1] = ' ';
          buff[2] = ' ';
         }
         clcd_print(buff, LINE1(6));
        }
        else if(msg_id == GEAR_MSG_ID)
        {
          if((char)data[0] == 'C')  //gear
          {
              PORTB |= 0x18;
//              RB3 = 1;
//              RB4 = 1;
          }
          else
          {
                PORTB &= 0xE7;
//              RB3 = 0;
//              RB4 = 0;
          }
          clcd_putch((char)data[0], LINE1(15));
        }
        
        if(button == stop_ind || prev_ind != button)
        {
            PORTB = 0x00;
        }
        
        prev_ind = button;
        
        if(delay++ == 200 && button == left_ind)
        {
          //  RE0 = !RE0;
            PORTB ^= 0x03;
        }      
        else if(delay == 200 && button == right_ind)
        {
          //  RE0 = !RE0;
            PORTB ^= 0xC0;
        }
        else if(delay == 200 && button == hazard_ind)
        {
           // RE0 = !RE0;
            PORTB ^= 0xC3;
        }
        else if(delay > 200)
            delay = 0;
    }
    return;
}
