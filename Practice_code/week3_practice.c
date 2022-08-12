#include <stdio.h>
#include <math.h>

void question1 (void)
//Write a program to generate and display a table of n and n2, for integer values of n ranging from 1 to 10.

{
   int inum=1;
   for (inum=1;inum<=10;inum++)
   {
      printf("%d\t%d\n",inum, inum*inum); 
   }
}

void question2 (void)
//Write a program to generate and print a table of the first 10 factorials
{
    int inum,isum=1;
   for (inum=1;inum<=10;inum++)
   {
      isum=isum*inum;
      printf("%d\t%d\n",inum, isum); 
   }
}

/*int question3(void)
{
    char input[20];
    int icount=0,isum=-1;
    printf('please enter a positive number\n');
    scanf(" %c",&input);
    for (icount=0;icount<20;icount++)
    {
        if (input[icount]=="0")
        isum=isum+1;
        if (input[icount]=="1")
        isum=isum+1;
        if (input[icount]=="2")
        isum=isum+2;
        if (input[icount]=="3")
        isum=isum+3;
        if (input[icount]=="4")
        isum=isum+4;
        if (input[icount]=="5")
        isum=isum+5;
        if (input[icount]=="6")
        isum=isum+6;
        if (input[icount]=="7")
        isum=isum+7;
        if (input[icount]=="8")
        isum=isum+8;
        if (input[icount]=="9")
        isum=isum+9;
        if (isum==-1)
        {
            printf("please enter a positive number");
            return -1;
        }
    }
    //unsure of the rest
}*/

void question4(void)
//compute the sum of digits of a single number
{

}

int maximum ( int values[], int numElements)
{
    int maxValue, i;
    maxValue=values[0];
    for (i=1;i<numElements;i++)
    {
        if (values[i]<maxValue)
            maxValue=values[i];
    }
    return maxValue;
}

void question5(void)
//obtain numbvers and print out the largest number
{
     int array[10],count=0;
    for (count=0;count<10;count++);
    {
            scanf(" %d", &array[count]);
    }
    printf("The minimum value given is: %d\n",maximum(array[10],10));
}

void question6(void)
//same as Q5 but does the second largest number aswell
{

}

int question7(void)
//given 3 numbers, assort them from smallest to largest
{
    int count[3];
    return 0;
}

void question8 (void)
/*Given an integer number X and a value n, write a program that prints an output that is made up of the first n digits of the number X, followed
by the first n-1 digits of the number X, and so on. Your program must check that the value n is smaller than the number of digits in the number X.*/
{
    int xNumber = 0, nNumber = 0;
    printf("Please enter values x and n: ");
    scanf("%d %d", &xNumber, &nNumber);

    int limit = pow(10, nNumber);
    if(limit > xNumber)
    {
        printf("You must enter a number that has more digits than n");
        return 0;
    }

    //12345 3
    //12345 -> 123

    while(xNumber > limit)
        xNumber /= 10;
    printf("New xNumber: %u\n", xNumber);

    unsigned long long int newNum = xNumber;
    while(--nNumber > 0)
    {
        xNumber /= 10; //12
        newNum *= pow(10, nNumber);
        //123 -> 12300
        newNum += xNumber;
    }

    printf("Output = %llu", newNum);
}

void question9 (void)
//test whether a string is a palindrome (same forward and back)
{
    int number = 0, reversed = 0, temp;
    printf("Please enter a number: ");
    scanf("%d", &number);

    //Reverse number
    temp = number;
    do{
        reversed *= 10;
        reversed += temp % 10;
        temp /= 10;
    }while(temp > 0);

    //Check if palindrome
    if(number == reversed)
        printf("%d is a palindrome\n", number);
    else
        printf("%d is NOT a palindrome\n", number);

}

void question10 (void)
//convert binary numbers into decimals
{
    int binNum = 0, decNum = 0, counter = 0;
    printf("Please enter a binary number: ");
    scanf("%d", &binNum);

    //conversion
    while(binNum != 0){
        if(binNum % 10)
            decNum += pow(2, counter);
        binNum /= 10;
        counter ++;
        }

    printf("Decimal equivalent =%d", decNum);
}

void question11 (void)
//calculate pi in a weird way
{
    int i, n;
    double pi = 0.0;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        if(i % 2 == 0)
            pi = pi - 4.0 / (i * 2 - 1);
        else
            pi = pi + 4.0 / (i * 2 - 1);
    }
    printf("%lf\n", pi);
}

