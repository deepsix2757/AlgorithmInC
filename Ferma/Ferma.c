#include <stdio.h>
#include <time.h>

#define DEBUG_

/* get int Root value */
int Root(int a){
	int i, x;
	x=1;
	for(i=1;i<a/2;i++){
		if(i*i>a) { return x;}
		else if(i*i==a) {return i;}
		else { x=i;}
#ifdef DEBUG
		printf("  **Root i:%d,x:%d\n",i,x);
#endif
		
	}	
	return x;
}

/* Check Prime, not divided by number less than root of itself */
int ckPrime(int x){
	int i, b;

	b = Root(x);
	if(x==1) return 0;
	for(i=2;i<=b;i++){
		if(x%i==0)
			return 0;
	}
	return 1;
}

int main(){

	int l,u, i,b, cntx, cnty;
	clock_t	begin,end;

	while(1){
		cntx = 0;
		cnty = 0;
		scanf("%d %d", &l, &u);
		begin = clock();
		if(l==-1 && u==-1)
			break;

		for(i=l;i<=u;i++){
#ifdef DEBUG
			printf("  **ckPrime i:%d\n",ckPrime(i));
#endif
			if(ckPrime(i))
			{
				/* Prime cnt */
				cntx++;
				/* Prime with expressed with sqaure of two digit */
				if(i%4==1)
					cnty++;
			}
		}
		end = clock();
		printf("%d %d %d %d %f\n", l, u, cntx, cnty, (double)(end-begin)/CLOCKS_PER_SEC);
	}
}
