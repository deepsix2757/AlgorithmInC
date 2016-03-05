#include <stdio.h>
#include <string.h>

#define debug
#define NO 0
#define YES 1

/* Pre define function */
void print_star(char *);
int check_len(int);
int check_dict(char *);
int set_map(char *, char *);
int check_conv();
void print_conv();
void conv();

/* typedef for word structure */
typedef struct{
	char word[17];
	int word_len;
} word;

typedef struct{
	char word[17];
	char d_word[17];
	int word_len;
} crypted;

/* Global variables */
char buf[81];
char tmp[17];
char map[26];
word dict[1000];
crypted crypt[80];
int dict_cnt;
int word_cnt;

int main(){
	int i,j,complete;
	char mapping_flag;
	
	scanf("%d",&dict_cnt);
#ifdef debug
	printf("**** debug  dict_cnt : %d\n",dict_cnt);
#endif

	/* dictionay setting */
	for(i=0;i<dict_cnt;i++){
		scanf("%s",dict[i].word);
		dict[i].word_len = strlen(dict[i].word);
#ifdef debug
		printf("**** debug  dict[%d](size) : %s(%d)\n",i,dict[i].word,dict[i].word_len);
#endif
	}
	/* for error exception when uging gets after scanf */
	getc(stdin);

	while(1){
		i = 0;
		j = 0;
		word_cnt = 0;
		mapping_flag = 'Y';
		complete = NO;
		/* string get */
		gets(buf);
#ifdef debug
		printf("**** debug  crypted_string(size) : %s(%ld)\n",buf,strlen(buf));
#endif
		/* string to words */
		for(i=0;i<strlen(buf);i++){
			if(buf[i]!=' '){
				tmp[j] = buf[i];
				j++;
			}
			else{
				tmp[j] = 0x00;
				strcpy(crypt[word_cnt].word, tmp);
				crypt[word_cnt].word_len = strlen(crypt[word_cnt].word);
				/* empty decoded word setting */
				for(j=0;j<crypt[word_cnt].word_len;j++){
					crypt[word_cnt].d_word[j] = ' ';
				}
#ifdef debug
				printf("**** debug  crypt[%d](size) : %s(%d)\n",i,crypt[word_cnt].word,crypt[word_cnt].word_len);
#endif
				/* check word length */
				if(check_len(crypt[word_cnt].word_len) == NO){
					/* if no matching size then print and break */
					print_star(buf);	
					mapping_flag = 'N';
					break;
				}
				j = 0;
				word_cnt ++;
				memset(tmp,0x00,strlen(tmp));
			}
		}

		/* word mapping setting */
		if(mapping_flag == 'Y'){
			for(i=0;i<27;i++)
				map[i] = ' ';
			map[strlen(map)] = '\0';
#ifdef debug
			printf("**** debug  101 map [%s]\n",map);
#endif
			for(i=0;i<word_cnt;i++){
				for(j=0;j<dict_cnt;j++){
#ifdef debug
					printf("**** debug  101 line i[%d],j[%d]\n",i,j);
#endif
					if(dict[j].word_len == crypt[i].word_len){
#ifdef debug
						printf("**** debug  106 line [%s],[%s]\n",dict[j].word,crypt[i].word);
#endif
						if((int)set_map(dict[j].word,crypt[i].word) == YES){
							conv();
							if((int)check_conv == YES)
								break;
						}
					}
				}
			}
		}
		
		if(complete == NO)
			print_star(buf);
		else
			print_conv();

		/*
		for(i=0;i<26;i++){
			if(find_word(map[i]) == ' ')
				find_word(map[i])
		}	
		*/

	}

}

int check_conv(){
	int i,j;
	for(i=0;i<word_cnt;i++){
#ifdef debug
		printf("**** debug  check_conv[%s]\n",crypt[i].d_word);
#endif
		for(j=0;j<strlen(crypt[i].d_word);j++){
			if(crypt[i].d_word[j] == ' ')
				return NO;
		}
	}
	return YES;
}

void conv(){
	int i,j;
	for(i=0;i<word_cnt;i++){
		for(j=0;j<crypt[i].word_len;j++){
			crypt[i].d_word[j] = map[crypt[i].word[j]-97];
#ifdef debug
			printf("**** debug         conv [%c]->[%c]\n",crypt[i].word[j], crypt[i].d_word[j]);
#endif
		}
	}	
}

void print_star(char *str){
	int i;	
	char tmp[81];

	for(i=0;i<strlen(str);i++){
		if(str[i]!=' ')
			tmp[i]='*';
		else
			tmp[i]=' ';
	}
	tmp[strlen(str)]=0x00;

	printf("%s\n",tmp);
}

int check_len(int s){
	int i;
	int check = 0;
	for(i=0;i<dict_cnt;i++){
		if(dict[i].word_len == s){
			check = 1;
			break;
		}
	}

	if(check == 0)
		return NO;
	else
		return YES;
}

int check_dict(char *s){
	int i;
	int check = 0;
	for(i=0;i<dict_cnt;i++){
		if(dict[i].word == s){
			check = 1;
			break;
		}
	}

	if(check == 0)
		return NO;
	else
		return YES;
}

int set_map(char *d, char *c){
	int i,j;
#ifdef debug
	printf("**** debug  before set_map [%s]\n",map);
#endif
	for(i=0;i<strlen(d);i++){
		/* check if exists */
		for(j=0;j<27;j++){
			if(map[j] == d[i])
				exist = YES;	
			break;
		}
		if(exists == NO && (map[c[i]-97] == ' ' || map[c[i]-97] == d[i]))
			map[c[i]-97] = d[i];	
		else
			return NO;
	}
#ifdef debug
	printf("**** debug         set_map [%s]\n",map);
#endif

	return YES;
}

void print_conv(){
	int i;
	for(i=0;i<word_cnt;i++){
		printf("%s",crypt[i].d_word);
		if(i != (word_cnt-1))
			printf("%s"," ");
	}
	printf("\n");
}

char* find_word(char s){
	int i,j;
	char *ret;

	strcpy(ret, " ");
	for(i=0;i<word_cnt;i++){
		for(j=0;j<strlen(crypt[i].word);j++)
			if(crypt[i].word[j] =='s')	
				strcpy(ret, crypt[i].word);
	}

	return ret;
}
