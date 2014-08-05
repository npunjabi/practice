
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeT{
struct TreeT *left;
struct TreeT *right;
int data;
}Tree;

typedef struct QueueT{
	Tree *node;
	struct QueueT * next;
}Queue;

Tree * createTree(){

	Tree * root;
	root = (Tree *)malloc(sizeof(Tree));
	root->data = 100;

	Tree * lnode1;
	lnode1 = (Tree *)malloc(sizeof(Tree));
	lnode1->data = 50;

	Tree * lnode2;
	lnode2 = (Tree *)malloc(sizeof(Tree));
	lnode2->data = 25;

	Tree * lnode3;
	lnode3 = (Tree *)malloc(sizeof(Tree));
	lnode3->data = 75;

	Tree * rnode1;
	rnode1 = (Tree *)malloc(sizeof(Tree));
	rnode1->data = 150;

	Tree * rnode2;
	rnode2 = (Tree *)malloc(sizeof(Tree));
	rnode2->data = 125;

	Tree * rnode3;
	rnode3 = (Tree *)malloc(sizeof(Tree));
	rnode3->data = 175;

	Tree * rnode4;
	rnode4 = (Tree *)malloc(sizeof(Tree));
	rnode4->data = 110;

	root->left= lnode1;
	root->right = rnode1;

	lnode1->left = lnode2;
	lnode1->right = lnode3;

	lnode2->left = NULL;
	lnode2->right = NULL;


	lnode3->left = NULL;
	lnode3->right = NULL;

	rnode1->left = rnode2;
	rnode1->right = rnode3;

	rnode2->left = rnode4;
	rnode2->right = NULL;

	rnode3->left= NULL;
	rnode3->right = NULL;

	return root;

}


void enqueue(Queue** front, Queue** back, Tree* treenode){


	Queue* temp = (Queue*)malloc(sizeof(Queue));
	temp->node = treenode;


	//temp->next = NULL;

	if(*front == NULL && *back ==NULL){	
		*front = temp;
		*back = temp;

	}
	else{
		(*back)->next=temp;
		*back = temp;
	}

}

Tree * dequeue(Queue** front, Queue** back){

	if(*front==NULL)
		return NULL;

	Tree * temp = (*front)->node;

	if((*front)->next == NULL){
		*front = NULL;
		*back = NULL;
	}else{
		*front = (*front)->next;
	}
	return temp;
}

int isempty(Queue ** front, Queue **back){
	if(!(*front) && !(*back))
		return 1;
	else 
		return 0;
}


void LevelOrderTraversal(Tree * root){

	Queue * front = NULL;
	Queue * end = NULL;
	int nodesInCurrentLevel = 1;
  	int nodesInNextLevel = 0;
	if(!root)
		return;

	Tree *temp;

	enqueue(&front,&end,root);

	
	while(!isempty(&front,&end)) {
		temp = dequeue(&front, &end);
		nodesInCurrentLevel --;	

		if(temp){
			printf(" %d",temp->data);
			if(temp->left){
				enqueue(&front,&end,temp->left);
				nodesInNextLevel++;
			}
			if(temp->right){			
				enqueue(&front, &end ,temp->right);
				nodesInNextLevel++;
			}
		}	
		if(nodesInCurrentLevel == 0){
			printf("\n");
			nodesInCurrentLevel = nodesInNextLevel;
			nodesInNextLevel = 0;
		}

	}

}



int main(){
	Tree * root,*rootcopy,**temp;
	temp = &root;
	//temp=NULL;
	root = createTree();
	LevelOrderTraversal(root);
	}
 