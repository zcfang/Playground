#include <stack>

class MyQueue {
public:
    std::stack<int> push_stack;
    std::stack<int> pop_stack;
    int front;
    /**
     * Problem from LeetCode 232: Implement Queue using Stacks. You can find
     * the problem
     * <a href="https://leetcode.com/problems/implement-queue-using-stacks/">
     * here</a>.
     */
    MyQueue() {

    }
    
    /**
     * Push element x to the back of queue.
     *
     * @param[in] x: Value to push on to queue
     */
    void push(int x) {
        if (push_stack.empty()) front = x;
        push_stack.push(x);
    }
    
    /**
     * Removes the front element of queue and returns that element.
     *
     * @returns Returns popped element
     */
    int pop() {
        if (pop_stack.empty()) {
            while (!push_stack.empty()) {
                int value = push_stack.top();
                pop_stack.push(value);
                push_stack.pop();
            }
        }
        int value = pop_stack.top();
        pop_stack.pop();

        return value;
    }
    
    /**
     * Get the front element.
     *
     * @returns The front element of the queue
     */
    int peek() {
        if (!pop_stack.empty()) return pop_stack.top();
        return front;
    }
    
    /**
     * Returns whether the queue is empty.
     *
     * @returns Returns whether the queue is empty.
     */
    bool empty() {
        return (pop_stack.empty() && push_stack.empty());
    }
};

int main(int argc, char const *argv[]) {
    MyQueue* obj = new MyQueue();

    obj->push(5);
    obj->push(10);

    assert(obj->top() == 5);
    assert(obj->pop() == 5);
    assert(!obj->empty());
    assert(obj->top() == 10);

    return 0;
}
