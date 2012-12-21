
#include <stdio.h>

// this is a comment

void foo( int f )
{ /* this as well */
  int i;
  for( i = 0; i < f; i++ )
    printf( "bla\n" );
}

int main( )
{
  volatile int c = 1;
  if( c == 1 )
    foo( 3 );
  foo( 4 );
  return 0;
}

