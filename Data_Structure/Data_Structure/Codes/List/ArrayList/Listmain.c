#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	List list;
	int data;
	ListInit(&list);
	
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	// print out all stored data
	printf("current data number : %d \n", LCount(&list));
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data)) printf("%d ", data);
	}
	printf("\n\n");

	// Search 22 and delete 22
	if (LFirst(&list, &data))
	{
		if (data == 22) LRemove(&list);
		while (LNext(&list, &data)) 
		{
			if(data == 22) LRemove(&list);
	}
	
	
	// print out all stored data
	printf("current data number : %d \n", LCount(&list));
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data)) printf("%d ", data);
	}
	printf("\n\n");

	getch();
	return 0;
}