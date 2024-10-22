#include <stdio.h>
#include <stdint.h>






int buffer_parse(uint8_t  *  input_data, uint32_t  input_size)
{
uint32_t   output_data[100]  =  {0};
int  j = 0;

int count = 0;
    for(int i =0; i < input_size; i++)
    {

         printf("  %d = 0x%x \n",i,input_data[i]);
        if(input_data[i] & 0x80)
        {
            output_data[j] = (output_data[j] << 8) | (input_data[i] & 0x7f);
            j++;
            count=0;
        }
        else
        {
            output_data[j] =  (output_data[j] << 8) | input_data[i];
        }
        count++;
         if(count%4==0)
         {
             j++;
         }
         

    }

    for(int i = 0; i <= j; i++)
        printf(" 0x%x  ",output_data[i]);
    printf("\n");

return 0;

}


main()
{
    uint8_t  data[] = {0xff,0x22,0x33,0xf4,0x55,0x66};

    printf("start...\n");


uint32_t retval = buffer_parse(data,sizeof(data));
     printf("%d\n",retval);


}