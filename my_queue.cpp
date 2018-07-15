#include "my_queue.h"

My_queue::My_queue() {
	at_add = true;
}


void My_queue::add(int val) {
	if (!at_add) {
		swap_stacks();
	}
	add_stack.push(val);
}


void My_queue::remove() {
	if (at_add) {
		swap_stacks();
	}
	remove_stack.pop();
}


int My_queue::peek() {
	if (this->is_empty()) {
		return -1;
	}
	if (at_add) {
		this->swap_stacks();
	}
	return remove_stack.top();
}


bool My_queue::is_empty() {
	if (add_stack.empty() && remove_stack.empty()) {
		return true;
	}
	return false;
}


void My_queue::swap_stacks() {
	if (at_add) {
		while (!add_stack.empty()) {
			remove_stack.push(add_stack.top());
			add_stack.pop();
		}
	}
	else {
		while (!remove_stack.empty()) {
			add_stack.push(remove_stack.top());
			remove_stack.pop();
		}
	}
	at_add = !at_add;
}

void My_queue::print_queue() {
	if (is_empty()) {
		printf("Queue empty\n");
	}
	else {
		if (at_add) {
			swap_stacks();
			while (!remove_stack.empty()) {
				print_helper();
			}
		}
		else {
			while (!remove_stack.empty()) {
				print_helper();
			}
			swap_stacks();
		}
	}
}


void My_queue::print_helper() {
	while (!remove_stack.empty()) {
		add_stack.push(remove_stack.top());
		printf("%d ", remove_stack.top());
		remove_stack.pop();
	}
	at_add = !at_add;
	printf("\n");
}