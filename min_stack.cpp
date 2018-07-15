#include "min_stack.h"


Min_stack::Min_stack() {
	min = -1;
}


void Min_stack::push(int val) {
	if (min_stack.empty() || val < min) {
		min_stack.push(val);
		min = val;
	}
	stack_vec.push_back(val);
}


bool Min_stack::pop() {
	if (stack_vec.size() == 0) {
		return false;
	}
	if (stack_vec.back() == min_stack.top()) {
		min_stack.pop();
		min = min_stack.top();
	}
	stack_vec.pop_back();
	return true;
}


int Min_stack::peek() {
	if (stack_vec.size() == 0) {
		return -1;
	}
	return stack_vec.back();
}


bool Min_stack::is_empty() {
	return (stack_vec.size() == 0);
}


int Min_stack::get_min() {
	return min;
}


void Min_stack::print_stack() {
	for (int i = 0; i < stack_vec.size(); ++i) {
		printf("%d ", stack_vec[i]);
		printf("\n");
	}
}