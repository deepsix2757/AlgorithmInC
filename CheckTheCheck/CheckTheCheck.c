#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define debug_

#define X_MAX 8
#define Y_MAX 8
#define WHITE 1
#define BLACK 2

char board[8][8];	

void ck_p(int,int,int);
void ck_r(int,int,int);
void ck_b(int,int,int);
void ck_q(int,int,int);
void ck_k(int,int,int);
void ck_n(int,int,int);
void call_check(int);

int check;
int cnt;
int empty;

int main(){

	int i,j,line;
	char buf[9];

	cnt = 1;

	while(1){
		for(i=0;i<Y_MAX;i++)
		{
			scanf("%s", board[i]);
#ifdef debug
			printf("	*** dubug : string %d,%s\n",i,board[i]);
#endif
		}

		check = 0; /* if 1, some king is checkmated */
		empty = 0; /* if higher than 0, board is not empty */
		while(check == 0){
			for(i=0;i<Y_MAX;i++){
				if(check >0) break;
				for(j=0;j<X_MAX;j++){
					if(check >0) break;
#ifdef debug
					printf("	*** dubug : before switch x:%d, y:%d, charter:%c\n",i,j,board[i][j]);
#endif
					switch(board[i][j]){
						case 'p':
#ifdef debug
							printf("	*** dubug : ck_p x:%d, y:%d, c:%c\n",i,j,board[i][j]);
#endif
							empty++;
							ck_p(i,j,BLACK);
							break;
						case 'r':
							empty++;
							ck_r(i,j,BLACK);
							break;
						case 'b':
							empty++;
							ck_b(i,j,BLACK);
							break;
						case 'q':
							empty++;
							ck_q(i,j,BLACK);
							break;
						case 'k':
							empty++;
							ck_k(i,j,BLACK);
							break;
						case 'n':
							empty++;
							ck_n(i,j,BLACK);
							break;
						case 'P':
							empty++;
							ck_p(i,j,WHITE);
							break;
						case 'R':
							empty++;
							ck_r(i,j,WHITE);
							break;
						case 'B':
							empty++;
							ck_b(i,j,WHITE);
							break;
						case 'Q':
							empty++;
							ck_q(i,j,WHITE);
							break;
						case 'K':
							empty++;
							ck_k(i,j,WHITE);
							break;
						case 'N':
							ck_n(i,j,WHITE);
							break;
					}
				}
			}
			if(i==X_MAX && j==Y_MAX && check ==0)
			{
				if(empty>0)
					printf("Game #%d: no king is in check.\n", cnt);
				check = 1;
			}
			
		}
		cnt++;
	}
}

void ck_p(int x,int y,int c){
	if(c==BLACK && board[x+1][y-1] == 'K')
	{
#ifdef debug
	printf("	*** dubug : ck_p x:%d, y:%d, c:%d\n",x,y,c);
#endif
		call_check(c);
	}
	else if(c==BLACK && board[x+1][y+1] == 'K')
		call_check(c);
	else if(c==WHITE && board[x-1][y-1] == 'k')
		call_check(c);
	else if(c==WHITE && board[x-1][y+1] == 'k')
		call_check(c);
}

void ck_r(int x,int y,int c){
	int i,j;
#ifdef debug
	printf("	*** dubug : check r, x:%d, y:%d, c:%d\n",x,y,c);
#endif
	/* upper side scan */
	for(i=(x-1);i>=0;i--)
	{
		if((board[i][y]=='K' && c==BLACK) || (board[i][y]=='k' && c==WHITE))
			call_check(c);
		else if(board[i][y]!='.') /* check blocked */
			break;
	}
	/* lower side scan */
	for(i=(x+1);i<Y_MAX;i++)
	{
		if((board[i][y]=='K' && c==BLACK) || (board[i][y]=='k' && c==WHITE))
			call_check(c);
		else if(board[i][y]!='.') /* check blocked */
			break;
	}
	/* left side scan */
	for(j=(y-1);j>=0;j--)
	{
		if((board[x][j]=='K' && c==BLACK) || (board[x][j]=='k' && c==WHITE))
			call_check(c);
		else if(board[x][j]!='.') /* check blocked */
			break;
	}
	/* right side scan */
	for(j=(y+1);j<X_MAX;j++)
	{
		if((board[x][j]=='K' && c==BLACK) || (board[x][j]=='k' && c==WHITE))
			call_check(c);
		else if(board[x][j]!='.') /* check blocked */
			break;
	}
}

