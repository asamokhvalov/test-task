#include <stdio.h>
#include <stdlib.h>

#include "static_alloc_mem.h"

unsigned char test_block_0[SIZE_BLOCK] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x11, 0x22, 0x33, 0x44, 0x55};
unsigned char test_block_1[SIZE_BLOCK] = {0xDE, 0xAD, 0xBE, 0xEF, 0x55, 0xAA, 0xDE, 0xAD, 0xBE, 0xEF};
unsigned char test_block_2[SIZE_BLOCK] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE};
unsigned char test_block_3[SIZE_BLOCK] = {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11};

/*
    Test description:

    Trying to overflow poll of memory.
    When poll of memory is empty then new data should not be written
*/

int main (void)
{
    printf ("********** start programm **********\n");

	init_user_alloc (&mPart, memPool, SIZE_BLOCK, COUNT_BLOCKS); // COUNT_BLOCKS blocks per SIZE_BLOCK bytes each

    test_print_mPart (&mPart);
    test_print_mem_poll ();

    void * address_block = GetMemBlock(&mPart);

    printf ("********** write block 0 **********\n");

    // write block 0
    if (address_block)
    {
        fill_block (address_block, (unsigned char *)test_block_0);
        test_print_mem_poll ();
        test_print_mPart (&mPart);
    }
    else
    {
        printf("end of free memory\n");
    }

    address_block = GetMemBlock(&mPart);

    printf ("********** write block 1 **********\n");

    // write block 1
    if (address_block)
    {
        fill_block (address_block, (unsigned char *)test_block_1);
        test_print_mem_poll ();
        test_print_mPart (&mPart);
    }
    else
    {
        printf("end of free memory\n");
    }

    address_block = GetMemBlock(&mPart);

    printf ("********** write block 2 **********\n");

    // write block 2
    if (address_block)
    {
        fill_block (address_block, (unsigned char *)test_block_2);
        test_print_mem_poll ();
        test_print_mPart (&mPart);
    }
    else
    {
        printf("end of free memory\n");
    }

    // write block overflow
    address_block = GetMemBlock(&mPart);

    printf ("********** write block with overflow **********\n");

    if (address_block)
    {
        fill_block (address_block, (unsigned char *)test_block_3);
        test_print_mem_poll ();
        test_print_mPart (&mPart);
    }
    else
    {
        printf("end of free memory\n");
    }

    printf ("********** end programm **********\n");

    return 0;
}
