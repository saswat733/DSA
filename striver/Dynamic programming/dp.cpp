#include<iostream>
#include<vector>
using namespace std;
                                // fibbonacci using memoization
                                // tiem complexity:O(n)
                                // space complexity: O(n)
int f(int n,vector<int> &dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    return dp[n]=f(n-1,dp)+f(n-2,dp);
}





                            //frog' Jump

// solution using memoiztion

// Recursive function to calculate the minimum energy expended by the frog to reach the stone at index 'ind'
int f(int ind, vector<int> &heights, vector<int> &dp){
    // Base case: If the frog is at the first stone (index 0), no energy is expended
    if(ind == 0){
        return 0;
    }
    
    // If the result for the current index 'ind' is already calculated, return it
    if(dp[ind] != -1){
        return dp[ind];
    }

    // Calculate the energy expended by jumping from the previous stone to the current stone
    int left = f(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
    
    // Calculate the energy expended by jumping from two stones back to the current stone, if possible
    int right = INT_MAX;
    if(ind > 1){
        right = f(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
    }

    // Store the minimum energy in the 'dp' array for future reference and return it
    return dp[ind] = min(left, right);
}

// Main function to solve the frog jump problem
int frogJump(int n, vector<int> &heights)
{
    // Initialize a dynamic programming array to store the results of subproblems
    vector<int> dp(n+1, -1);
    
    // Call the recursive function with the index of the last stone and return the result
    return f(n, heights, dp);
}




// solution using tabulation methos

#include <bits/stdc++.h> // This header includes most standard library headers. It's generally not recommended to use it in competitive programming or real projects.



// Function to solve the frog jump problem iteratively
int frogJump(int n, vector<int> &heights)
{
    // Initialize a dynamic programming array to store the minimum energy expended to reach each stone
    vector<int> dp(n, 0);
    dp[0] = 0; // Base case: Energy expended to reach the first stone is 0

    // Iterate through each stone starting from the second one
    for(int i = 1; i < n; i++) {
        // Calculate the energy expended by jumping from the previous stone to the current stone
        int first_step = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        
        // Calculate the energy expended by jumping from two stones back to the current stone, if possible
        int second_step = INT_MAX;
        if(i > 1) {
            second_step = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }

        // Store the minimum energy in the dp array for the current stone
        dp[i] = min(first_step, second_step);
    }

    // Return the minimum energy expended to reach the last stone
    return dp[n - 1];
}



//solution in which we can even more optimise the space using prev and prev2

//time complexity: O(n)
//space complexity: O(1)

#include <bits/stdc++.h> // Standard library header. Avoid using in production code.

// Function to solve the frog jump problem
int frogJump(int n, vector<int> &heights)
{
    // Initialize variables to keep track of minimum energy expended at each stone
    int prev = 0;   // Energy expended to reach the previous stone
    int prev2 = 0;  // Energy expended to reach the stone two steps back

    // Iterate through each stone starting from the second one
    for(int i = 1; i < n; i++) {
        // Calculate the energy expended by jumping from the previous stone to the current stone
        int first_step = prev + abs(heights[i] - heights[i - 1]);
        
        // Calculate the energy expended by jumping from two stones back to the current stone, if possible
        int second_step = INT_MAX;
        if(i > 1) {
            second_step = prev2 + abs(heights[i] - heights[i - 2]);
        }

        // Update the minimum energy for the current stone
        int curr = min(first_step, second_step);

        // Update the variables for the next iteration
        prev2 = prev;
        prev = curr;
    }

    // Return the minimum energy expended to reach the last stone
    return prev;
}
