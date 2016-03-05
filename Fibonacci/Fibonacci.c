#include <stdio.h>

int main(){
	unsigned long a,b,cnt,i,n1,n2,n;

	scanf("%ld %ld",&a, &b);

	n2=1;
	n1=2;
	cnt=0;

	for(i=3;i<b/2;i++)
	{
		n = n1 + n2;
		if(n>=a && n<=b)
		{
			cnt++;
			printf("cnt %ld : %ld\n", cnt, n );
		}
		n2 = n1;
		n1 = n;
	}

	printf("%ld\n", cnt);
}
