#include <stdio.h>




swap_two_bits_option1()
{
    int input  = 0x31;
    int bit1_to_swap = 2;
    int bit2_to_swap = 8;

    int temp1 = 1;
    for(int i = 0; i < bit1_to_swap; i++)
    { 
        temp1 = temp1 << 1;
    }
    printf("temp1 0x%x\n", temp1);
        if((input & temp1) == 0)//bit is 0
           input = input | temp1;
         else
           input = input & ~temp1;

    temp1 = 1;
    for(int i = 0; i < bit2_to_swap; i++)
    { 
        temp1 = temp1 << 1;
    }
    printf("temp1 0x%x\n", temp1);
        if((input & temp1) == 0)
            input = input | temp1;
        else
            input = input & ~temp1;



printf(" 0x%x\n\n",input);

}

main()
{
swap_two_bits_option1();
}
