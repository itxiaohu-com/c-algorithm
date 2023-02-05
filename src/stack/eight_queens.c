#include<stdio.h>
#include<stdlib.h>

/*
 * 八皇后问题
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

#define QUEEN_COUNT 8              /*皇后数量*/
#define TRUE 1                  
#define FALSE 0

int solution[QUEEN_COUNT];         /*摆放方案,索引表示列号,值表示行号*/
int solution_count = 0;            /*摆放方案数*/

/*
 * 打印结果
 */
void print();

/*
 * 摆放皇后
 */
void place(int queen_no);

/*
 * 摆放位置是否安全
 */
int is_safe(int row, int column);

int main(){
    place(0); //从摆放第一个皇后开始
	return 0;
}

void print(){
	solution_count++;
	printf("\nThe %d solution:\n", solution_count);
	for(int x = 0; x < QUEEN_COUNT; x++){
		for(int y = 0; y < QUEEN_COUNT; y++){
			if(x == solution[y]){
				printf("[Q]");
			}else{
				printf("[-]");
			}
		}
		printf("\n");
	}
	system("pause");
}

void place(int queen_no){
	int i = 0;
	while(i < QUEEN_COUNT){
		if(is_safe(i, queen_no) == TRUE){
			solution[queen_no] = i;
			if(queen_no == 7){
				print();
			}else{
				place(queen_no + 1);
			}
		}
		i++;
	}
}

int is_safe(int row, int column){
	int i = 0;
	int is_ok = TRUE;
	int row_offset = 0;
	int column_offset = 0;
	
	while((is_ok == TRUE) && (i < column)) {
		row_offset = abs(row - solution[i]);
		column_offset = abs(column - i);
		//  两个皇后在同一行或同一对对角线上则不安全，因为是按列比较，默认不会是同一列
		if( (row == solution[i]) || (row_offset == column_offset)){ 
		    is_ok = FALSE;
		}
		i++;
	}
    return is_ok;
}

