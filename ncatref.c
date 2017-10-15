
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>  
#include <time.h>


int locfoundline = 0;
int locopen = 0;

char *strgreploc( char *str) 
{

      char ptr[strlen(str)+1];
      int i,j=0;

     locfoundline = 0;
         locfoundline = 1;

      for(i=0; str[i]!='\0'; i++)
      {
         if ( locfoundline == 1 )
	 if ( i >= 6 )
         if ( str[i-6] == 'h'  ) 
         if ( str[i-5] == 'r'  ) 
         if ( str[i-4] == 'e'  ) 
         if ( str[i-3] == 'f'  ) 
         if ( str[i-2] == '='  ) 
         if ( ( str[i-1] == '"'  ) || ( str[i-1] == '\''  ) )
	   locopen = 1;

	 if ( i >= 0 )
	 if ( locopen == 1 )
         if ( ( str[i] == '"'  ) || ( str[i] == '\''  ) )
	   locopen = 0;

         if ( locopen == 1 )
            ptr[j++]=str[i];

      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}





///////////////////////////////////////////////////////////////////
void nfilegreploc( char *filein ){
  int fetchi;
  FILE *fp5;
  FILE *fp6;
  char fetchline[PATH_MAX];
  char fetchlinetmp[PATH_MAX];

  char charin[PATH_MAX];
  char charout[PATH_MAX];

  char lineout[PATH_MAX];

  /////////////////////////////////////////////////
  {
    fp6 = fopen( filein , "rb");
    while( !feof(fp6) ) 
    {
          fgets(fetchlinetmp, PATH_MAX, fp6); 
          strncpy( fetchline, "" , PATH_MAX );
          for( fetchi = 0 ; ( fetchi <= strlen( fetchlinetmp ) ); fetchi++ )
            if ( fetchlinetmp[ fetchi ] != '\n' )
              fetchline[fetchi]=fetchlinetmp[fetchi];


           if ( !feof(fp6) )
           {
	      strncpy( lineout , strgreploc( fetchline ) , PATH_MAX );
	      if ( strcmp( lineout , "" ) != 0 )
	      if ( strcmp( lineout , "\n" ) != 0 )
	      {
                printf( "%s\n" , lineout );
              }
	   }
     }
     fclose( fp6 );
   }
}











int main( int argc, char *argv[])
{
    char cwd[PATH_MAX]; int i ; 


    ////////////////////////////////////////////////////////
    if ( argc == 1)
    {
	  printf( " usage enter filename \n" );
          return 0;
    }

    ////////////////////////////////////////////////////////
    if ( argc >= 2)
    if ( strcmp(argv[1], "--arg" ) == 0)
    {
          for( i = 1 ; i < argc ; i++) 
	     printf( "%d/%d: %s\n", i, argc-1 ,  argv[ i] );
          return 0;
    }
    

    ////////////////////////////////////////////////////////
    if ( argc >= 2)
    {
          for( i = 1 ; i < argc ; i++)
             nfilegreploc(  argv[i] );
          return 0;
    }


    ////////////////////////////////////////////////////////
    if ( argc >= 2)
    {
          for( i = 1 ; i < argc ; i++)
              ;
          return 0;
    }




    return 0;
}









