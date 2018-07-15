#include "triple_stack.h"
#include "min_stack.h"
#include "multi_stack.h"
#include "my_queue.h"
#include "sort_stack.h"
#include "pound_queue.h"
#include <iostream>

void test_triple_stack();
void test_push(triple_stack & stack);
void test_pop(triple_stack & stack);
void test_peek(triple_stack stack);
int get_stack_num(triple_stack stack);
void test_min_stack();
void test_multi_stack();
void test_push_at(Multi_stack & temp_stack);
void test_pop_at(Multi_stack & temp_stack);
int get_stack_num(Multi_stack temp_stack);
void test_my_queue();
void test_sort_stack();
void test_pound_queue();
void test_enqueue(Pound_queue & queue);


int main() {
	test_pound_queue();
	return 0;
}


#pragma region TEST TRIPLE_STACK


void test_triple_stack() {
	triple_stack stack(12);
	bool done = false;
	printf("1. Push\n2. Pop\n3. Peek\n4. Quit\n\n");
	while (!done) {
		int choice = 0;
		std::cin >> choice;
		int stack_num = 0;
		switch (choice) {
		case 1:
			test_push(stack);
			break;
		case 2:
			test_pop(stack);
			break;
		case 3:
			test_peek(stack);
			break;
		case 4:
			done = true;
			break;
		default:
			printf("Please choose a correct option.\n");
			break;
		}
	}
}


void test_push(triple_stack & stack) {
	int stack_num = get_stack_num(stack);
	printf("Choose value: ");
	int value;
	std::cin >> value;
	stack.push(stack_num, value);
	stack.print_stack();
}


void test_pop(triple_stack & stack) {
	int stack_num = get_stack_num(stack);
	stack.pop(stack_num);
	stack.print_stack();
}


void test_peek(triple_stack stack) {
	int stack_num = get_stack_num(stack);
	if (stack.is_empty(stack_num)) {
		printf("Stack is Empty\n");
	}
	else {
		printf("Top of stack: %d\n", stack.peek(stack_num));
	}
}


int get_stack_num(triple_stack stack) {
	printf("Choose stack: ");
	int stack_num;
	std::cin >> stack_num;
	return stack_num;
}


#pragma endregion
#pragma region TEST MIN STACK


void test_min_stack() {
	Min_stack stack;
	printf("1. Push\n2. Pop\n3. Peek\n4. Quit\n\n");
	bool done = false;
	int choice = 0;
	int val = 0;
	while (!done) {
		std::cin >> choice;
		switch (choice) {
		case 1:
			printf("Choose a value to push: ");
			std::cin >> val;
			stack.push(val);
			stack.print_stack();
			break;
		case 2:
			stack.pop();
			stack.print_stack();
			break;
		case 3:
			val = stack.peek();
			printf("Top value: %d\n", val);
			stack.print_stack();
			break;
		case 4:
			done = true;
			break;
		default:
			printf("Please choose a correct option.\n");
			break;
		}
	}
}


#pragma endregion
#pragma region TEST MULTI_STACK


void test_multi_stack() {
	Multi_stack multi_stack;
	printf("1. Push\n2. Push At\n3. Pop\n4. Pop At\n5. Peek\n6. Peek At\n7. Is Empty\n8. Quit\n\n");
	bool done = false;
	int choice = 0;
	int stack_num = 0;
	int value = 0;
	bool success;
	for (int i = 0; i < 2; i++) {
		for (int i = 1; i < 6; i++) {
			multi_stack.push(i);
		}
	}
	while (!done) {
		std::cin >> choice;
		switch (choice) {
		case 1:
			printf("Choose a value to push: ");
			std::cin >> value;
			multi_stack.push(value);
			break;
		case 2:
			test_push_at(multi_stack);
			break;
		case 3:
			success = multi_stack.pop();
			printf(success ? "Pop successfull\n" : "Pop unsuccessfull\n");
			break;
		case 4:
			test_pop_at(multi_stack);
			break;
		case 5:
			printf("Top of stack: &d\n", multi_stack.peek());
			break;
		case 6:
			stack_num = get_stack_num(multi_stack);
			printf("Top of stack number %d:\n", multi_stack.peek_at(stack_num));
			break;
		case 7:
			printf(multi_stack.is_empty() ? "Empty\n" : "Not Empty\n");
			break;
		case 8:
			done = true;
			break;
		default:
			break;
		}
	}
}


