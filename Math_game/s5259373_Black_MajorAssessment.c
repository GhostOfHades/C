//  Slater Black    s5259373

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct resume
{
    float time;
    int x;
    int y;
    int boardmin;
    int boardmax;
};

int make_board (int x, int y, int bonus)
{
    int countx=0, county=0, ycount=0,icount=0, count=0;
    int guess[x][y], ax[x], ay[y],op[x*y];
    FILE * agrid = NULL;
    FILE * answery = NULL;
    FILE * answerx = NULL;
    FILE * operators = NULL;
    answerx = fopen("answerx.txt","r");//  Open all files needed to be entered into the board
    if (answerx==NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    answery = fopen("answery.txt","r");
    if (answery == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }   
    agrid = fopen("agrid.txt","r");
    if (agrid == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    operators = fopen("operators.txt","r");
    if (operators == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    for (countx=0;countx<y;countx++)//  Scan relevent information into arrays
    {
        fscanf(answerx," %d", &ax[countx]);
    }
    for (county=0;county<x;county++)
    {
        fscanf(answery," %d", &ay[county]); 
    }
    county=0;
    while (county<y)
    {
        for (countx=0;countx<x;countx++)
            fscanf(agrid," %d", &guess[countx][county]);
        county++;
    }
    for (count=0;count<(x*y);count++)
        op[count]=0;
    for (count=0;count<(x*y);count++)
        fscanf(operators," %d",&op[count]);
    printf("\t");
    for (countx=0;countx<x;countx++)//  Make Board with file info
    {
        if (countx==0)
            printf("\t%d",(countx+1));
        if (countx!=0)
            printf("\t\t\t%d",(countx+1));
    }  
    printf("\n");
    countx=0;
    county=0;
    count=0;
    ycount=0;
    while (ycount<(2*(y)-1))
    {
        if (ycount%2==0)
        {
            printf("\t");
            for (countx=1;countx<(2*x);countx++)
            {
                if (countx%2==0)
                    printf("+-------");
                if (countx%2==1)
                    printf("+---------------");
            }
            printf("+\n");
            printf("    %d\t|",(county+1));
            for (countx=0;countx<(x);countx++)//give values to guesses and creating the table with guesses
            {
                if (countx==0)
                {
                    if (guess[countx][county]==0)
                        printf("\t\t|", guess[countx][county]);
                    if (guess[countx][county]!=0)
                        printf("\t%d\t|", guess[countx][county]);
                    count++;
                }
                if ((countx!=0) && (op[icount]==1))//  Add row
                {
                    if (guess[countx][county]==0)
                        printf("   +   |\t\t|",guess[countx][county]);
                    if (guess[countx][county]!=0)
                        printf("   +   |\t%d\t|",guess[countx][county]);
                }
                if ((countx!=0) && (op[icount]==2))//  subtract row
                {
                    if (guess[countx][county]==0)
                        printf("   -   |\t\t|",guess[countx][county]);
                    if (guess[countx][county]!=0)
                        printf("   -   |\t%d\t|",guess[countx][county]);
                }
                if ((countx!=0) && (op[icount]==3))//  Multiply row
                {
                    if (guess[countx][county]==0)
                        printf("   x   |\t\t|",guess[countx][county]);
                    if (guess[countx][county]!=0)
                        printf("   x   |\t%d\t|",guess[countx][county]);
                } 
                if ((countx!=0) && (op[icount]==4))//  Divide row
                {
                    if (guess[countx][county]==0)
                        printf("   /   |\t\t|",guess[countx][county]);
                    if (guess[countx][county]!=0)
                        printf("   /   |\t%d\t|",guess[countx][county]);
                }
                if ((countx!=0) && (op[icount]==5))//  Modulus row
                {
                    if (guess[countx][county]==0)
                        printf("   %   |\t\t|",guess[countx][county]);
                    if (guess[countx][county]!=0)
                        printf("   %   |\t%d\t|",guess[countx][county]);
                }
                icount++;
            }  
            printf("\t  ( %d )",ax[county]);
            county++;
            printf("\n");
        }
        if (ycount%2==1)
        {
            printf("\t");
            for (countx=1;countx<(x*2);countx++)
            {
                if (countx%2==0)
                    printf("+-------");
                if (countx%2==1)
                    printf("+---------------");
            }
            printf("+\n");
            printf("\t|");
            if(ycount%4==3)
            {
                for (count=1;count<((2*(x)));count++)
                {
                    if (((count%2)==1) && ((count%4)==3))
                        printf("\t+\t|");
                    if (((count%2)==1) && ((count%4)==1))
                        printf("\t-\t|"); 
                    if ((count%2)==0)
                        printf(" XXXXX |");
                }
                printf("\n");
            }
            if (ycount%4!=3)
            {
                for (count=1;count<((2*(x)));count++)
                {
                    if (((count%2)==1) && ((count%4)==3))
                        printf("\t-\t|");
                    if (((count%2)==1) && ((count%4)==1))
                        printf("\t+\t|"); 
                    if ((count%2)==0)
                        printf(" XXXXX |");
                }
                printf("\n"); 
            }
        }            
        ycount++;   
    }
    printf("\t");
    for (countx=1;countx<(2*x);countx++)
    {
        if (countx%2==0)
            printf("+-------");
        if (countx%2==1)
            printf("+---------------");
    }
    printf("+\n\t");
    for (county=0;county<x;county++)
    {
        if (county==0)
            printf("\t( %d )",ay[county]);
        if (county!=0)
            printf("\t\t\t( %d )",ay[county]);
    }
    printf("\t\t( %d )",bonus);
    fclose(operators);
    fclose(agrid);
    fclose(answerx);
    fclose(answery);
}

int new_game (int x, int y, int boardmin, int boardmax)
{
    srand(time(0));
    FILE * agrid = NULL;
	FILE * grid = NULL;
    FILE * answerx = NULL;
    FILE * answery = NULL;
    FILE * AlterCount = NULL;
    FILE * operators = NULL;
    int countx, count=0, ycount=0, county=0, altered=0,op[x*y],bonus=0;// set altered guess values to 0, then close AlterCount
    AlterCount = fopen("AlterCount.txt","w");
    if (AlterCount==NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    fprintf(AlterCount,"%d",altered);
    fclose(AlterCount);
    operators = fopen("operators.txt","w");
    if (operators == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }    
    int ans[x][y], guess[y][y], ax[x], ay[y];//initialize variables
    for (count=1;count<(x*y);count++)
    op[count]=0;
    county= 0;//  create random numbers and obtain row and coloumn answer values
    count = 1;
    while (ycount<((2*y)-1))
    {
        if (ycount%2==0)
        {
            ax[county]=0;
            for (countx=0;countx<x;countx++)// creating random numbers for the grid and calculating the totals for the rows
            {
                op[count] =((rand()% 5 )+1);
                fprintf(operators," %d",op[count]);
                ans[countx][county]=((rand()%(boardmax - boardmin)) + boardmin);
                if (countx == 0) //first number
                    {ax[county]= ((ax[county]) + (ans[countx][county]));}
                if ((countx != 0) && (op[count] == 1))// Add row
                    {ax[county]= ax[county] + ans[countx][county];}
                if ((countx != 0) && (op[count] == 2))//  Subtract row
                        {ax[county]= ((ax[county]) - ans[countx][county]);}
                if ((countx != 0) && (op[count] == 3))//  Multiply row
                    {ax[county]= (ax[county] * ans[countx][county]);}
                if ((countx !=0 ) && (op[count] == 4))//  Divide row
                    {ax[county]= ((ax[county]) / (ans[countx][county]));}
                if ((countx !=0 ) && (op[count] == 5))//  Modulus row
                    {ax[county] = ax[county] - (ans[countx][county] * (ax[county] / ans[countx][county]));}
                count++;          
            }  
            county++;
        }
        ycount++;   
    }
	countx=0;//	calculating the totals for the columns
	while (countx<x)
	{
		ay[countx]=0;
		if (countx%2==0)
		{
			for (county=0;county<y;county++)
			{
				if ((county%2==1) || (county==0))
				    ay[countx]= ay[countx]+ans[countx][county];
				if ((county%2==0) && (county!=0))
				    ay[countx]= ay[countx]-ans[countx][county];			
			}	
		}
		if (countx%2==1)
		{
			for (county=0;county<y;county++)
			{
				if ((county%2==1) || (county==0))
				    ay[countx]= ay[countx]-ans[countx][county];
				if ((county%2==0) && (county!=0))
				    ay[countx]= ay[countx]+ans[countx][county];			
			}	
		}
		countx++;
	}
    grid = fopen("grid.txt","w");//store answers in a text file
    if (grid == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    answerx = fopen("answerx.txt","w");//  open answer x text to store answers for the x axis
    if (answerx==NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    answery = fopen("answery.txt","w");//  open answer y text to store answers for the y axis
    if (answery == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }   
    agrid = fopen("agrid.txt","w");//  open guess grid to add new user guess
    if (agrid == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    for (count=0;count<(x*y);count++) // reset guess file
    {
        fprintf(agrid," %d", 0);
    }
    count=0;
    countx=0;
    while (count<(y))//store grid data
    {
        for (countx=0;countx<(x);countx++)
            fprintf(grid," %d", ans[countx][count]);
        count++;
    }
    for (count=0;count<y;count++) //store row answers
        fprintf(answerx," %d",ax[count]);        
    for (count=0;count<x;count++)//  store column 
        fprintf(answery," %d",ay[count]);	
    if (x==y)
        for (count=0;count<y;count++)
            bonus= bonus+ans[count][count];
	fclose (AlterCount);//close all open files
    fclose(agrid);
	fclose(grid);
    fclose(answerx);
    fclose(answery);
    fclose (operators);
    make_board(x,y,bonus);//  make game board
    return 0;
}

int hint (int x, int y)
{
    int hint=0, random=0,count=0,availablecheck=0;
    int gridarray[x*y],agridarray[x*y];
    FILE * grid;
    FILE * agrid;
    agrid = fopen("agrid.txt","r");//  open two grid files to compare answers
    if (agrid == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    grid = fopen("grid.txt","r");
    if (grid == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    for (count=0;count<(x*y);count++)//  put all guess and answer values into an array
        fscanf(grid," %d",&gridarray[count]);
    for (count=0;count<(x*y);count++)
        fscanf(agrid," %d",&agridarray[count]);
    for (count=0;count<(x*y);count++)//  check for available poistions to place a hint value in
        if (agridarray[count]==0)
        availablecheck=1;
    if (availablecheck==0)
    {
        printf("\nThere are no unused values to provide a hint with, set at least one value to zero to obtain a hint");
        return 0;
    }
    availablecheck=0;//create random co-ordinates, until an available co-ordinate is obtained to insert a hint
    while (availablecheck==0)
    {
        random = (rand() % (x*y));
        if (agridarray[random]==0)
            availablecheck=1;
    }
    fclose (agrid);//  reopen agrid as write to enter new value
    agrid = fopen("agrid.txt","w");
    if (agrid == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    for (count=0;count<(x*y);count++)//  put hint value into guess text file
    {
        if (count==random)
            agridarray[count]=gridarray[count];
        fprintf(agrid," %d",agridarray[count]);
    } 
    fclose(agrid);
    fclose (grid);
    return 1;
}

int compareArray(int a[],int b[],int c)
{
    int count;
    for (count=0;count<c;count++)
        if (a[count]!=b[count])
            return 0;
    return 1;
}

int check (int x,int y)//return 0 for no match, 1 for basic win, 2 for bonus win
{
    FILE * agrid = NULL;
	FILE * grid = NULL;
    FILE * answerx = NULL;
    FILE * answery = NULL;
    FILE * operator = NULL;
    int count=0,countx=0,county=0,i=1,ycount=0,checkbonus=0,bonus=0;
    int guess[x][y],answer[x][y],ay[x],ax[y],op[x*y],Guess[x*y]; //    all answers and guesses from files
    int ex[y],ey[x]; // answer values calculated from guesses to obtain a bonus score
    answerx = fopen("answerx.txt","r");//  open answer x text to store answers for the x axis
    if (answerx==NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    answery = fopen("answery.txt","r");//  open answer y text to store answers for the y axis
    if (answery == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }   
    agrid = fopen("agrid.txt","r");//  open guess grid to add new user guess
    if (agrid == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    grid = fopen("grid.txt","r");//  open guess grid to add new user guess
    if (grid == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    operator = fopen("operators.txt","r");//  open guess grid to add new user guess
    if (operator == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    while (county<y)
    {
        for (countx=0;countx<x;countx++)
            fscanf(agrid," %d", &guess[countx][county]);
        county++;
    }
    count=0; 
    county=0; 
    countx=0;
    ycount=0;  
    while (county<y)
    {
        for (countx=0;countx<x;countx++)
            fscanf(grid," %d", &answer[countx][county]);
        county++;
    }
    for (count=0;count<(x*y);count++)
        fscanf(agrid," %d",&Guess[count]);
    for (count=0;count<x;count++)
        fscanf(answery," %d",&ay[count]);
    printf("\n");
    for (count=0;count<y;count++)
        fscanf(answerx," %d",&ax[count]);
    for (count=0;count<(x*y);count++)
        op[count]=1;
    for (count=0;count<(x*y);count++)
        {fscanf(operator," %d",&op[count]);}
    count=0; 
    county=0; 
    countx=0;
    ycount=0;
    while (ycount<y)
    {
        ex[county]=0;
        for (countx=0;countx<x;countx++)
        {
            printf(" %d",guess[countx][county]);
            if (countx == 0) //first number
                ex[county] = ex[county] + guess[countx][county];
            if ((countx != 0) && (op[count] == 1))// Add row
                ex[county] = ex[county] + guess[countx][county];
            if ((countx != 0) && (op[count] == 2))//  Subtract row
                ex[county] = ex[county] - guess[countx][county];
            if ((countx != 0) && (op[count] == 3))//  Multiply row
                ex[county] = (ex[county] * guess[countx][county]);
            if ((countx !=0 ) && (op[count] == 4))//  Divide row
                ex[county] = ex[county] / guess[countx][county];
            if ((countx !=0 ) && (op[count] == 5))//  Modulus row
                ex[county] = ex[county] - (guess[countx][county] * (ex[county] / guess[countx][county]));
            count++;          
        }  
        county++;
        ycount++;   
    }
    countx=0;
    while (countx<x)//	calculating the totals for the columns
    {
	    ey[countx]=0;
        if (countx%2==0)
        {
            for (county=0;county<y;county++)
            {
                if ((county%2==1) || (county==0))
                    ey[countx]= ey[countx]+guess[countx][county];
                if ((county%2==0) && (county!=0))
                    ey[countx]= ey[countx]-guess[countx][county];			
            }	
        }
        if (countx%2==1)
        {
            for (county=0;county<y;county++)
            {
                if ((county%2==1) || (county==0))
                ey[countx]= ey[countx]-guess[countx][county];
                if ((county%2==0) && (county!=0))
                ey[countx]= ey[countx]+guess[countx][county];			
            }	
        }
        countx++;
    }  
    if (x==y)
    {
        for (count=0;count<x;count++)
            bonus = bonus + guess[count][count];
        for (count=0;count<x;count++)
           checkbonus = checkbonus + answer[count][count];
    }
    if (compareArray(ex,ax,y)==1 && compareArray(ey,ay,x)==1 && (bonus==checkbonus))
    return 4;
    if (compareArray(ex,ax,y)==1 && compareArray(ey,ay,x)==1)
    return 3;
    fclose(agrid);
    fclose(grid);
    fclose(answerx);
    fclose(answery);
    fclose(operator);
    return 0;
}

int play (struct resume go) //int x and y are dimensions, gx and gy are co-ordinates for player guesses and guess is the players guess (swapped cos gx and gy coded the other way and too much effort to change)
    
{
    FILE * answerx = NULL;
    FILE * answery = NULL;
    FILE * agrid =NULL;
    FILE * AlterCount = NULL;
    FILE * save = NULL;
    int x=0,y=0,boardmin=0,boardmax=0,bonus=0;
    float time;
    x = go.x; //initialize important variables
    y = go.y;
    boardmin = go.boardmin;
    boardmax = go.boardmax;
    time = go.time;    
    int countx,count=0,ycount=0,county=0,icount,altered=0,gx=0,gy=0,gans=0,hinta=0;//initialize variables
    int ans[x][y], guess[x][y], ax[y], ay[x];
    answerx = fopen("answerx.txt","r");// files to obtain stored answers from
    if (answerx==NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    answery = fopen("answery.txt","r");
    if (answery == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        exit (1);
    }   
    agrid = fopen("agrid.txt","r");
    if (agrid == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    AlterCount = fopen("AlterCount.txt","r");//AlterCount file will hold how many times the user changes a value that has been set by the user
    if (AlterCount==NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    fscanf(AlterCount," %d",&altered);//obtain the count value before this attempt and close the file
    fclose (AlterCount);
    county=0;
    countx=0;
    icount=0;  
    clock_t start_of_play = clock();
    printf("\nPlease enter an x co-ordinate, a y co-ordinate and a value you would like to enter (press enter between each value)\n Enter a 0 for either the x or y coordinate to obtain a hint\n or enter a non-numerical character to end program\n or enter a negative number into any cooridnate to end cuurent game and view your score\n");//ask user for co-ords and guess value
    if (scanf(" %d %d %d",&gx,&gy,&gans)!=3)
        exit(1);
    if ((gans <boardmin && gans !=0)|| (gans > boardmax && gans))
    {
        printf("\n Please enter a value between your chosen minimum and maximum values\n");
        return 0;
    }
    if (gy<0 || gx<0)
        return 2; ////// change to take to score
    if (gx==0 || gy==0)//  Hint function
    {
        hinta = hint ( x, y );
        if (hinta == 1)
        altered = altered + 4; //hints make 4 altered so that the correct point does not count
    }
    count = 0;
    countx = 0;
    county = 0;
    while (count<=(x*y)) //  copy data from previous answers and hints into a user "guessing" array
    {
        if (countx==(y))
        {
            county++;
            countx=0;            
        }   
        fscanf(agrid," %d", &guess[countx][county]);
        count++;
        countx++;
    } 
    fclose (agrid);
    count=0;
    countx=0;
    county=0;  
    if ((guess[(gx-1)][(gy-1)] != 0) && (guess[(gx-1)][(gy-1)] != gans) && hinta==0)// check if the number is being altered or if it has been entered and is the same as what it was (which would mean that it would not be altered)
        altered++; 
    guess[(gx-1)][(gy-1)] = gans;    // answer gets put into array
    agrid = fopen("agrid.txt","w");//  reopen agrid so that we can change the grid guesses in write mode
    if (agrid == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        exit(1);
    }
    //reopen AlterCount file to store the number of times a user altered an existing guess
    AlterCount = fopen("AlterCount.txt","w");
    if (AlterCount==NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        exit (1);
    }
    fprintf(AlterCount,"%d",altered);
    countx=0;
    county=0;
    while (count<=(x*y)) // print final guess values to the guess text file
    {
        if (countx==(y))
        {
            county++;
            countx=0;            
        }   
        fprintf(agrid," %d",guess[countx][county]);
        countx++;
        count++;
    } 
    clock_t end_of_play = clock(); // update time in game
    time = time + (end_of_play - start_of_play); // add time with time of this play
    save = fopen("save.txt","w");
    if (save==NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    if (x==y)
        for (count=0;count<y;count++)
            bonus= bonus+ans[count][count];
    fprintf(save, " %f\n%d\n%d\n%d\n%d",time,x,y,boardmin,boardmax);//save files
	fclose(save);//  Close all currently open files
    fclose (AlterCount);
    fclose(agrid);
    fclose(answerx);
    fclose(answery);
    make_board(x,y,bonus);//  Make board
    return (check(x,y)); // returns a value that will determine whther the game is over or not
}

int score (int x,int y,float timestart,int numRange,int multiplier)//  The score will start at 0, increase by a combination of correct numbers and board size (bigger board and higher value range means more points for a correct value), points will then be deducted for incorrect guesses and score will be reduced (divivded) based on time taken  
{
    int score=0,count=0,correctValue=0, diffcoef=1,altered=0;
    int guesses [x*y], answers [x*y];
    float gridcoef=1;
    FILE * agrid = NULL;
    FILE * grid = NULL;
    FILE * AlterCount = NULL;
    AlterCount = fopen("AlterCount.txt","r");//AlterCount file will hold how many times the user changes a value that has been set by the user
    if (AlterCount==NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    fscanf(AlterCount," %d",&altered);
    agrid = fopen("agrid.txt","r");//  agrid holds the quesses given by the user
    if (agrid == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    grid = fopen("grid.txt","r");//  grid holds the answers to the table
    if (grid == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    for (count=0; count<(x*y);count++)//  obtaining answer values and putting them intoi an array to compare
        fscanf(grid," %d",&answers[count]);
    for (count=0; count<(x*y);count++)//  obtaining guess values and putting them into an array to compare
        fscanf(agrid," %d",&guesses[count]);   
    for (count=0; count<(x*y);count++)//  comparing the guess values to the answer values to obtain a score for correct values
        if (guesses[count]==answers[count])
            correctValue++;
    correctValue=correctValue * 20;// a correct value is worth 20 points
    correctValue= correctValue- (altered * 5);// deduct number of "mistakes" by less than correct answers (deduct 5 points per incorect value)
    correctValue = correctValue * (1+(0.1 * numRange));//multiply correctValue with a coeeficient that correctly descirbes difficulty (combo of number range and grid size)
    gridcoef = gridcoef + (0.1 * fmin(x,y));
    correctValue = correctValue * gridcoef;
    score = ((correctValue * ((1000-(2 * timestart))/1000))* multiplier);//  multiply the score with a coefficient that will decrease the score as time goes on by a rasonable margin (4% loss for 20 minutes) and double points if the soloution is solved with alternative values
    if (score<0)//  Score will not be a negative value
        score=0;
    fclose (agrid);//  close all open files
    fclose (grid);
    fclose (AlterCount);
    return (score);
}

int printHighscores (void)
{
    FILE * Highscores = NULL;
    int count=0, score=0;
    char name[20];
    Highscores = fopen("highscores.txt","r");
    printf("\tHIGHSCORES\n\n");
    if (Highscores == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }  
    for (count=0;count<10;count++)
    {
        fscanf(Highscores," %s",name);
        fscanf(Highscores, " %d", &score);
        printf("%d\t%s\t%d\n",(count+1),name,score);
    }
    fclose(Highscores);

    return 0;
}

int addscore (char name[20], int score)
{
    char names[10][20],temp[20];
    int scores[10],count = 0,icount=0;
    FILE * highscores = NULL;
    highscores = fopen("highscores.txt","r");
    if (highscores == NULL) 
    {
        printf("Cannot open file for storage, the the game cannot be played\n");
        return -1;
    }
    for (count=0;count<10;count++)
    {
        scores[count]=0;
        fscanf(highscores," %s %d", names[count],&scores[count]);
        if (scores[count]< score)
            icount++;
    }
    icount= 10-icount;
    fclose (highscores);
    if (icount!=0)
    {
        highscores = fopen("highscores.txt","w");
        if (highscores == NULL) 
        {
            printf("Cannot open file for storage, the the game cannot be played\n");
            return -1;
        }
        for (count=0;count<9;count++)
        {
        if (count == icount)
            fprintf(highscores," %s %d\n",name,score);
        fprintf(highscores," %s %d\n", names[count],scores[count]);
        }
        fclose(highscores);
    }
    return 0;
}

int main(void)
{
	FILE * save = NULL;
    int x=0, y=0, gans=0, gx=0, gy=0, boardmin=1, boardmax=9, option=0,game=0,program =0,points=0;
    float timetaken=0,timestart=0;
    char name[20];
    struct resume go;   //  structure used to hold all information of game data
	system("cls");      //  clear terminal board 
    srand (time(0));    //  initilize for random numbers on board
    while (program == 0)
    {
        while (option == 0) //  main menu
        {
            printf("\n\tMAIN MENU\n\nPlease choose from the following options by entering their respective values\n\n1. Show game rules\n2. Resume last game played\n3. Start New game\n4. view highscores\n5. exit game\n");
            scanf(" %d",&option);
            if (option>4 && option <1)
            option =0;
            system ("cls");
        }
        if (option ==1)     //  display rules
        {
            system("cls");
            printf("Welcome to Maths game\n the rules are simple\n\nFollow instructions to navagate the menus\nWhen entering values to guess, enter the x co-ordinate of youyr guess first and then the y-coodinate");
            printf("\nfollowed by the number you would like to insert into this position\n\nNegative numbers and letters are not recognised by the game and will end your current game\nAn exeption to this rule is the value -1");
            printf("\n This will take you back to the main menu\n\nOnce all corrent values have been entered into the table, the game will end and show you your highscore\n this can be viewed later through the main menu\n\n");
            printf("HINT^: Bonus points will be given if all diagonal values multiplied by each other obtains the value shown inthe bottom right most corner\n");
            printf("To request a hint, enter the number 0 for either the x co-ordinate or the y co-ordinate\nYou will gain no points from hints\n");
            printf("\nplease enter any integer value to continue\n");
            scanf(" %d",&option);
            option=0;
        }
        if (option == 2)    //  resume game
        {
            while (game == 0)
            {
                save = fopen("save.txt","r");
                if (save == NULL) 
                {
                    printf("Cannot open file for storage, the the game cannot be played\n");
                    return -1;
                }
                fscanf (save," %f %d %d %d %d", &go.time, &go.x,&go.y,&go.boardmin,&go.boardmax);
                fclose(save);
                game = play(go);
            }
            if (game == 2) // co-ordinate error that is fixed by repeating the loop
                option = 0;
            if (game == 3) // return 3 in check function for scoring with standard muliplier
                option = 6;
            if (game == 4) // return 4 in check function for scoring with bonus muliplier
                option = 7;   
        }
        if (option == 3)    //  new game
        {
            printf("how large would you like the playing board to be (x y)\n");//  obtain x and y values as these are used (but not changed) in all of the additional functions 
            scanf("%d %d",&x, &y);
            printf("Please enter a minimum value followed by a maximum value\n");//  obtain a range of numbers that can be used for the game
            scanf("%d %d",&boardmin, &boardmax);
            system("cls"); //  clear terminal board 
            clock_t start = clock();
            timestart = start;
            new_game(x,y,boardmin,boardmax);//  generate a new game and clear previopus save files
            go.time = 0;
            go.x = x;
            go.y = y;
            go.boardmin = boardmin;
            go.boardmax = boardmax;
            game = play(go);    //  inital play to put the new perameters into the save file          
            while (game == 0)
            {
                save = fopen("save.txt","r");
                if (save == NULL) 
                {
                    printf("Cannot open file for storage, the the game cannot be played\n");
                    return -1;
                }
                fscanf (save," %f %d %d %d %d", &go.time, &go.x,&go.y,&go.boardmin,&go.boardmax);
                fclose(save);
                game = play(go);
            }
            if (game == 2) // co-ordinate error that is fixed by repeating the loop
                option = 0;
            if (game == 3) // return 3 in check function for scoring with standard muliplier
                option = 6;
            if (game == 4) // return 4 in check function for scoring with bonus muliplier
                option = 7;
        }      
        if (option ==4)     //  view highscores
            {
                printHighscores();
                printf("\nPlease enter any positive value to return to the main menu\n");
                if (scanf(" %d",&option) !=1 )
                    exit(1);
                else
                {
                    system("cls");
                    option=0;
                }
            }
        if (option == 5)    //  exit game
        program = 1; //exit loop for exit game
        if (option ==6) //score game with starndard win
        {
            system("cls");
            printf("please enter a username up to 20 characters for your score\n");
            if (scanf(" %s",name)!=1)//obtain a username
                exit(1);
            save = fopen("save.txt","r");
           if (save == NULL) 
           {
               printf("Cannot open file for storage, the the game cannot be played\n");
               return -1;
           }
           fscanf (save," %f %d %d %d %d", &go.time, &go.x,&go.y,&go.boardmin,&go.boardmax);
           fclose(save);
            points = score (x,y,timestart,(boardmax - boardmin),1);
            printf("\nCongradulations %s, your score is: %d\n\n",name,points);
            printf("Please enter any positive value to return to the main menu\n");
            addscore(name,points);// update scoreboard
            if (scanf(" %d",&option) !=1)
                exit(1);
            else
            {
                system("cls");
                option=0;
            }
        }   
        if (option == 7)// score game with bonus win
        {
            system("cls");
            printf("please enter a username up to 20 characters for your score\n");
            if (scanf(" %s",name)!=1)//obtain a username
                exit(1);
            save = fopen("save.txt","r");
            if (save == NULL) 
            {
                printf("Cannot open file for storage, the the game cannot be played\n");
                return -1;
            }
            fscanf (save," %f %d %d %d %d", &go.time, &go.x,&go.y,&go.boardmin,&go.boardmax);
            fclose(save);
            points = score (x,y,timestart,(boardmax - boardmin),2);
            printf("\nCongradulations %s, your score is: %d\n\n",name,score);
            printf("Please enter any positive value to return to the main menu\n");
            addscore(name,points); // update scoreboard
            if (scanf(" %d",&option) !=1)
                exit(1);
            else
            {
                system("cls");
                option=0;
            }
        }
    }
    return 0;
}