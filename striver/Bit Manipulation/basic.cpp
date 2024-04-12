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



#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;






vector<int> bitManipulation(int num, int j)
{
    vector<int> ans;
    int firstAns = (num >> (j - 1)) & 1;

    int secondAns = (num ^ (1 << (j-1)));
    
    ans.push_back(firstAns);
    ans.push_back(secondAns);
    ans.push_back(num);
    return ans;
}




int main(){
   int ans=(12|11);
   cout<< ans;

}
