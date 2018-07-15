#include "triple_stack.h"

#pragma region CONSTRUCTORS/DESTRUCTOR


triple_stack::triple_stack() {
	stack_vec.resize(100);
	total_size = 100;
	initialize_indexes();
}


triple_stack::triple_stack(int size) {
	stack_vec.resize(size);
	total_size = size;
	initialize_indexes();
}


void triple_stack::initialize_indexes() {
	one_bottum = 0;
	one_top = 0;
	two_bottum = 0;
	two_top = 0;
	three_bottum = 0;
	three_top = 0;
}


triple_stack::~triple_stack() {};


#pragma endregion
#pragma region PUSH


bool triple_stack::push(int stack_num, int value) {
	bool result = false;
	switch (stack_num)
	{
	case 1:
		result = push_stack_one(value);
		return result;
		break;
	case 2:
		result = push_stack_two(value);
		return result;
		break;
	case 3:
		result = push_stack_three(value);
		return result;
		break;
	default:
		return false;
		break;
	}
}


bool triple_stack::push_stack_one(int value) {
	if (!vec_full) {
		++three_top;
		for (int i = three_top; i > two_bottum; --i) {
			stack_vec[i] = stack_vec[i - 1];
		}
		++one_top;
		++two_bottum;
		++two_top;
		++three_bottum;
		stack_vec[one_top - 1] = value;
		vec_full = check_full();
		return true;
	}
	else {
		return false;
	}
}


bool triple_stack::push_stack_two(int value) {
	if (!vec_full) {
		++three_top;
		for (int i = three_top; i > three_bottum; --i) {
			stack_vec[i] = stack_vec[i - 1];
		}
		++two_top;
		++three_bottum;
		stack_vec[two_top - 1] = value;
		vec_full = check_full();
		return true;
	}
	else {
		return false;
	}
}


bool triple_stack::push_stack_three(int value) {
	if (!vec_full) {
		++three_top;
		stack_vec[three_top - 1] = value;
		vec_full = check_full();
		return true;
	}
	else {
		return false;
	}
}


bool triple_stack::check_full() {
	if (three_top == total_size) {
		vec_full = true;
	}
	return false;
}


#pragma endregion
#pragma region POP


bool triple_stack::pop(int stack_num) {
	bool result = false;
	switch (stack_num)
	{
	case 1:
		result = pop_stack_one();
		return result;
		break;
	case 2:
		result = pop_stack_two();
		return result;
		break;
	case 3:
		result = pop_stack_three();
		return result;
		break;
	default:
		return false;
		break;
	}
}


bool triple_stack::pop_stack_one() {
	if (one_bottum == one_top) {
		return false;
	}
	--one_top;
	for (int i = three_top; i > one_top; --i) {
		stack_vec[i - 1] = stack_vec[i];
	}
	--two_bottum;
	--two_top;
	--three_bottum;
	--three_top;
	vec_full = false;
	return true;
}


bool triple_stack::pop_stack_two() {
	if (two_bottum == two_top) {
		return false;
	}
	--two_top;
	for (int i = three_top; i > two_top; --i) {
		stack_vec[i - 1] = stack_vec[i];
	}
	--three_bottum;
	--three_top;
	vec_full = false;
	return true;
}


bool triple_stack::pop_stack_three() {
	if (three_bottum == three_top) {
		return false;
	}
	--three_top;
	vec_full = false;
}


#pragma endregion
#pragma region PEEK


int triple_stack::peek(int stack_num) {
	switch (stack_num)
	{
	case 1:
		return stack_vec[one_top - 1];
		break;
	case 2:
		return stack_vec[two_top - 1];
		break;
	case 3:
		return stack_vec[three_top - 1];
		break;
	default:
		return -1;
		break;
	}
}


#pragma endregion
#pragma region IS EMPTY

bool triple_stack::is_empty(int stack_num) {
	switch (stack_num)
	{
	case 1:
		if (one_top == 0) {
			return true;
		}
		return false;
		break;
	case 2:
		if (two_bottum == two_top) {
			return true;
		}
		return false;
		break;
	case 3:
		if (three_bottum == three_top) {
			return true;
		}
		return false;
		break;
	default:
		printf("Choose a correct stack number\n");
		return false;
		break;
	}
}
#pragma endregion
#pragma region PRINT


void triple_stack::print_stack() {
	printf("Stack One: \n\tBottum: %d\n\tTop: %d\n", one_bottum, one_top);
	printf("Stack two: \n\tBottum: %d\n\tTop: %d\n", two_bottum, two_top);
	printf("Stack three: \n\tBottum: %d\n\tTop: %d\n", three_bottum, three_top);
	printf("Full: ");
	printf(vec_full ? "Yes\n" : "No\n");
	printf("Empty: ");
	for (int i = 1; i < 4; ++i) {
		bool empty = is_empty(i);
		printf("Stack %d empty: ", i);
		printf(empty ? "Yes\n" : "No\n");
	}
}


#pragma endregion