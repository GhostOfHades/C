#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//stdlib allowes for functions such as
//malloc()      -   which allocates a size of memory to a pointer (not conversion type specific)(returns a pointer)
//calloc()      -   same as malloc, slight difference to code
//free()        -   realeases memory that has been allocated
//system("cls") -   which clears the terminal

#include <string.h>
//string.h allows for functions such as
//strlen()      -   returns the length of the string(in characters)
//strcpy()      -   copies one string to another
//strcat()      -   adds one string to the end of another
//strcmp()      -   compares two strings to see if they are equal (exact same characters, returns non-zero int if NOT equal)

#include <ctype.h>
//ctype.h allows for functions such as
//toupper       -   takes a char and returns the same char as a upper case char
//tolower       -   takes a char and returns the same char as a lower case char
//isupper       -   checks whether a char is upper case and returns 0 if it is not
//islower       -   checks whether a char is lower case and returns 0 if it is not
//isspace       -   checks whether a char is white space and returns 0 if it is not
//isalnum       -   checks whether a char is a number or letter (returns 0 if not)
//isalpha       -   checks whether a char is an alpahabetical letter (returns 0 if not)
//isdigit       -   checks whether a char is a digit (returns 0 if not)

//A pointer is a memory address

void print_memory_sizes (void)
{
    printf("type\t\tbyte size\t values sizes\n");
    printf("==============================================================================\n");
    printf("char\t\t 1\n");
    printf("int\t\t 4\t\t -2,147,483,648 to 2,147,483,647 \n");
    printf("short int\t 2\t\t -32,768 to 32,767\n"); 
    printf("long int\t 8\t\t -9223372036854775808 to 9223372036854775807\n");
    printf("float\t\t 4\t\t 1.2E-38 to 3.4E+38\n");
    printf("double\t\t 8\t\t 2.3E-308 to 1.7E+308\n");
    printf("long double\t 10\t\t 3.4E-4932 to 1.1E+4932\n"); 
    printf("==============================================================================\n");
    return;
}

void lecture_code1 (int a, int b)
//what are pointers
{

    //  &ch yields the value 0x2000 (stored in hexadecimals)
    //  & <- is known as the address operator

    printf("values for intergers are a = %d , b = %d \n", a, b); //prints the value of the intergers
    printf("the storage loactions of the entergers are a = %p , b = %p \n", &a, &b); //prints the storage location for a and b

    //  "%p" and "& (variable)" are used to obtain the proper memory address (%x conversion specifier can be used aswell, but %p gives full address and is preferred)
    //  Stroage location of integers are 4 units apart as eachinteger contains 4 bytes of storage
    //  b is stored first, stoarge stacks backward from limit down
    //  Addresses cant be changed 
    return;
}

void lecture_code2 (int a , int b)
//using and setting variables as memory addresses
{
    int *ptra = NULL, *ptrb = NULL ;

    //  NULL sets pointer to a address thats imposible to use until it is initialized in the code, else pointer is random and could cause issues with your PC

    /*
        pointers can be decaled in many ways, such as:
        int* ptr;
        int * ptr

        if the pointer is declared as int *a,b,c
        only a will be a pointer, while the rest are integers
        for all to be pointers, use:
        int *a, *b, *c ;
    */

    //  *ptr can hold the address of an integer, hence ptr is a pointer to a integer
    //  the " * " before chPtr, shows that chPtr does not hold a char, but rather the variable address of ch (using & to show that the address is needed)
    
    printf("values for intergers are a = %d , b = %d \n\n", a,b);

    ptra = &a;
    ptra = &b;

    printf("the storage loactions of a is %p\n", ptra);
    printf("the storage loactions of b is %p\n\n", ptra+2);

    //checking how many storage locations away from a, b is (2 storage spaces... should be 1 but IDK)

    printf("the storage loactions of a is %p\n", &a); 
    printf("the storage loactions of b is %p\n", &b);

    //  Don't use " & " in printf else the wrong address will be called
    //  The value stored in ptr will be the address of a, which is "000000e9cf5ff880"

    printf("the storage loactions of ptr is %p\n\n", &ptra);
    
    //  Using &ptr prints the address of ptr, not the address of a

    printf("the integer value in the address of ptr is = %d, which is a\n\n",*ptra);

    //  " * " means "value of", hence using *ptr, printf delivers the value of the interger (or whatwever other storage type) that is located in address ptr (for this code, it is a = 10)

    *ptra = 50;
    printf("the new value of a is = %d\n", a);
    *(ptra +2)=5;
    printf("the new value of b is = %d\n\n", b);

    //  *ptr refers to the data in location ptr (int a), therefore this changes a from 10 to 50
    //  adding or subtarcting nubers from pointers will then point to ther locations (+2 leading the pointer to 2 integer storage addresses backward, directing the address to b (this was checked before))
    return; 
}

void lecture_swap_code (int *a, int *b)
//uses variable addresses instead of making variables that represent given values
{
    int temp;
    temp = *a;
    *a=*b;
    *b = temp;
    return;
}

void lecture_code3 (void)
{
    int array[3] = {10, 20, 30};
    int *arrayPtr =NULL;
    arrayPtr = array;
    for (int i=0; i<3;i++)
    {
        printf("array[%d] =%d\n",i, array[i]);
        printf("array[%d] =%d\n",i, *(arrayPtr+i));
        printf("array[%d] =%d\n",i, *(array+i));
    }
    //  all 3 array statements are the same
    return;
}

