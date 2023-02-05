#include<stdio.h>

/*
 * 选择排序
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

void sort(int array[], int length);
void print(int array[], int length);

int main() {
	int array[] = {55, 23, 87, 99, 62, 16, 17, 73, 11, 37};
	int length = sizeof(array)/sizeof(array[0]);
	
	printf("--------before selection sort--------\n");
	print(array, length);
	
	sort(array, length);
	
	printf("--------after selection sort--------\n");
	print(array, length);
	return 0;
}

/**
 * 选择排序
 * 假如从小到大排序，一开始挑选一个最小的元素放在第一个位置，
 * 再从第二个元素开始挑选一个最小的元素放在第二个位置，
 * 以此重复，直到完成排序为止。
 */
void sort(int array[], int length) {
	for(int i = 0; i < length - 1; i++){         /*排序位置或扫描次数*/
	
		int min = array[i];                      /*把待排序位置的值设置为初始最小值*/
		int min_index = i;                       /*把待排序位置索引设置为初始最小值索引*/
	
		for(int j = i + 1; j < length; j++){     /*从待排序位置下一个元素之后的元素中寻找最小值*/
			if(array[j] < min){
				min = array[j];                  /*更新最小值*/
				min_index = j;                   /*更新最小值索引*/
			}
		}
		
		if(min_index != i){                      /*若最小值所以有变更，说明待排序位置值不是剩余*/
	        int num = array[i];                  /*元素中的最小值，需要对调处理*/
			array[i] = array[min_index];
			array[min_index] = num;
		}
	}
}

void sort2(int array[], int length) {
	for(int i = 0; i < length - 1; i++){         /*排序位置或扫描次数*/
		for(int j = i + 1; j < length; j++){     /*从待排序位置下一个元素之后的元素中寻找最小值*/
			if(array[j] < array[i]){             /*此做法可能发生多次最小值对调,效率稍低*/
			    int num = array[i];
			    array[i] = array[j];
			    array[j] = num;
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