#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
 * 使用除留余数法和线性探测法实现数据哈希存储
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

#define CAPACITY 10

/**
 * 打印数组
 */
void print(int array[], int length);

/**
 * 添加数据到哈希表
 */
int add(int *table, int value);

int table[CAPACITY] = {};

int main(void) {
	// 测试数据
	int array[8] = {-1};
	// 用时间初始化随机函数
	srand((unsigned)time(NULL));
	for(int i=0; i<8; i++){
		array[i] = rand()%20 + 1;
	}
	
	for(int i=0; i<CAPACITY; i++){
		table[i] = -1;
	}
	
	printf("--------test data--------\n");
	print(array, 8);
	
	printf("--------bucket data--------\n");
	print(table, CAPACITY);
	
	printf("--------add data--------\n");
	for(int i=0; i<8; i++){
		add(table, array[i]);
		print(table, CAPACITY);
	}
	
	return 0;
}

int add(int *table, int value){
	int index = value%CAPACITY;
	while(1){
		if(table[index] == -1){
			table[index] = value;
			return 1;
		}else{
			index = (index+1)%CAPACITY;
		}
	}
}

void print(int array[], int length) {
    for(int i = 0; i < length; i++){
    	printf("[%d]:%d\t", i, array[i]);
	}
	printf("\n");
}