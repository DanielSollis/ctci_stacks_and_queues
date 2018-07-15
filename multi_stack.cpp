#include "multi_stack.h"


Multi_stack::Multi_stack() {
	stack<int> * initial_stack = new stack<int>;
	stack_vec.push_back(initial_stack);
	current_stack_size = 0;
	int number_of_stacks = 0;
}


Multi_stack::~Multi_stack() {}

void Multi_stack::push(int val) {
	if (current_stack_size == MAX_STACK_SIZE) {
		push_to_new_stack(val);
		number_of_stacks++;
	}
	else {
		if (number_of_stacks == 0) {
			number_of_stacks++;
		}
		stack_vec.back()->push(val);
		++current_stack_size;
	}
}


void Multi_stack::push_to_new_stack(int val) {
	stack<int> * new_stack = new stack<int>;
	stack_vec.push_back(new_stack);
	stack_vec.back()->push(val);
	current_stack_size = 1;
}


void Multi_stack::push_at(int stack_num, int val) {
	if (stack_num == stack_vec.size() || is_empty()) {
		push(val);
	}
	else {
		stack<int> buffer_stack = get_buffer_stack(stack_num);
		push(val);
		return_buffer_stack(buffer_stack);
	}
	printf("Value Pushed\n");
}


bool Multi_stack::pop() {
	if (is_empty()) {
		return false;
	}
	else if (current_stack_size == 1 && stack_vec.size() > 1) {
		delete stack_vec.back();
		stack_vec.pop_back();
		current_stack_size = MAX_STACK_SIZE;
		number_of_stacks--;
		return true;
	}
	else {
		stack_vec.back()->pop();
		--current_stack_size;
		return true;
	}
}


bool Multi_stack::pop_at(int stack_num) {
	if (stack_num == stack_vec.size()) {
		pop();
		return true;
	}
	else if (is_empty()) {
		return false;
	}
	else {
		stack<int> buffer_stack = get_buffer_stack(stack_num);
		pop();
		return_buffer_stack(buffer_stack);
		return true;
	}
}


stack<int> Multi_stack::get_buffer_stack(int stack_num) {
	stack<int> buffer_stack;
	while (stack_vec.size() > stack_num) {
		buffer_stack.push(peek());
		pop();
	}
	return buffer_stack;
}


void Multi_stack::return_buffer_stack(stack<int> & buffer_stack) {
	while (!buffer_stack.empty()) {
		push(buffer_stack.top());
		buffer_stack.pop();
	}
}


int Multi_stack::peek() {
	return stack_vec.back()->top();
}


int Multi_stack::peek_at(int stack_num) {
	return stack_vec[stack_num - 1]->top();
}


bool Multi_stack::is_empty() {
	return (stack_vec.size() <= 1 && current_stack_size == 0);
}