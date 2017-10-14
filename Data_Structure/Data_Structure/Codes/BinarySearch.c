#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (target == ar[mid]) return mid;
		else
		{
			if (target < ar[mid]) last = mid - 1;
			else first = mid + 1;
		}
	}
	// whether the searhing value is exist or not first and last index become identical
	return -1;
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 3);
	if (idx == -1) printf("Search failure \n");
	else printf("target index : %d \n", idx);

	getch();
	return 0;
}