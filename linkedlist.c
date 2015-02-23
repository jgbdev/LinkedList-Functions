#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int x;
	struct node * next;
} node;

void insert(node **root, int i){

	if((*root) == NULL){
		(*root) = (node*)malloc(sizeof(node));
		(*root)->x = i;
		(*root)->next = NULL;

	}else{
		insert(&(*root)->next,i);
	}

}

void printLinkedList(node * root){
	if(root != NULL){
		printf("%d\n",root->x);
		printLinkedList(root->next);
	}

}

int Count(node * list, int i){
	if(list != NULL){
		if(list->x==i){
			return 1 + Count(list->next,i);
		}else{
			return Count(list->next,i);
		}
	}return 0;

}

int GetNth(node * list, int n){
	if(list!=NULL){
		if(n>0){
			return GetNth(list->next,n-1);
		}else{
			return (list->x);
		}
	}return 0;
}

void DeleteList(node ** list){
	if(*list != NULL){
		DeleteList(&(*list)->next);
		free(*list);
		*list = NULL;
	}

}

void InsertNth(node ** head, int n, int i){
	if(*head != NULL){
		if(n>0){
			InsertNth(&(*head)->next,n-1,i);
		}else{
			node * newNode;
			newNode = (node*)malloc(sizeof(node));
			newNode->x = i;
			newNode->next = *head;
			*head = newNode;
		}	
		
	}

}

int Pop(node ** head){
	int out = (*head)->x;
	node * old = *head;
	*head = (*head)->next;
	free(old);

	return out;

}


int main(){

	node * root;
	root = NULL;
	insert(&root,1);
	insert(&root,2);
	insert(&root,3);
	insert(&root,4);
	insert(&root,5);
	insert(&root,6);

	InsertNth(&root,4,10);
	InsertNth(&root,0,-1);
	InsertNth(&root,2,44);

	printLinkedList(root);
	

	return -1;
}
