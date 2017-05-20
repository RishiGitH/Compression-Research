#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct
{
char ch ;
int count ;
} RLE [ 100 ] ;
int main ( )
{
int i , j , n , count ;
char ch , str [ 100 ] ;
JINVIP :
printf ( "\nPROGRAM TO IMPLEMENT RUN - LENGTH ENCODING TECHNIQUE =>:-"
"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ) ;
printf ( "\n\n1 =>: Run - Length Encoding."
"\n\n2 =>: Run - Length Decoding."
"\n\n3 =>: Exit the Program. "
"\n\nEnter your Choice =>: " ) ;
ch = getche ( ) ;
switch ( ch )
{
case '1' : printf ( "\n\nEnter the Input Sequence =>: " ) ;
gets ( str ) ;
printf ( "\nThe Output Run - Length Encoded Sequence is =>: \n\n" ) ;
for ( i = count = 0 , ch = * str ; i < strlen ( str ) ; i ++ , count ++ )
if ( ch != str [ i ] )
{
printf ( "[ %c , %x ] \t" , ch , count ) ;
ch = str [ i ] ;
count = 0 ;
}
printf ( "[ %c , %x ] \t" , ch , count ) ;
break ;
case '2' : printf ( "\n\nEnter the RLE Entries =>:- "
"\n\n[ Press Enter to Terminate !!! ] \n" ) ;
for ( i = n = 0 ; ; i ++ , n ++ )
{
printf ( "\nEnter the Character =>: " ) ;
RLE [ i ].ch = getche ( ) ;
printf ( "\n" ) ;
if ( RLE [ i ].ch == 13 )
break ;
printf ( "Enter Count for ` %c ' =>: " , RLE [ i ].ch ) ;
scanf ( "%d" , & RLE [ i ].count ) ;
}
printf ( "\nThe Output Run - Length Decoded Sequence is =>:- \n\n" ) ;
for ( i = 0 ; i < n ; i ++ )
for ( j = 0 ; j < RLE [ i ].count ; j ++ )
putch ( RLE [ i ].ch ) ;
break ;
case '3' : exit ( 0 ) ;
default : printf ( "\n\nERROR =>: Invalid Menu Choice !!!"
"\n\n Please Enter a Valid Menu Choice in the Range [ 1 - 3 ] !!!" ) ;
}
printf ( "\n\nPress any Key to Continue ... " ) ;
getch ( ) ;
goto JINVIP ;
return 0;
}
