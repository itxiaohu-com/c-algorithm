#include<stdio.h>

/*
 * 大项堆
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

#define LENGTH 9

/*
 * 堆化指定节点
 *
 * 此方法只能让指定的节点及其子孙节点符合大项堆，且前提条件是左右子节点已经是大项堆。
 * 因此在处理时需要从下至上遍历，即每个叶子节点就是一个大项堆。
 *
 * 参数说明:
 * array   存放数据的数组指针,零号位不用，从一号位开始
 * count   数据总数,数据项包括[1, count]
 * target  待堆化的节点
 */
void heapify_single(int *array, int count, int target);

/*
 * 堆化整个数组
 *
 * 由于每个叶子节点就是一个大项堆，因此可以从最后一个非叶子节点开始从下至上遍历。
 * 依据一颗完全二叉树可知，叶子节点数占总节点数的一半以上。
 * 因此，可从总结点数的一半开始遍历。
 *
 * 参数说明:
 * array   存放数据的数组指针,零号位不用，从一号位开始
 * count   数据总数,数据项包括[1, count]
 */
void heapify(int *array, int count);

void print(int *array, int count);

int main(){
    
    int array[LENGTH] = {0, 5, 6, 4, 8, 3, 2, 7, 1};

    printf("\n----------origin array----------\n");
	print(array, LENGTH-1);

//    int i;
//    for(i = LENGTH-1; i > 0; i--){
//    	printf("\n--------heapify target:%d--------\n", i);
//    	heapify_single(array, LENGTH-1, i);
//    	print(array, LENGTH-1);
//	}

    printf("\n----------heapify array----------\n");
    heapify(array, LENGTH-1);
	print(array, LENGTH-1);
	
	return 0;
}


void heapify_single(int *array, int count, int target) {
	int parent_index = target;                       /*父节点索引*/
	int descendant_index = 2*parent_index;           /*子孙节点索引*/

    int parent_data = array[parent_index];

    while(descendant_index <= count) {

        // 更新子孙节点索引为兄弟节点中较大的一个
    	if(descendant_index < count && array[descendant_index] < array[descendant_index+1]){
    		descendant_index++;
    	}

        // 若父节点值较大，已经符合条件，结束处理
    	if(parent_data > array[descendant_index]) {
    		break;
    	}

        // 使用左右子节点中较大的覆盖父节点
    	array[descendant_index/2] = array[descendant_index];
    	// 更新子孙节点索引为下一层
        descendant_index = 2*descendant_index;
    }
    
    // 使用目标父节点值填入空出来的子孙节点
    array[descendant_index/2] = parent_data;
}

void heapify(int *array, int count){
    int n = count/2;
    while(n > 0){
    	heapify_single(array, count, n);
    	n--;
    }
}

void print(int *array, int count){
	int i = 1;
	while(i <= count) {
		printf("[%d] ", array[i++]);
	}
	printf("\n");
}