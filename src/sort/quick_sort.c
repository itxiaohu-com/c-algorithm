#include<stdio.h>

/*
 * 快速排序
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

/*
 * 经典实现
 */
void sort(int array[],  int length, int start, int end);

/**
 * 打印数组
 */
void print(int array[], int length);

/**
 * 数组元素交换
 */
void swap(int array[], int source, int target);

int main() {
	int array[] = {55, 23, 87, 99, 62, 16, 17, 73, 11, 37};
	int length = sizeof(array)/sizeof(array[0]);
	
	printf("--------before quick sort--------\n");
	print(array, length);
	
	sort(array, length, 0, length - 1);
	
	printf("--------after quick sort--------\n");
	print(array, length);
	return 0;
}

void sort(int array[],  int length, int start, int end) {
	if(start >= end){
		return;
	}
	
	int division = array[start];            /*1. 假设K的值为第一个键值*/
	int left = start + 1;
	int right = end;
	int i = start + 1;
	int j = end;
	
	while(left < right){
		for(; i <= end; i++){               /*2. 从左向右找出键值Ki，使得Ki>K*/
			if(array[i] > division){
				left = i;
				break;
			}
			left++;
		}
	
		for(; j >= start + 1; j--){         /*3. 从右往左找出键值Kj，使得Kj<K*/
			if(array[j] < division){
				right = j;
				break;
			}
			right--;
		}
		
		if(left < right){                   /*4. 若i<j，则Ki与Kj互换，并回到步骤2*/
			swap(array, left, right);
		}
	}
	
	swap(array, start, right);              /*5. 若i>=j，则K与Kj互换，并以j为基准点分割成*/
	sort(array, length, start, right - 1);  /*左右两个部分，然后针对左、右两边执行步骤(1)~(5)，*/
	sort(array, length, right + 1, end);    /*直到左边键值等于右边键值为止。*/
}

void print(int array[], int length) {
    for(int i = 0; i < length; i++){
    	printf("array[%d]:%d\n", i, array[i]);
	}
}

void swap(int array[], int source, int target){
	if(source == target){
		return;
	}
	int element = array[source];
	array[source] = array[target];
	array[target] = element;
}