# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

/*
	note
	1. cant delete pointer unless it didnt point to anything
	2. How to traversal: while(temp)
	3. how to change *head value [important!][pop_back read again!]
*/
struct node{
	int data;
	struct node *next;
}typedef node;

void push_back(int value, node **nod);
void print_all(node *nod);
void push_front(int value, node **nod);
int pop_front(node **nod);
int pop_back(node **nod);
int front(node *nod);
int back(node *nod);
void insert(int index, int value, node **nod);
void erase(int index, node **nod);
int value_at(int index, node *nod);
int value_n_from_end(int verse_index, node *nod); //return the value of the node from the the end of the list
void reverse(node **nod);
void remove_value(int value, node **nod);//remove the first item in the list with this value
int size(node *nod);
bool isempty(node *nod);

int main(void){
	node *head = NULL;
	int r;
	printf("\n");
	push_front(3, &head);
	print_all(head);
	insert(1, 13, &head);
	print_all(head);
	erase(0, &head);
	print_all(head);
	push_back(51, &head);
	print_all(head);
	push_back(7, &head);
	print_all(head);
	push_front(119, &head);
	print_all(head);
	push_front(12, &head);
	print_all(head);
	push_back(1, &head);
	print_all(head);
	r = pop_front(&head);
	print_all(head);
	r = pop_back(&head);
	print_all(head);
	r = front(head);
	print_all(head);
	r = back(head);
	print_all(head);
	insert(2, 4, &head);
	print_all(head);
	erase(0, &head);
	print_all(head);
	r = value_at(3, head);
	print_all(head);
	r = value_n_from_end(3, head);
	print_all(head);
	reverse(&head);
	print_all(head);
	remove_value(51, &head);
	print_all(head);
	r = size(head);
	print_all(head);
}

void push_back(int value, node **head){
	printf("Now we push %d at the back of the list \n", value);
	node *nod = malloc(sizeof(node));
	nod->data = value;
	nod->next = NULL;
	if(head){
		node *temp = *head;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = nod;
	}else{
		*head = nod;
	}
}

void push_front(int value, node **head){
	printf("Now we push %d at the front of the list \n", value);
	node *nod = malloc(sizeof(node));
	nod->data = value;
	nod->next = NULL;
	if(head){
		nod->next = *head;
		*head = nod;
	}else{
		*head = nod;
	}
}

int pop_front(node **head){
	if(head==NULL){
		printf("There is nothing can pop\n");
		return -1;
	}
	node *temp = *head;
	*head = (*head)->next;
	int value = temp->data;
	free(temp);
	printf("Now we pop the front value of the list\n");
	printf("We got %d \n", value);
	return value;
}

int pop_back(node **head){
	if(head==NULL){
		printf("There is nothing can pop\n");
		return -1;
	}

	node *temp = *head;
	node *previous = NULL;

	while(temp->next){
		previous = temp;
		temp = temp->next;
	}

	int value = temp->data;

	if(previous){
		previous->next = NULL;	
	}else{
		*head = NULL;
	}

	free(temp);

	printf("Now we pop the back of the value of the list \n");
	printf("We got %d \n", value);
	return value;
}

void print_all(node *head){
	printf("Now the linked list is:");
	node *temp = head;
	while(temp){
		printf("%d,", temp->data);
		temp = temp->next;
	}
	printf("\n----------------------------------\n");
}

int front(node *head){
	if(head==NULL){
		printf("The list is empty");
		return -1;
	}
	int value = head->data;
	printf("The front of the list is: %d\n", value);
	return value;
}

int back(node *head){
	if(head==NULL){
		printf("The list is empty");
		return -1;
	}
	int value;
	node *temp = head;
	while(temp->next){
		temp = temp->next;
	}
	value = temp->data;
	printf("The back of the list is: %d\n", value);
	return value;
}

void insert(int index, int value, node **head){
	node *previous = NULL;
	node *current = *head;
	node *nod = malloc(sizeof(node));
	nod->data = value;
	nod->next = NULL;
	
	int i;
	for(i = 0; i < index && current ; i++){ //current == NULL 已到尾巴
		previous = current;
		current = current->next;
	}
	if(i != index){ //for loop 會先執行完上面的步驟才停 -> out of bound
		printf("The index didnt exist\n");
		exit(0);
	}

	if(previous){
		previous->next = nod;
		nod->next = current;
		printf("Now we insert %d at the index of %d\n", value, index);
	}else{
		nod->next = *head;
		*head = nod; //only one node and insert at the index of 1
	}
}

void erase(int index, node **head){
	printf("Now we are going to erase the value at index %d \n", index);
	node *current = *head;
	node *previous = NULL;

	int i;
	for(i=0; i<index && current->next; i++){//current->next NULL 就已經不能刪了
		previous = current;
		current = current->next;
	}

	printf("the index is %d the i is %d \n", index, i );
	if(i != index){
		printf("The index is out of bound \n");
		exit(0);
	}

	// if(previous && current->next){ //123->12
	// 	previous -> next = current->next;
	// 	free(current);
	// }

	// if(previous && current->next==NULL){ //12->1
	// 	previous->next = NULL;
	// 	free(current);
	// }

	// if(previous==NULL && current->next==NULL){ //1
	// 	*head = NULL;
	// 	free(current);
	// }

	// if(previous==NULL && current->next){ //1234->234
	// 	*head = current->next;
	// 	free(current);
	// }

	if(previous){
		previous->next = current->next;
	}else{
		*head = current->next;
	}
	free(current);
}

int value_at(int index, node *head){
	node *temp = head;
	int value, i;
	for(i=0; i<index && temp->next; i++){
		temp = temp->next;
	}
	if(i != index){
		printf("The index out of bound \n");
		exit(0);
	}

	value = temp->data;

	printf("The value at the index of %d is %d \n", index, value);
	return value;
}

int value_n_from_end(int verse_index, node *head){
	if(verse_index <1 || head==NULL){
		printf("Cant get the nth item from end");
	}

	node *front = head;
	node *tail = head;

	int i, value;
	for(i = 1; i<verse_index && tail->next; i++){
		tail = tail->next;
	}

	if(i != verse_index){
		printf("The index is out of bound \n");
		exit(0);
	}

	while(tail->next){
		tail = tail->next;
		front = front->next;
	}

	value = front->data;
	printf("the value of the node at %d position from the end of the list is %d \n", verse_index, value);
	return value;
}

void reverse(node **head){
	printf("Now we reverse the list \n");
	if(head==NULL){
		printf("The list is empty \n");
		exit(0);
	}

	node *previous= NULL;
	node *next = *head;
	node *current = *head;

	while(current){
		next= current->next;
		current -> next = previous;
		previous = current;
		current = next;
	}

	*head = previous;
}

void remove_value(int value, node **head){
	node *temp = *head;
	node *previous = NULL;
	int flag=0;

	while(temp->next){
		if(temp->data == value){
			flag += 1;
			if(previous){
				previous->next = temp->next;
				free(temp);
			}else{
				*head = temp->next;
				free(temp);
			}
			break;
		}
		previous = temp;
		temp = temp->next;
	}
	if(flag==0){
		printf("We cant find value of %d in the list \n", value);
	}else{
		printf("We already remove %d \n", value);
	}
}

int size(node *head){
	node *current = head;
	int size = 0;
	while(current){
		size++;
		current = current->next;
	}
	printf("The size of the list is: %d \n", size);
	return size;
}

bool isempty(node *head){
	return head == NULL;
}
