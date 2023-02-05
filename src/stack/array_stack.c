#include<stdio.h>

/*
 * 用数组结构实现栈
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

#define CAPACITY 20

int count = -1;
int array[CAPACITY] = {};

int is_empty();
int is_full();
int push(int item);
int pop();

int main(){	
	printf("--------Is Empty:%d--------\n", is_empty());

    printf("--------Push Item--------\n");	
	for(int i = 0; i <25; i++){
		if(is_full()){	
		    printf("----Is Full, Push %d Failed----\n", i);
		}
		push(i);
	}
	
	printf("--------Pop Item--------\n");	
	while(!is_empty()){
		printf("--------Pop Item:%d--------\n", pop());	
	}	
}

int is_empty(){
	return count == -1;
}

int is_full(){
	return count >= CAPACITY - 1;
}

int push(int item){
	if(count >= CAPACITY){
		return 0;
	}
	array[++count] = item;
	return 1;
}

int pop(){
	return array[count--];
}

