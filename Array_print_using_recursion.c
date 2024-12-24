
#include <stdio.h>

void array_print_recursion(int array[], int start, int end, int array_length)
{
       
    if(start < 0 || end > array_length)
    {
        return;
    }

    printf("%d %d ",array[start],array[end]);
    array_print_recursion(array, start - 1, end + 1,array_length);
}

main()
{
    int array[]= {1,2,3,4,5,6,7,8,9,0};
printf("\n");

int array_length = sizeof(array)/(sizeof(int));
printf("array_length = %d\n",array_length);

array_print_recursion( array, array_length/2 -1,array_length/2,array_length);
//array_print_recursion( array, 0,sizeof(array)/sizeof(int) );
printf("\n");
}