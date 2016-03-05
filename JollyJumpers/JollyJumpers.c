#include <stdio.h>
#include <strings.h>

#define debug_

int main(){

	char bitmap[3001];
	int str_len,i,last,cur;

	while(1){
		for(i=0;i<3000;i++)
			bitmap[i] = 'N';

		scanf("%d",&str_len);
#ifdef debug
		printf("**** Debug strlen:%d\n",str_len);
#endif

		/* set bitmap */
		for(i=0;i<str_len;i++){
			scanf("%d",&cur);
#ifdef debug
			printf("**** Debug i:%d\t,cur:%d,str_len:%d\n",i,cur,str_len);
#endif
			/* set bitmap */
			if(i>0){
				bitmap[(last-cur-1)>=0?(last-cur-1):(cur-last-1)] = 'Y';
			}
			/* set last value */
			last = cur;	
#ifdef debug
			printf("**** Debug last:%d\n",last);
#endif
		}

		/* check bitmap */
		if(str_len==1){
			printf("Jolly\n");
		}
		else{
			for(i=0;i<(str_len-1);i++){
				if(bitmap[i]!='Y'){
					printf("Not jolly\n");
					break;
				}
				else if(i==(str_len-2) && bitmap[i]=='Y')
					printf("Jolly\n");
			}
		}
	}
}
