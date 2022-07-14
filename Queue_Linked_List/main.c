# include <stdlib.h> //malloc
# include <stdio.h> //printf
# include <stdbool.h> //bool

/*
	note
	1. head->first in  tail->last in
	2.  empty-> head is null
*/
struct Node{
	int data;
	struct Node *next;
}typedef node;

struct Queue{
	node *head;
	node *tail;
}typedef Queue;

Queue *create_new();
Queue *enqueue(int item, Queue *qu);
int dequeue(Queue *qu);
bool isempty(Queue *qu);
void print_all(Queue *qu);

int main(void){
	int r;
	Queue *qu = create_new();
	qu = enqueue(3, qu);
	print_all(qu);
	qu = enqueue(2, qu);
	print_all(qu);
	r = dequeue(qu);
	print_all(qu);
	qu = enqueue(1, qu);
	print_all(qu);
	qu = enqueue(5, qu);
	print_all(qu);
	qu = enqueue(4, qu);
	print_all(qu);
	r = dequeue(qu);
	print_all(qu);
	r = dequeue(qu);
	print_all(qu);
	r = dequeue(qu);
	print_all(qu);
	r = dequeue(qu);
	print_all(qu);
	r = dequeue(qu);
	print_all(qu);
	return 0;
}

Queue *create_new(){
	Queue *qu = (Queue *)malloc(sizeof(Queue));
	qu->head = NULL;
	qu->tail = NULL;
	return qu;
}

Queue *enqueue(int item, Queue *qu){
	printf("Now enqueuing...\n");
	printf("We want enqueue %d \n", item);
	node *nod = (node *)malloc(sizeof(node));
	nod->data = item;
	nod->next = NULL;

	if(qu->head){
		qu->tail->next = nod;
		qu->tail = qu->tail->next;		
	}else{
		qu->head = nod;
		qu->tail = nod;
	}
	return qu;
}

int dequeue(Queue *qu){
	printf("Now dequeueing....\n");
	if(isempty(qu)){ //if tail==0 cause segmentation fault
		printf("There is nothing can dequeue \n");
		return -1;
	}else{
		node *temp = qu->head;
		int item = qu->head->data;
		qu->head = qu->head->next;
		free(temp);
		printf("Dequeue number is %d \n", item);
		return item;
	}
}

bool isempty(Queue *qu){
	return qu->head == NULL;
}

void print_all(Queue *qu){
	printf("The queue is: ");
	node *current = qu->head;
	while(current){
		printf("%d", current->data);
		current = current->next;
	}
	printf("\n--------------------------\n");
}