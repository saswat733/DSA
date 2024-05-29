#include <vector> // Include the header file for vector, although it's not used in this code
using namespace std; // Import the entire std namespace

/*
 * Function to check if the kth bit of an integer n is set (i.e., equals 1).
 * @param n The integer whose kth bit is to be checked.
 * @param k The position of the bit to be checked (1-indexed).
 * @return true if the kth bit of n is set, false otherwise.
 */
bool isKthBitSet(int n, int k) {
    // Check if the kth bit of n is set
    if (n >> (k - 1) & 1 == 1) {
        return true; // If the kth bit is set, return true
    } else {
        return false; // If the kth bit is not set, return false
    }
}

// Function to count the number of set bits (bits with value 1) in the binary representation of an integer 'n'
int countSetBits(int n) {
    // Initialize a variable 'count' to keep track of the number of set bits
    int count = 0;
    
    // Iterate over each bit of 'n' until 'n' becomes 1 (greater than 1), as long as there are more bits to process
    while (n > 1) {
        // Check if the least significant bit of 'n' is set (equals 1)
        // If it is, increment 'count'
        count += n & 1;
        
        // Right shift 'n' by 1 to move to the next bit
        n = n >> 1;
    }
    
    // Check if the last bit of 'n' is 1 (for numbers that are not powers of 2)
    // If it is, increment 'count' by 1, as there's still one set bit remaining in 'n'
    if (n == 1) {
        count += 1;
    }
    
    // Return the final count of set bits
    return count;
}

/**
 * @brief Counts the total number of set bits (bits with value 1) in the binary representation 
 *        of integers from 1 to n using Brian Kernighan's Algorithm.
 * 
 * @param n The upper limit of the range of integers to count set bits for.
 * @return The total count of set bits in the range from 1 to n.
 */
int countSetBits(int n) {
    int count = 0; // Initialize count to 0 to keep track of the total number of set bits
    
    // Loop through each number from 1 to n
    for (int i = 1; i <= n; i++) {
        int num = i; // Store the current number in a separate variable
        
        // Count the number of set bits in the current number using Brian Kernighan's Algorithm
        while (num != 0) {
            num = num & (num - 1); // Clear the least significant set bit
            count++; // Increment count
        }
    }
    
    return count; // Return the total count of set bits in the range from 1 to n
}