void test_push_at(Multi_stack & multi_stack) {
	int stack_num = get_stack_num(multi_stack);
	if (stack_num == -1) {
		printf("Stack number out of range\n");
	}
	else {
		int value;
		printf("Choose value to push: ");
		std::cin >> value;
		multi_stack.push_at(stack_num, value);
	}
}


void test_pop_at(Multi_stack & multi_stack) {
	int stack_num = get_stack_num(multi_stack);
	if (stack_num == -1) {
		printf("Stack number out of range\n");
	}
	else {
		bool success = multi_stack.pop_at(stack_num);
		printf(success ? "Pop successfull\n" : "Pop unsuccessfull\n");
	}
}


int get_stack_num(Multi_stack multi_stack) {
	printf("Choose a number between 1 and %d: ", multi_stack.number_of_stacks);
	int stack_num = 0;
	std::cin >> stack_num;
	if (stack_num < 1 || stack_num > multi_stack.number_of_stacks) {
		return -1;
	}
	return stack_num;
}


#pragma endregion
#pragma region TEST MY_QUEUE


void test_my_queue() {
	My_queue my_queue;
	bool done = false;
	int val = 0;
	printf("1. Add\n2. Remove\n3. Peek\n4. Quit\n\n");
	while (!done) {
		int choice = 0;
		std::cin >> choice;
		switch (choice) {
		case 1:
			printf("Choose a value to add: ");
			std::cin >> val;
			my_queue.add(val);
			break;
		case 2:
			my_queue.remove();
			break;
		case 3:
			printf("Value at front of queue: %d\n", my_queue.peek());
			break;
		case 4:
			done = true;
			break;
		default:
			printf("Please choose a correct option.\n");
			break;
		}
	}
}


#pragma endregion
#pragma region TEST SORT_STACK


void test_sort_stack() {
	Sort_stack stack;
	bool done = false;
	int val = 0;
	printf("1. Add\n2. Remove\n3. Peek\n4. Sort\n5. Quit\n\n");
	while (!done) {
		int choice = 0;
		std::cin >> choice;
		switch (choice) {
		case 1:
			printf("Choose a value to add: ");
			std::cin >> val;
			stack.push(val);
			break;
		case 2:
			stack.pop();
			break;
		case 3:
			printf("Value at top of stack: %d\n", stack.peek());
			break;
		case 4:
			stack.print_stack();
			stack.sort();
			stack.print_stack();
			break;
		case 5:
			done = true;
			break;
		defauld:
			printf("Please choose a correct option.\n");
			break;
		}
	}
}


#pragma endregion
#pragma region TEST POUND QUEUE


void test_pound_queue() {
	Pound_queue queue;
	bool done = false;
	bool result = false;
	int val = 0;
	printf("1. Enqueue\n2. Dequeue any\n3. Dequeue dog\n4. Dequeue cat\n5. Quit\n\n");
	while (!done) {
		int choice = 0;
		std::cin >> choice;
		switch (choice) {
		case 1:
			test_enqueue(queue);
			break;
		case 2:
			result = queue.dequeue_any();
			printf(result ? "Dequeue Successfull\n" : "Dequeue Unsuccessfull\n");
			break;
		case 3:
			result = queue.dequeue_dog();
			printf(result ? "Dequeue Dog Successfull\n" : "Dequeue Dog Unsuccessfull\n");
			break;
		case 4:
			result = queue.dequeue_cat();
			printf(result ? "Dequeue Cat Successfull\n" : "Dequeue Cat Unsuccessfull\n");
			break;
		case 5:
			done = true;
			break;
		default:
			break;
		}
	}
}



void test_enqueue(Pound_queue & queue) {
	char animal_type;
	printf("Is animal a cat or dog? ('C' or 'D')\n");
	std::cin >> animal_type;
	bool result = queue.enqueue(animal_type);
	printf(result ? "Enqueue Successfull\n" : "Enqueue Unsuccessfull\n");
}

#pragma endregion