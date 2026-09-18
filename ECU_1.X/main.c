/*
 * File:   main.c
 * Author: Hp
 *
 * Created on 7 October, 2025, 10:38 PM
 */


#include <xc.h>
#include "sensor.h"
#include "common.h"
#include "clcd.h"
#include "adc.h"
#include "matrix.h"
#include "can.h"
#include "dkps.h"

#define __XTAL_FREQ 20000000

unsigned char gear1[8] = {'N','1','2','3','4','5','R','C'};
unsigned char gear;
unsigned char speed = 0;
uint16_t msg_id;
uint8_t data[8], length;

void init_config()
{
//    TRISB = 0x00; //set rb0 as o/p for led
//    PORTBbits.RB0 = 0;
    
    TRISC |= 0x0F;// set trisc as i/p
    
    //init_clcd();//initalize clcd
    init_adc();//initalize adc
    //init_matrix_keypad();//initalize matrix keypad
    init_can();
}

//void receive()
//{
//        can_receive(&msg_id, &data[0], &length);
//        
//        if(msg_id == SPEED_MSG_ID)
//        {
//         int value = (int)data[0];
//         char buff[4] = {0};
//         itoa(value,buff);
//    
//         if(value < 100 && value > 9)
//         {
//          buff[2] = ' ';
//         }
//         else if(value > -1 && value < 10)
//         {
//          buff[1] = ' ';
//          buff[2] = ' ';
//         }
//         clcd_print("SPEED:", LINE1(0));
//         clcd_print(buff, LINE1(6));
//        }
//        else if(msg_id == GEAR_MSG_ID)
//        { 
//          if((char)data[0] == 'C')
//          {
//              RB0 = 1;
//          }
//          else
//          {
//              RB0 = 0;
//          }
//          clcd_print("GEAR:", LINE1(10));
//          clcd_putch((char)data[0], LINE1(15));
//        }
//}

void main(void) {
    
    init_config();
    
    unsigned char key, once=0;
    short int i = 0;
    gear = gear1[0];
    
    while(1)
    {
        speed1();
        //receive();
        
//     clcd_print("GEAR ", LINE1(12));
//     clcd_putch(gear, LINE2(14));
        //receive();  
        
        send_data();
        
        //key = read_switches(STATE_CHANGE);
        key = switch_read(EDGE); 
        
        if(key == 0x0E && i<6)
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
        else if(key == 0x0D && i>0)
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
        else if(key == 0x0B)
        {
            once = 1;
           // RB0 = 1;
            i = 1;
            gear = gear1[7];
        }
    }
    
    return;
}

