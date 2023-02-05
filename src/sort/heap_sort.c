#include<stdio.h>

/*
 * 堆排序
 *
 * <p>基于大项堆完成排序，参看src/tree/max_heap_tree.c</p>
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

/*
 * 经典实现
 */
void sort(int *array, int length);

/**
 * 打印数组
 */
void print(int *array, int length);

void heapify_single(int *array, int count, int target);
void heapify(int *array, int count);

int main() {
	int array[] = {0, 55, 23, 87, 99, 62, 16, 17, 73, 11, 37};
	int length = sizeof(array)/sizeof(array[0]);
	
	printf("--------before heap sort--------\n");
	print(array, length);
	
	sort(array, length);
	
	printf("--------after heap sort--------\n");
	print(array, length);
	return 0;
}

void sort(int *array, int length) {
	// 先对这个数组堆化成大项堆
	heapify(array, length - 1);
	
	//  再把堆顶项与最后一位交换，即完成最后一位排序
	//  然后再对剔除了最后一项数据的数组的顶点进行堆化处理
	//  因为此时也只有交换过来的堆顶不符合规则
	int count = length - 1;
	while(count > 0){
		int value = array[1];
		array[1] = array[count];
		array[count] = value;
		count--;
		heapify_single(array, count, 1);
	}
}

void print(int *array, int length) {
    for(int i = 0; i < length; i++){
    	printf("array[%2d]:%d\n", i, array[i]);
	}
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
