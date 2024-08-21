#include <string>
#include <climits> // for INT_MAX and INT_MIN
using namespace std;

//string to integer (atoi)
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long ans = 0; // Use long long to handle potential overflow

        // Skip leading whitespace
        while (i < s.length() && s[i] == ' ')
            i++;

        // Handle optional sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert characters to integer
        while (i < s.length() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // Check for overflow
            if (ans * sign > INT_MAX)
                return INT_MAX;
            if (ans * sign < INT_MIN)
                return INT_MIN;

            i++;
        }

        return ans * sign;
    }
};



//******************************************************************* */

//50. pow(x,n)
class Solution {
public:
    double myPow(double x, int n) {
        // Initialize the answer to 1.0
        double ans = 1.0;

        // Use long long to handle negative n, particularly INT_MIN case
        long long nn = n;

        // If the exponent is negative, convert it to positive for calculation
        if (nn < 0) {
            nn = -nn;
        }

        // Exponentiation by Squaring
        while (nn) {
            // If nn is odd, multiply the current base to the answer
            if (nn % 2) {
                ans *= x;
                nn = nn - 1;  // Reduce the exponent by 1
            }
            else {
                // If nn is even, square the base and halve the exponent
                x = x * x;
                nn = nn / 2;
            }
        }

        // If the original exponent was negative, take the reciprocal of the result
        if (n < 0) {
            ans = 1.0 / ans;
        }

        // Return the final computed power
        return ans;
    }
};



/**************************************************** */
// 1922.count good numbers
class Solution {
private:
    // Helper function to compute power using Exponentiation by Squaring
    long pow(long base, long exp) {
        long ans = 1;
        const long MOD = 1000000007; // Modulus value
        
        // Exponentiation by squaring with modulus
        while (exp) {
            if (exp % 2) { // If exponent is odd
                ans = (ans * base) % MOD; // Multiply the base and apply modulus
                exp = exp - 1;
            } else { // If exponent is even
                base = (base * base) % MOD; // Square the base and apply modulus
                exp = exp / 2;
            }
        }
        return ans;
    }
    
public:
    int countGoodNumbers(long long n) {
        // Calculate the number of even and odd positions
        long even = (n + 1) / 2; // Number of even-indexed positions
        long odd = n / 2;        // Number of odd-indexed positions
        
        // Calculate the number of valid digits for even and odd positions
        long first = pow(5, even) % 1000000007;
        long second = pow(4, odd) % 1000000007;
        
        // Calculate the final answer, applying modulus to prevent overflow
        long ans = (first * second) % 1000000007;
        
        return (int)ans;
    }
};



