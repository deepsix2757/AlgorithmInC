#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct stack{
	int stk[MAXSIZE];
	int top;
} STACK;


void Push(int x, STACK *s){
	int num;
	s->top ++;
	printf("Push %d\n", s->top);
	s->stk[s->top] = x;
	return;
}

int Pop(STACK *s){
	int num;
	printf("Pop %d\n", s->top);
	num = s->stk[s->top];
	s->top --;
	return num;
}

void Init(STACK *s){
	s->top = -1;
	printf("Init %d\n", s->top);
	return;
}

int main(){

	STACK *s = (STACK *)malloc(sizeof(STACK));

	Init(s);

	Push(1, s);
	Push(2, s);
	Push(3, s);

	printf("%d\n", Pop(s));
	printf("%d\n", Pop(s));
	printf("%d\n", Pop(s));

}

