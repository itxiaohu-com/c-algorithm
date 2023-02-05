#include<stdio.h>

/*
 * 阶乘
 *
 * 公式定义一:
 *   F(n) = 1，n = 0
 *   F(n) = n * (n-1) * (n-2) * ... * 1，n > 0
 * 
 * 公式定义二:
 *   F(n) = 1，n = 0
 *   F(n) = n * F(n-1)，n > 0
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 
 
int main(void){ 
	for(int i = 0; i < 50; i++){
		printf("factorial(%d):%d\n", i, factorial_recursion(i));
	}
	
	printf("\n--------------------\n\n");
	
	for(int i = 0; i < 50; i++){
		printf("factorial(%d):%d\n", i, factorial_iteration(i));
	}
}

// 递归实现
int factorial_recursion(int n){
	if(n == 0){
		return 1;
	}else{
		return n * factorial_recursion(n - 1);
	}
}

// 迭代法实现
int factorial_iteration(int n){
	int result = 1;
	for(int i = 1; i <= n; i++){
		result *= i;
	}
	return result;
}