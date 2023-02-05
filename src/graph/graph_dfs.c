#include<stdio.h>
#include<stdlib.h>

/*
 * 图深度优先遍历
 *  
 * <p>Depth First Search,利用递归调用(栈)完成</p>
 * <p>Reference<a href="https://cs.stanford.edu/people/abisee/tutorial/dfs.html"><b>Depth First Search</b></a></p>
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */

// 边数
#define EDGE_COUNT 20
// 顶点数
#define VERTEX_COUNT 8

#define SEARCHED 1
#define NOT_SEARCHED 0

struct node {
	// 终点
    int value;
    // 下一个节点指针
    struct node *next;
};

typedef struct node vertex;
typedef vertex *vertex_ptr;

// 顶点指针数组
vertex_ptr head[VERTEX_COUNT+1];
// 遍历标识，取值SEARCHED，NOT_SEARCHED
int search_flag[VERTEX_COUNT+1];

/*
 * 从指定顶点进行深度优先遍历
 */
void dfs(int value);

int main(){
    // 图的边数组表示
	int edge_array[EDGE_COUNT][2] = {
		{1,2}, {2,1}, {1,3}, {3,1},
	    {2,4}, {4,2}, {2,5}, {5,2},
	    {3,6}, {6,3}, {3,7}, {7,3},
	    {4,8}, {8,4}, {5,8}, {8,5},
	    {6,8}, {8,6}, {8,7}, {7,8}};
    
    // 把图的边数组表示转为顶点数组链表形式
    int i,j;
    vertex_ptr cur_ptr, new_ptr;
    for(i = 1; i < VERTEX_COUNT+1; i++){
    	search_flag[i] = NOT_SEARCHED;
    	
    	head[i] = (vertex_ptr)malloc(sizeof(vertex));
    	head[i]->value = i;
    	head[i]->next = NULL;
    	
    	cur_ptr = head[i];
    	
    	for(j = 0; j < EDGE_COUNT; j++){
    		if(edge_array[j][0] == i){
    			new_ptr = (vertex_ptr)malloc(sizeof(vertex));
    			new_ptr->value = edge_array[j][1];
    			new_ptr->next = NULL;
    			
    			do{
				    cur_ptr->next = new_ptr;
				    cur_ptr = cur_ptr->next;
				}while(cur_ptr->next != NULL);
				
			}
		}
	}
    
    // 图的邻接表
    printf("\n------dfs-graph adjacency list---------\n\n");
    for(i = 1; i <= VERTEX_COUNT; i++){
	    cur_ptr = head[i];
	    printf("vertxt[%d]", cur_ptr->value);
	    while(cur_ptr->next != NULL){
	    	cur_ptr = cur_ptr->next;
	    	printf("->%d", cur_ptr->value);
		}
		printf("\n");
	}
	
	// 深度优先遍历
	printf("\n------dfs-depth first search---------\n\n");
	dfs(1);

	return 0;
}

void dfs(int value){
	
	vertex_ptr ptr = head[value];
	search_flag[value] = SEARCHED;
	printf("[%d]", ptr->value);
	
	while(ptr->next != NULL){
		if(search_flag[ptr->next->value] == NOT_SEARCHED){
			dfs(ptr->next->value);
		}
		ptr = ptr->next;
	}
	
}