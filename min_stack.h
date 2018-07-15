#pragma once
#include <Vector>
#include <stack>

using std::vector;
using std::stack;

class Min_stack
{
private:
	vector<int> stack_vec;
	stack<int> min_stack;
	int min;
public:
	Min_stack();
	void push(int val);
	bool pop();
	int peek();
	bool is_empty();
	int get_min();
	void print_stack();
};