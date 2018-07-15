#pragma once
#include <stack>

using std::stack;

class My_queue
{
private:
	stack<int> add_stack;
	stack<int> remove_stack;
	bool at_add;
	void print_helper();
public:
	My_queue();
	void add(int val);
	void remove();
	int peek();
	bool is_empty();
	void swap_stacks();
	void print_queue();
};