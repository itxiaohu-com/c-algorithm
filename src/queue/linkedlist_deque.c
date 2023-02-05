#include<stdio.h>
#include<stdlib.h>

/*
 * 用链表结构实现双向队列
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

#define MODE_QUEUE 1         /*队列模式*/
#define MODE_STACK 0         /*堆栈模式*/

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
int dequeue(int mode);

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
	printf("%5d\n", peek());
	
	printf("<-<-<-<-dequeue<-<-<-<-\n");
	int i = 0;
	while(is_empty() == FALSE){
//		printf("(%d):%5d\n", i++, dequeue(MODE_QUEUE));
		printf("(%d):%5d\n", i++, dequeue(MODE_STACK));
	}
	printf("\n");
}

void enqueue(int item){
	pointer draft = (pointer)malloc(sizeof(item));
	draft->data = item;
	draft->next = NULL;
	if(tail == NULL){
		head = draft;
	}else{
		tail->next = draft;
	}
	tail = draft;
}

int dequeue(int mode){
	int result;
	pointer waste = NULL;
	pointer cursor = NULL;
	
	switch(mode){
		case MODE_QUEUE:{
			if(head == tail){
				tail = NULL;
			}
			waste = head;
			result = waste->data;
			head = head->next;
			break;
		}
		case MODE_STACK:{
			waste = tail;
			result = waste->data;
			if(head == tail){
				head = NULL;
				tail = NULL;
			}else{
				cursor = head;
				while(cursor->next != tail){
					cursor = cursor->next;
				}
				tail = cursor;
				cursor->next = NULL;
			}
			break;
		}
        default:{
            printf("The para:%d is invalid!\n");
		    return -1;
        }
	}
	if(waste != NULL){
		free(waste);
	}
	return result; 
}

int peek(){
	if(is_empty()){
		printf("The deque is empty!\n");
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