void question12 (void)
/*Write a program that reads in the size of an array and the array elements (all of which are integers). The program then prints out an array that contains the exact same 
numbers as the original given array, but with the array elements rearranged such that all the even numbers come before all the odd numbers. Other than the latter requirement,
the numbers can be in any order. Challenge: Instead of using a new array to store the rearranged numbers, try to rearrange the numbers in the original given array itself.*/
{
    int n, temp;
    printf("Please enter size of array: ");
    scanf("%d", &n);
    int x[100];
    printf("enter %d values: ", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    int i = 0, j = n-1;
    while(i < j){
        while(i < j && x[i] % 2 == 0) //skip even on left
            i++;
        while(j >= 0 && x[j] % 2 == 1)//skip odd on right
            j--;
        if(i < j)
        {
            temp = x[i];
            x[i] = x[j];
            x[j] = temp;
            i++;
            j--;
            }
        }

    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);
    printf("\n");
}

void question13 (void)
/*Write a program that reads in 20 integer numbers, each of which is between 1 and 10, inclusive. Use an array to store the numbers as they are 
being read in, if and only if that number is not a duplicate of a number already read. Print out the array containing non-duplicate numbers.*/
{
    int array[20], temp = 0, size = 0, flag = 0;
    printf("Please enter 20 numbers:\n");
    for(int i = 0; i < 20; i++){
        scanf("%d", &temp);
        flag = 1;
        //check if element is in array
        for(int j = 0; j < size; j++)
            if(array[j] == temp)
                flag = 0;
        //Add element to array
        if(flag)
            array[size++] = temp;
    }

    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

void question14 (void)
/*Write a program that reads in the size of an array and the array elements (all of which are integers). Print a 
version of the given array where each zero value in the array is replaced by the largest odd value to the right of the
zero in the array. If there is no odd value to the right of the zero, leave the zero as a zero.*/
{
    int array[20], size = 0;
    printf("Please enter a size: ");
    scanf("%d ", &size);

    //read values into array
    for(int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    //convert 0's to next-most largest odd number

    int j = 0, ref = 0;
    for(int i = 0; i < size; i++){
        if(array[i] == 0){
            j = i + 1;
            //find next odd number
            while(j < size && array[j] % 2 == 0)
                j++;
            if(j < size)
                array[i] = array[j];
        }
    }
    printf("Adapted: ");
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

void question15 (void)
/*. Write a program that reads in the size of an array and the array elements (all of which are integers). Find the number of indexes in the array such that the 
sum of elements at lower indexes is equal to the sum of elements at higher indexes. For example given an array {-7, 1, 5, 2, -4, 3, 0}, one of such indexes is index 3 because

-7 + 1 + 5 = -4 + 3 + 0
Given the same array, another of such indexes is index 6 because
-7 + 1 + 5 + 2 – 4 + 3 = 0
Therefore, the number of such indexes in the given array would be 2.*/
{
    int n, x[10], count=0, left, right;
    printf("Enter array size: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    for(int i = 0; i < n; i++){
        left = 0;
        right = 0;
        for(int j = 0; j < i; j++)
            left += x[j];
        for(int j = i+1; j < n; j++)
            right += x[j];
        if(left == right){
            printf("Index: %d\n", i);
            count++;
        }

    }

    printf("Found %d indexes\n", count);
}

void evalq (void)
//solve a matrix sum equation
{
    int matrix1[3][3],matrix2[3][3],matrixans[3][3],count=0,icount=1;
    //obtaing matrix 1 values
    printf("please enter the digits of the first matric one at a time\n");
    while (icount<=3)
    {
        count=0;
        while (count<=3)
            {
            scanf(" %d",&matrix1[count][icount]);
            count++;
            if(count==3)
            {break;}
            }
        icount++;
    }
    icount=1;
    while (icount<=3)
    {
        count=0;
        while (count<=3)
            {
            printf(" %d",matrix1[count][icount]);
            printf("\t");
            count++;
            if(count==3)
            {break;}
            }
        printf("\n");
        icount++;        
    }

    printf("\n");
    //obtaining matrix 2 values
    printf("please enter the digits of the second matrix one at a time\n");
    count=0;
    icount=1;
    while (icount<=3)
    {
        count=0;
        while (count<=3)
            {
            scanf(" %d",&matrix2[count][icount]);
            count++;
            if(count==3)
            {break;}
            }
        icount++;
    }
    icount=1;
    while (icount<=3)
    {
        count=0;
        while (count<=3)
            {
            printf(" %d",matrix2[count][icount]);
            printf("\t");
            count++;
            if(count==3)
            {break;}
            }
        printf("\n");
        icount++;        
    }

    //adding the two matrices
    printf("The sum of your two matrices is:\n");
    count=0;
    icount=1;
    while (icount<=3)
    {
        count=0;
        while (count<=3)
            {
            printf(" %d",((matrix1[count][icount])+(matrix2[count][icount])));
            printf("\t");
            count++;
            if(count==3)
            {break;}
            }
        printf("\n");
        icount++;        
    }
}


int main (void)
{
    question5();
    return 0;
}