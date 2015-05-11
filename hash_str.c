#include <stdio.h>
#include <stdlib.h>

#define M 100

struct node{
	char *key;
	int  info;
	struct node *next;
};



void hashlistinitialize(int size)
{
	struct node *heads[size];
	int i=0;

	for (i=0; i<size; i++){
		heads[i] = (struct node *)malloc(sizeof (struct node));
		heads[i]->next = NULL;
		heads[i]->info = -1;
		heads[i]->key  = NULL;
	}
}

unsigned int hash(char *v) {
	int h, i;
	for (h=0, i=0; *v != '\0'; v++, i++) {
		h += (h*64 + *v) % M;
		printf("%d: %d \n", i, h);
	}
	return h;
}

int main(int argc, char *argv[]){
	if (argc < 2)
		return 0;
	hash(argv[1]);
	return 0;
}

