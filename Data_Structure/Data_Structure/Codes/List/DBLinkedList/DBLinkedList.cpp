#include <stdio.h>
#include <stdlib.h>
#include "DBLInkedList.h"

void ListInit(List * plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List * plist, Data data) // Insert at head
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	if(plist->head != NULL) // not the first node
		plist->head->prev = newNode;

	newNode->prev = NULL; // initialize prev member of node
	plist->head = newNode; 

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if (plist->head == NULL) return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if (plist->cur->next == NULL) return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LPrevious(List * plist, Data * pdata)
{
	if (plist->cur->prev == NULL) return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

int LCount(List * plist) { return plist->numOfData; }
