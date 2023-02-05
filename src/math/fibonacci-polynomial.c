#include<stdio.h>

/*
 * 斐波那契数列(Fibonacci Polynomial)
 * 
 * 公式定义:
 *   F(n) = 0，n = 0
 *   F(n) = 1，n = 1 
 *   F(n) = F(n-1) + F(n-2)，n > 1
 *
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 
 
// Fibonacci缓存区，用于DPA方法实现
int  fp_cache[1000] = {0};
 
int main(){
	for(int i = 0; i < 50; i++){
		printf("fibonacci(%d):%d\n", i, fibonacci_dpa(i));
	}
	
	printf("\n--------------------\n\n");
	
	for(int i = 0; i < 50; i++){
		printf("fibonacci(%d):%d\n", i, fibonacci_recursion(i));
	}
}

// 递归实现
int fibonacci_recursion(int n){
    if(n == 0){
    	return 0;
	}
	if(n == 1 || n == 2){
		return 1;
	}
    return fibonacci_recursion(n-1) + fibonacci_recursion(n-2);
}

// 动态规划实现
int fibonacci_dpa(int n){
	int result = fp_cache[n];
	
	if(result != 0){
	  return result;	
	}
	
	if(n == 0){
    	result = 0;
	}else if(n == 1 || n == 2){
		result = 1;
	}else{
	    result =  fibonacci_dpa(n-1) + fibonacci_dpa(n-2);	
	}
    fp_cache[n] = result;
    return result;
}