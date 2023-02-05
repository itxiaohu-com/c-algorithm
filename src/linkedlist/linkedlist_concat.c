#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * 链表串联
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
void concat(pointer left, pointer right);

int main(){

	pointer head1 = create();
	
	printf("-------List1 Created-------\n");
	print(head1);
	
	pointer head2 = create();
	
	printf("-------List2 Created-------\n");
	print(head2);
	
	char data1[DATA_MAX_LENGTH][COUNT] = {
		{"First"}, {"Second"}, {"Third"}, {"Fourth"}, {"Fifth"},
		{"Sixth"}, {"Seventh"}, {"Eighth"}, {"Ninth"}, {"Tenth"}
	};
	
	char data2[DATA_MAX_LENGTH][COUNT] = {
		{"1th"}, {"2th"}, {"3th"}, {"4th"}, {"5th"},
		{"6th"}, {"7th"}, {"8th"}, {"9th"}, {"10th"}
	};	
	
    pointer current1 = head1;
    pointer current2 = head2;

    printf("--------List1 Added--------\n");
    for(int i = 0; i < COUNT; i++){	
	    current1 = add(current1, 60001 + i, data1[i]);
	}
	print(head1);

    printf("--------List2 Added--------\n");
    for(int i = 0; i < COUNT; i++){	
	    current2 = add(current2, 90001 + i, data2[i]);
	}
	print(head2);
	
	printf("--------List1+List2--------\n");
	concat(head1, head2);
	print(head1);
}

pointer create(){
	pointer draft = (pointer)malloc(sizeof(node));
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
	pointer ptr = head->next;
	while(ptr != NULL){
		printf("{id:%5d, data:%s}\n", ptr->id, ptr->data);
		ptr = ptr->next;
	}
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

