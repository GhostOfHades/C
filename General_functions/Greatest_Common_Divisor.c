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