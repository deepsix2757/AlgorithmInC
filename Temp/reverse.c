#include <stdio.h>

int main()
{
	int i, n, sum=0;

	printf("input no!\n");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		if(i%2==1)
			sum+=i;	
	}
	printf("%d\n",sum);

}
