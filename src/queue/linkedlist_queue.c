#include<stdio.h>
#include<stdlib.h>

/*
 * 用链表结构实现队列
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

#define TRUE 1
#define FALSE 0
#define COUNT 100

struct element {
	int data;
	struct element *next;
};
 
typedef struct element item;
typedef item *pointer;

pointer head = NULL;         /*队头节点*/ 
pointer tail = NULL;         /*队尾节点*/

/*
 * 入队
 */
void enqueue(int item);

/*
 * 出队
 */
int dequeue();

/*
 * 查看队头元素
 */
int peek();

/*
 * 查看队头是否为空
 */
int is_empty();

int main(){
	printf("->->->->enqueue->->->->\n");
	for(int i = 0; i < COUNT; i++){
		enqueue(10000 + i);
	}
	
	printf("----------peek---------\n");
	for(int i = 0; i < COUNT; i++){
		printf("(%d):%5d\n", i, peek());
	}
	printf("\n");
	
	printf("<-<-<-<-dequeue<-<-<-<-\n");
	int i = 0;
	while(is_empty() == FALSE){
		printf("(%d):%5d\n", i++, dequeue());
	}
	printf("\n");
}

void enqueue(int item){
	pointer draft = (pointer)malloc(sizeof(item));
	draft->data = item;
	draft->next = NULL;
	
	if(tail == NULL){
		head = draft;
		tail = draft;
	}else{
		tail->next = draft;
		tail = draft;
	}
}

int dequeue(){
	if(is_empty()){
		printf("The queue is empty!\n");
		return -1;
	}
	pointer waste = head;
	int result = waste->data;
	head = head->next;
	free(waste);
	return result; 
}

int peek(){
	if(is_empty()){
		printf("The queue is empty!\n");
		return -1;
	}
	return head->data;
}

int is_empty(){
	if(head == NULL){
        return TRUE;
	}else{
        return FALSE;
	}
}