#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Multi_stack {
private:
	vector<stack<int> *> stack_vec;
	const int MAX_STACK_SIZE = 5;
	int current_stack_size;

	//helpers
	void push_to_new_stack(int val);
	stack<int> get_buffer_stack(int stack_num);
	void return_buffer_stack(stack<int> & buffer_stack);
public:
	int number_of_stacks;

	Multi_stack();
	~Multi_stack();
	void push(int val);
	void push_at(int stack_num, int val);
	bool pop();
	bool pop_at(int stack_num);
	int peek();
	int peek_at(int stack_num);
	bool is_empty();
};