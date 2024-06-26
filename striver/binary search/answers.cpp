#include<bits/stdc++.h>
#include<math.h>
using namespace std;
//finding the square root of a given number
//time complexity:O(log(m+n))
int floorSqrt(int n) {
    // Initialize variables for the search range
    int low = 0;
    int high = n - 1;
    
    // Binary search loop to find the integer square root
    while (low <= high) {
        // Calculate the middle index
        int mid = (low + high) / 2;
        
        // Calculate the square of the middle index
        long long val = mid * mid;

        // Check if the square of the middle index is less than or equal to the target number
        if (val <= n) {
            // If yes, update the lower bound of the search range
            // to search for a larger candidate
            low = mid + 1;
        } else {
            // If no, update the upper bound of the search range
            // to search for a smaller candidate
            high = mid - 1;
        }
    }

    // high represents the largest integer mid such that mid * mid is less than or equal to n
    // Since we are looking for the floor square root, we return high
    return high;
}


//***************************************************************************
//finding nth root of a number
// This function calculates the power of 'mid' raised to 'n' and compares it with 'm'.
// It returns:
//   - 1 if 'mid' raised to 'n' equals 'm'.
//   - 0 if 'mid' raised to 'n' is less than 'm'.
//   - 2 if 'mid' raised to 'n' is greater than 'm'.
int power(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans = ans * mid;
        if (ans > m) {
            return 2;
        }
    }
    if (ans == m) {
        return 1;
    }
    return 0;
}

// This function calculates the nth root of 'm' using binary search.
int NthRoot(int n, int m) {
    int low = 0;
    int high = m - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Calculate the power of 'mid' raised to 'n' and compare it with 'm'.
        int val = power(mid, n, m);

        // If 'mid' raised to 'n' equals 'm', return 'mid' as the nth root of 'm'.
        if (val == 1) {
            return mid;
        }

        // If 'mid' raised to 'n' is less than 'm', search for a larger 'mid'.
        if (val == 0) {
            low = mid + 1;
        } else { // If 'mid' raised to 'n' is greater than 'm', search for a smaller 'mid'.
            high = mid - 1;
        }
    }

    // If the nth root of 'm' is not found, return -1.
    return -1;
}


//***********************************************************
//maximum banana person can eat in given hours
#include<bits/stdc++.h> // This line includes all standard C++ libraries.
#include<iostream> // This line includes the iostream library.

// This function finds the maximum element in a vector.
int findMax(vector<int> &v) {
    int maxi = INT_MIN; // Initialize the maximum value to the minimum possible integer value.
    int n = v.size(); // Get the size of the vector.
    for (int i = 0; i < n; i++) { // Iterate through the elements of the vector.
        maxi = max(maxi, v[i]); // Update the maximum value if the current element is greater.
    }
    return maxi; // Return the maximum value.
}

// This function calculates the total hours required to eat all bananas at a given rate.
int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0; // Initialize the total hours to 0.
    int n = v.size(); // Get the size of the vector.
    for (int i = 0; i < n; i++) { // Iterate through the elements of the vector.
        totalH += ceil((double)v[i] / (double)hourly); // Calculate the total hours required to eat all bananas.
    }
    return totalH; // Return the total hours.
}

// This function finds the minimum rate at which a person can eat bananas.
int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1; // Initialize the lower bound of the binary search.
    int high = findMax(v); // Initialize the upper bound of the binary search using the maximum element in the vector.
    while (low <= high) { // Perform binary search until the lower bound is less than or equal to the upper bound.
        int mid = (low + high) / 2; // Calculate the middle rate.
        int totalH = calculateTotalHours(v, mid); // Calculate the total hours required at the middle rate.
        if (totalH <= h) { // If the total hours is less than or equal to the given hours,
            high = mid - 1; // Update the upper bound to search for a lower rate.
        } else { // Otherwise,
            low = mid + 1; // Update the lower bound to search for a higher rate.
        }
    }
    return low; // Return the minimum rate.
}



//************************************************************************
//roses to make bouke
//time complexity:O(n X log(mini*maxi))