void lecture_code4 (void)
{ 
    //  allocate memory for array of 10 integers
    int *ptr =  (int *)malloc(10*sizeof(int));

    if (ptr== NULL)
    {
        printf("malloc failed\n");
        return;
    }
    //  precaution if malloc cannot allocate the desired amount of storage

    free(ptr);
    //  release memory allocated by malloc
    ptr =  (int *)calloc(10,sizeof(int));
     if (ptr== NULL)
    {
        printf("calloc failed\n");
        return;
    }   
    free(ptr);
    //  calloc is the same as malloc, slight different code, initilized all stored data to 0's (as apposed to nothing like malloc)
    //  before you free ptr, you may use the memory of ptr as an array

    //  note that once memory is free, it does not automatically clear, this should be done before releasing.
    return;
}

void lab_q1 (void)
{
    char sentence[10];
    int sentencelength;
    printf("enter a word\n");
    scanf(" %s",sentence);
    sentencelength = strlen(sentence);
    printf("your word is %d character(s) long",sentencelength);
    return;
}

void lab_q1_2 (void)
{
    char sentence[50];
    int sentencelength, count;
    printf("enter a word\n");
    scanf(" %s",sentence);

    for (count=0;sentence[count]!='\0';count++)
    {   
        printf("");
    }
    printf("the length of the word is %d",count);
    return;
}

void lab_q2 (void)
{
    char line[50];
    int count;
    printf("enter a word\n");
    scanf(" %s",line);
    for (count=0;line[count]!='\0';count++)
    {   
        if (isupper(line[count])==0)
        printf("%c",toupper(line[count]));

        if (islower(line[count])==0)
        printf("%c",tolower(line[count]));       
    }
    return;
}

void lab_q3 (void)
{
    char line[50];
    int count,rlength;
    printf("enter a word\n");
    scanf(" %s",line);
    rlength=strlen(line);
    char rline[rlength];
    for (count=0;line[count]!=0;count++)
    {
        printf("%c",line[(rlength-1)-(count)]);
    }
    return;
}

void lab_q4 (void)
{
    int count,out=0,length;
    char line[50],req;  
    printf("enter a word\n");
    scanf("%s",&line);
    length = strlen(line);
    printf("enter a letter\n");   
    scanf(" %c",&req);
    for (count=0;count<=length;count++)
    {
        if (line[count]==req)
        {
            out= out+1;  
        }
    }
    printf("letter %c\n",line[0]); 
    printf("letter %c appears %d times",req,out);
}

void lab_q5 (void)
{
    char next='B',current='y';
    char *ptr;
    ptr=&current;
    *ptr='0';
    ptr=&next;
    *ptr='d';
    printf("ptr has %c stored\nnext has %c stored\ncurrent has %c stored",*ptr,next,current);

}

void lab_q7 (void)
{
    int count,out=0,length;
    char line[50],req,change;  
    printf("enter a word\n");
    scanf("%s",&line);
    length = strlen(line);
    printf("enter the old letter\n");   
    scanf(" %c",&req);
    printf("enter the new letter\n");   
    scanf(" %c",&change);   
    for (count=0;count<=length;count++)
    {
        if (line[count]==req)
        {
            line[count]=change;  
        }
    }
    printf("%s",line);    
}

void lab_q8 (void)
{
    int count,length;
    char line[50],req,change;  
    printf("enter a word\n");
    scanf("%s",&line); 
    printf("enter how many letters you want of the word\n");
    scanf(" %d",&length);
    for (count=0;count<length;count++)
    printf("%c",line[count]);  
}

void lab_q9 (void)
{
    int count,icount=0,length;
    char line[50],req;  
    printf("enter a word\n");
    scanf("%s",&line);
    length = strlen(line);
    char lout[length];
    printf("enter the old letter\n");   
    scanf(" %c",&req);  
    for (count=0;count<=length;count++)
    {
        if (line[count]!=req)
        {
            lout[icount]=line[count];
            icount++;
        }
    }
    printf("%s",lout);     
}

void lab_q10(void)
{
  //dont understand tyhe question  
}

void lab_q11(void)
{
    char line[100];
    int change,count,temp1=1,temp2=0,temp3=1,length;
    //use isspace and isalnum
    printf("please eneter a sentence\n");
    scanf(" %s",line);
    length=strlen(line);
    if (isspace(line[0])==0)
    change++;
    for (count=0;count<length;count++)
    {

    }
    printf("%d",change);
}

void lab_q12 (void)
{
    char line[50];
    int count,rlength;
    printf("enter a word\n");
    scanf(" %s",line);
    rlength=strlen(line);
    char new[rlength],old[rlength];
    for (count=0;count<rlength;count++)
    {
        old[count]=line[count];
        new[count]=(line[(rlength-1)-(count)]);
    }
    if (strcmp(new,old)==0)
    printf("the line given is a palindrome");
    else 
    printf("the line given is not a palindrome");
}

void lab_q13 (void)
{
{
    char line[50],temp[50];
    int count,icount=0,rlength,i=0;
    printf("enter a word\n");
    scanf(" %s",line);
    for (count=0;count<50;count++)
    {
        temp[i] = line[count];
        if (line[count]=='\0')
        {
            i--;
        }
        i++;

    }
    rlength=strlen(temp);
    printf("rlength is %d\n",rlength);
    char new[rlength],old[rlength];
    for (count=0;count<10;count++)
    {
        if(isspace(temp[count])!=0)
        printf("space\n");
        old[icount]=tolower(temp[count]);
        new[icount]=tolower(temp[(rlength-1)-(count)]);
        icount++;

    }
    if (strcmp(new,old)==0)
    printf("the line given is a palindrome");
    else 
    printf("the line given is not a palindrome");
}
}

int main (void)
{
    int a = 10, b = 20;//variables for lecture_codes
    system("cls");
    lab_q13();
    return 0;
}