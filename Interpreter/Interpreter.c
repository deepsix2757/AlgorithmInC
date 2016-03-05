#include <stdio.h>
#include <string.h>

#define debug

int main(){
	
	int i,j,ck,cnt;
	char instruct[4];

	ck = 2;
	cnt = 0;
	while(ck){
		scanf("%s",instruct);
#ifdef debug
		printf("*** instruct : %s\n", instruct);
#endif
		if(strcmp(instruct,"100")==0)
		{
			cnt++;
			break;
		}
		else if(instruct[0] != '1' && instruct[0] != '\0')
		{
			cnt++;
			if(ck < 2 )
				ck++;
		}
		else
			ck--;

#ifdef debug
		printf("*** ck : %d\n", ck);
#endif
	}

	printf("%d\n",cnt);

	return 0;
}