// This function checks if it's possible to pick flowers within 'day' days
// such that at least 'm' bouquets can be formed, each containing at least 'k' flowers.
bool possible(vector<int> arr, int day, int k, int m) {
    int count = 0;
    int noBouke = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= day) {
            count++;
        } else {
            noBouke += (count / k);
            count = 0;
        }
    }
    noBouke += (count / k);
    return noBouke >= m;
}

// This function calculates the minimum number of days required to pick flowers
// such that each bouquet contains at least 'k' flowers and there are at least 'm' bouquets.
int roseGarden(vector<int> arr, int k, int m) {
    long long val = m * k;
    if (val > arr.size()) {
        return -1;
    }
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    int low = mini, high = maxi;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (possible(arr, mid, k, m)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}


//****************************************************************
//smallest divisor

//brute force solution
#include <vector>
#include <cmath> // for ceil
#include <climits> // for INT_MAX
#include <algorithm> // for min
int answer(vector<int>& arr, int ele) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += ceil((double)arr[i] / ele);
    }
    return sum;
}

int smallestDivisor(vector<int>& arr, int limit) {
    int smallest = INT_MAX;
    for (int i = 1; i <= *max_element(arr.begin(), arr.end()); i++) {
        int sum = answer(arr, i);
        if (sum <= limit) {
            smallest = min(smallest, i);
        }
    }
    return smallest;
}

//optimised using binary search
#include <vector>
#include <cmath> // for ceil
#include <climits> // for INT_MAX
#include <algorithm> // for max

using namespace std;

int answer(vector<int> arr, int ele) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        int a = ceil((double)arr[i] / ele); // Cast to double to ensure correct division
        sum += a;
    }
    return sum;
}

int smallestDivisor(vector<int>& arr, int limit) {
    int mini = 1, maxi = INT_MIN; 
    for (int i = 0; i < arr.size(); i++) {
        maxi = max(maxi, arr[i]);
    }
    int low = mini;
    int high = maxi;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (answer(arr, mid) <= limit) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}



//**********************************************************
//least capacity to ship packages in D days
#include <vector>
#include <algorithm>

using namespace std;

