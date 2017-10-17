#include <stdio.h>
#include "ArrayList.h"

/* don't care whether the data is overlapped or not
   also don't care the order of data
*/
void ListInit(List * plist)
{
	(plist->numofData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List * plist, LData data)
{
	if (plist->numofData >= LIST_LEN)
	{
		puts("unable to store data");
		return;
	}
	plist->arr[plist->numofData] = data;
	(plist->numofData)++;
}

int LFirst(List * plist, LData * pdata) // for intialize searching
{
	if (plist->numofData == 0) return FALSE;
	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->curPosition >= (plist->numofData) - 1) return FALSE;
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist)
{
	int rpos = plist->curPosition;
	int num = plist->numofData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numofData)--;
	(plist->curPosition)--;
	return rdata;
}
/* In general, list don't take responsibility to deallocate the memory
   It is hard to implement deciding the memory is heap allocated and deleting it
   So it is common that remove function returns data address
   */


int LCount(List * plist)
{
	return plist->numofData;
}