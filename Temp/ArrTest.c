#include <stdio.h>

int main()
{
	int _abc, labc, abc1;
	int a, b, tmp;
	int num[2];


	printf("input two numbers to compare!\n");
	scanf("%d %d", &a, &b);

	if(a>b){
		printf("%d is bigger than %d.\n", a, b);
		tmp = a;
		a = b;
		b = tmp;
	}
	else{
		printf("%d is not bigger than %d.\n", a, b);
	}

	num[0] = a;
	num[1] = b;

	printf("%d < %d = True\n", num[0], num[1]);
}
