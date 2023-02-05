#include<stdio.h>

/*
 * 希尔排序
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

/*
 * 经典实现
 */
void sort(int array[], int length);

/**
 * 打印数组
 */
void print(int array[], int length);

int main() {
	int array[] = {55, 23, 87, 99, 62, 16, 17, 73, 11, 37};
	int length = sizeof(array)/sizeof(array[0]);
	
	printf("--------before shell sort--------\n");
	print(array, length);
	
	sort(array, length);
	
	printf("--------after shell sort--------\n");
	print(array, length);
	return 0;
}

void sort(int array[], int length) {
	int step = length/2;
	
	while(step != 0){
		for(int i=0; i<length-step; i++){
			int num = array[i+step];
			int j = i;
			while(j>=0 && num<array[j]){
				array[j+step] = array[j];
				j -= step;
			}
			array[j+step] = num;
		}	
		step /= 2;
	}
}

void print(int array[], int length) {
    for(int i = 0; i < length; i++){
    	printf("array[%d]:%d\n", i, array[i]);
	}
}