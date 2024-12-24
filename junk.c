#include <stdio.h>

void init(int temp)
{
    int a = temp;
    int b;
    int c;
    int d;
}

void print(void)
{   //NOTE: here reusing the same stack space as the init() a and b varibles
    //NOTE: here reusing the same stack space as the init() a and b varibles
    //NOTE: here reusing the same stack space as the init() a and b varibles
    int x;
    printf("%d\n", x++);
}

int main()
{
    init(2);
    print();
    print();
    
    init(10);
    print();
    print();
    
    return 0;
}