#include<stdio.h>
#include<stdlib.h>

typedef struct TreeT{
struct TreeT *left;
struct TreeT *right;
int data;
}Tree;

typedef struct StackT{
	struct StackT * next;
	int data;
}Stack;


typedef struct QueueintT{
	int data;
	struct QueueintT * next;
}Queueint;

typedef struct QueueT{
	Tree *node;
	struct QueueT * next;
}Queue;

void enqueue(Queue** front, Queue** back, Tree* treenode){

	Queue* temp = (Queue*)malloc(sizeof(Queue));
	temp->node = treenode;
	temp->next = NULL;

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

	Queue *freetemp = *front;
	Tree * temp = (freetemp)->node;

	if((*front)->next == NULL)
	{
		*front = NULL;
		*back = NULL;
	}

	else{
		*front = (*front)->next;
	}

	free(freetemp);

	return temp;
}

int isempty(Queue ** front, Queue **back){
	if(!(*front) && !(*back))
		return 1;
	else 
		return 0;
}


void LevelOrderTraversal(Tree *root){

	Queue *front = NULL;
	Queue *back = NULL;

	if(!root)
		return;

	int currentRow = 0 , nextRow = 0;
	enqueue(&front,&back,root);
	currentRow++;
	Tree *temp;

	while(!isempty(&front,&back)){

		temp = dequeue(&front,&back);
		currentRow --;

		if(temp != NULL){
	    	printf("%d\t",temp->data);
	    	if(temp->left != NULL){
				enqueue(&front,&back,temp->left);
				nextRow++;
			}
			if(temp->right != NULL){
				enqueue(&front,&back,temp->right);
				nextRow++;		
	    	}
        }
        if(currentRow == 0){
	    		printf("\n");
	    		currentRow = nextRow;
	    		nextRow = 0;
	    }
	}
}

void simpleLevelOrderTraversal(Tree *root){

	Queue *front = NULL;
	Queue *back = NULL;

	if(!root)
		return;
	enqueue(&front,&back,root);

	Tree *temp;

	while(!isempty(&front,&back)){
		temp = dequeue(&front,&back);

		if(temp != NULL){
			printf("%d \t",temp->data );
	    	if(temp->left != NULL){
				enqueue(&front,&back,temp->left);

			}
			if(temp->right != NULL){
				enqueue(&front,&back,temp->right);					
	    	}
		}
	}
}




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



void nthinorder(Tree * root , int n , Tree **nthnode){
	static int count;
	
	if (!root){
		return;
	}

	nthinorder(root->left,n,nthnode);
	{ 
		count++;
		if(count == n){
			*nthnode = root;
			printf("In rec func : %d\n", (*nthnode)->data);
		}	
	}
	nthinorder(root->right,n,nthnode);
}




void printTreeInorder(Tree * root){
	if (!root)
		return;
	
	printTreeInorder(root->left);
	printf("%d ",root->data);
	printTreeInorder(root->right);

	printf("\n");
}


void enqueue_int(Queueint ** front , Queueint ** back  , int data) {

Queueint* temp = (Queueint*)malloc(sizeof(Queueint));
	temp->data = data;

	if(*front == NULL && *back == NULL){
		printf(" in  null block\n");
		*front = temp;
		*back = temp;
	}else{
		printf(" in not null block\n");	
		(*back)->next=temp;
		*back = temp;
	}

}

int dequeue_int( Queueint **front, Queueint **end){

	if(!*front && !*end){
		printf("DQ in null block");
		return -1;}

	int ret; Queueint *temp;
	temp = *front;

	ret = temp->data;

	*front = (*front)->next;


	free(temp);

	return ret;
}

int main(){
	Tree * root;
	root = createTree();


	//simpleLevelOrderTraversal(root);
	LevelOrderTraversal(root);

	// Queue *front = NULL;
	// //*front = NULL;
	// Queue *back = NULL;

	// //Queueint *front= NULL;
	// //Queueint *back = NULL;

	// //enqueue_int(&front,&back,1);
	// //enqueue_int(&front,&back,2);

 //    //int data = dequeue_int(&front,&back);
	// //int data2 = dequeue_int(&front,&back);
	// //*back = NULL;


	Queue *front = NULL;
	// //*front = NULL;
	Queue *back = NULL;


// 	enqueue(&front,&back,root);
// 	enqueue(&front,&back,root->left);
// 	enqueue(&front,&back,root->right);
// 	enqueue(&front,&back,root->right->left);

// 	if(!isempty(&front,&back)){

// 	Tree* node1 = dequeue(&front,&back);
// 	printf("node1 - data %d\n",node1->data );

// }
// 	if(!isempty(&front,&back)){
// 	Tree* node2  = dequeue(&front,&back);
// 	printf("node2- data %d\n",node2->data );
// }

// if(!isempty(&front,&back)){
// 	Tree* node3  = dequeue(&front,&back);
// 	printf("node3- data %d\n",node3->data ); }

// 	Tree* node4  = dequeue(&front,&back);
// 	printf("node4- data %d\n",node4->data);
  










	// Tree **nthnode;
	// nthnode = &root;
	// printf("\n*nthnode = %p",*nthnode);	
	// nthinorder(root,5, nthnode);
	// printf("In main : %d\n", (*nthnode)->data);



}
