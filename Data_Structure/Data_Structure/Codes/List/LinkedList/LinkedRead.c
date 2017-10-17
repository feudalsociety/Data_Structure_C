#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
} Node;

int main(void)
{
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	while (1)
	{
		//
		scanf("%d", &readData);
		if (readData < 1) break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->next = readData;
		newNode->next = NULL;

		if (head == NULL) head = newNode;
		else tail->next = newNode;

		tail = newNode; // at first head and tail will point the same node
	}
	printf("\n");

	if (head == NULL) printf("no data stored\n");
	else
	{
		cur = head;
		printf("%d\n", cur->data);

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d", cur->data);
		}
	}
	printf("\n\n");

	if (head == NULL) return 0;
	else
	{
		Node * delNode = head;
		Node * delNextNode = head->next; // if head is deleted cannot access the next node

		printf("delete %d\n", head->data);
		free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("delete %d\n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}
// it is more prefered to add data to head
// implement dummy node to simplify the code of referencing and deleting