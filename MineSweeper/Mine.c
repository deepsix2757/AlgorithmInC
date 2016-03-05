#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define debug_

char mine[100][100];
int nmax = 0, mmax = 0;

int getMin(int a, int b){
	if(a>b)
		return b;
	else
		return a;
}

int getMax(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

int getCnt(int x, int y){
	int i = 0, j = 0, cnt = 0;

	for(i=getMax(x-1, 0);i<=getMin(x+1, nmax);i++){
		for(j=getMax(y-1, 0);j<=getMin(y+1, mmax);j++){
			if(mine[i][j] == '*'){
				cnt ++;
			}
#ifdef debug
			printf("---- getCnt : i:%d, j:%d, cnt:%d\n", i, j, cnt); 
#endif
		}
	}
	return cnt;
}

int main(){
	char buf[101];
	int s, i, j, n, m;

	s = 1; /* Set counter */
	n = 0; /* Row counter in set */
	m = 0; /* Column counter in row */
	while(gets(buf)){

		if(strlen(buf) < 1)
			break;

		if(n == 0){
			nmax = buf[0] - '0';
			mmax = buf[2] - '0';
#ifdef debug
			printf("---- nmax : %d, mmax : %d\n", nmax, mmax); 
#endif
			if(nmax == 0 && mmax == 0)
				break;
		}
		else{
			for(j=0;j<mmax;j++){
				mine[n-1][j] = buf[j];
#ifdef debug
				printf("---- n : %d, m : %d, char : %c\n", n, j, mine[n-1][j]); 
#endif
			}
		}

		if(n == nmax){
			printf("Field #%d\n", s);
			for(i=0;i<nmax;i++){
				for(j=0;j<mmax;j++){
					if(mine[i][j] == '*')
						printf("%c",'*');
					else
						printf("%d",getCnt(i, j));

					if(j == (mmax - 1))
						printf("\n");
				}
			}
			s++;
			n = 0;
			memset(mine,'\0',sizeof(mine));
		}
		else{
			n++;
		}
	}

	return 0;
}
