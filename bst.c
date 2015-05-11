#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
	struct node *prev;
	struct node *left;
	struct node *right;
};

struct node *node[7];

void init_node(struct node **n, int val)
{
	*n = (struct node *)malloc(sizeof (struct node));
	(*n)->val = val;
}

void destroy_node(struct node *n){
	free(n);
}

struct node *listify(struct node **node, int dir){
	printf("listify(%d) ---> ", (*node)->val);
	if(!(*node)->left && !(*node)->right)
		return *node;
	struct node *tmpleft;
	struct node *tmpright;
	if ((*node)->left){
		tmpleft = listify(&((*node)->left), 0);
	}
	if ((*node)->right){
	    tmpright= listify(&((*node)->right), 1);
	}
	printf("Creating links: %d --> %d --> %d \n", tmpleft->val, (*node)->val,
			tmpright->val);
	tmpleft->next = *node;
	(*node)->prev = tmpleft;
	tmpright->prev = *node;
	(*node)->next = tmpright;
	return dir? tmpleft : tmpright;
}

void display_list(struct node *n){
	printf("Displaying list: \n");
	while (n)
	{
		printf("%d\n", n->val);
		n=n->next;
	}
}

void display_tree(struct node *n){
	if (n->left)
		display_tree(n->left);
	printf(" %d ", n->val);
	if (n->right)
		display_tree(n->right);
}

void display_tree_recursive(struct node *n){
	int i;
	if (!n)
		return;
	printf(" %d ", n->val);
	if (n->left){
		display_tree_recursive(n->left);
	}
	if (n->right){
		display_tree_recursive(n->right);
	}
}

int main(int argc, char *argv){
	int i;
	for (i=0; i<7; i++)
		init_node(&(node[i]),i+1);

	/* set the links */
	node[3]->left = node[1];
	node[3]->right = node[5];
	node[1]->left = node[0];
	node[1]->right = node[2];
	node[5]->left = node[4];
	node[5]->right = node[6];

	/* display the tree */
	display_tree_recursive(node[3]);

	printf("-------------------------\n");
	listify(&(node[3]),0);

	/* display linked list */

	printf("-------------------------\n");
	display_list(node[0]);

	/* cleanup */

	for (i=0; i<7; i++)
		destroy_node(node[i]);


	return 0;
}

