#include<stdio.h>

/*
 * 矩阵相加
 *
 * <p>Reference<a href="https://matrixcalc.org/en/"><b>Matrix calculator</b></a></p>
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 
 
#define WIDTH 5
#define HEIGHT 5

void addition(int a[WIDTH][HEIGHT], int b[WIDTH][HEIGHT], int c[WIDTH][HEIGHT]);
void print(int matrix[WIDTH][HEIGHT]);
 
int main(){
	
	int ma[WIDTH][HEIGHT] = {
		{11, 12, 13, 14, 15},
		{21, 22, 23, 24, 25},
		{31, 32, 33, 34, 35},
		{41, 42, 43, 44, 45},
		{51, 52, 53, 54, 55}
	};
	
	int mb[WIDTH][HEIGHT] = {
		{11, 12, 13, 14, 15},
		{21, 22, 23, 24, 25},
		{31, 32, 33, 34, 35},
		{41, 42, 43, 44, 45},
		{51, 52, 53, 54, 55}
	};
	
	int mc[WIDTH][HEIGHT] = {};
	
	printf("--------matrix A--------\n");
	print(ma);
	
	printf("--------matrix B--------\n");
	print(mb);
	
	addition(ma, mb, mc);
	
	printf("--------matrix C--------\n");
	print(mc);
		
}

void addition(int a[WIDTH][HEIGHT], int b[WIDTH][HEIGHT], int c[WIDTH][HEIGHT]){
	for(int i = 0; i < WIDTH; i++){
		for(int j = 0; j < HEIGHT; j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void print(int matrix[WIDTH][HEIGHT]){
	for(int i = 0; i < WIDTH; i++){
		for(int j = 0; j < HEIGHT; j++){
			printf("[%d,%d]:%d\t", i, j, matrix[i][j]);	
		}
		printf("\n");
	}
}