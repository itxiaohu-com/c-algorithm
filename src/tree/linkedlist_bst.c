#include<stdio.h>
#include<stdlib.h>

/*
 * 链表实现二叉查找树
 * 
 * 1. 二叉查找树链表实现
 * 2. 节点的插入
 * 3. 前序遍历/中序遍历(利用二叉查找树的中序遍历可完成数据排序)/后续遍历
 * 4. 节点的查找
 * 5. 节点的删除
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 

struct model {
    int data;
    struct model *left;
    struct model *right;
};

typedef struct model node;
typedef node *node_ptr;

node_ptr root = NULL;

/*
 * 添加元素
 */
void add(int item);

/*
 * 查找元素
 */
node_ptr find(node_ptr ptr, int item);

/*
 * 删除元素
 */
node_ptr rm(node_ptr ptr, int item);

/*
 * 创建节点
 */
node_ptr create(int item);

/*
 * 前序遍历
 */
void preorder(node_ptr ptr);

/*
 * 中序遍历
 */
void inorder(node_ptr ptr);

/*
 * 后序遍历
 */
void postorder(node_ptr ptr);

int main(){
	int data[8] = {6, 3, 5, 4, 7, 8, 9, 2};
	int length = 8;
	
	printf("----------add item----------\n");
	int i = 0;
	while(i < length){
		add(data[i]);
		i++;	
	}
	
	printf("----------preorder----------\n");
	preorder(root);
	
	printf("----------inorder----------\n");
	inorder(root);
	
	printf("----------postorder----------\n");
	postorder(root);
	
	int target = 9;
	printf("----------find:%d----------\n", target);
	node_ptr ptr = find(root, target);
	if(ptr != NULL){
		printf("%d is found\n", ptr->data);
	}else{
		printf("%d is not found\n", target);
	}
	
	int item = 3;
	printf("----------remove:%d----------\n", item);
	root = rm(root, item);
	if(NULL == find(root, item)){
		printf("remove %d success\n", item);
	}else{
		printf("remove %d failed\n", item);
	}
	
	printf("----------preorder----------\n");
	preorder(root);
	
}

void add(int item){
	if(root == NULL){
		root = create(item);
	}else{
		node_ptr parent = NULL;
		node_ptr ptr = root;
		
		while(ptr != NULL){
			parent = ptr;
			if(item < ptr->data){
				ptr = ptr->left;
			}else{
				ptr = ptr->right;
			}
		}
		
		node_ptr draft = create(item);
		if(item < parent->data){
			parent->left = draft;
		}else{
			parent->right = draft;
		}
	}
}

node_ptr create(int item){
	node_ptr ptr = (node_ptr)malloc(sizeof(node));
	ptr->data = item;
	ptr->left = NULL;
	ptr->right = NULL;
}

void preorder(node_ptr ptr){
	if(ptr == NULL){
		return;
	}
	printf("%2d\n", ptr->data);
	preorder(ptr->left);
	preorder(ptr->right);
}

void inorder(node_ptr ptr){
	if(ptr == NULL){
		return;
	}
	inorder(ptr->left);
	printf("%2d\n", ptr->data);
	inorder(ptr->right);
}

void postorder(node_ptr ptr){
	if(ptr == NULL){
		return;
	}
	postorder(ptr->left);
	postorder(ptr->right);
	printf("%2d\n", ptr->data);
}

node_ptr find(node_ptr ptr, int item){
    if(ptr == NULL){
    	return NULL;
	}
	if(item == ptr->data){
		return ptr;
	}else if(item < ptr->data){
		return find(ptr->left, item);
	}else{
		return find(ptr->right, item);
	}
}

node_ptr rm(node_ptr ptr, int item){
	node_ptr cursor = ptr;
	node_ptr parent = NULL;
	while(cursor != NULL){
		if(cursor->data == item){
			if(cursor->left == NULL && cursor->right == NULL){
				if(item < parent->data){
					parent->left = NULL;
				}else{
					parent->right = NULL;
				}
			}else if(cursor->left == NULL) {
			    if(item < parent->data){
					parent->left = cursor->right;
				}else{
					parent->right = cursor->right;
				}
			}else if(cursor->right == NULL) {
			    if(item < parent->data){
					parent->left = cursor->left;
				}else{
					parent->right = cursor->left;
				}
			}else{
				// 方案一: 左子树最大值(最右边节点)
				node_ptr left_child_ptr = cursor->left;
				node_ptr right_child_ptr = cursor->right;
				
				node_ptr left_child_mr_ptr = left_child_ptr->right;
				node_ptr left_child_mrp_ptr = NULL;
				
				while(left_child_mr_ptr != NULL){
					left_child_mrp_ptr = left_child_mr_ptr;
					left_child_mr_ptr = left_child_mr_ptr->right;
				}
				if(left_child_mrp_ptr != NULL){
					left_child_mrp_ptr->right = NULL;
					parent->left = left_child_mr_ptr;
					left_child_mr_ptr->left = left_child_ptr;
					left_child_mr_ptr->right = right_child_ptr;
				}else{
					parent->left = left_child_ptr;
					left_child_ptr->right = right_child_ptr;
				}
				
				// 方案二: 右子树最小值(最左边节点)
				
			}	
			return ptr;
		}else if(item < cursor->data){
			parent = cursor;
			cursor = cursor->left;
		}else{
			parent = cursor;
			cursor = cursor->right;
		}
	     
	}
	return ptr;
}




