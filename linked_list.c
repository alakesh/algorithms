#include <stdio.h>
#include <stdlib.h>

int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

struct node {
	int value;
	struct node *next;
};

struct node *head = NULL;

struct node *insert_node_start(struct node **h, struct node *n, int val)
{
	n->value = val;
	n->next = NULL;
	if (*h == NULL) {
		*h = n;
	} else {
		n->next = *h;
		*h = n;
	}
	return *h;
}

void print(struct node *n)
{
	struct node *tmp;
	tmp = head;
	while ( tmp != NULL)
	{
		printf("%d --> ", tmp->value);
		tmp = tmp->next;
	}
	printf("NULL \n");
}

struct node *create_list(int *arr, int count){
	int i=0;
	printf("Creating Linked List \n");
	for (i=0; i<count; i++){
		struct node *n = (struct node *)malloc(sizeof(struct node));
		insert_node_start(&head, n, i);
	}
	return head;
}

struct node *delete_node_with_value(struct node **head, int val)
{
	struct node *ptr = *head;
	struct node *ptr_prev = NULL;
	printf("Delete Node with value: %d\n", val);
	while (ptr) {
		if (ptr->value == val) {
			if (ptr_prev == NULL){
				*head  =(*head)->next;
				free(ptr);
				return *head;
			} else {
				ptr_prev->next = ptr->next;
				free(ptr);
				return *head;
			}
		} else {
			ptr_prev = ptr;
			ptr = ptr->next;
		}
	}
	printf("Could not find node with value: %d \n", val);

	return *head;
}

void delete_list(struct node **h)
{
	struct node *tmp = NULL;
	while (*h != NULL){
		tmp = (*h)->next;
		free(*h);
		*h = tmp;
		printf("After Delete Node: ");
		print(*h);
	}
}

struct node *reverse_list(struct node **h) 
{
	struct node *temp, *temp_t;
	temp = NULL;
	while (*h) {
		temp_t = (*h)->next;
		(*h)->next = temp;
		temp = (*h);
		(*h) = temp_t;
	}

	return temp;
}

int main(int argc, char *argv[])
{
	printf("Original List: \n");
	head = create_list(arr, 10);
	print(head);
	printf("Reversed List: \n");
	head = reverse_list(&head);
	print(head);
	printf("Reversed Again List: \n");
	head = reverse_list(&head);
	print(head);

	delete_node_with_value(&head, 9);
	print(head);
	delete_node_with_value(&head, 4);
	print(head);
	delete_node_with_value(&head, 12);
	print(head);
	delete_node_with_value(&head, 0);
	print(head);
	delete_node_with_value(&head, 1);
	print(head);
	delete_list(&head);
	print(head);
	return 0;
}
