//exe.c
#include <stdio.h>

int main()
{
	char *argv[3];
	argv[0] = "ls";
	argv[1] = "-a";
	argv[2] = 0;

	int pid = fork();
	if (pid > 0) {
		printf("parent: child=%d \n",pid);
		pid = wait();
		printf("child %d is done \n",pid);
	} else if (pid == 0) {
		printf("child: exiting \n");

		execve("/bin/ls", argv);
	} else {
		printf("fork error \n");
	}
	return 0;
}
