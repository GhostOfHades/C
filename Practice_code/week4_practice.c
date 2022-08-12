#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// pi = 3.1415
//Q1
float compute_sphere_radius (float radius)
{
    float volume;
    volume =(1.3333333 * 3.1415 * radius * radius * radius);
    return(volume);
}
//Q2
double compute_cap_reactance(double cap, double freq)
{
    double reactance;
    reactance= (1/(2*3.1415*cap*freq));
    return (reactance);
}
//Q3
int add_between_numbers(int first, int second)
{
    int  sum=0;
    if (second<first)
    return 0;
    else 
    {
        while (first>second)
        {
            sum=sum + first;
            first++;
        }

        return(sum);
    }
}
//Q4
int greatest_common_divisor (int n1, int n2)
{
    int  gcd, i ;
    for(i=1; i <= n1 && i <= n2; ++i)
    {
        // Checks if i is factor of both integers
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }
    return (gcd);  
}
//Q5
int lowest_common_multiple (int n1, int n2)
{
    int  i, gcd, lcm;
    for (i = 1; i <= n1 && i <= n2; ++i) 
        {
            if (n1 % i == 0 && n2 % i == 0)
                gcd = i;
        }
    lcm = (n1 * n2) / gcd;
    return (lcm);
}
//Q6
int prime_tester (int quiery)
{
    int i,p=0;
    for (i=2;i<quiery;i++)
    {
        if (quiery%i==0)
        {
            return -1;
        }
        else 
        p=1;
    }
    if (p==1||quiery==2)

    return 0;
}
//Q7
void coin_toss_probability(void)
{
    int i, n;
    time_t t;  
    /* Intializes random number generator */
   srand (time(0));
    for ( i = 0 ; i < 1000 ; i++ ) 
    {
       n = n+ (rand() % 2);
    }
    printf("there were %d heads and %d tails",n,1000-n );
}
//Q8
//Q9
int fibonacci (int n1)
{
    int answer,count=2,sum,n2=0,n3=1;
    if (n1==0)
    {
        printf("the fibonacci numkber for the degree that you have given is: 0");
        return 0;
    }
   
    if (n1==1)
    {
        printf("the fibonacci numkber for the degree that you have given is: 1");
        return 0;
    }

    for (count=2;count<=n1;count++)
    {
        sum=n2+n3;
        n2=n3;
        n3=sum;
    }
    printf("the fibonacci number for the degree that you have given is: %d", sum);
    return 0;
}
//Q10

//Q11
int goldbach_conjecture (int n1,int n2)
{
    int count , icount , p1 , p2;
    for (count=n1;count<=n2;count++)
    {
        if (count % 2 == 0)
        {
            printf("%d",count);
            for (icount=2;icount<=count;icount++)
            {
                if (prime_tester(icount)==0)
                    p1=icount;
                if (prime_tester(count-p1)==0)
                    p2=count-icount;
                if (((prime_tester(p1)==0)&&(prime_tester(p2)==0)))
                {
                    printf(" = %d + %d\n",p1,p2);
                    break;
                }
            }
        }              
    }
    return 0;
}

int main (void)
{
    int n1=4,n2=10;
    goldbach_conjecture(n1, n2);
    return 0;
}