void ck_b(int x,int y,int c){
	int i;
#ifdef debug
	printf("	*** dubug : check b, x:%d, y:%d, c:%d\n",x,y,c);
#endif
	/* Up side check */
	for(i=1;i<Y_MAX;i++)
	{
		/* upper left side scan */
		if(check >0 ) break;
#ifdef debug
		printf("	*** dubug : check b upper left , x:%d, y:%d, board:%c\n",x-i,y-i,board[x-i][y-i]);
#endif
		if((board[x-i][y-i]=='K' && c==BLACK && (x-i) >=0 && (y-i) >=0) 
			|| (board[x-i][y-i]=='k' && c==WHITE && (x-i) >=0 && (y-i) >=0))
			call_check(c);
		else if(board[x-i][y-i]!='.') /* check blocked */
			break;
	}
	/* upper right side scan */
	for(i=1;i<Y_MAX;i++)
	{
		if(check >0 ) break;
#ifdef debug
		printf("	*** dubug : check b upper right , x:%d, y:%d, board:%c\n",x-i,y+i,board[x-i][y+i]);
#endif
		if((board[x-i][y+i]=='K' && c==BLACK && (x-i) >=0 && (y+i) < X_MAX) 
			|| (board[x-i][y+i]=='k' && c==WHITE && (x-i) >=0 && (y+i) < X_MAX))
			call_check(c);
		else if(board[x-i][y+i]!='.') /* check blocked */
			break;
	}
	/* Down side check */
	/* lower left side scan */
	for(i=1;i<Y_MAX;i++)
	{
		if(check >0 ) break;
#ifdef debug
		printf("	*** dubug : check b lower left , x:%d, y:%d, board:%c\n",x+i,y-i,board[x+i][y-i]);
#endif
		if((board[x+i][y-i]=='K' && c==BLACK && (x+i) < Y_MAX && (y-i) >=0)
			|| (board[x+i][y-i]=='k' && c==WHITE && (x+i) < Y_MAX && (y-i) >=0))
			call_check(c);
		else if(board[x+i][y-i]!='.') /* check blocked */
			break;
	}
	/* lower right side scan */
	for(i=1;i<Y_MAX;i++)
	{
		if(check >0 ) break;
#ifdef debug
		printf("	*** dubug : check b lower right , x:%d, y:%d, board:%c\n",x+i,y+i,board[x+i][y+i]);
#endif
		if((board[x+i][y+i]=='K' && c==BLACK && (x+i) < Y_MAX && (y+i) < X_MAX) 
			|| (board[x+i][y+i]=='k' && c==WHITE && (x+i) < Y_MAX && (y+i) < X_MAX))
			call_check(c);
		else if(board[x+i][y+i]!='.') /* check blocked */
			break;
	}
}
	
void ck_q(int x,int y,int c){
#ifdef debug
	printf("	*** dubug : check q, x:%d, y:%d, c:%d\n",x,y,c);
#endif
	ck_r(x,y,c);
	ck_b(x,y,c);
}

