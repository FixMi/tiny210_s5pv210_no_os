#define BL2_BIN_SIZE		(32 * 1024u)
#define NAND_BLOCK_SIZE		(64u)
#define NAND_PAGE_SIZE		(2048u)

typedef unsigned int (*copy_nand_to_mem) (unsigned int  block_addr, unsigned int  page_addr, unsigned int  *trg);

void copy_code_to_dram(void)
{
	unsigned long ch;
	void (*BL2)(void);
	int i = 0;
	int pages = BL2_BIN_SIZE / NAND_PAGE_SIZE;

	// 函数指针
	copy_nand_to_mem copy_bl2 = (copy_nand_to_mem) (*(unsigned int *) (0xD0037F90));

	unsigned int ret;

	printf("copying NAND to SDRAM....\r\n");

	// 裸机程序起始blcok为20，页为0，pagesize 2k
	// 0x20000000:目的,链接地址0x20000000
	for (i=0; i<8; i++)
	{
		ret = copy_bl2(20, i, (unsigned char *)(0x20000000 + i * NAND_PAGE_SIZE));
		printf("ret: %d\r\n", ret);
	}
//	printf("ret: %d\r\n", ret);

#if 1
	{
		int i = 0;
		
			
			for (i=0; i<4*2048; i++)
			{
			//	if (i % 8 == 0) printf("\r\n");
				printf("%04x", *((unsigned short *)0x20000000 + i));
				if ((i + 1) % 8 == 0) printf("\r\n");
				else printf(" ");
			}

	
		printf("\r\n");
	}
#endif	


	printf("run BL2.....\r\n");
	// 跳转到DRAM
    BL2 = (void *)0x20000000;
    (*BL2)();
}
