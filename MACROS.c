#include <stdio.h>
#define MIN(A,B) ((A) <= (B) ? (A) : (B)); \
printf(" value in macro A=%X...B=%X.\n",A ,B);



#define MACRO_POINTER(A) *A++
//printf(" value in macro A=%X...\n",*A);



void main()
{
    int val[]={6,7,8,9,10};
    int *p = val;
    int res;

//*** NOTE SENDING A POINTER TO THE MACRO WONT WORK BECAUSE IT GETS CALLED TWICE*/


printf(" MACRO PTR %X\n",MACRO_POINTER(p));
printf(" MACRO PTR %X\n",MACRO_POINTER(p));

printf(" %X\n",*p++);
printf(" %X\n",*p++);


    res=MIN(*p++, 8);
    printf(" %d\n",res);

    res=MIN(*p++, 8);
    printf(" %X\n",res);


printf(" \n");
}