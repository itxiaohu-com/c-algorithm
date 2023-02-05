#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * Floyd算法
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */

#define SIZE 7
#define COUNT 6
#define INFINITE 99999

int graph_matrix[SIZE][SIZE];
int distance[SIZE][SIZE];

/**
 * 构建图数组
 */
void buildGraphMatrix(int *address);

/**
 * 寻找最短路径
 */
void findShortestPath(int count);
/*
 * 打印图矩阵
 */
void printGraphMatrix();
/*
 * 打印结果
 */
void printResult();

int main(){
	int graph[7][3] = { {1, 2, 20},
						{2, 3, 30},
						{2, 4, 25},
						{3, 5, 28},
						{4, 5, 32},
						{4, 6, 95},
						{5, 6, 67}};
						
    buildGraphMatrix(&graph[0][0]);
	
	findShortestPath(COUNT);
	
	printGraphMatrix();
	
	printResult();
	
	return 0;
}

void buildGraphMatrix(int *address){
	for(int i = 1; i < SIZE; i++) {
		for(int j = 1; j < SIZE; j++){
			if(i == j){
				graph_matrix[i][j] = 0;         // 顶点到自己的距离设置为零
			}else{
				graph_matrix[i][j] = INFINITE;  //其他设置为无穷大
 			}
		}
	}
	
	int k = 0;
	int start = 0;  // 边线起点
	int end = 0;    // 边线终点
	while(k < SIZE){
		start = address[k*3];
		end = address[k*3+1];
		graph_matrix[start][end] = address[k*3+2];
		k++;
	}
}

void findShortestPath(int count){
	
	// 初始化图的长度数组
    for(int i = 1; i <= count; i++){
    	for(int j = i; j <= count; j++){
    		distance[j][i] = distance[i][j] = graph_matrix[i][j];
		}
	}
    
    // 使用Floyd算法找出所有顶点两两之间的最短距离
    for(int k = 1; k <= count; k++){
    	for(int i = 1; i <= count; i++){
	    	for(int j = 1; j <= count; j++){
	    		if(distance[i][k] + distance[k][j] < distance[i][j]){
	    			distance[i][j] = distance[i][k] + distance[k][j];
				}
			}
	    }
	}
}

void printGraphMatrix() {
	printf("--------printGraphMatrix--------\n");
	int i = 0;
	int j = 0;
	for(i = 1; i < SIZE; i++) {
		for(j = 1; j < SIZE; j++){
			printf("%d\t", graph_matrix[i][j]);
		}
		printf("\n");
	}
}

void printResult(){
	printf("--------printResult--------\n");
	printf("\tvertex1 vertex2 vertex3 vertex4 vertex5 vertex6\n");
	for(int i = 1; i < SIZE; i++){
		printf("vertex%d\t", i);
		for(int j = 1; j < SIZE; j++){
			printf("%d\t", distance[i][j]);
		}
		printf("\n");
	}
}
