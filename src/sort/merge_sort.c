#include<stdio.h>
#include<stdlib.h>

/*
 * 合并/归并排序
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

/*
 * 经典实现
 */
void sort(int array[], int length);

void inner_sort(int array[], int left, int right);
void inner_merge(int array[], int left, int middle, int right);

/**
 * 打印数组
 */
void print(int array[], int length);

int main() {	
	int array[] = {55, 23, 87, 99, 62, 16, 17, 73, 11, 37};
	int length = sizeof(array)/sizeof(array[0]);
	
	printf("--------before merge sort--------\n");
	print(array, length);
	
	sort(array, length);
	
	printf("--------after merge sort--------\n");
	print(array, length);
	return 0;
}

void sort(int array[], int length) {
	inner_sort(array, 0, length-1);
}

void inner_sort(int array[], int left, int right) {
	if(left<right){
		int middle = (left+right)/2;
		inner_sort(array, left, middle);
		inner_sort(array, middle+1, right);
		inner_merge(array, left, middle, right);
	}
}

void inner_merge(int array[], int left, int middle, int right) {
	int *buffer = (int *)malloc(sizeof(int) * (right-left+1));
	int i = left;
	int j = middle + 1;
	int m = 0;
	
	while(i <= middle && j <= right){
		if(array[i] < array[j]){
			buffer[m++] = array[i++];
		}else{
			buffer[m++] = array[j++];
		}
	}
	
	while(i <= middle){
		buffer[m++] = array[i++];
	}
	
	while(j <= right){
		buffer[m++] = array[j++];
	}
	
	int n = left;
	while(n < left + m){
		array[n] = buffer[n - left];
		n++;
	}
	free(buffer);
}

void print(int array[], int length) {
    for(int i = 0; i < length; i++){
    	printf("array[%d]:%d\n", i, array[i]);
	}
}