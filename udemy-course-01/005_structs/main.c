/******************************************************************************
* @file          :main.c
* @author        :Paul Barrionuevo
* @brief         : Two exercises to learn define and structs 
*                  Exercise to decode a given 32bit packet information and print the values from the different fields
*                  Create a struct of member elements as packet fields.
* 
***************************************************************************

Manipulate exercise structure with bit fields

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint32_t crc:2;        // 2 bits
    uint32_t status:1;     // 1 bit
    uint32_t payload:12;    // 12 bits
    uint32_t bat:3;        // 3 bits
    uint32_t sensor:3;     // 3 bits 
    uint32_t longAddr:8;   // 8 bits
    uint32_t shortAddr:2;  // 2 bits
    uint32_t addrMode:1;   // 1 bits
    
} Packet_t;

int main()
{
    volatile uint32_t packet;
    Packet_t packet_t;

    printf("Enter an address value of 32bits: ");
    scanf("%x", &packet);
    
    packet_t.crc = (uint8_t) (packet & 0x3);
    packet_t.status = (uint8_t) ((packet >> 2) & 0x1);
    packet_t.payload = (uint16_t) ((packet >> 3) & 0xFFF);
    packet_t.bat = (uint8_t) ((packet >> 15) & 0x7);
    packet_t.sensor = (uint8_t) ((packet >> 18) & 0x7);
    packet_t.longAddr = (uint8_t) ((packet >> 21) & 0xFF);
    packet_t.shortAddr = (uint8_t) ((packet >> 29) & 0x3);
    packet_t.addrMode = (uint8_t) ((packet >> 31) & 0x1);

    
    printf("crc         :%#x \n", packet_t.crc);
    printf("status      :%#x \n", packet_t.status);
    printf("payload     :%#x \n", packet_t.payload);
    printf("bat         :%#x \n", packet_t.bat);
    printf("sensor      :%#x \n", packet_t.sensor);
    printf("longAddr    :%#x \n", packet_t.longAddr);
    printf("shortAddr   :%#x \n", packet_t.shortAddr);
    printf("addrMode    :%#x \n", packet_t.addrMode);


    printf("Size of the structure is: %ld \n", sizeof(packet_t) );


    return 0;
}

/******************************************************************************

*******************************************************************************/
//#include <stdio.h>
//#include <stdint.h>
//
//typedef struct
//{
//    char crc;        // 2 bits
//    char status;     // 1 bit
//    short payload;    // 12 bits
//    char bat;        // 3 bits
//    char sensor;     // 3 bits 
//    char longAddr;   // 8 bits
//    char shortAddr;  // 2 bits
//    char addrMode;   // 1 bits
//    
//    
//} Packet_t;
//
//int main()
//{
//    volatile int packet;
//    Packet_t packet_t;
//
//    printf("Enter an address value of 32bits: ");
//    scanf("%x", &packet);
//    
//    packet_t.crc = (uint8_t) (packet & 0x3);
//    packet_t.status = (uint8_t) ((packet >> 2) & 0x1);
//    packet_t.payload = (uint16_t) ((packet >> 3) & 0xFFF);
//    packet_t.bat = (uint8_t) ((packet >> 15) & 0x7);
//    packet_t.sensor = (uint8_t) ((packet >> 18) & 0x7);
//    packet_t.longAddr = (uint8_t) ((packet >> 21) & 0xFF);
//    packet_t.shortAddr = (uint8_t) ((packet >> 29) & 0x3);
//    packet_t.addrMode = (uint8_t) ((packet >> 31) & 0x1);
//
//    
//    printf("crc         :%#x \n", packet_t.crc);
//    printf("status      :%#x \n", packet_t.status);
//    printf("payload     :%#x \n", packet_t.payload);
//    printf("bat         :%#x \n", packet_t.bat);
//    printf("sensor      :%#x \n", packet_t.sensor);
//    printf("longAddr    :%#x \n", packet_t.longAddr);
//    printf("shortAddr   :%#x \n", packet_t.shortAddr);
//    printf("addrMode    :%#x \n", packet_t.addrMode);
//
//
//    printf("Size of the structure is: %ld \n", sizeof(packet_t) );
//
//
//    return 0;
}