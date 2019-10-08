#include <apue.h>
#include <myerror.h>

#define BUFFSIZE 4096

int main()
{
    int n;
    char buf[BUFFSIZE];
    
    while ( ( n = read(STDIN_FILENO,buf,BUFFSIZE) ) > 0 )
    {
        printf( "n = %d\n",n);
	if ( write(STDOUT_FILENO,buf,n) != n)
 		err_sys("writh error");
    }

    if ( n < 0) 
	err_sys("read error");

    exit(0);
}
