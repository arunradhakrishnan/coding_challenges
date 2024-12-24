#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int i;
    int *ptr = (int *) malloc(5 * sizeof(int));

    for (i=0; i<5; i++)
    {
        *(ptr + i) = i;
      
    }



//printf("getpagesize() =0x%x\n",getpagesize());

//DEREFERENCE THEN INCREMENT!!!!

 printf("%p ", (void *)ptr);  printf("%d \n", *((ptr++)));
   printf("%p ", (void *)ptr);  printf("%d \n", *ptr++);
   printf("%p ", (void *)ptr);  printf("%d \n", *ptr++);
   printf("%p ", (void *)ptr);  printf("%d \n", *ptr++);
   printf("%p ", (void *)ptr);  printf("%d \n", *ptr++);
   printf("%p ", (void *)ptr);
   
   printf("\n");
// printf("%p \n", (void *)ptr);
// printf("%p \n", (void *)(ptr++));
// printf("%p \n", (void *)ptr++);
    printf("%p %d %p %d\n", (void*)(ptr++),*ptr,(void*)ptr,*ptr);
    printf("%d %d\n", *(ptr++),*ptr);
    // printf("%d \n", (*ptr)++);
    // printf("%d \n", *ptr);
    // printf("%d \n", *++ptr);
    // printf("%d \n", ++*ptr);
}

