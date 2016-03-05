#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define debug_


typedef struct{
	char name[81];
	int res_cnt[3];
} ca_s;

ca_s ca_list[20];

int find_top(char *);
int find_bottom(int n);
void balancing(int, int);

int res_cnt;

int main(){

	int i,ca_cnt,res_no,empty_ck,ck;	
	int res_1;
	int res_2;
	int res_3;
	char buf[81];

	while(1){

		memset(ca_list,'\0',sizeof(ca_list));
		ca_cnt = 0;

		/* get set cnt */
		gets(buf);
		gets(buf);
		/* get candidate list */
		gets(buf);
		ca_cnt = atoi(buf);
#ifdef debug
		printf("\t*** debug candidate cnt : %d\n", ca_cnt);
#endif
		for(i=0;i<ca_cnt;i++){
			gets(buf);
#ifdef debug
			printf("\t*** debug candidate name : %s\n", buf);
#endif
			strcpy(ca_list[i].name, buf);
		}
	
		/* get voting list */
		res_cnt = 0;
		while(gets(buf) && strlen(buf)>0){
			sscanf(buf,"%d %d %d",&res_1,&res_2,&res_3);
#ifdef debug
			printf("\t*** debug res_1 : %d\n", res_1);
			printf("\t*** debug res_2 : %d\n", res_2);
			printf("\t*** debug res_3 : %d\n", res_3);
#endif
			ca_list[res_1-1].res_cnt[0]++ ;
			ca_list[res_2-1].res_cnt[1]++ ;
			ca_list[res_3-1].res_cnt[2]++ ;

			if(res_1 > 0)
				res_cnt++;
		}
#ifdef debug
		printf("\t*** debug res_cnt : %d\n", res_cnt);
#endif

		/* calc voting result */
		ck = 0;
		/* rebalancing start result set no */
		res_no = 1;
		empty_ck = 0;
		while(ck==0){
#ifdef debug
			printf("\t*** debug while loop\n");
#endif
			if(find_top(buf)==0)
				balancing(find_bottom(res_no-1),res_no);
			else
				ck++;

			for(i=0;i<res_cnt;i++){
				empty_ck += ca_list[i].res_cnt[res_no];
			}
			/* checking result set  is empty */
			if(empty_ck==0)
				res_no++;
		}
		

		/* print result */
		printf("%s\n", buf);
	}
}

/* check and return topcandidate */
int find_top(char *buf){
	int i,ret;
	ret = 0;
	for(i=0;i<res_cnt;i++){
		if(ca_list[i].res_cnt[0] * 100 / res_cnt > 50){
#ifdef debug
			printf("\t*** debug find_top %d\n",i);
#endif
			strcpy(buf, ca_list[i].name);	
			ret = 1;
		}
	}

	return ret;
}

int find_bottom(int n){
	int i,ret_no,buf_cnt;

	ret_no = 0;
	buf_cnt = 1000;
	for(i=0;i<res_cnt;i++){
		if(buf_cnt > ca_list[i].res_cnt[n] && ca_list[i].res_cnt[n] != 0){
#ifdef debug
			printf("\t*** debug find_bottom i:%d, n:%d\n",i,n);
#endif
			buf_cnt = ca_list[i].res_cnt[n];
			ret_no = i;
		}
	}
	return ret_no;
}

/* drop lowest candidates count to majorities */
void balancing(int bott_n, int res_no){
	/* bottom cnt to add top cnt */
	ca_list[ca_list[bott_n].res_cnt[res_no]].res_cnt[res_no-1]++;
#ifdef debug
	printf("\t*** debug balancing bott_n:%d, res_no:%d\n",bott_n,res_no);
#endif
	/* set to 0 bottom cnt */
	ca_list[bott_n].res_cnt[res_no] = 0;
}
