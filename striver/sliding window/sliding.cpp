
                            // program to find the longest substring with unique characters 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int maxi = 0;
        int l = 0;
        int r = 0;
        // Initialize the hashmap to store the index of the last occurrence of each character
        int hash[256];
        fill(hash, hash + 256, -1); // Initialize all elements to -1 indicating character not encountered

        while (r < s.length()) {
            // If the character is in the hashmap and its last occurrence is within the current window
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                // Move the left pointer to the position after the last occurrence of the character
                l = hash[s[r]] + 1;
            }
            // Update the length of the current substring
            len = r - l + 1;
            // Update the maximum length
            maxi = max(len, maxi);
            // Store the index of the current character in the hashmap
            hash[s[r]] = r;
            // Move the right pointer to the next character
            r++;
        }
        return maxi;
    }
};



                                    // Max consecutive ones

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0;  // Initialize the maximum length of subarray
        // Outer loop to consider each starting point of the subarray
        for (int i = 0; i < nums.size(); i++) {
            int len = 0;    // Current length of the subarray
            int zeros = 0;  // Count of zeros in the current subarray
            // Inner loop to expand the subarray from the starting point i
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == 0) {
                    zeros++;  // Increment count of zeros if the current element is 0
                }
                if (zeros <= k) {  // Check if the number of zeros is within the allowed limit
                    len = j - i + 1;  // Update the current length of the subarray
                    maxlen = max(len, maxlen);  // Update the maximum length found so far
                } else {
                    break;  // If number of zeros exceeds k, break out of the inner loop
                }
            }
        }
        return maxlen;  // Return the maximum length of subarray found
    }
};



        // more optimized using sliding window
        //time complexity: O(N)
        //space complexity: O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;    // Left boundary of the sliding window
        int right = 0;   // Right boundary of the sliding window
        int maxlen = 0;  // Maximum length of subarray with at most k zeros
        int zeros = 0;   // Count of zeros in the current window
        
        // Iterate through the array with the right pointer
        while (right < nums.size()) {
            // If the current element is zero, increment the zero count
            if (nums[right] == 0) {
                zeros++;
            }
            
            // If the number of zeros exceeds k, shrink the window from the left
            while (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;  // Decrement the zero count as we move the left pointer
                }
                left++;  // Move the left boundary of the window to the right
            }
            
            // Update the maximum length of the subarray
            maxlen = max(maxlen, right - left + 1);
            
            // Move the right boundary of the window to the right
            right++;
        }
        
        return maxlen;  // Return the maximum length of the valid subarray found
    }
};




                //**********************************************************************

class Solution {
public:
    /**
     * @brief Finds the length of the longest substring with at most k character replacements.
     * 
     * This function calculates the maximum length of a substring in which we can replace
     * at most 'k' characters to make all characters in the substring the same.
     * 
     * @param s The input string consisting of uppercase English letters.
     * @param k The maximum number of character replacements allowed.
     * @return int The length of the longest valid substring.
     */
    int characterReplacement(string s, int k) {
        int n = s.length(); // Length of the input string
        int maxi = 0; // To store the maximum length of the valid substring

        // Outer loop to consider each character as the starting point of the substring
        for (int i = 0; i < n; i++) {
            int maxLen = 0; // To store the count of the most frequent character in the current window
            int changes = 0; // To keep track of the number of changes needed
            int hash[26] = {0}; // Frequency array to count occurrences of each character in the current window

            // Inner loop to extend the substring from the starting point 'i'
            for (int j = i; j < n; j++) {
                hash[s[j] - 'A']++; // Increment the count of the current character in the hash array
                maxLen = max(maxLen, hash[s[j] - 'A']); // Update the maxLen with the highest frequency in the current window
                changes = (j - i + 1) - maxLen; // Calculate the number of changes needed

                // Check if the number of changes needed is within the allowed limit 'k'
                if (changes <= k) {
                    maxi = max(maxi, j - i + 1); // Update the maximum length of the valid substring
                } else {
                    break; // If changes exceed 'k', break out of the inner loop
                }
            }
        }

        return maxi; // Return the maximum length of the valid substring found
    }
};


                //more optimized code using sliding window

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        if (n == 0) return 0;

        int maxCount = 0; // This keeps track of the count of the most frequent character in the current window
        int maxLength = 0; // This keeps track of the maximum length of valid substring
        int left = 0; // Left pointer of the window
        int count[26] = {0}; // Array to keep count of each character in the window

        for (int right = 0; right < n; ++right) {
            count[s[right] - 'A']++; // Include the current character in the window
            maxCount = max(maxCount, count[s[right] - 'A']); // Update the count of the most frequent character

            // Check if the current window is valid
            if ((right - left + 1) - maxCount > k) {
                // If it's not valid, move the left pointer to make it valid
                count[s[left] - 'A']--;
                left++;
            }

            // Update the maximum length of the valid window
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
