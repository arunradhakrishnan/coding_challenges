#include <stdio.h>
#include <stdint.h>


//32 -(10+5)


uint32_t read_bits(uint32_t regval, int start, int length)
{
    if (start < length)
        return -1;

//generate the mask with appropreate length
    int mask = 1;
    for(int i = 0 ; i < length-1; i++)
    {
        mask = mask|mask<<1;
    }
    printf("mask %X\n",mask);
    regval = regval >> (start - length);

    printf("regval = 0x%X\n", (regval & mask));

    return regval & mask;
}

uint32_t write_bits(uint32_t regval, int start, int length, int writeval)
{

    int mask = 1;
    for(int i = 0; i < length - 1; i++)
    {
        mask = mask | mask << 1;
    }


    if(writeval > mask)
    {
        printf("ERRROR\n");
        return -1;
    }

    writeval = writeval << start+1;
    mask = mask << start+1;

    regval = regval & ~mask;//makeing the specified field values 0
    printf("cleaned up write value 0x%x\n",regval);
    regval = regval |writeval;

    printf("write value 0x%x\n",regval);
}

main()
{
uint32_t regval = 0xfffffffff;
write_bits(regval, 15, 8, 0xff);
read_bits(regval,15 ,8);
}