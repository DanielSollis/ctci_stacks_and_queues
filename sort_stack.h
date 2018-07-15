#pragma once
#include <stack>

class Sort_stack {
private:
	struct Max {
		int max_val;
		int max_num;
	};

	std::stack<int> stack;
	std::stack<int> buffer;

	//helpers
	Max push_from_stack(int sort_level);
	bool push_from_buffer(int max);
public:
	void push(int val);
	void pop();
	int peek();
	bool is_empty();
	void sort();
	void print_stack();
};