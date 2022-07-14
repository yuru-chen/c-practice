# include <stdio.h>
# include <stdlib.h> //for malloc

/*
	note:
	1. check ;
	2. check variable
	3. enqueue and dequeue pointer need to be careful %
*/
struct Queue{
	int read;
	int write;
	int capacity;
	int *data;
}typedef Queue;

Queue *new_queue(int num);
Queue *enqueue(int item, Queue *qu);
int dequeue(Queue *qu);
int is_empty(Queue *qu);
int is_full(Queue *qu);
void print_all(Queue *qu);

int main(void){
	int r;
	Queue *qu = new_queue(5);
	print_all(qu);
	qu = enqueue(2, qu);
	print_all(qu);
	qu = enqueue(3, qu);
	print_all(qu);
	qu = enqueue(4, qu);
	print_all(qu);
	qu = enqueue(5, qu);
	print_all(qu);
	r = dequeue(qu);
	printf("The dequeue number is: %d \n", r);
	print_all(qu);
	r = dequeue(qu);
	printf("The dequeue number is: %d \n", r);
	print_all(qu);
	r = dequeue(qu);
	printf("The dequeue number is: %d \n", r);
	print_all(qu);
	qu = enqueue(4, qu);
	print_all(qu);
	qu = enqueue(5, qu);
	print_all(qu);
	r = dequeue(qu);
	printf("The dequeue number is: %d \n", r);
	print_all(qu);

	return 0;
}

Queue *new_queue(int num){
	Queue *qu = (Queue *)malloc(sizeof(Queue));
	qu->read = 0;
	qu->write = 0;
	qu->capacity = num;
	qu->data = (int *)malloc(sizeof(int)*num);

	return qu;
}

Queue *enqueue(int item, Queue *qu){
	printf("Now enqueueing...\n");
	if(is_full(qu) == 1){
		printf("Sorry the queue is full! Can't enqueue! \n");
		return qu;
	}else{
		*(qu->data+qu->read) = item;
		qu->read = ((qu->read+1)%qu->capacity);
		return qu;
	}
}

int dequeue(Queue *qu){
	printf("Now dequeueing...\n");
	if(is_empty(qu)== 1){
		printf("Sorry! The queue is empty \n");
		return -1;
	}else{
		int item = *(qu->data+qu->write);
		*(qu->data+qu->write) = 0;
		qu->write = ((qu->write+1)%qu->capacity);
		return item;
	}
}

int is_empty(Queue *qu){
	if(qu->read == qu->write) return 1;
	else return 0;
}

int is_full(Queue *qu){
	if(((qu->read+1)%qu->capacity) == qu->write) return 1;
	else return 0;
}
void print_all(Queue *qu){
	printf("The queue is:");
	for(int indx = 0; indx < qu->capacity; indx++){
		printf("%d,", *(qu->data+indx));
	}
	printf("\n");
	printf("The capacity is: %d \n", qu->capacity);
	printf("The indx of read is: %d \n", qu->read);
	printf("The index of write is: %d \n", qu->write);
	printf("----------------------------\n");
}