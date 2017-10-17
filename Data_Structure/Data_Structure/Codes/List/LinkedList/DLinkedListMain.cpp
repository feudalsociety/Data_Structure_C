#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2) return 0; // d1 is close to head
	else return 1; // d2 is close to head
}

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);


	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data)) printf("%d ", data);
	}
	printf("\n\n");


	if (LFirst(&list, &data))
	{
		if (data == 22) LRemove(&list);

		while (LNext(&list, &data))
			if (data == 22) LRemove(&list);
	}
	printf("\n\n");

}