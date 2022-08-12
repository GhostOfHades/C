#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 50

//
//  Structures
//

    //  struct starts structure functions
    struct date
    {
        int day;
        int month;
        int year;
    };
    struct friendstr
    {
        char name [20];
        long int phoneNumber;
        char street [20];
        struct date dob;
    };
    //  this structure contains 3 types of data and keeps them together to call on a structure is easier than calling parts
    //  requires semicolon after end bracket
void lecture_1 (void)
{

    //  when calling on a structure,k repeat the first part "struct friendstr" followed by a "variable name" 
    struct friendstr sarah;
    strcpy (sarah.name,"Sarah Finch");
    sarah.phoneNumber = 55559999;
    strcpy (sarah.street,"Happy St");
    sarah.dob.day=13;
    sarah.dob.month=9;
    sarah.dob.year=2001;

    //  allocating data to the variables within the friend structure allocated to "sarah"

    struct friendstr Sam;
    scanf(" %s",Sam.name);
    scanf(" %ld",&Sam.phoneNumber);
    scanf(" %s",Sam.street);

    // allowing user to input data into the friend structure

    struct friendstr class[20];
    strcpy(class[0].name, "Holly");
    class[0].phoneNumber=55569999;
    strcpy(class[0].street, "Holly st");

    //you can point to structures using "->"
    struct friendstr john;
    struct friendstr *ptr = &john;
    scanf(" %s", ptr->name);
    scanf(" %ld",&ptr->phoneNumber);
    scanf(" %s",ptr->street);  
    //  you can use (*ptr).name or ptr->name, both do the same thing

    //to see if a structure is equal to another, each part must be compared, best to do this through a function
}

    //  typedef
typedef struct friendstr Friend;
    //  the code above means that typing "Friend" will be replaced by the compiler with "struct friendstr" (saves time and keystrokes)



//followuing is for lecture_2
struct StudentRec
{
    char lastname[MAXLEN];
    float mark;
};

typedef struct StudentRec Student;

void printStudent (Student *s)
{
    printf(" %s %f\n",s->lastname, s->mark);
}
//  use pointer to be able to edit

void lecture_2 (void)
{
    Student studA;
    Student studB;

    printf("Enter last name and mark for student A: ");
    scanf("  %s %f",studA.lastname, &(studA.mark));
    printf("Enter last name and mark for student B: ");
    scanf("  %s %f",studB.lastname, &(studB.mark));

    printf(" student\tlast name\tmark\n");
    printf("=======================================\n");
    printf("Student A:\t%s\t\t%f\n",studA.lastname, studA.mark);
    printf("Student B:\t%s\t\t%f\n",studB.lastname, studB.mark);

    printStudent (&studA);
}

// to print entire structure type print(structure name)

//  read student function
Student readRecord (void)
{
    Student newstudent;
    printf("Enter last name and mark: ");
    scanf(" %s %f", newstudent.lastname,&(newstudent.mark));
    return newstudent;
}
//  more effective read student function
void readStudent (Student *newstudent)
{
    printf("Enter last name and mark: ");
    scanf(" %s %f", newstudent->lastname,&(newstudent->mark));
}

//
// Files
//

//only really use files to read and write
//treated as a "stream of data"
//  file handling functions include - fopen(); fclose(); fscanf(); fprintf();
// new variable / pointer, which are file pointers... FILE*. functions use the file pointer, not the file name



int lecture_3 (void)
{
    //declare file handlers
    FILE *inputfile = NULL;
    FILE *outputfile = NULL;
    FILE *currentfile = NULL;

    inputfile = fopen("names.lst","r");         //  open file, file name is "names.lst" and the file is opened in "read" mode (read the data in a file)
    currentfile = fopen("names_marks.dat","a"); //  open file, file name is "names_marks.dat" andthe file is opened as "append" mode (data will be added to what ever is aready there)
    // you can open a file read-write mode with "w+"
    char name [50];
    float mark;

    if (inputfile ==NULL)
    {
        printf("Cannot open file for reading\n");
        return -1;
    }
    if (outputfile = (fopen("output.txt","w"))  /*  open file, file name is "marks.dat" and the file is opened in "write" mode (write data in a file, but delete what was in there before)*/ ==NULL) 
    //open output file joint with if statement to check whether it can open
    {
        printf("Cannot open file for writing\n");
        return -1;
    }
    
    while (fscanf(inputfile, " %s",name)==1) //checking for file results (1 in this case) is more reliable than EOF (end of file)
    {
        printf("Enter a mark for %s: ",name);
        scanf(" %f",&mark);
        printf("%s: %f\n",name ,mark);
        fprintf(outputfile,"%s: %f\n",name ,mark);
    }
    fclose(inputfile);
    fclose(outputfile); //always the file pointer (no .txt or .lst at the end)
    return 0;
}

int main (void)
{
    //system("cls");
    lecture_3();
    return 0;
}