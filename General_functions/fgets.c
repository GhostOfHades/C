#include <stdio.h>


int main ( void )
{
    char buffer[1000] ;

    int x=-1, y=-1, num = 1000 ;
    int error = 1 ;

    do
    {
        error = 0 ;
        printf ( "Please enter the coordinates to change (x y ): " ) ;
        fgets ( buffer, 1000, stdin ) ;
        if ( buffer[0] == 'q' )
        {
            printf ( "You're a quitter!\n" ) ;
            return 0 ;
        }
        if ( sscanf ( buffer, "%d %d", &x, &y ) != 2 )
        {
            // couldn't read two numbers
            printf ( "Error reading values\n" ) ;
            error = 1 ;
        } else if ( x < 0 || x > 5 || y < 0 || y > 5 )
        {
            printf ( "Values are out of range\n" ) ;
            error = 1 ;
        }
    } while ( error ) ;

    do {
        printf ( "Please enter the number to put in that position: " ) ;
        fgets ( buffer, 1000, stdin ) ;
        if ( sscanf ( buffer, "%d", &num ) != 1 )
        {
            printf ( "Error reading value\n" ) ;
            continue ;
        } else if ( num < 1 || num >= 10)
        {
            printf ( "Error, value out of range\n" ) ;
            continue ;
        }

    } while ( num >= 10 ) ;




