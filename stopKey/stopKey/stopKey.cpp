#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

#define DEBUG
#define SWAP(tmp, x, y) (tmp=x, x=y, y=tmp)

#define NAME_LEN 20
#define MAX_CASE 2002

// for test case count
int T = 2000;
int vote;
char name[20];

typedef struct _NODE {
	int vote;
	char name[NAME_LEN];
} NODE;

NODE list[MAX_CASE];

void mstrcpy(char *tar, char *src) {
	int i = 0;
	while (src[i] != '\0') {
		tar[i] = src[i];
		++i;
	}
}

int mstrcmp(char *a, char *b) {
	int i = 0;
	while (a[i] != '\0' && a[i] == b[i] ) {
		i++;
	}
#ifdef DEBUG_
	printf("\t mstrcmp  %s %s %d \n", a, b, (b[i] - a[i]));
#endif

	return (b[i] - a[i]);
}

void printList() {
	for (int i = 0; i < T; i++) {
		printf("\t%d\t%d\t%s\n", i, list[i].vote, list[i].name);
	}
}

void heapify(NODE *list, int size) {
	int mid = size / 2 - 1;
	NODE tmp;
	do {
		if (list[mid].vote < list[2 * mid + 1].vote && (2 * mid + 1) < size) {
			SWAP(tmp, list[mid], list[2 * mid + 1]);
		}

		if (list[mid].vote == list[2 * mid + 1].vote && (2 * mid + 1) < size) {
			if(mstrcmp(list[mid].name, list[2 * mid + 1].name) > 0)
				SWAP(tmp, list[mid], list[2 * mid + 1]);
		}

		if (list[mid].vote < list[2 * mid + 2].vote && (2 * mid + 2) < size) {
			SWAP(tmp, list[mid], list[2 * mid + 2]);
		}

		if (list[mid].vote == list[2 * mid + 2].vote && (2 * mid + 2) < size) {
			if (mstrcmp(list[mid].name, list[2 * mid + 2].name) > 0)
				SWAP(tmp, list[mid], list[2 * mid + 2]);
		}
		mid--;
	} while (mid >= 0);

	SWAP(tmp, list[0], list[size - 1]);
}

void heapSort(NODE *list, int size) {
	heapify(list, size);
	if (size > 2)
		heapSort(list, size - 1);
}

int main(){
	time_t startTime;
	time_t endTime;
	fflush(stdin);
	freopen("sample_input.txt", "r", stdin);

	startTime = clock();
	//scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &vote);
		scanf("%s", name);
		list[i].vote = vote;
		mstrcpy(list[i].name, name);
	}

	heapSort(list, T);

	endTime = clock();
#ifdef DEBUG
	printList();
	printf("Time is %f\n", (float)(endTime - startTime) / CLOCKS_PER_SEC);
#endif

	return 0;
}
