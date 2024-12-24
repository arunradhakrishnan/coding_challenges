  #include <stdio.h>
  #include <string.h>

float func_div(int value, int divisor)
{

    int remainder;
    int quotient=0;
    int post_decimal[2] ={0,0};
    
    float output =0;

    while(value > 0){
        remainder = value;
        value = value - divisor;
        quotient++;
    }
    //here "remainder" is the value of the penultimate operation..

if(remainder != 0)
{
    for(int i = 0; i < 2; i++)
    {
         //printf("remainder = %d\n", remainder);
        if(remainder == 0)
        {
            break;
        }

        value = remainder * 10;
        while(value >= 0) {
            //printf("value = %d\n", value);
            remainder = value;
            value = value - divisor;
            post_decimal[i]++;
        }
        post_decimal[i]--;
    }
}
printf("quotient = %f\n",(float)quotient);
printf("post_decimal[0] = %f\n",(float)post_decimal[0] * 0.1);
printf("post_decimal[1] = %f\n",(float)post_decimal[1] * 0.01);
output = ((float)quotient - 1.000) + ((float)post_decimal[0] * 0.1) + ((float)post_decimal[1] * 0.01); 

return output;
}

main()
{
    printf("\n %f \n",func_div(12, 5));
}