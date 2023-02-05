#include<stdio.h>
#include<stdlib.h>

/*
 * Kruskal算法
 *  
 * <p>Kruskal算法又称为K氏算法，是将各边按照权值从小到大排列，接着从权值最低的边开始建立最小生成树，如果加入的边会造成回路则舍弃不用，知道加入n-1个边为止。</p>
 * <p>Reference<a href="https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/">Kruskal’s Minimum Spanning Tree Algorithm | Greedy Algo-2</a></p>
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */

#define VERTEX_COUNT 6
#define EDGE_COUNT 10
#define AVAILABLE 1
#define UNAVAILABLE 0

struct element {               /*声明边的结构数据类型*/
	int start;                 /*起点*/
	int end;                   /*终点*/
	int weight;                /*权重*/ 
	int flag;                  /*标识:1-可用;0-不可用*/ 
	struct element *next;
};

typedef struct element edge;
typedef edge *edge_ptr;

// Minimum Spanning Tree
int MST[VERTEX_COUNT+1];
edge_ptr HEAD = NULL;

/*
 *  找到最小权重边
 */
edge_ptr findMinWeightEdge();

/*
 *  打印最小生成树
 */
void printMst();

int main(){
	// 权重边数组
    int graph[EDGE_COUNT][3]={
	    {1,2,6},{1,6,12},{1,5,10},{2,3,3},{2,4,5},
		{2,6,8},{3,4,7},{4,6,11},{4,5,9},{5,6,16}};
    
    
    // 构建边组成的链表
    printf("--------build edge linked list--------\n");
    edge_ptr cur_ptr, new_ptr;
    int i,j;
    
    for(i = 0; i < EDGE_COUNT; i++){
    	for(j = 1; j < VERTEX_COUNT; j++){
    		if(graph[i][0] == j){
    			new_ptr = (edge_ptr)malloc(sizeof(edge));
    			new_ptr->start = graph[i][0];
    			new_ptr->end = graph[i][1];
    			new_ptr->weight = graph[i][2];
    			new_ptr->flag = AVAILABLE;
    			new_ptr->next = NULL;
    			if(HEAD == NULL){
    				HEAD = new_ptr;
    				HEAD->next = NULL;
    				cur_ptr = HEAD;
				}else{
					cur_ptr->next = new_ptr;
					cur_ptr = cur_ptr->next;
				}
			}
		}
	}
	
	cur_ptr = HEAD;
	while(cur_ptr != NULL){
		printf("{start:%d,end:%d,weight:%d,flag:%d}\n", 
				cur_ptr->start, cur_ptr->end, 
				cur_ptr->weight, cur_ptr->flag);
		cur_ptr = cur_ptr->next;		
	}
    
    printf("--------print minimum spanning tree--------\n");
    printMst();
    
    return 0;
}

edge_ptr findMinWeightEdge(){
	edge_ptr iterate_ptr = HEAD;
	edge_ptr result_ptr = NULL;
	int min_weight = 999999999;
	
	while(iterate_ptr != NULL){
		if(iterate_ptr->weight < min_weight && iterate_ptr->flag == AVAILABLE){
			min_weight = iterate_ptr->weight;
			result_ptr = iterate_ptr;
		}
		iterate_ptr = iterate_ptr->next;
	}
	
	result_ptr->flag = UNAVAILABLE;
	return result_ptr;
}

void printMst(){
	int i;
	for(i = 0; i < VERTEX_COUNT+1; i++){
		MST[i] = 0;
	}
	
	edge_ptr iterate_ptr = HEAD;
	while(iterate_ptr != NULL){
		edge_ptr mst_ptr = findMinWeightEdge();
		MST[mst_ptr->start]++;
		MST[mst_ptr->end]++;
		if(MST[mst_ptr->start]>1 && MST[mst_ptr->end]>1){
			MST[mst_ptr->start]--;
		    MST[mst_ptr->end]--;
		}else{
			printf("{start:%d,end:%d,weight:%d\n", 
				mst_ptr->start, mst_ptr->end, mst_ptr->weight);
		}
		iterate_ptr = iterate_ptr->next;
	}
	
}

