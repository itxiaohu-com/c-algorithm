#include<stdio.h>
#include<stdlib.h>

/*
 * 矩阵相乘
 *
 * <p>Reference<a href="https://matrixcalc.org/en/"><b>Matrix calculator</b></a></p>
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 
 
#define LENGTH 3
#define WIDTH 4 
#define HEIGHT 5

void multiply(int *a, int *b, int *c, int l, int w, int h);
void print(int *a, int l, int w);

int main(){
	int TA[LENGTH][WIDTH] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
	
	int TB[WIDTH][HEIGHT] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20}
	};
	
	int *A = (int*)malloc(LENGTH*WIDTH*sizeof(int));
	int *B = (int*)malloc(WIDTH*HEIGHT*sizeof(int));
	int *C = (int*)malloc(LENGTH*HEIGHT*sizeof(int));
	
	printf("--------Matrix A Init--------\n");
	for(int i = 0; i < LENGTH; i++){
		for(int j = 0; j < WIDTH; j++){
			A[i*WIDTH+j] = TA[i][j];
		}
	}
	print(A, LENGTH, WIDTH);
	
	printf("--------Matrix B Init--------\n");
    for(int i = 0; i < WIDTH; i++){
		for(int j = 0; j < HEIGHT; j++){
			B[i*HEIGHT+j] = TB[i][j];
		}
	}
	print(B, WIDTH, HEIGHT);
			
    multiply(A, B, C, LENGTH, WIDTH, HEIGHT);
    
    
	printf("--------Matrix C Data--------\n");
	print(C, LENGTH, HEIGHT);
	
    system("pause");
}

void multiply(int *a, int *b, int *c, int l, int w, int h){
	for(int i = 0; i < l; i++){
		for(int j = 0; j < h; j++){
			c[i*h+j] = 0;
			for(int k = 0; k < w; k++){
				c[i*h+j] += a[i*w+k] * b[k*h+j];
			}
		}
	}
}

void print(int *a, int l, int w){
	for(int i = 0; i < l; i++){
		for(int j = 0; j < w; j++){
			printf("[%d,%d]:%5d", i, j, a[i*w+j]);	
		}
		printf("\n");
	}
}