#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>	

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
	}
	
    void *ptr = NULL;
    void (*fptr)(int iNo);

    ptr = dlopen("lib_factorial.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
	
    fptr = dlsym(ptr,"CalculateFactorial");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
	
	fptr(atoi(argv[1]));
	
    return 0;
}



