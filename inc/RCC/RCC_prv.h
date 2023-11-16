#ifndef RCC_PRV_H_
#define RCC_PRV_H_

typedef struct
{
	u32 CR;
	u32 CFGR;
	u32 CIR;
	u32 APB2RSTR;
	u32 APB1RSTR;
	u32 AHBENR;
	u32 APB2ENR;
	u32 APB1ENR;
	u32 BDCR;
	u32 CSR;
	u32 AHBRSTR;
	u32 CFGR2;
	u32 CFGR3;
}RCC_t;


#define RCCp	((volatile RCC_t*)0x40021000)
#endif