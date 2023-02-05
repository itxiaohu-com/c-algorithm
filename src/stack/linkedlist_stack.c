#include<stdio.h>
#include<stdlib.h>

/**
 * 用链表结构实现栈
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

struct element {
	int data;
	struct element *next;
};
 
typedef struct element item;
typedef item *pointer;

pointer top = NULL;
 
int is_empty();
void push(int data);
int pop(); 

int main(){	
	printf("------Is Empty:[%d]------\n", is_empty());

    printf("--------Push Item-------\n");	
	for(int i = 10; i < 20; i++){
		printf("->->->->->[%2d]->->->->->\n", i);	
		push(i);
	}
	
	printf("--------Pop Item-------\n");	
	while(!is_empty()){
		printf("<-<-<-<-<-[%d]<-<-<-<-<-\n", pop());	
	}
}

int is_empty(){
	return top == NULL;
}

void push(int data){
	pointer draft = (pointer)malloc(sizeof(item));
	draft->data = data;
	draft->next = top;
	top = draft;
}

int pop(){
	int result = top->data;
	
	pointer to_free = top;
	top = top->next;
	free(to_free);
	
	return result;
}