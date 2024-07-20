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


                //find the next greater element 496

#include <vector>
using namespace std;
                        //brute force
class Solution {
public:
    /**
     * Finds the next greater element for each element in nums1 based on their positions in nums2.
     * 
     * @param nums1 The first vector of integers.
     * @param nums2 The second vector of integers.
     * @return A vector containing the next greater element for each element in nums1.
     */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Initialize a vector to store the results
        vector<int> ans;

        // Iterate over each element in nums1
        for (int j = 0; j < nums1.size(); j++) {
            // Initialize greater element to -1
            int greater = -1;
            
            // Start from the end of nums2 and traverse backwards
            int i = nums2.size() - 1;
            while (nums1[j] != nums2[i]) {
                // If element in nums2 is greater than element in nums1, update greater
                if (nums2[i] > nums1[j]) {
                    greater = nums2[i];
                }
                i--; // Move to the previous element in nums2
            }
            
            // Add the next greater element to the result vector
            ans.push_back(greater);
        }
        
        // Return the result vector
        return ans;
    }
};


                //using hashmap and stack
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Hash map to store the next greater element for each element in nums2
        unordered_map<int, int> nextGreater;
        // Stack to keep track of the next greater elements
        stack<int> st;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            // Maintain the stack such that the top of the stack is the next greater element
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            // If the stack is not empty, the top of the stack is the next greater element
            if (!st.empty()) {
                nextGreater[nums2[i]] = st.top();
            } else {
                nextGreater[nums2[i]] = -1;
            }
            // Push the current element onto the stack
            st.push(nums2[i]);
        }

        // Prepare the result for nums1
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};


