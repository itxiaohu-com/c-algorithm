#include<stdio.h>
#include<stdlib.h>

/*
 * 图广度优先遍历
 *  
 * <p>Breadth First Search,利用队列辅助完成</p>
 * <p>Reference<a href="https://cs.stanford.edu/people/abisee/tutorial/bfs.html"><b>Breadth First Search</b></a></p>
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

// 队列容量
#define QUEUE_CAPACITY 128
#define QUEUE_IS_EMPTY 1

struct node {
	// 终点
    int value;
    // 下一个节点指针
    struct node *next;
};

typedef struct node vertex;
typedef vertex *vertex_ptr;

// 链表
struct link {
	vertex_ptr first;
	vertex_ptr last;
};

// 顶点链表数组
struct link head[VERTEX_COUNT+1];

// 遍历标识，取值SEARCHED，NOT_SEARCHED
int search_flag[VERTEX_COUNT+1];

/*
 * 从指定顶点进行广度优先遍历
 */
void bfs(int value);

void add_head(struct link *head, vertex_ptr ptr);

int queue[QUEUE_CAPACITY];
int head_index = -1;
int tail_index = -1;

void enqueue(int value);
int dequeue();
int is_empty();

int main(){
    // 图的边数组表示
	int edge_array[EDGE_COUNT][2] = {
		{1,2}, {2,1}, {1,3}, {3,1},
	    {2,4}, {4,2}, {2,5}, {5,2},
	    {3,6}, {6,3}, {3,7}, {7,3},
	    {4,8}, {8,4}, {5,8}, {8,5},
	    {6,8}, {8,6}, {8,7}, {7,8}};
    
    // 把图的边数组表示转为顶点链表数组形式
    int i,j;
    vertex_ptr new_ptr;
    
    for(i = 1; i < VERTEX_COUNT+1; i++){
    	
		search_flag[i] = NOT_SEARCHED;
    	
    	head[i].first = NULL;
    	head[i].last = NULL;
    	
    	for(j = 0; j < EDGE_COUNT; j++){
    		if(edge_array[j][0] == i){
    			new_ptr = (vertex_ptr)malloc(sizeof(vertex));
    			new_ptr->value = edge_array[j][1];
    			new_ptr->next = NULL;		
    			add_head(&head[i], new_ptr);
			}
		}
	}
	
	// 图的邻接表
    printf("\n------bfs-graph adjacency list---------\n\n");
    vertex_ptr cur_ptr;
	for(i = 1; i <= VERTEX_COUNT; i++){
	    printf("vertxt[%d]", i);
	    cur_ptr = head[i].first;
	    printf("{%d,%d}:", head[i].first->value, head[i].last->value);
	    while(cur_ptr != NULL){
	    	printf("->%d", cur_ptr->value);
	    	cur_ptr = cur_ptr->next;
		}
		printf("\n");
	}
	
	// 广度优先遍历
	printf("\n------bfs-breadth first search---------\n\n");
	bfs(1);

	return 0;

}

void add_head(struct link *head, vertex_ptr ptr){
	if(head->first == NULL){
		head->first = ptr;
		head->last = ptr;
	}else{
		head->last->next = ptr;
		head->last = ptr;
	}
}

void bfs(int value){
	
	enqueue(value);
	search_flag[value] = SEARCHED;
    printf("[%d] ", value);	
    
    vertex_ptr ptr;
	while(is_empty() != QUEUE_IS_EMPTY){
		value = dequeue();
		ptr = head[value].first;
		while(ptr != NULL){
			if(search_flag[ptr->value] == NOT_SEARCHED){
			    enqueue(ptr->value);
			    search_flag[ptr->value] = SEARCHED;
			    printf("[%d] ", ptr->value);	
		    }  
		    ptr = ptr->next;
		}
	}
	
}

void enqueue(int value){
	if(tail_index > QUEUE_CAPACITY - 1){
		return;
	}
	queue[++tail_index] = value;
}

int dequeue(){
	return queue[++head_index];
}

int is_empty(){
	if(head_index >= tail_index){
		return QUEUE_IS_EMPTY;
	}
	return 0;
}

