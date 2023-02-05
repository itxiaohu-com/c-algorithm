#include<stdio.h>

/*
 * 插入排序
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

/*
 * 经典实现
 */
void sort(int array[], int length);
/**
 * 笨方法实现
 */
void stupid_sort(int array[], int length);
/**
 * 打印数组
 */
void print(int array[], int length);

int main() {
	int array[] = {55, 23, 87, 99, 62, 16, 17, 73, 11, 37};
	int length = sizeof(array)/sizeof(array[0]);
	
	printf("--------before insert sort--------\n");
	print(array, length);
	
	sort(array, length);
	
	printf("--------after insert sort--------\n");
	print(array, length);
	return 0;
}

void sort(int array[], int length) {
    for(int i=0; i<length-1; i++){           /*i为已完成排序界限,第一个元素默认排好,因此从0开始。最后一轮已完成排序界限是length-2*/
    	int num = array[i+1];                /*获取带插入目标值，即已完成排序界限的下一个值*/
    	int j = i;                           /*记录插入比较区间左边界，即已排序的左边界值*/
    	while(j>=0 && num < array[j]){       /*如果待插入指值比目标值小，则将数组内的值右移一位，核心逻辑*/ 
    		array[j+1] = array[j];           /*右移赋值*/
    		j--;                             /*左移一位继续检测*/  
		}
    	array[j+1] = num;                    /*跳出循环后，说明j位置数值<=num值, 则把num值插入j的后一位j+1，此时j+1在上一轮比较中*/
	}                                        /*已经赋值到j+2了。或者j最后取值-1，则把num值插入0位置*/
}

void stupid_sort(int array[], int length) {
	for(int i = 0; i < length - 1; i++) {    /*已排好序尾部索引*/
		int num = array[i+1];
		if(num > array[i]){
			continue;
		}
		if(num < array[0]){
			for(int j = i+1; j > 0; j--){
				array[j] = array[j-1];
			}
			array[0] = num;
			continue;
		}

        int idx = 0;
		for(int k = 0; k <= i; k++){
			if(num >= array[k-1] && num <= array[k]){
				idx = k;
				break;
			}
		}
		
		for(int m = i+1; m > idx; m--){
			array[m] = array[m-1];
		}
		
		array[idx] = num;
	}
}

void print(int array[], int length) {
    for(int i = 0; i < length; i++){
    	printf("array[%d]:%d\n", i, array[i]);
	}
}