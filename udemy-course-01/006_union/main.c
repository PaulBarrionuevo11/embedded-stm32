/******************************************************************************

* @file          : main.c
* @author        : Paul Barrionuevo
* @brief         : Same exercise as with structures but adding union
*                  in order to bring mutual exclusion between memory address
*                  (same variable size) 

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

union Packet
{
    uint32_t packetValue;
    struct
    {
        uint32_t crc        :2;     // 2 bits
        uint32_t status     :1;     // 1 bit
        uint32_t payload    :12;    // 12 bits
        uint32_t bat        :3;     // 3 bits
        uint32_t sensor     :3;     // 3 bits 
        uint32_t longAddr   :8;     // 8 bits
        uint32_t shortAddr  :2;     // 2 bits
        uint32_t addrMode   :1;     // 1 bits
        
    } s_packet;
    
};

int main()
{
    union Packet new_packet;

    printf("Enter an address value of 32bits: ");
    scanf("%x", &new_packet.packetValue);

    
    printf("crc         :%#x \n", new_packet.s_packet.crc);
    printf("status      :%#x \n", new_packet.s_packet.status);
    printf("payload     :%#x \n", new_packet.s_packet.payload);
    printf("bat         :%#x \n", new_packet.s_packet.bat);
    printf("sensor      :%#x \n", new_packet.s_packet.sensor);
    printf("longAddr    :%#x \n", new_packet.s_packet.longAddr);
    printf("shortAddr   :%#x \n", new_packet.s_packet.shortAddr);
    printf("addrMode    :%#x \n", new_packet.s_packet.addrMode);


    printf("Size of the structure is: %ld \n", sizeof(new_packet) );


    return 0;
}