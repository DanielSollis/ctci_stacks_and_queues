#include "sort_stack.h"


void Sort_stack::push(int val) {
	stack.push(val);
}


void Sort_stack::pop() {
	stack.pop();
}


int Sort_stack::peek() {
	return stack.top();
}


bool Sort_stack::is_empty() {
	return stack.empty();
}


void Sort_stack::sort() {
	int sort_level = 0;
	bool done_sorting = false;
	while (!done_sorting) {
		Max max = push_from_stack(sort_level);
		for (int i = 0; i < max.max_num; ++i) {
			stack.push(max.max_val);
			++sort_level;
		}
		done_sorting = push_from_buffer(max.max_val);
	}
	print_stack();
}


Sort_stack::Max Sort_stack::push_from_stack(int sort_level) {
	int max = -1;
	int max_num = 0;
	for (int i = stack.size(); i > sort_level; --i) {
		if (stack.top() > max) {
			max = stack.top();
			max_num = 1;
		}
		else if (stack.top() == max) {
			++max_num;
		}
		buffer.push(stack.top());
		stack.pop();
	}
	Max result = { max, max_num };
	return result;
}


bool Sort_stack::push_from_buffer(int max) {
	bool sorted = true;
	while (!buffer.empty()) {
		if (buffer.top() == max) {
			buffer.pop();
		}
		else {
			stack.push(buffer.top());
			buffer.pop();
			if (!buffer.empty() && stack.top() < buffer.top()) {
				sorted = false;
			}
		}
	}
	return sorted;
}


void Sort_stack::print_stack() {
	while (!stack.empty()) {
		buffer.push(stack.top());
		stack.pop();
	}
	while (!buffer.empty()) {
		printf("%d ", buffer.top());
		stack.push(buffer.top());
		buffer.pop();
	}
	printf("\n");
}