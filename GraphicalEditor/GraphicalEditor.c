#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define debug_

#define N_MAX 250
#define M_MIN 1

void Sprint(char *);
void Bucket(int, int, char *);

/*  for easy of reference */
int x,y;
char *canverse;

int main(){
	char string[1000];
	char cmd[2];
	char par1[1000]; /* for file name */
	char par2[4];
	char par3[4];
	char par4[4];
	char par5[4];
	int i,j;
	
	while(gets(string)){
#ifdef debug
		printf("**** string %s\n", string);
#endif
		if(string[0] == 'I'){
			sscanf(string, "%s %s %s", cmd, par1, par2);
			x = atoi(par1);
			y = atoi(par2);
			if(x < M_MIN || y > N_MAX)
				exit(1);
			canverse = (char *)malloc(x*y);
			memset(canverse,'O',x*y);
		}
		else if(string[0] == 'C')
			memset(canverse,'O',x*y);
		else if(string[0] == 'L'){
			sscanf(string, "%s %s %s %s", cmd, par1, par2, par3);
			canverse[(atoi(par1)-1)+((atoi(par2)-1)*x)] = par3[0];
		}
		else if(string[0] == 'V'){
			sscanf(string, "%s %s %s %s %s", cmd, par1, par2, par3, par4);
			for(i=atoi(par2);i<=atoi(par3);i++)
				canverse[(atoi(par2)-1)+((i-1)*x)] = par4[0];
		}
		else if(string[0] == 'H'){
			sscanf(string, "%s %s %s %s %s", cmd, par1, par2, par3, par4);
			for(i=atoi(par1);i<=atoi(par2);i++)
				canverse[(i-1)+((atoi(par3)-1)*x)] = par4[0];
		}
		else if(string[0] == 'K'){
			sscanf(string, "%s %s %s %s %s %s", cmd, par1, par2, par3, par4, par5);
			for(i=atoi(par1);i<=atoi(par3);i++)
				for(j=atoi(par2);j<=atoi(par4);j++)
					canverse[(i-1)+(j-1)*x] = par5[0];
		}
		else if(string[0] == 'F'){
			sscanf(string, "%s %s %s %s", cmd, par1, par2, par3);
			Bucket(atoi(par1), atoi(par2), par3);
		}
		else if(string[0] == 'S'){
			sscanf(string, "%s %s", cmd, par1);
			Sprint(par1);
		}
		else if(string[0] == 'X')
			exit(0);
		else
			continue;
	}
	return 0;
}

void Sprint(char *file){
	int i,j;
	printf("%s\n", file);
	for(i=1;i<=y;i++){
		for(j=1;j<=x;j++){
#ifdef debug
			printf("**** S i:%d, j:%d, canverse[%d] \n", i,j,(i-1)*x+j-1);
#endif
			printf("%c",canverse[(i-1)*x+j-1]);
		}
		printf("\n");
	}
}

/* Recursive Function */
void Bucket(int _x, int _y, char *c){
	char oldc;
	oldc = canverse[(_x-1)+(_y-1)*x];
	canverse[(_x-1)+(_y-1)*x] = c[0];

#ifdef debug
	printf("**** Bucket  _x:%d, _y:%d, oldc:%c, c:%s \n", _x,_y,oldc,c);
#endif
	if((_x-1) > 0 && (canverse[((_x-1-1)+(_y-1)*x)] == oldc))
		Bucket(_x-1, _y, c);	
	if((_x+1) <= x && (canverse[(_x+(_y-1)*x)] == oldc))
		Bucket(_x+1, _y, c);	
	if((_y-1) > 0 && (canverse[((_x-1)+(_y-1-1)*x)] == oldc))
		Bucket(_x, _y-1, c);	
	if((_y+1) <= y && (canverse[((_x-1)+(_y)*x)] == oldc))
		Bucket(_x, _y+1, c);	
}
