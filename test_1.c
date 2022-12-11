#include <stdio.h>
#include <stdlib.h>

#include "static_alloc_mem.h"

/*
    Test description:

    Trying to allocate block of memory from @memPool.
    After that read allocated block and see what is happening in @mPart structure. This block is free or not.
*/

unsigned char test_block_0[SIZE_BLOCK] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x11, 0x22, 0x33, 0x44, 0x55};

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

    printf ("********** read block 0 **********\n");

    // read block 0
    unsigned char * addr_block_0 = &(memPool);

    printf("addr_block_0 = %x\n", addr_block_0);

    PutMemBlock (&mPart, addr_block_0);
    test_print_mem_poll ();
    test_print_mPart (&mPart);

    printf ("********** end programm **********\n");

    return 0;
}