int fun(vector<int> weights, int cap) {
    int days = 1;
    int load = 0;
    for (int i = 0; i < weights.size(); i++) {
        if (load + weights[i] > cap) {
            days = days + 1;
            load = weights[i];
        } else {
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int>& weights, int d) {
    int sum = 0;
    for (int i = 0; i < weights.size(); i++) {
        sum += weights[i];
    }
    int leastCap = INT_MAX;

    for (int i = 1; i <= sum; i++) {
        int daysRequired = fun(weights, i);
        if (daysRequired <= d) {
            leastCap = min(leastCap, i);
        }
    }
    return (leastCap == INT_MAX) ? -1 : leastCap;
}

//better approach using binary search
// This function calculates the number of days required to ship all the weights
// given a maximum capacity per day.
int fun(vector<int> weights, int cap) {
    int days = 1; // Initialize the number of days to 1.
    int load = 0; // Initialize the current load to 0.

    // Iterate over each weight.
    for (int i = 0; i < weights.size(); i++) {
        // If adding the current weight exceeds the capacity,
        if (load + weights[i] > cap) {
            days = days + 1; // Increment the number of days required.
            load = weights[i]; // Reset the load to the current weight.
        } else {
            load += weights[i]; // Add the current weight to the load.
        }
    }
    return days; // Return the total number of days required.
}

// This function finds the minimum weight capacity required to ship all the weights
// in 'd' days.
int leastWeightCapacity(vector<int>& weights, int d) {
    // Find the lowest possible weight capacity, which is the maximum weight
    // among the weights.
    int low = *max_element(weights.begin(), weights.end());

    // Find the highest possible weight capacity, which is the sum of all weights.
    int high = accumulate(weights.begin(), weights.end(), 0);

    // Perform binary search to find the minimum weight capacity.
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate the mid-point of the range.

        // Calculate the number of days required for the current mid-point capacity.
        int numberOfDays = fun(weights, mid);

        // If the number of days required is less than or equal to the target days,
        if (numberOfDays <= d) {
            high = mid - 1; // Update the upper bound of the range to search the left half.
        } else {
            low = mid + 1; // Update the lower bound of the range to search the right half.
        }
    }

    return low; // Return the minimum weight capacity found.
}


//********************************************************************
//k'th missing positive integer

int missingK(vector<int> vec, int n, int k) {
    // Initialize variables to represent the lower and upper bounds of the search range
    int low = 0, high = n - 1;
    
    // Binary search loop
    while (low <= high) {
        // Calculate the middle index of the current range
        int mid = (low + high) / 2;
        
        // Calculate the number of missing elements up to index 'mid'
        int missing = vec[mid] - (mid + 1);
        
        // If the number of missing elements up to 'mid' is less than 'k'
        if (missing < k) {
            // Update the lower bound of the search range
            low = mid + 1;
        } 
        // If the number of missing elements up to 'mid' is greater than or equal to 'k'
        else {
            // Update the upper bound of the search range
            high = mid - 1;
        }
    }
    // Return the k-th missing element
    return low + k;
}

//*******************************************************


//aggresive cows problem


#include<bits/stdc++.h>

// Function to check if we can place cows with a minimum distance 'dist' between them
bool canwePlace(vector<int> &stalls, int dist, int cows) {
    int cntCows = 1;  // Number of cows placed
    int last = stalls[0];  // Position of the last placed cow
    for (int i = 1; i < stalls.size(); i++) {
        // If the distance between the current stall and the last placed cow is greater than or equal to 'dist'
        if (stalls[i] - last >= dist) {
            cntCows++;  // Place a cow
            last = stalls[i];  // Update the position of the last placed cow
        }
        // If the required number of cows is placed
        if (cntCows >= cows)
            return true;  // We can place the cows
    }
    return false;  // We can't place the cows
}

// Function to find the maximum possible minimum distance such that 'k' cows can be placed
int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());  // Sort the stalls in ascending order
    int n = stalls.size();  // Number of stalls
    int low = 1, high = stalls[n - 1] - stalls[0];  // Initialize the search space
    while (low <= high) {
        int mid = (low + high) / 2;  // Calculate the middle distance
        // If we can place the cows with the current minimum distance
        if (canwePlace(stalls, mid, k) == true) {
            low = mid + 1;  // Update the lower bound of the search space
        } else {
            high = mid - 1;  // Update the upper bound of the search space
        }
    }
    return high;  // Return the maximum possible minimum distance
}


//**********************************************************************
//book allocation problem


int countStudents(vector<int> arr, int pages) {
    int students = 1; // Initialize the number of students to 1
    long long pagesStudent = 0; // Initialize the number of pages read by the current student to 0

    // Iterate through the array of pages
    for (int i = 0; i < arr.size(); i++) {
        // If adding the current book's pages to the pages read by the current student does not exceed the maximum pages allowed,
        // add the pages to the current student's count
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        } 
        // If adding the current book's pages exceeds the maximum pages allowed,
        // increment the number of students and reset the pages read by the current student to the current book's pages
        else {
            students += 1;
            pagesStudent = arr[i];
        }
    }
    return students; // Return the total number of students required
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) {
        return -1; // If the number of students is greater than the number of books, return -1 (invalid input)
    }

    // Find the range of pages such that each student can be assigned at least one book
    int low = *max_element(arr.begin(), arr.end()); // Minimum possible number of pages assigned to a student is the maximum number of pages in any book
    int high = accumulate(arr.begin(), arr.end(), 0); // Maximum possible number of pages assigned to a student is the sum of all pages in all books

    // Perform binary search within the range of possible pages
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate the mid-point of the range
        int students = countStudents(arr, mid); // Count the number of students required to read books with maximum pages as mid

        // If the number of students required is greater than the given number of students (m),
        // increase the minimum pages per student to mid+1
        if (students > m) {
            low = mid + 1;
        } 
        // If the number of students required is less than or equal to the given number of students (m),
        // reduce the maximum pages per student to mid-1
        else {
            high = mid - 1;
        }
    }
    return low; // Return the minimum number of pages per student that satisfies the condition
}


//*****************************************************
// largest subarray sum minimized

