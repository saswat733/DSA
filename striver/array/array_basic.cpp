#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// function to get the largest element it is the brute force approach having O(nlogn) TC
void sort_array(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int largestElement(vector<int> &arr, int n)
{
    sort_array(arr, n);
    return arr[n - 1];
}

// optimised way having time complexity of O(n)

int largestElementt(vector<int> &arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// function to get second largest and second smallest element its time complexity is O(nlogn) it is brute fore approach
void sortArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        swap(arr[mini], arr[i]);
    }
    // return arr;
}
vector<int> getSecondOrderElements(int n, vector<int> a)
{
    sortArray(a);
    vector<int> result;
    result.push_back(a[n - 2]);
    result.push_back(a[1]);
    return result;
}

// more optimised solution for finding the second largest and second smallest elements in O(2n)
int secondLargest(int n, vector<int> a)
{
    int max = a[0];
    int smax = INT_MIN; // Initialize with a value smaller than any element

    for (int i = 1; i < n; i++)
    { // Start from i = 1
        if (a[i] > max)
        {
            smax = max;
            max = a[i];
        }
        else if (a[i] > smax && a[i] != max)
        {
            smax = a[i];
        }
    }
    return smax;
}

int secondSmallest(int n, vector<int> a)
{

    int small = INT_MAX;  // Initialize with a large value
    int Ssmall = INT_MAX; // Initialize with a large value
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < small)
        {
            Ssmall = small;
            small = a[i];
        }
        else if (a[i] < Ssmall && a[i] != small)
        {
            Ssmall = a[i];
        }
    }
    return Ssmall;
}

vector<int> getSecondOrderElement(int n, vector<int> a)
{
    int sLargest = secondLargest(n, a);
    int sSmallest = secondSmallest(n, a);

    return {sLargest, sSmallest};
}

// program to check whether array is sorted or not
int isSorted(int n, vector<int> arr)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

// brute force for this problem is storing the elements in stack and if the top element of stack is same to the element going to be inserted we move ahead
// program to remove duplicate from arrays and give the count of new array
int removeDuplicates(vector<int> &arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            count++;
        }
    }
    return count;
}

// left rotating aan array by 1
#include <bits/stdc++.h>
// brute force  time complexity:O(n) and space complexity:O(1)
void left_rotate1(vector<int> &arr, int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

// best solution
vector<int> rotateArray(vector<int> &arr, int n)
{
    reverse(arr.begin(), arr.begin() + 1);
    reverse(arr.begin() + 1, arr.end());
    reverse(arr.begin(), arr.end());
    return arr;
}

// left rotating the array by d places

// brute force approach
vector<int> rotate_arrayD(vector<int> arr, int k)
{
    vector<int> ans;
    int n = arr.size();
    for (int i = n - k; i < n; i++)
    {
        ans.push_back(arr[i]);
    }
    for (int i = 0; i < k; i++)
    {
        ans.push_back(arr[i]);
    }

    return ans;
}

vector<int> rotateArray(vector<int> arr, int k)
{
    int size = arr.size();
    k = k % size; // Adjust k in case it's greater than the array size

    reverse(arr.begin() + k, arr.end());   // Reverse the remaining elements
    reverse(arr.begin(), arr.begin() + k); // Reverse the first k elements
    reverse(arr.begin(), arr.end());       // Reverse the whole array

    return arr;
}

// move all zeros to end

// best
vector<int> moveZeroToEnd(vector<int> a, int n)
{
    // Initialize a variable j to keep track of the position of the first zero encountered
    int j = -1;

    // Iterate through the array to find the first zero
    for (int i = 0; i < n; i++)
    {
        // If a zero is found
        if (a[i] == 0)
        {
            // Update the position of the first zero encountered and break the loop
            j = i;
            break;
        }
    }

    // If no zero is found, return the array as it is (no need to move zeros)
    if (j == -1)
    {
        return a;
    }

    // Iterate through the array starting from the position after the first zero
    for (int i = j + 1; j < n; j++)
    {
        // If a non-zero element is found
        if (a[i] != 0)
        {
            // Swap the non-zero element with the first zero encountered
            swap(a[i], a[j]);
        }
    }

    // Return the modified array with zeros moved to the end
    return a;
}

// bbrute force
vector<int> moveZeros(int n, vector<int> a)
{
    int count = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            count++;
        }
        else
        {
            ans.push_back(a[i]);
        }
    }
    while (count > 0)
    {
        ans.push_back(0);
        count--;
    }

    return ans;
}

// linear search for the idex of element
int linearSearch(int n, int num, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

// merge two sorted array in sorted form
// brute force
vector<int> sortedArray(vector<int> a, vector<int> b)
{
    vector<int> result;
    for (int i = 0; i < a.size(); i++)
    {
        result.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        result.push_back(b[i]);
    }
    sort(result.begin(), result.end());
    vector<int> ans;
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] != result[i + 1])
        {
            ans.push_back(result[i]);
        }
    }

    return ans;
}

