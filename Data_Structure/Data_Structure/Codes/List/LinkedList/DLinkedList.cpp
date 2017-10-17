#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // dummy node
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next; // newNode->next = Node after dummy node
	plist->head->next = newNode; // add new node at head (next of the dummy node = new node)
}

void SInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	Node * pred = plist->head; // dummy node 
	// why start with the dummy node? - (cannot add data before a first valid node)
	newNode->data = data;

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) // if data is close to head escape
		pred = pred->next;

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

void LInsert(List * plist, LData data)
{
	if (plist->comp == NULL) FInsert(plist, data);
	else SInsert(plist, data);
}

int LFirst(List * plist, LData *pdata)
{
	if (plist->head->next == NULL) return FALSE;

	plist->before = plist->head; // dummy node - initialize before member
	plist->cur = plist->head->next;  // initialize cur member

	*pdata = plist->cur->data;
	return TRUE;
}


int LNext(List * plist, LData *pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist) // should use after reference
{
	Node * rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before; // cur and before points at same node 

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}
