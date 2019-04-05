#include <stack>

class MinStack {
public:
    std::stack<int> regular_stack;
    std::stack<int> min_stack;
    /**
     * Problem from LeetCode 155: Min Stack. You can find the
     * problem
     * <a href="https://leetcode.com/problems/min-stack/">
     * here</a>.
     */
    MinStack() {

    }
    
    /**
     * Push value on to stack
     *
     * @param[in] x: Value to push on to stack
     */
    void push(int x) {
        regular_stack.push(x);
        if (min_stack.empty() || min_stack.top() >= x) min_stack.push(x);
    }
    
    /**
     * Pop value off stack
     */
    void pop() {
        if (regular_stack.top() == min_stack.top()) min_stack.pop();
        regular_stack.pop();        
    }

    /**
     * Return top value of stack
     *
     * @returns Top value of stack
     */
    int top() {
        // For this problem, it will be assumed that the stack is not empty when
        // calling this function
        return regular_stack.top(); 
    }

    /**
     * Return min value in stack
     *
     * @returns Min value in stack
     */
    int get_min() {
        // For this problem, it will be assumed that the stack is not empty when
        // calling this function
        return min_stack.top();
    }
};

int main(int argc, char const *argv[]) {
    MinStack *min_stack = new MinStack();
    min_stack->push(-2);
    min_stack->push(0);
    min_stack->push(-3);
    min_stack->get_min();
    min_stack->pop();
    min_stack->top();
    min_stack->get_min();
    return 0;
}