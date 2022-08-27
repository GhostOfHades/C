void bin_to_dec (void)
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