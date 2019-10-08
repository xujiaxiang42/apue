#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t; // cal time
    struct tm * tmp; // break-down time
    char buf1[16];
    char buf2[64];

    time(&t); // return cal time

    tmp = localtime(&t); // return break-down time

    if ( strftime(buf1, 16, "time and data: %r,%a %b %d, %Y",tmp) == 0 )
	printf("buffer length 16 is too small\n");
    else 
	printf("%s\n",buf1);

    if ( strftime(buf2,64, "time and date: %r,%a %b %d,%Y",tmp) == 0)
	printf("buffer length 64 is too small\n");
    else
	printf("%s\n",buf2);
    exit(0);
}
