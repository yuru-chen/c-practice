# C practice

## Array
<ul>
	<ol type = 1>
		<li> Using pointer to jump index</li>
		<li> Arr *push(value);</li>
		<li> int pop(Arr*); </li>
		<li> bool isempty(Arr*);</li>
		<li> Arr *insert(index, value, Arr*); </li>
		<li> Arr *prepend(value, Arr*); </li>
		<li> int at(value);</li>
		<li> Arr *delete(index, Arr*); -> delete value at the index</li>
		<li> Arr *remove(value, Arr*); -> remove all value in the array</li>
		<li> int find(value, Arr*); -> find the first index of the value</li>
		<li> void destroy(Arr*); -> destroy all array </li>
		<li> Arr *resize(Arr*); -> if size>=capacity => capacity*2 if size< capacity/4 => capacity/2 </li>
	</ol>
</ul>

## Queue
<ul>
	<li> Queue Array </li>
	<ol type = 1>
		<li> Queue *enqueue(value); read += 1</li>
		<li> int dequeue(Queue); write += 1</li>
		<li> bool isempty(Queue); -> read == write</li>
		<li> bool isfull(Queue); -> (read+1)%capacity == write</li>
	</ol>
	<li> Queue Linked List </li>
	<ol type = 1>
		<li> enqueue tail = tail->next</li>
		<li> dequeue head = head->next</li>
		<li> isempty -> head == NUL</li>
	</ol>
</ul>

