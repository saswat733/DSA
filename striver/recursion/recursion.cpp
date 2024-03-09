#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

//Reverse an array
//we can also reverse an array using single variable using n and i ====> last digit(n-i-1) and for first digit(i=0) then swap them

//using 2 variable
vector<int> rever(int n,vector<int> &nums,vector<int> &ans){
    if(n==0){
        return ans;
    }

    ans.push_back(nums[n-1]);
    return rever(n-1,nums,ans);
}

vector<int> reverseArray(int n, vector<int> &nums)
{
    // Write your code here.
    vector<int> ans;
    rever(n,nums,ans);
    return ans;

}



//factorial of a number

int factorial_of_number(int n){            
    int ans=1;
    if(n==0){
        return 1;
    }

    return factorial_of_number(n-1)*n;
}



// check for palindrome

string rev(string &str,int start,int end){
    if(start>=end){
        return str;
    }

    swap(str[start],str[end]);
    // cout<<str<<endl;
    return rev(str,start+1,end-1);
}

bool isPalindrome(string& str) {
    // Write your code here.
    string real=str;
    string ans=rev(str,0,str.length()-1);
   
    if(ans==real){
        return true;
    }

    return false;
   
}


//program to print fibbonacci seriess
/*
Generate Fibonacci numbers recursively. Base case: n <= 0, return result. Append sum to result, update a to b and b to a + b. Recur with n - 1 and updated a, b, and sum. Return result.
*/
vector<int> generate(int n,int a,int b,vector<int> &result,int sum){
    if(n<=0){
        return result;
    }

    result.push_back(sum);
    return generate(n-1, b, a+b,result, b);
}

vector<int> generateFibonacciNumbers(int n) {
    // Write your code here.
    int a=0;
    int b=1;
    vector<int> result;
    result=generate(n,a,b,result,a);
    return result;

}



// Function to generate all subsets of an array
void generateSubset(int index, vector<int>& result, const vector<int>& arr, int n) {
    if (index == n) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }

    // Include the current element and generate subsets
    result.push_back(arr[index]);
    generateSubset(index + 1, result, arr, n);

    // Exclude the current element and generate subsets
    result.pop_back();
    generateSubset(index + 1, result, arr, n);
}


//  Problem statement:

// You are given an array 'nums' of ‘n’ integers.




vector<int> subsetSums(vector<int>& nums) {
    vector<int> result;
    generateSubsetSums(0, 0, nums, result);
    
    // Sort the subset sums in non-decreasing order
    sort(result.begin(), result.end());
    
    
    return result;
}


// Print all Sub sequence which sums to K
void sum_equal_k(int n,int sum,int s,vector<int> &nums,vector<int> &arr,int i){
    if(i==n){
        if(s==sum){
            for(auto i:nums){
                cout<<i<<" ";
            }
            cout<<endl;
        }
            return;
    }

    nums.push_back(arr[i]);
    s+=arr[i];
    sum_equal_k(n,sum,s,nums,arr,i+1);

    s-=arr[i];
    nums.pop_back();
    sum_equal_k(n,sum,s,nums,arr,i+1);
}


// Print only one Sub sequence which sums to K
bool first_sum_equal_K(int n,int sum,int s,vector<int> &result,vector<int> &nums,int i){
    if(i==n){
       if(s==sum){
         for(auto i:result){
            cout<<i<<" ";
        }
        cout<<endl;
        return true;
       }
       else return false;
    }

    result.push_back(nums[i]);
    s+=nums[i];
    if(first_sum_equal_K(n,sum,s,result,nums,i+1)==true){
        return true;
    };
    
    s-=nums[i];
    result.pop_back();
    if(first_sum_equal_K(n,sum,s,result,nums,i+1)==true){
        return true;
    };

    return false;

}

//print the count of sums of subsequence
//time complexity is O(n)
int count_subsequences(int index,int sum,int s,vector<int> nums){
    if(index==nums.size()){
        if(s==sum){
            return 1;
        }
        else{
            return 0;
        }
    }

    s+= nums[index];
    int l=count_subsequences(index+1,sum,s,nums);

    s-=nums[index];
    int r=count_subsequences(index+1,sum,s,nums);
    return l+r;
}


//merge sort time complexity:O(nlogn)  space complexity:O(n)


void mergehai(vector<int> &arr, int start, int end, int mid) {
    int n1 = mid - start + 1;

    int n2 = end - mid;
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);
    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = start; // Corrected k to start
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k++] = leftArray[i++];
        } else {
            arr[k++] = rightArray[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArray[i++];
    }
    while (j < n2) {
        arr[k++] = rightArray[j++];
    }
}

void mergeSor(vector<int> &arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2; 
        mergeSor(arr, start, mid); 
        mergeSor(arr, mid + 1, end); 
        mergehai(arr, start, end, mid);
    }
}

void mergeSort(vector<int> &arr, int n) {
    mergeSor(arr, 0, n - 1);
}


// Return all subset sums of 'nums' in a non-decreasing order.
void generateSubsetSums(int index, int sum, const vector<int>& nums, vector<int>& subsetSums) {
    if (index == nums.size()) {
        subsetSums.push_back(sum);
        return;
    }

    // Include the current element and generate subsets
    generateSubsetSums(index + 1, sum + nums[index], nums, subsetSums);

    // Exclude the current element and generate subsets
    generateSubsetSums(index + 1, sum, nums, subsetSums);
}



int main() {
    vector<int> arr{1,2,3,4,5};
   generateSubsetSums(0,0,nums,subsetSums)
    cout << endl;
    return 0;
}
