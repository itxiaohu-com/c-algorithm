#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * 链表创建及添加节点
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 
 
#define DATA_MAX_LENGTH 1024 
 
struct model{
	int id;
	char data[DATA_MAX_LENGTH];
	struct node *next;
};

typedef struct model node;
typedef node *pointer;

pointer current; //当前节点
pointer head;    //头节点
pointer draft;   //新节点
	
void create();
void add(int id, char data[DATA_MAX_LENGTH]);
void print();

int main(){

	create();
	
	printf("-------List Created-------\n");
	print();
	
	printf("--------List Added--------\n");
	add(10001, "First");
	print();
	
	printf("--------List Added--------\n");
	add(10002, "Second");
	print();
	
	printf("--------List Added--------\n");
	add(10003, "Third");
	print();
}

void create(){
	head = (pointer)malloc(sizeof(node));
	head->next = NULL;
	current = head;
}

void add(int id, char data[DATA_MAX_LENGTH]){
	draft = (pointer)malloc(sizeof(node));
	draft->id = id;
	strcpy(draft->data, data);
	draft->next = NULL;
	
	current->next = draft;
	current = draft;
}

void print(){
	pointer ptr = head->next;
	while(ptr != NULL){
		printf("{id:%5d, data:%s}\n", ptr->id, ptr->data);
		ptr = ptr->next;
	}
}

