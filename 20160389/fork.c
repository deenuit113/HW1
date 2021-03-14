//fork.c
#include <stdio.h>

int main()
{
	int pid = fork();

	if(pid > 0) {
		printf("parent: child %d \n", getpid());
		pid = wait();
		printf("child %d is done \n", getpid());
	} else if (pid == 0 ){
		printf("child: exiting\n");
	} else {
		printf("fork error \n");
	}
	return 0;
}
		
