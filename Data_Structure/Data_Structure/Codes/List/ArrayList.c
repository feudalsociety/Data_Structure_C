#include <stdio.h>
#include "ArrayList.h"

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

int LFirst(List * plist, LData * pdata)
{
	if (plist->numofData == 0) return FALSE;

}
