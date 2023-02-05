#include<stdio.h>

/*
 * 冒泡排序
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

void sort(int array[], int length);
void print(int array[], int length);

int main(void){
	int array[] = {55, 23, 87, 99, 62, 16, 17, 73, 11, 37};
	int length = sizeof(array)/sizeof(array[0]);
	
	printf("--------before bubble sort--------\n");
	print(array, length);
	
	sort(array, length);
	
	printf("--------after bubble sort--------\n");
	print(array, length);
	return 0;
}

/**
 * 冒泡排序
 */
void sort(int array[], int length) {
	for(int i = length - 1; i > 0; i--){    /*扫描次数或扫描右边界*/
		for(int j = 0; j < i; j++){         /*比较或交换次数*/
			if(array[j] > array[j+1]){      /*相邻元素比较,当顺序有误则进行对调*/
				int num = array[j];
				array[j] = array[j+1];
				array[j+1] = num;
			}
		}
	}
}

/**
 * 打印数组
 */
void print(int array[], int length) {
    for(int i = 0; i < length; i++){
    	printf("array[%d]:%d\n", i, array[i]);
	}
}