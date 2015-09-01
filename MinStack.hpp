//Min Stack

//Design a stack that supports push, pop, top, and retrieving the minimum element 
//in constant time.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//getMin() --Retrieve the minimum element in the stack.


#include <climits>
class MinStack {
public:
	MinStack() :min_value(INT_MAX),it_top(0){};

	void push_top(int x){
		stack[it_top++] = x;
	}

	void push(int x) {
		push_top(x);
		if (x <= min_value)
			min_value = x;
		push_top(min_value);
	}

	void pop() {
		if (it_top > 0)
			it_top -= 2;
	}

	int top() {
		if (it_top > 0)
			return stack[it_top - 2];
	}

	int getMin() {
		if (it_top > 0)
			return stack[it_top - 1];
	}

private:
	void push_top(int x){
		stack[it_top++] = x;
	}

	int stack[150];
	int it_top;
	int min_value;
};