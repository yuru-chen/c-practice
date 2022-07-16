# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
}typedef node;

node *insert(int , node*);
void print_all(node*);
void delete_tree(node*);
bool is_in_tree(int, node*);
int get_height(node*);
int max_num(int, int);
int get_min(node*);
int get_max(node*);
bool is_bst(node*);
bool is_between_num(node*, int, int);
node *delete_value(int, node*);
int get_successor(node*, int);

int main(void){
	int i;
	node *head = NULL;
	head = insert(3, head);
	head = insert(7, head);
	head = insert(9, head);
	head = insert(5, head);
	print_all(head);
	printf("\n");
	i = get_max(head);
	printf("Max is : %d \n", i);
	i = get_min(head);
	printf("min is : %d \n", i);
	head = delete_value(7, head);
	print_all(head);
	printf("\n");
	i = get_successor(head, 3);
	printf("the successor of %d is %d \n", 3, i);
}

node *insert(int value, node *head){
	if(head == NULL){
		node *nod = malloc(sizeof(node));
		nod->data = value;
		nod->left = NULL;
		nod->right = NULL;
		head = nod;
		return head;
	}

	if(value < head->data){
		head->left = insert(value, head->left);
	}else if(value > head->data){
		head->right = insert(value, head->right);
	}

	return head;
}

void print_all(node *head){
	if(head == NULL){
		return;
	}

	print_all(head->left);
	printf("%d", head->data);
	print_all(head->right);
}

void delete_tree(node *head){
	if (head == NULL) return;

	delete_tree(head->left);
	delete_tree(head->right);
	free(head);
}

bool is_in_tree(int value, node *head){
	if(head == NULL) return false;

	if(value < head->data){
		return is_in_tree(value, head->left);
	}else if(value > head->data){
		return is_in_tree(value, head->right);
	}else{
		return true;
	}
}

int get_max(node *head){
	if(head == NULL) return -1;

	node *current = head;

	while(current->right != NULL){
		current = current->right;
	}	
	return current->data;
}

int get_min(node *head){
	if(head == NULL) return -1;

	node *current = head;

	while(current->left != NULL){
		current = current->left;
	}
	return current->data;
}

int get_height(node *head){
	if(head == NULL) return 0;

	return 1 + max_num(get_height(head->left), get_height(head->right));
}

int max_num(int left, int right){
	if(left > right) return left;
	else return right;
}

bool is_bst(node *head){
	if(head == NULL) return true;

	return is_between_num(head, INT_MIN, INT_MAX);
}

bool is_between_num(node *head, int min, int max){
	if(head == NULL) return true;

	return head->data > min && head->data < max &&
			is_between_num(head->left, min, head->data)&&
			is_between_num(head->right, head->data, max);
}

node *delete_value(int value, node* head){
	if(head ==NULL) return head;

	if(value < head->data){
		head->left = delete_value(value, head->left);
	}else if(value > head->data){
		head->right = delete_value(value, head->right);
	}else{
		if(head->left == NULL){
			node *temp = head;
			head = head->right;
			free(temp);
		}else if(head->right == NULL){
			node *temp = head;
			head = head->left;
			free(temp);
		}else{
			int right_min = get_min(head->right);
			head->data = right_min;
			head->right = delete_value(right_min, head->right);
		}
	}
	return head;
}

int get_successor(node *head, int value){
	if(head == NULL) return -1;

	node *target = head;

	while(target->data != value){
		if(target->data > value){
			target = target->left;
		}else if(target->data < value){
			target = target->right;
		}
	}


	if(target->right != NULL){
		int i = get_min(target->right);
		return i;
	}else{
		node *successor = NULL;
		node *ancestor = head;
		while(ancestor != NULL){
			if(ancestor->data > value){
				successor = ancestor;
				ancestor = ancestor->left;
			}else{
				ancestor = ancestor->right;
			}
		}
		return successor->data;
	}
}