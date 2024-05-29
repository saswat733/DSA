            // program for min stack 155
        

#include <iostream>
#include <stack>
#include <limits.h>

class MinStack {
private:
    // Stack to store the main elements
    std::stack<int> mainStack;

    // Stack to store the minimum elements
    std::stack<int> minStack;

public:
    // Constructor to initialize the stack object
    MinStack() {
        // No initialization needed for stacks as they are empty by default
    }

    /**
     * Pushes an element onto the stack.
     * @param val The value to be pushed onto the stack.
     */
    void push(int val) {
        // Push the value onto the main stack
        mainStack.push(val);
        
        // If minStack is empty or val is less than or equal to the top element of minStack, push it onto minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    /**
     * Removes the element on the top of the stack.
     */
    void pop() {
        // If mainStack is empty, do nothing
        if (mainStack.empty()) {
            return;
        }

        // If the top element of mainStack is the same as the top element of minStack, pop it from minStack
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }

        // Pop the top element from the main stack
        mainStack.pop();
    }

    /**
     * Gets the top element of the stack.
     * @return The top element of the stack, or INT_MIN if the stack is empty.
     */
    int top() {
        // If mainStack is empty, return INT_MIN as a sentinel value
        if (mainStack.empty()) {
            return INT_MIN;
        }

        // Return the top element of the main stack
        return mainStack.top();
    }

    /**
     * Retrieves the minimum element in the stack.
     * @return The minimum element in the stack, or INT_MIN if the stack is empty.
     */
    int getMin() {
        // If minStack is empty, return INT_MIN as a sentinel value
        if (minStack.empty()) {
            return INT_MIN;
        }

        // Return the top element of the min stack, which is the current minimum
        return minStack.top();
    }
};

int main() {
    // Create an instance of MinStack
    MinStack minStack;

    // Push elements onto the stack
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    // Get the minimum element in the stack
    std::cout << "Min element: " << minStack.getMin() << std::endl; // Output: -3

    // Pop the top element from the stack
    minStack.pop();

    // Get the top element of the stack
    std::cout << "Top element: " << minStack.top() << std::endl;    // Output: 0

    // Get the minimum element in the stack
    std::cout << "Min element: " << minStack.getMin() << std::endl; // Output: -2

    return 0;
}



