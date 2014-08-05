#include<stdio.h>
#include<stdlib.h>



    

typedef struct nodeT{
	struct nodeT *next;
	int data;
} node;



node* createll(){

	node* node1 = (node*) malloc(sizeof(node));
	node1->data = 1;

	node* node2 = (node*) malloc(sizeof(node*));
	node2->data = 2;

	node* node3 = (node*) malloc(sizeof(node*));
	node3->data = 3;

	node* node4 = (node*) malloc(sizeof(node*));
	node4->data = 4;

	node* node5 = (node*) malloc(sizeof(node*));
	node5->data = 5;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	return node1;

}

void printll(node* head){
	node* iter = head;

	while(iter){
		printf("%d (%p)\t-->\t",iter->data,iter);
		iter = iter->next;
	}
	printf("NULL\n\n");
}

void reverse(node** p) {
  if (!*p) 
  	return;
  node* rest = (*p)->next;

  if (!rest){
  	return;
  } 
  	
  reverse(&rest);
  (*p)->next->next = (*p);
  (*p)->next = NULL;
  (*p) = rest;
}

void  recursivereverse(node ** head){
    node * first, * rest;

    if(*head == NULL)
        return ;

    first = *head;
    rest = first->next;

    if(rest == NULL){
        //*head = first; // very important
        return ;
    }

    recursivereverse(&rest);
  

    first->next->next = first;

    /*Good Stuff*/
    first->next = NULL;

    *head = rest;
    //printll(rest);

}


int main() {
	
	node * head = createll();
	printf ("before reverse\n");
	printll(head);
	printf("head address : %p\n",head);

	recursivereverse(&head);

	printf ("after reverse\n");
	printll(head);
	printf("head address : %p\n",head);
    return 0;
}

    
  

