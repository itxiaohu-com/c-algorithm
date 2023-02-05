#include<stdio.h>

/*
 * 数组实现二叉查找树
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

#define CAPACITY 32

int tree_array[CAPACITY] = {0};

/*
 * 添加元素
 */
void add(int item);

/*
 * 二叉树元素个数
 */
int length();

/*
 * 打印二叉树数据
 */
void print();

int main(){
	int data[8] = {6, 3, 5, 4, 7, 8, 9, 2};
	int length = 8;
	
	int i = 0;
	while(i < length){
		add(data[i]);
		i++;	
	}
	
	print();
}

void add(int item){
	if(length() == 0){
		tree_array[1] = item;
		tree_array[0] = 1;
	}else{
		int n = 1;
		while(tree_array[n] != 0){
			if(item < tree_array[n]){
				n = 2*n;
			}else{
				n = 2*n + 1;
			}
		}
		tree_array[n] = item;
		tree_array[0] += 1;
	}
}

int length(){
	return tree_array[0];
}

void print(){
	int i;
	for(i = 0; i < CAPACITY; i++){
		printf("[%2d]%2d\n", i, tree_array[i]);
	}
}






