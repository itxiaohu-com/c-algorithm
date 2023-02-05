#include<stdio.h>

/*
 * 基数排序
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
void print_two(int array[10][20], int width, int height);

int main() {
	int array[] = {55, 23, 87, 99, 62, 16, 17, 73, 11, 37};
	int length = sizeof(array)/sizeof(array[0]);
	
	printf("--------radix shell sort--------\n");
	print(array, length);
	
	sort(array, length);
	
	printf("--------radix shell sort--------\n");
	print(array, length);
	return 0;
}

void sort(int array[], int length) {
	for(int place = 1; place <= 100; place*=10){
		int buffer[10][20]={0};
		for(int i = 0; i < length; i++){         /*放入暂存表*/
			int index = (array[i]/place)%10;
			buffer[index][i] = array[i];
		}
		print_two(buffer, 10, 20);
		int j = 0;
		for(int m = 0; m < 10; m++){             /*从暂存表按照升序写入原数组*/
			for(int n = 0; n < length; n++){
			    int num = buffer[m][n];	
			    if(num != 0){
		            array[j++] = num;
				}
			}
		}
	}
}

void print(int array[], int length) {
    for(int i = 0; i < length; i++){
    	printf("array[%d]:%d\n", i, array[i]);
	}
}

print_two(int array[10][20], int width, int height){
	printf("--------print_two--------\n");
	for(int j = 0; j < height; j++){
		for(int i = 0; i < width; i++){
		    printf("%3d", array[i][j]);
		}
    	printf("\n");
	}
}