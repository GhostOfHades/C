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