// best approach
vector<int> merge_sortedArray(vector<int> a, vector<int> b)
{
    vector<int> ans;
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (ans.size() == 0 || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < n1)
    {
        if (ans.back() != a[i] || ans.size() == 0)
        {
            ans.push_back(a[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (ans.back() != b[j] || ans.size() == 0)
        {
            ans.push_back(b[j]);
        }
        j++;
    }
    return ans;
}


//find the number that appears once and other numbers twice         

//best case using hashing
// TC:O(n) in worst and best case for unorderd map
void getSingleElement(vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        ans[arr[i]]++;
    }

    for (auto i : ans)
    {
        if (i.second == 1)
        {
            cout << i.first;
        }
    }
}

//optimal solution using xor
int getSingleElementt(vector<int> &arr){
    int xor1=0;
    for(int i=0;i<arr.size();i++){
        xor1=arr[i]^xor1;
    }

    return xor1;
}


// intersection of two sorted array
vector<int> intersectTwoSortedArray(vector<int> a, vector<int> b)
{
    int i = 0;
    int j = 0;
    int n1 = a.size();
    int n2 = b.size();
    vector<int> ans;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}



//find the missing number in consecutive numbers

//optimal solution using hash
int missingNumber(vector<int>& a, int N) {
    int arr[N + 1] = {0}; // Initialize array with size N + 1 and all elements to 0
    for(int i = 0; i < N; i++) {
        arr[a[i]] += 1; // Increment count at index a[i] in arr
    }

    for(int i = 1; i <= N; i++) { // Start from index 1 since numbers start from 1
        if(arr[i] == 0) {
            return i; // Return the missing number
        }
    }

    return -1; // If no missing number found, return -1
}

//best solution
int missingNumberr(vector<int>& a, int N) {
    int sum=(N*(N+1))/2;
    int actualsum=0;
    for(int i=0;i<N-1;i++){
        actualsum=actualsum+a[i];
    }
    cout<<actualsum<<endl;

    return sum-actualsum;
}

//bestest solution using xor
int missingNumberrr(vector<int>& a,int N){
    int xor1=0;
    int xor2=0;
    int n=N-1;
    for(int i=1;i<n;i++){
        xor2=xor2^a[i];
        xor1=xor1^(i+1);
    }
   xor1=xor1^N;
    return xor1^xor2;

}



//finding the maximum consecutive ones
// ARR = [0, 1, 1, 0, 0, 1, 1, 1], here you can see the maximum length of consecutive 1’s is 3. Hence the answer is 3.
int consecutiveOnes(vector<int>& arr){
    int count=0;
    int ans=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            count++;
            if(count>ans){
                ans=count;
            }
        }
        else{
            count=0;
        }
    }
    if(count>ans){
        return count;
    }
    return ans;
}


#include <iostream>
#include <vector>

using namespace std;
//function for generating subarrays brute force
vector<vector<int>> generateSubarrays(const vector<int>& arr) {
    vector<vector<int>> subarrays;
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> subarray;
            for (int k = i; k <= j; k++) {
                subarray.push_back(arr[k]);
            }
            subarrays.push_back(subarray);
        }
    }
    return subarrays;
}


//longest subarray with sum k

//brute force solution with O(n^3) worst time complexity
int  generateSubarrayss(const vector<int>& arr,int target) {
    int n = arr.size();
    int length=0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> subarray;
            int sum = 0;
            for (int k = i; k <= j; k++) {
                subarray.push_back(arr[k]);
            }
            for (int l = 0; l < subarray.size(); l++) { // Fixed loop condition
                sum = 0; // Initialize sum inside the loop
                for (int m = l; m < subarray.size(); m++) { // Iterate over subarray elements
                    sum += subarray[m];
                    if (sum == target) {
                        if (length < m - l + 1) {
                            length = m - l + 1;
                        }
                    }
                }
            }
        }
    }
    return length;
}


//brute force solution with O(n2) time complexity
int generateSub(const vector<int> arr,int target){
    int n=arr.size();
    int length=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+arr[j];
            if(sum==target){
                if((j-i+1)>length){
                    length=j-i+1;
                }
            }

        }
    }
    return length;
}

//better solution using hash this solution will work in all cases if ther is +ve -ve 0 numbers in array so this can also be considered as most optimal solution
// having time complexity of O(nLogn) is ordered map is used and O(nx O(1)) if unordered map is used

#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    map<long long,int> preSumMap;
    long long sum=0;
    int maxLength=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==k){
            maxLength=max(maxLength,i+1);
        }
        long long rem=sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()){
            int len=i-preSumMap[rem];
            maxLength=max(maxLength,len);

        }
        if(preSumMap.find(sum)==preSumMap.end()){
            preSumMap[sum]=i;
        }
    }
    return maxLength;
}


//best solution if only the 0,+ve numbers are givenr
// time complexity is O(2n)

int longestSubarrayWithSumK(vector<int> arr, long long target) {
    int n=arr.size();
    int length=0;
    int left=0,right=0;
    long long sum=arr[0];
    while(right<n){
        while(sum>target && left<=right){
            sum-=arr[left];
            left++;
        }
        if(sum==target){
            length=max(length,right-left+1);
        }
        right++;
        if(right<n){
            sum=sum+arr[right];
        }
    }
    return length;
}



