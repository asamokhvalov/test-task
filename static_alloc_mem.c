#include "static_alloc_mem.h"

unsigned char memPool[SIZE_MEMORY]; // pool of memory

M_PART mPart;

// print all memory pool
void test_print_mem_poll (void)
{
    printf("pMem: ");
    for (unsigned int i = 0; i < SIZE_MEMORY; i++)
    {
        printf("%x ", memPool[i]);
    }
    printf("\n");
}

// print memory pool structure values
void test_print_mPart (M_PART *pMem)
{
    printf("mPart struct: ");
    printf("pMemFree = %x, ", pMem->pMemFree);
    printf("blkSize = %x, ", pMem->blkSize);
    printf("blkNum = %x, ", pMem->blkNum);
    printf("blkFree = %x\n", pMem->blkFree);
}

// clear block
void PutMemBlock (M_PART *pMem,void *pBlk)
{
    unsigned char **pLink;

    if(pMem->blkFree < pMem->blkNum)
    {
        pLink = (unsigned char **)pBlk;
        *pLink = pMem->pMemFree;
        pMem->pMemFree = pBlk;
        pMem->blkFree++;
    }
}

// get address of free block
void *GetMemBlock(M_PART *pMem)
{
    void **pBlk;
    if(pMem->blkFree > 0)
    {
        pBlk = (void **)pMem->pMemFree;
        pMem->pMemFree = *pBlk;
        pMem->blkFree--;
        return pBlk;
    }
    else
        return 0;
}

// fill block by bytes
void fill_block (void * pBlk, unsigned char * arr)
{
    unsigned char * addr = (unsigned char * )pBlk;

    for (unsigned int i = 0; i < 10; i++)
    {
        *(addr + i) = arr[i];
    }
}

// initialize memory pool
void init_user_alloc (M_PART * pMem, void *addr, unsigned char size, unsigned int num)
{
	void** pLink;
	unsigned char * pBlk;

	pLink = (void**)addr;
	pBlk = (unsigned char *)addr + size;

	for (unsigned int i = 0; i < num - 1; i++)
	{
		*pLink = (void*)pBlk;
		pLink = (void **)pBlk;
		pBlk += size;
	}

	 *pLink = 0;

	pMem->pMemFree = addr;
	pMem->blkSize = size;
	pMem->blkNum = num;
	pMem->blkFree = num;
}
