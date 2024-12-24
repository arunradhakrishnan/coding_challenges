#include <stdint.h>
#include <stdio.h>

#define CLEAR_LOWER_BITS_FLAG  0xCCCCCCCC


int swap_higher_nibble_bits(uint32_t input)
{
    int only_high_bits = input & CLEAR_LOWER_BITS_FLAG;
    
    uint8_t nibble[8];
    for(int i = 0 ; i < 8; i++)
    {
        nibble[i] = only_high_bits & 0xC; // Extract the last nibble
        printf("only_high_bits 0x%x nibble =0x%x \n",only_high_bits,nibble[i]);
        switch (nibble[i])
        {
            case 0:
            case 0xC:
                break;
            case 4:
                nibble[i] = 8;
                break;
            case 8:
                nibble[i] = 4;
                break;
            default :
                break;  

        }
        //printf("only_high_bits 0x%x nibble =0x%x \n",only_high_bits,nibble[i]);
        only_high_bits = only_high_bits >> 4;
    }

int updated_higer_bits =  nibble[7] << 28 |
                            nibble[6] << 24 |
                            nibble[5] << 20 |
                            nibble[4] << 16 |
                            nibble[3] << 12 |
                            nibble[2] << 8 |
                            nibble[1] << 4 |
                            nibble[0];

input = input & 0x33333333; //clear higher bits from the input

input = input | updated_higer_bits;

return input;
}

int main()
{
    printf("val = 0x%x\n",swap_higher_nibble_bits(0x88888888));
    printf("val = 0x%x\n",swap_higher_nibble_bits(0x4C8));
    return 0;
}
