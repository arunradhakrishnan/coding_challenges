#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_VAL -1

char header[] = "header";
int header_pointer = 0; 
int header_read_done_flag = 0 ;


int data_size_read_done_flag = 0 ;

char data_size[2];
int data_size_pointer = 0;
int data_size_val = 0;
int data_pointer = 0;


int read_data(char input)
{
    while(data_size_val > 0 )
    {
        printf("%c",input);
        data_size_val--;
        return;
    }
}

int read_data_size(char input)
{
    printf("input  %c\n",input);
    data_size[data_size_pointer] = input;
    data_size_pointer++;

    if(data_size_pointer >= 1)
    {
        data_size_read_done_flag = 1;
        data_size_val = atoi(data_size);
        printf("data_size = %d\n",data_size_val);
    }

    if(!data_size_val)
        return ERR_VAL;

}


int parse_stream(char input)
{
    if((input == header[header_pointer]) && (header_read_done_flag == 0))
    {
        printf("header_pointer = %d\n",header_pointer);
        header_pointer++;
    }
    else
    {
        header_pointer == 0;
        
    }
    if((header_pointer == (6)) && (header_read_done_flag == 0))
    {
        //printf("header read_done**");
        header_read_done_flag = 1;
        return 0;
    }

    if((header_read_done_flag == 1) && (data_size_read_done_flag == 0))
    {
        printf("read_data_size\n" );
        if(read_data_size(input) == ERR_VAL )
            return ERR_VAL; 
        return 0;
    }

    if((header_read_done_flag == 1) && (data_size_read_done_flag == 1))
    {
        read_data(input);
    }
}





int main()
{
    char arr[] = "header41234footer";
    for(int i = 0 ; i < sizeof(arr);i++)
    {
        //printf(" %c\n",arr[i]);
        parse_stream(arr[i]);
    }

printf("\n");
return 0;
}