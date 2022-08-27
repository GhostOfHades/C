void matrix_sum (void)
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