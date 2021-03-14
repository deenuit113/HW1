//cat.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void cat(int fd)
{
	int n = 0;
	char buf[20];
	getchar();
	
	while((n = read(fd, buf, sizeof(buf))) > 0) {
		if (write(stdout, buf, n) != n) {
			printf("cat: write error \n");
			return;
		}
	}
	if(n < 0) {
		printf("cat: read error \n");
		return;
	}
}

int main(int argc, char *argv[])
{
	int fd = 0;
	int i = 0;
	if(argc <= 1){
		cat(0);
		exit(1);
	}
	for(i = 1; i < argc; i++){
		if((fd = open(argv[i],0)) < 0){
			printf(1, "cat: cannot open %s \n", argv[i]);
			exit(1);
		}
		cat(fd);
		close(fd);
	}
	exit(1);
}
