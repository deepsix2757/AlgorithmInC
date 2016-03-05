#include <stdio.h>
#include <string.h>

#define debug
#define MAX 5

struct hands{
	char cards[5][2];
	char stat[8];
	char high[1];
	char low[1];
}

hands white;
hands black;

void ch_all();
void ck_high(hands);
void ck_one_pair(hands);
void ck_two_pair(hands);
void ck_triple(hands);
void ck_stright(hands);
void ck_flush(hands);
void ck_house(hands);
void ck_four(hands);
void ck_st_flu(hands);

void main(){

	while(1){
		scanf("%s %s %s %s %s %s %s %s %s %s",
				black.card[0],
				black.card[1],
				black.card[2],
				black.card[3],
				black.card[4],
				white.card[0],
				white.card[1],
				white.card[2],
				white.card[3],
				white.card[4]);

		ck_all(black);
		ck_all(white);
	}
}

void ck_all(hands){
	ck_high(hands);
	ck_one_pair(hands);
	ck_two_pair(hands);
	ck_triple(hands);
	ck_stright(hands);
	ck_flush(hands);
	ck_house(hands);
	ck_four(hands);
	ck_st_flu(hands);
}

void ck_high(hands){
	int i,buf,buf2;
	buf = 0;
	buf = 'T';
	for(i=0;i<MAX;i++){
	if(buf < atoi(hands.card[i][0]))
		buf = atoi(hands.card[i][0]);
	if(buf2 > atoi(hands.card[i][0]))
		buf2 = atoi(hands.card[i][0]);
	}
	hands.high = buf;
}

void ck_one_pair(hands){
	int i,min,max,,buf;
	buf = 0;
	for(i=0;i<MAX;i++){
	}	
}
