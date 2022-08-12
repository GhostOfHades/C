#include <math.h>
#include <stdio.h>
int main()
{
    float result,value;

    printf("Input a float value: ");
    scanf("%f",&value);

    value =abs(value); //returns the number given as a positive integer
    printf("The absolute value of then value is %.2f\n",value);

    result = sqrt(value); //calculates square root of a value
    printf("The square root of %.2f is %.2f\n",value,result);  

    result = pow(value,3); //calculates the first value to the power of the second value
    printf("%.2f to the 3rd power is %.2f\n", value,result);

    result = floor(value); //rounds up float to last whole number
    printf("The floor of %.2f is %.2f\n", value,result);

    result = ceil(value); //rounds up float to next whole number
    printf("And the ceiling of %.2f is %.2f\n",value,result);

    return(0);
}