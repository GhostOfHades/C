void factorial_calc (int target)
//Write a program to generate and print a table factorials until the given number
{
    int inum,isum=1;
   for (inum=1;inum<=target;inum++)
   {
      isum=isum*inum;
      printf("%d\t%d\n",inum, isum); 
   }
}
