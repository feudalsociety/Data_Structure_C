#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListIinit(List * plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) // empty
	{
		plist->tail = newNode;
		newNode->data = newNode;
	}
	else
	{
		newNode->next = plist->tail->next; // new Node next = head;
		plist->tail->next = newNode; // head = new Node;
	}
	(plist->numOfData)++;
}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) // empty
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode; // additional code
	}
}

int LFirst(List * plist, Data * pdata)
{
	if (plist->tail == NULL) return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if (plist->tail == NULL) return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data rdata = plist->cur->data;

	if (rpos == plist->tail)
	{
		if (plist->tail == plist->tail->next) // if remove node is only one left node
			plist->tail = NULL;
		else plist->tail = plist->before;
	}

	plist->before = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

