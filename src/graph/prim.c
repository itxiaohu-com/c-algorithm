#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * Prim算法
 *  
 * <p>Reference<a href="https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/">Prim’s Minimum Spanning Tree (MST) | Greedy Algo-5</a></p>
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */
 
// 顶点数
#define V 5

int minKey(int key[], bool mstSet[]){
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++) {
		if (mstSet[v] == false && key[v] < min){
			min = key[v], min_index = v;
		}
	}
	return min_index;
}

int printMST(int parent[], int graph[V][V]){
	printf("Edge \tWeight\n");
	for (int i = 1; i < V; i++){
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
	}
     return 0;   
}

void primMST(int graph[V][V]){
	
	int parent[V];   // 记录最小生成树的边,即parent[v]->v
	int key[V];      // 起点到顶点v的最新权重
	bool mstSet[V];  // 加入最小生成树标示数组

	for (int i = 0; i < V; i++){
		key[i] = INT_MAX, mstSet[i] = false;
	}
		
	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);

        printf("----count:%d, u:%d----\n", count, u);

		mstSet[u] = true;
		for (int v = 0; v < V; v++){
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
				parent[v] = u, key[v] = graph[u][v];
			}	
		}
			
	}

	printMST(parent, graph);
}

int main(){
	int graph[V][V] =  {{ 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 }};

	primMST(graph);

	return 0;
}