void ck_k(int x,int y,int c){
#ifdef debug
	printf("	*** dubug : check k, x:%d, y:%d, c:%d\n",x,y,c);
#endif
	if((board[x-1][y]=='k' && c==WHITE && (x-1)>=0)
		|| (board[x-1][y]=='K' && c==BLACK && (x-1)>=0))
		call_check(c);
	else if((board[x+1][y]=='k' && c==WHITE && (x+1)<Y_MAX)
			||(board[x+1][y]=='K' && c==BLACK && (x+1)<Y_MAX))
		call_check(c);
	else if((board[x][y-1]=='k' && c==WHITE && (y-1)>=0)
			||(board[x][y-1]=='K' && c==BLACK && (y-1)>=0))
		call_check(c);
	else if((board[x][y+1]=='k' && c==WHITE && (y+1)<X_MAX)
			||(board[x][y+1]=='K' && c==BLACK && (y+1)<X_MAX))
		call_check(c);
	else if((board[x-1][y+1]=='k' && c==WHITE && (x-1)>=0 && (y+1)<X_MAX)
			||(board[x-1][y+1]=='K' && c==BLACK && (x-1)>=0 && (y+1)<X_MAX))
		call_check(c);
	else if((board[x-1][y-1]=='k' && c==WHITE && (x-1)>=0 && (y-1)>=0)
			||(board[x-1][y-1]=='K' && c==BLACK && (x-1)>=0 && (y-1)>=0))
		call_check(c);
	else if((board[x+1][y+1]=='k' && c==WHITE && (x+1)<Y_MAX && (y+1)<X_MAX)
			||(board[x+1][y+1]=='K' && c==BLACK && (x+1)<Y_MAX && (y+1)<X_MAX))
		call_check(c);
	else if((board[x+1][y-1]=='k' && c==WHITE && (x+1)<Y_MAX && (y-1)>=0)
			||(board[x+1][y-1]=='K' && c==BLACK && (x+1)<Y_MAX && (y-1)>=0))
		call_check(c);
}

void ck_n(int x,int y,int c){
#ifdef debug
	printf("	*** dubug : check n, x:%d, y:%d, c:%d\n",x,y,c);
#endif
	if((board[x-2][y-1]=='k' && c==WHITE && (x-2)>=0 && (y-1)>=0)
		|| (board[x-2][y-1]=='K' && c==BLACK && (x-2)>=0 && (y-1)>=0))
		call_check(c);
	else if((board[x-2][y+1]=='k' && c==WHITE && (x-2)>=0 && (y+1)<X_MAX)
		|| (board[x-2][y+1]=='K' && c==BLACK && (x-2)>=0 && (y+1)<X_MAX))
		call_check(c);
	else if((board[x-1][y-2]=='k' && c==WHITE && (x-1)>=0 && (y-2)>=0)
		|| (board[x-1][y-2]=='K' && c==BLACK && (x-1)>=0 && (y-2)>=0))
		call_check(c);
	else if((board[x-1][y+2]=='k' && c==WHITE && (x-1)>=0 && (y+2)<X_MAX)
		|| (board[x-1][y+2]=='K' && c==BLACK && (x-1)>=0 && (y+2)<X_MAX))
		call_check(c);
	else if((board[x+1][y+2]=='k' && c==WHITE && (x+1)<Y_MAX && (y+2)<X_MAX)
		|| (board[x+1][y+2]=='K' && c==BLACK && (x+1)<Y_MAX && (y+2)<X_MAX))
		call_check(c);
	else if((board[x+1][y-2]=='k' && c==WHITE && (x+1)<Y_MAX && (y-2)>=0)
		|| (board[x+1][y-2]=='K' && c==BLACK && (x+1)<Y_MAX && (y-2)>=0))
		call_check(c);
	else if((board[x+2][y-1]=='k' && c==WHITE && (x+2)<Y_MAX && (y-1)>=0)
		|| (board[x+2][y-1]=='K' && c==BLACK && (x+2)<Y_MAX && (y-1)>=0))
		call_check(c);
	else if((board[x+2][y+1]=='k' && c==WHITE && (x+2)<Y_MAX && (y+1)>X_MAX)
		|| (board[x+2][y+1]=='K' && c==BLACK && (x+2)<Y_MAX && (y+1)>X_MAX))
		call_check(c);
}

void call_check(int c){
	if(c==BLACK)
		printf("Game #%d: white king is in check.\n", cnt);
	else
		printf("Game #%d: black king is in check.\n", cnt);

	check++;
}
