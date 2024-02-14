#include<bits/stdc++.h> 

// problem ::: Count Frequency in a range 
/*

Input: ‘n’ = 6 ‘x’ = 9 ‘arr’ = [1, 3, 1, 9, 2, 7]    
Output: [2, 1, 1, 0, 0, 0]
Explanation: Below Table shows the number and their counts, respectively, in the array
Number         Count 
 1                2
 2                1
 3                1
 4                0
 5                0
 6                0

*/
vector<int> countFrequency(int n, int x, vector<int> &nums){
    // Write your code here.
    // Initialize a vector to store the frequency of each number from 1 to n
    std::vector<int> frequency(n, 0); // Initialize frequency array with zeros
    
    // Loop through the elements of the input vector nums
    for (int i = 0; i < nums.size(); ++i) {
        // Get the current element from the vector
        int num = nums[i];
        
        // Check if the current element is within the range [1, n]
        if (num >= 1 && num <= n) { 
            // Increment the frequency count of the current element
            // The frequency count is stored in the frequency array
            frequency[num - 1]++;
        }
    }
    
    // Return the frequency array containing counts of elements from 1 to n
    return frequency;
}
