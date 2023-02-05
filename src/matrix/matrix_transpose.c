#include<stdio.h>

/*
 * 矩阵转置
 *
 * <p>Reference<a href="https://matrixcalc.org/en/"><b>Matrix calculator</b></a></p>
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 
 
#define WIDTH 5
#define HEIGHT 5

void transpose(int source[WIDTH][HEIGHT], int target[WIDTH][HEIGHT]);
void print(int matrix[WIDTH][HEIGHT]);
 
int main(){
	
	int source[WIDTH][HEIGHT] = {
		{11, 12, 13, 14, 15},
		{21, 22, 23, 24, 25},
		{31, 32, 33, 34, 35},
		{41, 42, 43, 44, 45},
		{51, 52, 53, 54, 55}
	};
	int target[WIDTH][HEIGHT] = {};
	
	printf("--------source matrix--------\n");
	print(source);
	
	transpose(source, target);
	
	printf("--------target matrix--------\n");
	print(target);
		
}

void transpose(int source[WIDTH][HEIGHT], int target[WIDTH][HEIGHT]){
	for(int i = 0; i < WIDTH; i++){
		for(int j = 0; j < HEIGHT; j++){
			target[i][j] = source[j][i];
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

