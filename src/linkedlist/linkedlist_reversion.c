#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * 链表反转
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
pointer reverse(pointer head);

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

    printf("--------List Reverse--------\n");
    head = reverse(head);
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

pointer reverse(pointer head) {
    
    pointer previous = NULL;
    pointer current = head;
    pointer next = head->next;
    
    while(next != NULL){
    	current->next = previous;
    	previous = current;
    	current = next;
    	next = next->next;
	}
	
	current->next = previous;

	return current;
}
