#include<stdio.h>
#include<stdlib.h>

/*
 * 老鼠走迷宫
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */

#define EAST MAZE[x][y+1]     /*定义东方相对位置*/
#define WEST MAZE[x][y-1]     /*定义西方相对位置*/
#define SOUTH MAZE[x+1][y]    /*定义南方相对位置*/
#define NORTH MAZE[x-1][y]    /*定义北方相对位置*/

#define ExitX 8               /*定义出口X坐标*/
#define ExitY 10              /*定义出口Y坐标*/

// 定义节点
struct node {
	int x,y;
	struct node* next;
};

// 定义步伐
typedef struct node step;

// 定义栈，栈顶为当前行走节点
typedef step* stack;

// 函数声明
stack push(stack head, int x, int y);
stack pop(stack head, int* x, int* y);
int chkExit(int x, int y, int ex, int ey);

// 声明迷宫数组
int MAZE[10][12] = {2,1,1,1,1,0,0,0,1,1,1,1,
		            1,0,0,0,1,1,1,1,1,1,1,1,
				    1,1,1,0,1,1,0,0,0,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,0,0,0,1,1,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,1,1,0,0,1,0,1,1,
					1,1,0,0,0,0,0,0,1,0,0,1,
					1,1,1,1,1,1,1,1,1,1,1,3};

int main(){
	int x = 1, y = 1;                                             /*入口X,Y坐标*/
	stack path = NULL;
	
	printf("[迷宫模拟图(1表示墙,2表示入口,3表示出口]\n");            /*打印迷宫模拟图*/
	printf("---------------------------\n");
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 12; j++){
			printf("%2d", MAZE[i][j]);
		}
		printf("\n");
	}
	
	// 走迷宫逻辑
    while(x <= ExitX && y <= ExitY){
    	MAZE[x][y] = 6;
    	if(NORTH == 0){
			x -= 1;
			path = push(path, x, y);
		}
		else if(SOUTH == 0){
			x += 1;
			path = push(path, x, y);
		}
		else if(WEST == 0){
			y -= 1;
			path = push(path, x, y);
		}
		else if(EAST == 0){
			y += 1;
			path = push(path, x, y);
		}
		else if(chkExit(x, y, ExitX, ExitY) == 1){          /*检查是否走到出口了*/
			break;
		}
		else{
			path = pop(path, &x, &y);
		}
	}
	
	printf("[老鼠走迷宫路径图(6表示走过的路线]\n");           /*打印出老鼠走迷宫路径图*/                  
	printf("---------------------------\n");
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 12; j++){
			printf("%2d", MAZE[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

/*
 * 入栈记录最新步伐
 */
stack push(stack head, int x, int y){
	stack node = (stack)malloc(sizeof(step));
	if(node == NULL){
		printf("memory allocate failure!");
		return NULL;
	}
	node->x = x;
	node->y = y;
	node->next = head;
	head = node;
	return head;
}

/*
 * 出栈返回上一次步伐
 */
stack pop(stack head, int* x, int* y){
	if(head != NULL){
		stack step = head;
		head = head->next;
		*x = head->x;
		*y = head->y;
		free(step);
		return head;
	}else{
		*x = -1;
	}
	return head;
}

/*
 * 出口校验
 */
int chkExit(int x, int y, int ex, int ey){
	if(x == ex && y == ey){
		return 1;
	}else{
		return 0;
	}
}
