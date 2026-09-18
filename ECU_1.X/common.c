/*
 * File:   common.c
 * Author: Hp
 *
 * Created on 9 October, 2025, 11:49 AM
 */


#include <xc.h>

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
