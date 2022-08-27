void Calc_pi (void)
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
