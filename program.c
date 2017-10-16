#include"program.h"

void *ThreadProc(void *arg)
{
	int argument = *((int *) arg);
	long res=0;
	
	printf("Argument passed to thread: %d\n",argument);	
	
	if(argument==10)
		res = 1;
	else
		res = 2;
	
	pthread_exit((void *) res);
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	int ret,val=20,*res;
	
	ret = pthread_create(&thread, NULL, ThreadProc,(void *) &val);
	if(ret!=0)
	{
		printf("Thread not created. Error number: %d",ret);
		exit(EXIT_FAILURE);
	}
	
	pthread_join(thread, (void**) res);
	printf("Result: %d\n",*res);
	printf("Threads terminated.\n");
	
	pthread_exit(NULL);
	return 0;
}

