#include <apue.h>    
#include <myerror.h> // for err handle function
#include <string.h> // for strcmp
#include <pwd.h>  // for struct passwd

struct passwd * getpwnam(const char * name);


int  main()
{
    struct passwd * pwdptr; 

    pwdptr = getpwnam("xu_cpp");
    
    if ( pwdptr != NULL )
    {
        printf("name: %s\n",pwdptr->pw_name);
        printf("uid: %u\n",pwdptr->pw_uid);
	printf("gid: %u\n",pwdptr->pw_gid);
	printf("???: %s\n",pwdptr->pw_gecos);
	printf("init dir: %s\n",pwdptr->pw_dir);
	printf("shell: %s\n",pwdptr->pw_shell);
//	printf("name: %s\n",pwdptr->pw_name);
    }
    exit(0);
    
}

struct passwd * getpwnam(const char* name)
{
    struct passwd * ptr;
    
    setpwent(); // set offset of /etc/passwd to head
    
    while ( (ptr = getpwent()) != NULL)
        if ( strcmp(name,ptr->pw_name) == 0 )
	    break;
    endpwent();
    return ptr;
}
