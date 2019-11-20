#include <queue>
#include <assert.h> 

class MyStack {
public:
    std::queue<int> my_stack;
    int top_element;
    /**
     * Problem from LeetCode 225: Implement Stack using Queues. You can find the
     * problem
     * <a href="https://leetcode.com/problems/implement-stack-using-queues/">
     * here</a>.
     */
    MyStack() {
        
    }
    
    /**
     * Push element x onto stack.
     *
     * @param[in] x: Value to push on to stack
     */
    void push(int x) {
        my_stack.push(x);
        top_element = x;
    }
    
    /**
    * Removes the element on top of the stack and returns that element.
    *
    * @returns Returns popped element
    */
    int pop() {
        int size = my_stack.size() - 1;
        int value;

        for (std::size_t i = 0; i < size; i++) {
            value = my_stack.front();
            my_stack.pop();
            my_stack.push(value);
        }
        top_element = value;
        value = my_stack.front();
        my_stack.pop();

        return value;
    }
    
    /**
    * Get the top element.
    *
    * @returns The top element of the stack
    */
    int top() {
        return top_element;
    }
    
    /**
    * Returns whether the stack is empty.
    *
    * @returns Whether the stack is empty
    */
    bool empty() {
        return my_stack.empty();
    }
};

int main(int argc, char const *argv[]) {
    MyStack* obj = new MyStack();

    obj->push(5);
    obj->push(10);

    assert(obj->top() == 10);
    assert(obj->pop() == 10);
    assert(!obj->empty());
    assert(obj->top() == 5);

    return 0;
}
