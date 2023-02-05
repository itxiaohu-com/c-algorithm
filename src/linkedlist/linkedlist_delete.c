#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * 链表查找及删除节点
 * 
 * <p>更多内容参看<a href="https://itxiaohu.com" target="_blank"><b>IT小胡频道</b></a></p>
 * @author IT小胡
 */ 
 
#define DATA_MAX_LENGTH 1024 
#define COUNT 10

struct model{
	int id;
	char data[DATA_MAX_LENGTH];
	struct node *next;
};

typedef struct model node;
typedef node *pointer;

pointer create();
pointer add(pointer head, int id, char data[DATA_MAX_LENGTH]);
void print(pointer head);
void print_single(pointer ptr);
pointer find(pointer head, int id);
pointer del(pointer head, int id);
pointer delete_by_id(pointer head, int id);

int main(){

	pointer head = create();
	
	printf("-------List Created-------\n");
	print(head);
	
	char data[DATA_MAX_LENGTH][COUNT] = {
		{"First"}, {"Second"}, {"Third"}, {"Fourth"}, {"Fifth"},
		{"Sixth"}, {"Seventh"}, {"Eighth"}, {"Ninth"}, {"Tenth"}
	};
	
    pointer current = head;

    printf("--------List Added--------\n");
    for(int i = 0; i < COUNT; i++){	
	    current = add(current, 10001 + i, data[i]);
	}
	print(head);

    int id = 10005;
    printf("--------Find id:%d--------\n", id);
    print_single(find(head, id));
    
    int rid;
    
    rid = 0;
    printf("--------Delete id:%d--------\n", rid);
    head = delete_by_id(head, rid);
    print(head);
    
    rid = 10005;
    printf("--------Delete id:%d--------\n", rid);
    head = delete_by_id(head, rid);
    print(head);
    
    rid = 10010;
    printf("--------Delete id:%d--------\n", rid);
    head = delete_by_id(head, rid);
    print(head);
}

pointer create(){
	pointer draft = (pointer)malloc(sizeof(node));
	draft->id = 0;
	char data[DATA_MAX_LENGTH] = {"Head"}; 
	strcpy(draft->data, data);
	draft->next = NULL;
	return draft;
}

pointer add(pointer head, int id, char data[DATA_MAX_LENGTH]){
	pointer draft = (pointer)malloc(sizeof(node));
	draft->id = id;
	strcpy(draft->data, data);
	draft->next = NULL;
	
	pointer tail = head;
	while(tail->next != NULL) {
		tail = tail->next;
	}
    
    tail->next = draft;
    return draft;
}

void print(pointer head){
	pointer ptr = head;
	while(ptr != NULL){
		printf("{id:%5d, data:%s}\n", ptr->id, ptr->data);
		ptr = ptr->next;
	}
}

void print_single(pointer ptr){
	if(ptr == NULL) {
		return;
	}
	printf("{id:%5d, data:%s}\n", ptr->id, ptr->data);
}

void concat(pointer left, pointer right){
	pointer tail = left;
	while(tail->next != NULL) {
		tail = tail->next;
	}
	
	pointer right_head = right;
	right = right->next;
	tail->next = right;
	
	free(right_head);
}

pointer find(pointer head, int id) {
	pointer ptr = head;
	while(ptr != NULL) {
		if(ptr->id == id){
			return ptr;
		}
		ptr = ptr->next;
	}
    return NULL;
}

pointer del(pointer head, int id){
    pointer target = find(head, id);
    if(target == NULL){
    	return head;
	}
	
	// 删除头节点
	pointer to_remove;
	if(head == target){
		to_remove = head;
		head = head->next;
	}else{
		pointer ptr = head;
		while(ptr->next != target){
			ptr = ptr->next;
		}
		to_remove = ptr->next;
		ptr->next = ((pointer)(ptr->next))->next;
	}
	
	free(to_remove);
	return head;
}

pointer delete_by_id(pointer head, int id){
	pointer to_remove;
	if(head->id == id){
		to_remove = head;
		head = head->next;
		free(to_remove);
	    return head;
	}
	
	pointer ptr = head;
	
	while(ptr->next != NULL && ((pointer)(ptr->next))->id != id){
		ptr = ptr->next;
	}
	
	if(ptr->next == NULL){
		return head;
	}
	
	to_remove = ptr->next;
	ptr->next = to_remove->next;
	
	free(to_remove);
	return head;
}
