#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * Dijkstra算法
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */

#define SIZE 7
#define COUNT 6
#define INFINITE 99999

int graph_matrix[SIZE][SIZE];
int distance[SIZE];

/**
 * 构建图数组
 */
void buildGraphMatrix(int *address);

/**
 * 寻找最短路径
 */
void findShortestPath(int vertex, int count);
/*
 * 打印图矩阵
 */
void printGraphMatrix();
/*
 * 打印结果
 */
void printResult();

int main(){
	int graph[8][3] = { {1, 2, 29},
						{2, 3, 30},
						{2, 4, 35},
						{3, 5, 28},
						{3, 6, 87},
						{4, 5, 42},
						{4, 6, 75},
						{5, 6, 97}};
						
    buildGraphMatrix(&graph[0][0]);
	
	findShortestPath(1, COUNT);
	
	printGraphMatrix();
	
	printResult();
	
	return 0;
}

void buildGraphMatrix(int *address){
	int i = 0;
	int j = 0;
	for(i = 1; i < SIZE; i++) {
		for(j = 1; j < SIZE; j++){
			if(i == j){
				graph_matrix[i][j] = 0;         // 顶点到自己的距离设置为零
			}else{
				graph_matrix[i][j] = INFINITE;  //其他设置为无穷大
 			}
		}
	}
	
	int k = 0;
	int start = 0;
	int end = 0;
	while(k < SIZE){
		start = address[k*3];
		end = address[k*3+1];
		graph_matrix[start][end] = address[k*3+2];
		k++;
	}
}

void findShortestPath(int vertex, int count){
	
	int shortest_vertex = 1;     //最短顶点
	int shortest_distance = 0;   //最短距离
	int selected_vertex[SIZE];   //顶点选取标示
	
	for(int i = 1; i <= count; i++){
		selected_vertex[i] = 0;
		distance[i] = graph_matrix[vertex][i];
	}
	
	selected_vertex[vertex] = 1;
	distance[vertex] = 0;
	
	for(int j = 1; j <= count-1; j++){
		
		shortest_distance = INFINITE;
		
		// 找最短的距离
		for(int k = 1; k <= count; k++){
			if(selected_vertex[k] == 0 && shortest_distance > distance[j])
			shortest_distance = distance[j];
			shortest_vertex = j;
		}
		
		selected_vertex[shortest_vertex] = 1;
		
		// 计算开始顶点到各顶点的距离
		for(int k = 1; k <= count; k++){
			if(selected_vertex[k] == 0 && distance[shortest_vertex] + graph_matrix[shortest_vertex][k] < distance[k]) {
				distance[k] = distance[shortest_vertex] + graph_matrix[shortest_vertex][k];
			}
		}
		
	}
}

void printGraphMatrix() {
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
	for(int i = 1; i < SIZE; i++){
		printf("vertex[1] -> vertxt[%d] distance is: %d\n", i, distance[i]);
	}
}
