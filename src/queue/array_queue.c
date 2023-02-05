#include<stdio.h>

/*
 * 用数组结构实现队列
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

#define TRUE 1
#define FALSE 0
#define CAPACITY 1024         /*队列容量*/
#define COUNT 100

int array[CAPACITY] = {};     /*队列存放数据的数组*/
int head = -1;                /*队头索引*/ 
int tail = -1;                /*队尾索引*/

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
	if(tail > CAPACITY - 1){
		printf("The queue is full!\n");
		return;
	}
	array[++tail] = item;
}

int dequeue(){
	if(is_empty()){
		printf("The queue is empty!\n");
		return -1;
	}
	return array[++head];
}

int peek(){
	if(is_empty()){
		printf("The queue is empty!\n");
		return -1;
	}
	return array[head+1];
}

int is_empty(){
	if(head == tail){
	    return TRUE;	
	}else{
	    return FALSE;	
	}
}