# include <stdio.h>
# include <stdlib.h>
# include <string.h>
/*
	note
	1. printf(i)-> printf("%d", &num);
	2. (*int) malloc()-> (int *) malloc();
	3. pop 順序 記得push順序相反就可以了！
	4. ;
	5. declartion
	6. 加東西以後size忘記加1
	7.insert (indx > arr->size-1(size比indx多1)+1因為indx可以比原本的array多一個（多加上去)）
	8.resize is the most complex part!!! Using realloc can efficiently avoid addr change
*/

struct Array{
	int size;
	int capacity;
	int *data;
}typedef Array;

Array *create_new(int num);
void push(int num, Array *arr);
int pop(Array *arr);
int at(int indx, Array *arr); // return item at particular indx
Array *insert(int item, int indx, Array *arr);
Array *prepend(int item, Array *arr); //insert item at indx 0
Array *delete(int indx, Array *arr); //delete item at particular indx
Array *remove_arr(int num, Array *arr); //remove all item in the arr
int find(int item, Array *arr); //search item and return first indx with the value, -1 if not found
void print_all(Array *arr);
int is_empty(Array *arr);
Array *resize(Array *arr);//if array size = capacity size*2, if size<capacity/4 size/2
int determine_size(int);//if num<1 exit while(num> true/capacity) true*2
void destroy(Array *arr);

const int up_resize=2;
const int down_resize=4;
const int grow_factor = 2;

int main(void){
	int i;
	int r;
	Array *arr = create_new(2);
	push(3, arr);
	print_all(arr);
	push(5, arr);
	print_all(arr);
	push(8, arr);
	print_all(arr);
	push(1, arr);
	print_all(arr);
	push(1, arr);
	print_all(arr);
	arr = insert(1, 1, arr);
	print_all(arr);
	arr = prepend(9, arr);
	print_all(arr);
	arr = remove_arr(8, arr);
	print_all(arr);
	r = find(3, arr);
	printf("the index of 3 is : %d \n",r);
	arr = remove_arr(1, arr);
	print_all(arr);
	i = pop(arr);
	printf("pop is : %d \n",i);
	print_all(arr);
	i = pop(arr);
	printf("pop is : %d \n",i);
	print_all(arr);
	arr= delete(0, arr);
	i = pop(arr);
	printf("pop is : %d \n",i);
	print_all(arr);
	i = pop(arr);
	printf("pop is : %d \n",i);
	print_all(arr);
	i = pop(arr);
	printf("pop is : %d \n",i);
	i = pop(arr);
	printf("pop is : %d \n",i);
	i = pop(arr);
	printf("pop is : %d \n",i);
	return 0;
}

Array *create_new(int num){
	int capacity = determine_size(num);

	printf("New Capacity is %d \n", capacity);
	Array *arr = (Array *)malloc(sizeof(Array));
	arr->size = 0;
	arr->capacity = capacity;
	arr->data = (int *)malloc(sizeof(int)*capacity);
	return arr;
}

int determine_size(int num){
	int capacity = 1;

	if(num<1){
		printf("Can't create size");
		exit(0);
	}
	while(num/grow_factor >= 1){
		capacity *= grow_factor;
		num /= 2;
	}
	return capacity;
}


void push(int num, Array *arr){
	arr = resize(arr);
	*(arr->data+arr->size) = num;
	arr->size += 1;
}

int pop(Array *arr){
	int result;
	if(arr->size == 0){
		printf("Nothing");
		exit(0);
	}
	else{
		arr->size -= 1;
		result = *(arr->data+arr->size);
		resize(arr);
		return result;
	}
}

int at(int indx, Array *arr){
	int result;
	if(indx >arr->size){
		printf("No this item");
		exit(0);
	}
	else{
		result = *(arr->data+indx);
		return result;
	}
}

Array *insert(int item, int indx, Array *arr){
	if(indx < 0 || indx > (arr->size)){ 
		printf("No this position");
	}
	else{
		arr = resize(arr);
		memmove(arr->data+indx+1, arr->data+indx, (arr->size - indx)*sizeof(int));
		*(arr->data+indx) = item;
		arr->size += 1;
		return arr;
	}
	return arr;
}

Array *prepend(int item, Array *arr){
	arr = insert(item , 0, arr);
	arr = resize(arr);
	return arr;
}

Array *delete(int indx, Array *arr){
	if(indx > (arr->size-1)){
		printf("No this indx");
	}else{
		memmove(arr->data+indx, arr->data+indx+1, (arr->size - indx)*sizeof(int));
		--(arr->size);
		arr = resize(arr);
		return arr;
	}
	return arr;
}

int find(int item, Array *arr){
	for(int indx=0 ;indx < arr->size; indx++){
		if(*(arr->data+indx)==item){
			return indx;
		}
	}
	return -1;
}

Array *remove_arr(int item, Array *arr){
	while(find(item, arr) != -1){
		int indx = find(item, arr);
		arr = delete(indx, arr);
	}
	arr = resize(arr);
	return arr;
}

void print_all(Array *arr){
	printf("Now the Array is: ");
	for(int indx = 0; indx < arr->size ; indx++){
		printf("%d,", *(arr->data+indx));
	}
	printf("\n");
	printf("The capacity is: %d \n", arr->capacity);
	printf("The size is: %d \n", arr->size);
	printf("The data addr is: %p \n", arr->data);
}

int is_empty(Array *arr){
	if(arr->size == 0){
		return 1;
	}else{
		return 0;
	}
}

/* 
	wrong:
	new_arr->data = arr->data; print to same position
	but the mem would be free later 
	Therefore the data would disappear
	If we datele destroy code, everything would be ok
	But the memory would be wasted
*/
// Array *resize(Array *arr){
// 	if(arr->size+1 > arr->capacity){
// 		Array *new_arr = create_new(arr->capacity*grow_factor);
// 		new_arr->size = arr->size;
// 		new_arr->data = arr->data;
// 		// destroy(arr);
// 		return new_arr;
// 	}else if(arr->size < arr->capacity/down_resize){
// 		Array *new_arr = create_new(arr->capacity/grow_factor);
// 		new_arr->size = arr->size;
// 		new_arr->data = arr->data;
// 		// destroy(arr);
// 		return new_arr;		
// 	}
// 	return arr;
// }

Array *resize(Array *arr){
	if(arr->size >= arr->capacity){
		int new_capacity = determine_size(arr->capacity*2);
		int *new_data = (int *)realloc(arr->data, sizeof(int)*new_capacity);
		arr->capacity = new_capacity;
		arr->data = new_data;
		return arr;
	}else if(arr->size < arr->capacity/down_resize){
		int new_capacity = determine_size(arr->capacity/2);
		int *new_data = (int *)realloc(arr->data, sizeof(int)*new_capacity);
		arr->capacity = new_capacity;
		arr->data = new_data;
		return arr;		
	}
	return arr;
}

void destroy(Array *arr){
	free(arr->data);
	free(arr);
}