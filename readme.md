# C practice

## Array
<ul>
	<ol type = 1>
		<li> Using pointer to jump index</li>
		<li> push()</li>
		<li> pop() </li>
		<li> isempty()</li>
		<li> insert() </li>
		<li> prepend() </li>
		<li> at()</li>
		<li> delete() -> delete value at the index</li>
		<li> remove() -> remove all value in the array</li>
		<li> find() -> find the first index of the value</li>
		<li> destroy() -> destroy all array </li>
		<li> resize() -> if size>=capacity => capacity*2 if size< capacity/4 => capacity/2 </li>
	</ol>
</ul>

## Queue
<ul>
	<li> Queue Array </li>
	<ol type = 1>
		<li> enqueue() -> read += 1</li>
		<li> dequeue() -> write += 1</li>
		<li> isempty() -> read == write</li>
		<li> isfull() -> (read+1)%capacity == write</li>
	</ol>
	<li> Queue Linked List </li>
	<ol type = 1>
		<li> enqueue() -> tail = tail->next</li>
		<li> dequeue() -> head = head->next</li>
		<li> isempty() -> head == NUL</li>
	</ol>
</ul>

