#ifndef STATIC_ALLOC_MEM_H
#define STATIC_ALLOC_MEM_H

#define COUNT_BLOCKS    3
#define SIZE_BLOCK     10

#define SIZE_MEMORY COUNT_BLOCKS*SIZE_BLOCK

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	void *pMemFree;			// Free block pointer
	unsigned char blkSize;	// Size block of the partition
	unsigned int  blkNum;	// Number blocks in the partition
	unsigned int  blkFree;	// Number free blocks in the partiotion
}
M_PART;

extern M_PART mPart;
extern unsigned char memPool[SIZE_MEMORY];

void init_user_alloc (M_PART * pMem, void *addr, unsigned char size, unsigned int num);
void fill_block (void * pBlk, unsigned char * arr);
void PutMemBlock (M_PART *pMem,void *pBlk);
void *GetMemBlock(M_PART *pMem);

void test_print_mPart (M_PART *pMem);
void test_print_mem_poll (void);

#endif // STATIC_ALLOC_MEM_H
