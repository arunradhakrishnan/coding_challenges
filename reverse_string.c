#include <stdio.h>
#include <string.h>

    reverse(char str[])
    {

        int start = 0;
        int end = strlen(str)-1;
        char temp;

        while(start < end)
        {
            temp = str[end];
            str[end]=str[start];
            str[start] = temp;
            start++;
            end--;
        }
    }



main()
{
    char str[] = "asdfasdf";
    reverse(str);
    printf("\n%s\n",str);

}