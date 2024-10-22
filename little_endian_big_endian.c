
#include <stdio.h>
main()
{
    unsigned int x = 0xffff0000;
    char * temp = &x;


    if(*temp  == 0)
    {
        printf("little endian %x\n\n",*temp);
    }
    else
    {
        printf("big endian %x\n\n",*temp);
    }
    return;
}