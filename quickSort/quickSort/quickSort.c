#include <stdio.h>

#define SWAP(x, y, temp) (temp=x, x=y, y=temp)

int partition(int[], int, int);
void quick_sort(int[], int, int);

int main() {
	int i;
	int list[] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };

	quick_sort(list, 0, sizeof(list) / sizeof(int) - 1);

	for (i = 0; i < sizeof(list) / sizeof(int); i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}

void quick_sort(int list[], int left, int right) {

	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int partition(int list[], int left, int right) {
	int pivot, temp, low, high;
	low = left;
	high = right + 1;
	pivot = list[low];

	do {do {low++;} while (low <= right && list[low] < pivot);
		do {high--;} while (left <= high && pivot < list[high]);
		if (low < high) {SWAP(list[low], list[high], temp);}
	} while (low < high);

	SWAP(list[left], list[high], temp);

	return high;
}
