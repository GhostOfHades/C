#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include <locale.h> //localization functions
#include <stdarg.h> //variable argument list functions
#include <time.h>
#include <ctype.h>

struct book
{
    int isbn;
    char Author[30];
    char title[30];
    char publisher[30];
    int year;
    char genre[30];
    float price;
};
struct date
{
    int day;
    int month;
    int year;
};


enum day {sun, mon, tue, wed, thu,fri,sat};
typedef enum day day ;

day findNextDay (day d)
{
    day nextDay;
    switch (d)
    {
        case sun : nextDay = mon;
            break;
        case mon : nextDay = tue;
            break;
        case tue : nextDay = wed;
            break;
        case wed : nextDay = thu;
            break;
        case thu : nextDay = fri;
            break;
        case fri : nextDay = sat;
            break;
        case sat : nextDay = sun;
            break;
    }
    return nextDay;
}

int lab_5 (float array[],int size)
{
    int i ;
    // save first value so it can be used to average with last
    float first = array[0] ;

    // go through entire array
    for ( i = 0 ; i < size ; i++ )
    {
        // if it's the last element average with the first one (that we saved)
        if ( i == size-1 )
        {
            array[i] = ( array[i] + first ) / 2 ;
        } else
        // otherwise, average this one with the next one
        {
            array[i] = ( array[i] + array[i+1] ) / 2 ;
        }
    }
}

void books_struct (void)
{
    struct book array[100];
    int i;

    for (i=0;i<100;i++)
    {
        printf("Enter ISBN number\n");
        scanf(" %d",&array[i].isbn);
        if (array[i].isbn ==0)
            break;
        printf("Enter Authors name\n");
        scanf(" %d",&array[i].isbn);

        printf("Enter book title\n");
        scanf(" %d",&array[i].isbn);

        printf("Enter book publisher\n");
        scanf(" %d",&array[i].isbn);

        printf("Enter the year that the book was released\n");
        scanf(" %d",&array[i].isbn);
        
        printf("Enter the genre of the book\n");
        scanf(" %d",&array[i].isbn);

        printf("Enter price of the book\n");
        scanf(" %d",&array[i].isbn);
    }
}

void string_count (char str[],int *vowel, int *caps,int *digits)
{
    int i;
    *vowel = *caps = *digits = 0;
    for (i=0 ; str[i]!='\0' ; i++)
    {
        if ( str[i]>='A' && str[i] <='Z')
            *caps += 1;
        if ( str[i]>='0' && str[i] <='9')
            *digits += 1;
        if ( tolower(str[i]) =='a' || tolower(str[i]) =='e' || tolower(str[i]) =='i' || tolower(str[i]) =='o' || tolower(str[i]) =='u')
            *vowel += 1;
    }
}

int valid_date (struct date d)
{
    if (d.month<1 || d.month >12||d.day >31 ||d.day < 1)
        return 0;
    if (d.month ==2 )
        if (d.day >28)
            return 0;
    else if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
        if (d.day > 30)
            return 0;
    else 
    return 1;
}

int run_valid_date (struct date d)
{
    FILE *dates;
    struct date array[1000];
    int valid =0,invalid = 0;
    dates =fopen ("dates.txt","r");
    if (dates == NULL)
        exit (-1);

    while (valid<1000 && fscanf(dates," %d %d %d",&array[valid].day ,&array[valid].month, &array[valid].year) == 3)
    {
        if (!valid_date (array[valid]))
        {
            printf("Invalid date detected: %d %d %d\n",array[valid].day ,array[valid].month, array[valid].year);
            invalid++;
        }
        else 
        valid++;
    }
}

float abundancy (int num)
{
    int i = 0,sum = 0;
    while (i<=num/2)
    {
        if (num%i==0)
            sum=+1;
        i++;
    }
    return (sum/num);
}

int is_friendly (int num1, int num2)
{
    if (abundancy(num1)==abundancy(num2))
        return 1;
    return 0;
}

void is_friendly_range (int a, int b)
{
    for (a=1 ; a<1000;a++)
    {
        if (is_friendly(a,b) == 1)
            printf("%d and %d are friendly\n",a,b);
    }
}

int main ( void )
{
    int num=0,i=0;

    printf ( "Please enter a number: " ) ;

    scanf ( "%d", &num ) ;

    for ( i = 0 ; i <= num ; i++ )
    {
        if ( (num % i) == 0 )
            printf ( "%d\n", i ) ;
    }
}