#include<stdio.h>

/*
 * 插值查找
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

void sort(int array[], int length);
void print(int array[], int length);

/*
 * 查找数据
 */
int search(int array[], int length, int value);


int main() {	
	int array[] = {55, 23, 87, 99, 62, 16, 17, 73, 11, 37};
	int length = sizeof(array)/sizeof(array[0]);
	
	sort(array, length);
	print(array, length);
	
	int value = 62;
	printf("the index of value[%d] is %d", value, search(array, length, value));
	return 0;
}

/**
 * 插值查找步骤
 *
 * 1) 对记录升序排序;
 * 2）令low=1, high=n;
 * 3) 当low<high时，重复执行步骤04和步骤05;
 * 4) 令 middle = low + ((value - array[low])/(array[high] - array[low])) * (high - low); 
 * 5) 若value < array[middle]且high!=middle-1, 则令high=middle-1;
 * 6) 若value > array[middle]且low!=middle+1, 则令low=middle+1;
 * 7) 若value = array[middle]，则表示成功查找到值的位置;
 */
int search(int array[], int length, int value) {
	int low = 0;
	int high = length - 1;
	int middle = 0;
	while(low<high){
		middle = low + ((value - array[low])/(array[high] - array[low])) * (high - low);
		if(value < array[middle]){
			high = middle - 1;
		}else if(value > array[middle]){
			low = middle + 1;
		}else{
			return middle;
		}
	}
	return -1;
}


/**
 * 冒泡排序
 */
void sort(int array[], int length) {
	for(int i = length - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(array[j] > array[j+1]){
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