#include<stdio.h>
#include<string.h>
#define SIZE 80

FILE *fp = NULL;
int main(int argc, char *argv[]){
	char buf[SIZE];

	/* Open file from argument one */
	if (argc != 3){
		printf("Usage: %s  <filename> <string>", argv[0]);
		return 0;
	}

	fp = fopen(argv[1], "r");
	if(!fp)
		return -1;

	while(fgets(buf, SIZE-1, fp) != NULL){
		char *str;
		str = strstr(buf, argv[2]);
		if (str)
			printf("%s", buf);
	}
}


