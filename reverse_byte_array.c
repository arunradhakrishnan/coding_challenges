#include <stdio.h>
#include <stdint.h>


void swap(uint8_t * val1, uint8_t * val2)
{
uint8_t temp;

temp = *val1;
*val1 = *val2;
*val2 = temp;
}

void reverse_byte_array(uint8_t input_buffer[],int length  )
{
    int i = 0;
    int j = length - 1;
    while(i < length/2)
    {
        swap(&input_buffer[i], &input_buffer[j]);
        i++;
        j--;
    }
return;
}



uint32_t little_endian_2_big_endian(uint32_t input)
{
    uint32_t output = 0;

uint8_t nibble1 = input    & 0xff;
uint8_t nibble2 = input>>8 & 0xff ;  
uint8_t nibble3 = input>>16 & 0xff ;  
uint8_t nibble4 = input>>24 & 0xff ;  

output =  nibble1<<24|nibble2<<16|nibble3<<8|nibble4;

return output;
}



main()
{
    uint8_t  input_array[] = {0x11,0x22,0x33,0x44,0x55,0x66};

    printf("start...\n");

    // reverse_byte_array(input_array,6 );
    // for(int i  = 0 ; i < 6 ; i++)
    //     printf("0x%x\n",input_array[i]);



uint32_t retval = little_endian_2_big_endian(0xFFEEDDCC);
     printf("0x%x\n",retval);


}