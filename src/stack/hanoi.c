#include<stdio.h>

/*
 * 汉诺塔问题
 * 
 * <p>Reference<a href="https://www.tutorialspoint.com/data_structures_algorithms/tower_of_hanoi.htm"><b>Data Structure & Algorithms - Tower of Hanoi</b></a></p>
 * <p>Reference<a href="https://www.mathsisfun.com/games/towerofhanoi.html"><b>Tower of Hanoi</b></a></p>
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

#define N 3   /*移动圆盘数量*/
#define P1 1  /*塔一位置标识*/
#define P2 2  /*塔二位置标识*/
#define P3 3  /*塔三位置标识*/

/*
 * n       移动圆盘个数
 * from    移动起点位置标识
 * buffer  移动缓冲位置标识
 * to      移动终点位置标识
 * 为了方便理解，from表示塔一，buffer表示塔二，to表示塔三
 */
void hanoi(int n, int from, int buffer, int to);

int main(){	
	hanoi(N, P1, P2, P3);
}

void hanoi(int n, int from, int buffer, int to){
    if(n == 1) {                                 /*一个圆盘时的移动方案,即递归结束条件*/
    	printf("Tower%d->Tower%d\n", from, to);
    }else{                                       /*大于一个圆盘时的移动方案*/
        hanoi(n-1, from, to, buffer);            /*步骤一:把n-1个圆盘从塔一移动到塔二*/
        printf("Tower%d->Tower%d\n", from, to);  /*步骤二:把第n个圆盘从塔一移动到塔三*/ 
        hanoi(n-1, buffer, from, to);            /*步骤三:把n-1个圆盘从塔二移动到塔三*/ 
    }
}


