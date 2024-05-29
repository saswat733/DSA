/**
 * Counts the number of bits that need to be flipped in integer A to make it equal to integer B.
 * 
 * @param A The first integer.
 * @param B The second integer.
 * @return The number of bits that need to be flipped.
 */
int flipBits(int A, int B) {
    // Initialize a variable to count the number of bits that need to be flipped
    int count = 0;
    
    // Calculate the XOR of A and B, which will result in a number where each bit is set if the corresponding bits in A and B are different
    int ans = A ^ B;
    
    // Iterate over each bit in the integer (assuming a typical size of 32 bits for int)
    for (int i = 0; i < sizeof(int) * 8; i++) {
        // Check if the i-th bit of ans is set (i.e., if the XOR of corresponding bits in A and B resulted in 1)
        if (ans & (1 << i)) {
            // If the bit is set, increment the count of bits that need to be flipped
            count++;
        }
    }
    
    // Return the count of bits that need to be flipped
    return count;
}




//******************************************************************************************************


/**
 * Finds the missing number in a sequence of integers.
 * 
 * @param n The number of elements in the sequence.
 * @param arr The sequence of integers.
 * @return The missing number.
 */
int missingNumber(int n, vector<int> &arr){
    // Initialize a variable to store the XOR of all elements in the sequence
    int xorr = 0;
    
    // Iterate through the sequence and calculate the XOR of all elements
    for(int i = 0; i < n; i++){
        xorr = xorr ^ arr[i];
    }
    
    // Return the XOR result, which will be the missing number
    return xorr;
}



//*********************************************************************************************************

/**
 * Calculates the XOR of all integers from L to R (inclusive).
 * 
 * @param L The left endpoint of the range.
 * @param R The right endpoint of the range.
 * @return The XOR of all integers from L to R.
 */
int findXOR(int L, int R){
    // Initialize a variable to store the XOR result
    int xorr = 0;
    
    // Iterate through the range from L to R (inclusive) and perform XOR operation
    for(int i = L; i <= R; i++){
        xorr = xorr ^ i;
    }
    
    // Return the XOR result
    return xorr;
}


//beter solution

/**
 * Computes a value based on the remainder of division by 4.
 * 
 * @param n The input integer.
 * @return The computed value.
 */
int fun1(int n){
    if(n % 4 == 1){
        return 1;
    }
    else if(n % 4 == 2){
        return n + 1;
    }
    else if(n % 4 == 3){
        return 0;
    }
    else{
        return n;
    }
}

/**
 * Finds the XOR of values within a given range.
 * 
 * @param L The left endpoint of the range (inclusive).
 * @param R The right endpoint of the range (inclusive).
 * @return The XOR of values within the range.
 */
int findXOR(int L, int R){
    // Utilize fun1 to compute XOR of values at L-1 and R
    return fun1(L - 1) ^ fun1(R);
}



//*******************************************************************************************************

#include <vector>
#include <algorithm> // Include the algorithm header for the sort function
using namespace std;

/**
 * Finds the two numbers that occur an odd number of times in a given vector.
 * 
 * @param arr The input vector containing integers.
 * @return A vector containing the two numbers that occur an odd number of times, sorted in decreasing order.
 */
vector<int> twoOddNum(vector<int> arr){
    long xorr = 0;
    vector<int> ans;

    // Calculate the XOR of all elements in the vector
    for(int i = 0; i < arr.size(); i++){
        xorr = xorr ^ arr[i];
    }

    // Find the rightmost set bit in the XOR result
    int rightmost = (xorr & (xorr - 1)) ^ xorr;

    // Initialize variables to store the two numbers occurring an odd number of times
    int b1 = 0;
    int b2 = 0;

    // Iterate through the vector to separate numbers based on the rightmost set bit
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] & rightmost){
            b1 = b1 ^ arr[i];
        }
        else{
            b2 = b2 ^ arr[i];
        }
    }  

    // Push the numbers into the result vector, pushing the larger number first
    ans.push_back(b2);
    ans.push_back(b1);

    // Sort the result vector in decreasing order
    sort(ans.begin(), ans.end(), greater<int>());

    // Return the sorted result vector
    return ans;
}





