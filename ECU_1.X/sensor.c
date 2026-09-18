/*
 * File:   sensor.c
 * Author: Hp
 *
 * Created on 7 October, 2025, 5:48 PM
 */


#include <xc.h>
#include "clcd.h"
#include "adc.h"
#include "common.h"
#include "can.h"

extern unsigned char gear;
extern unsigned char speed;
void speed1()
{
    speed = read_adc(CHANNEL4) / 10.23;
    
//    can_transmit(SPEED_MSG_ID, &speed, 1);
    
//    char once=0, time=1, buff[4] = {0};
//    itoa(value,buff);
//    if(value < 100 && value > 9)
//    {
//        buff[2] = ' ';
//    }
//    else if(value > -1 && value < 10)
//    {
//        buff[1] = ' ';
//        buff[2] = ' ';
//    }
//    clcd_print("SPEED", LINE1(0));
//    clcd_print(buff, LINE2(1));
//    
//     if(value == 100 && time)
//     {
//         once = 1;
//         time = 0;
//     }
//     else if(value == 10 && time)
//     {
//         once = 1;
//         time = 0;
//     }
//     
//     if(once)
//     {
//         CLEAR_DISP_SCREEN;
//         once = 0;
//     }
//     
//    if(value != 100 && value != 10)
//    {
//        time = 1;
//    }
    
}

void send_data()
{
    char data[1];
    data[0] = speed;
    can_transmit(SPEED_MSG_ID, data, 1);
    for(int i =1000; i>0; i--);
    
    //char data1[1];
    data[0] = gear;
    can_transmit(GEAR_MSG_ID, data, 1);
    for(int i =1000; i>0; i--);
}