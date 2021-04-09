/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1459
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
#include <xc.h>
#include "externs.h"
#include "mcc_generated_files/mcc.h"
#include "24aa32a.h"
unsigned short measarray[52][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}, {12,13,14,15}, {16,17,18,19}, 
                                {20,21,22,23}, {24,25,26,27}, {28,29,30,31}, {32,33,34,35}, {36,37,38,39}, 
                                {40,41,42,43}, {44,45,46,47}, {48,49,50,51}, {52,53,54,55}, {56,57,58,59}, 
                                {60,61,62,63}, {64,65,66,67}, {68,69,70,71}, {72,73,74,75}, {76,77,78,79}, 
                                {80,81,82,83}, {84,85,86,87}, {88,89,90,91}, {92,93,94,95}, {96,97,98,99}, 
                                {100,101,102,103}, {104,105,106,107}, {108,109,110,111}, {112,113,114,115}, {116,117,118,119}, 
                                {120,121,122,123}, {124,125,126,127}, {128,129,130,131}, {132,133,134,135}, {136,137,138,139}, 
                                {140,141,142,143}, {144,145,146,147}, {148,149,150,151}, {152,153,154,155}, {156,157,158,159}, 
                                {160,161,162,163}, {164,165,166,167}, {168,169,170,171}, {172,173,174,175}, {176,177,178,179}, 
                                {180,181,182,183}, {184,185,186,187}, {188,189,190,191}, {192,193,194,195}, {196,197,198,199}, {200,201,202,203}, {204,205,206,207}};
unsigned char data[32] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
unsigned char byte;
unsigned char row = 0;
unsigned char column = 0;
unsigned char writecomplete = 0;
unsigned short currentEepromAddress = 0;
uint8_t numBytes;
uint8_t buffer[1];

/*
                         Main application
 */

void main(void)
{
    SYSTEM_Initialize();
    I2C_Initialize();
    CDCInitEP();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    char datas[] = {1, 2, 0xA7};
   
    
    while(1)
    {
        CDCTxService();
        
        numBytes = getsUSBUSART(buffer,sizeof(buffer));
        if(buffer[0] == 'k')
        {
            if(USBUSARTIsTxTrfReady())
                {
                    putUSBUSART(datas,3);
                    buffer[0] = 'n';
                }
        }
    }
}