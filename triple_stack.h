#pragma once
#include <vector>

using std::vector;

class triple_stack {
private:
	vector<int> stack_vec;
	int total_size;
	int one_top;
	int one_bottum;
	int two_top;
	int two_bottum;
	int three_top;
	int three_bottum;
	bool vec_full;

	//helpers
	void initialize_indexes();
	bool push_stack_one(int value);
	bool push_stack_two(int value);
	bool push_stack_three(int value);
	bool check_full();
	bool pop_stack_one();
	bool pop_stack_two();
	bool pop_stack_three();
public:
	triple_stack();
	triple_stack(int size);
	~triple_stack();
	bool push(int stack_num, int value);
	bool pop(int stack_num);
	bool is_empty(int stack_num);
	int peek(int stack_num);
	void print_stack();
};