#include<bits/stdc++.h>

//function for getting the number of students who got allocated slabs
int func(vector<int> a,int pages){
    int ans=1;
    int startSum=0;
    for(int i=0;i<a.size();i++){
        if(startSum+a[i]<=pages){
            startSum+=a[i];
        }
        else{
            ans++;
            startSum=a[i];
        }
    }
    return ans;
}

//check for whether the number of students matches the give constraint
int largestSubarraySumMinimized(vector<int> a, int k) {
    if(k>a.size()){
        return -1;
    }

    int low=*max_element(a.begin(),a.end());
    int high=accumulate(a.begin(),a.end(),0);

    while(low<=high){
        int mid=(low+high)/2;
        int ans=func(a,mid);
        if(ans>k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}


//********************************************************
// Minimize the max distance to substation

//brute force
double minimiseMaxDistance(vector<int> &arr, int k) {
  int n = arr.size();
  vector<int> howMany(n - 1, 0);
  for (int gasStations = 1; gasStations <= k; gasStations++) {
    long double maxSection = -1;
    int maxInd = -1;
    for (int i = 0; i < n - 1; i++) {
      long double diff = (arr[i + 1] - arr[i - 1]);
      long double sectionLength = diff / ((long double)(howMany[i] + 1));
      if (sectionLength > maxSection) {
        maxSection = sectionLength;
        maxInd = i;
      }
    }
    howMany[maxInd]++;
  }
  long double maxAns = -1;
  for (int i = 0; i < n - 1; i++) {
    long double diff = (arr[i + 1] - arr[i]);
    long double sectionLength = diff / (long double)(howMany[i] + 1);
    maxAns = max(maxAns, sectionLength);
  }

  return maxAns;
}

//************88888888*************************************
//find the median of two sorted array
double median(vector<int>& a, vector<int>& b) {
    // Initialize variables
    vector<int> arr3;
    int n1=a.size();
    int n2=b.size();
    int n=(n1+n2);
    int i=0,j=0; // Initialize indices for arrays a and b
    int ind2=n/2;
    int ind1=ind2-1;
    int cnt=0; // Counter to track the number of elements processed
    int ind1el=-1,ind2el=-1; // Initialize elements at indices ind1 and ind2

    // Merge arrays and find elements contributing to median
    while(i<n1 && j<n2){
        if(a[i]<b[j]){ // If element in a is smaller
            if(cnt==ind1){ // If it's at the position of ind1
                ind1el=a[i]; // Update ind1el
            }
            if(cnt==ind2){ // If it's at the position of ind2
                ind2el=a[i]; // Update ind2el
            }
            cnt++; // Increment the counter
            i++; // Move to the next element in array a
        }
        else{ // If element in b is smaller or equal
            if(cnt==ind1){ // If it's at the position of ind1
                ind1el=b[j]; // Update ind1el
            }
            if(cnt==ind2){ // If it's at the position of ind2
                ind2el=b[j]; // Update ind2el
            }
            cnt++; // Increment the counter
            j++; // Move to the next element in array b
        }
    }

    // Handle remaining elements in array a
    while(i<n1){
        if(cnt==ind1){ // If current position is ind1
            ind1el=a[i]; // Update ind1el
        }
        if(cnt==ind2){ // If current position is ind2
            ind2el=a[i]; // Update ind2el
        }
        cnt++; // Increment the counter
        i++; // Move to the next element in array a
    }

    // Handle remaining elements in array b
    while(j<n2){
        if(cnt==ind1){ // If current position is ind1
            ind1el=b[j]; // Update ind1el
        }
        if(cnt==ind2){ // If current position is ind2
            ind2el=b[j]; // Update ind2el
        }
        cnt++; // Increment the counter
        j++; // Move to the next element in array b
    }

    // Determine and return median
    if(n%2==1){ // If total number of elements is odd
        return ind2el; // Median is the element at position ind2
    }
    // If total number of elements is even, median is average of elements at ind1 and ind2
    return (double)(ind2el+ind1el)/2.0;
}


int main(){
    vector<int> arr{8 ,4 ,2,3 };
    int ans=smallestDivisor(arr,10);
}