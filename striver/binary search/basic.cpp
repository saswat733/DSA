
//program for finding the ele in rotated sorted array
#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
//recursive way for binary search
int binarySearch(vector<int> arr,int low,int high,int target){
    if(low>high){
        return -1;
    }
    int mid=low+(high-low)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
        return binarySearch(arr,low,mid-1,target);
    }
    else{
       return binarySearch(arr,mid+1,high,target);
    }
}


//implementing lower bound
// Function to find the lower bound of a given value x in a sorted array arr
int lowerBound(vector<int> arr, int n, int x) {
    // Initialize start and end indices for binary search
	int start = 0;
    int end = n - 1;
    
    // Initialize ans to n in case x is smaller than all elements in arr
    int ans = n;

    // Perform binary search
    while (start <= end) {
        // Calculate mid index
        int mid = start + (end - start) / 2;
        
        // If current element is greater than or equal to x, update ans and search in the left half
        if (arr[mid] >= x) {
            ans = mid;
            end = mid - 1;
        } 
        // If current element is less than x, search in the right half
        else {
            start = mid + 1;
        }
    }
    
    // Return the lower bound index
    return ans;
}

//using stl
#include<iostream>
#include<algorithm>
int lowerBound(vector<int> arr, int n, int x) {
	 return lower_bound(arr.begin(), arr.end(), x) - arr.begin();
}


//implementing upper bound
int upperBound(vector<int> &arr, int x, int n){
	int start=0;
    int end=n-1;
    int ans=n;
    while(start<=end){
        int mid=start+(end-start)/2;
       if(arr[mid]>x){
		   ans=mid;
		   end=mid-1;
	   }
	   else{
		   start=mid+1;
	   }
    }
    return ans;	
}


//serach for the index of missing value 
int searchInsert(vector<int>& arr, int x)
{
	int start=0;
	int end=arr.size()-1;
	int ans=arr.size();
	 while (start <= end) {
        // Calculate the middle index
        int mid = start + (end - start) / 2;
        
        // If the middle element is greater than or equal to x
        if (arr[mid] >= x) {
            // Update ans to the current middle index
            ans = mid;
            // Move the end pointer to mid - 1 to search in the left half
            end = mid - 1;
        } else {
            // If the middle element is smaller than x,
            // move the start pointer to mid + 1 to search in the right half
            start = mid + 1;
        }
    }

    // Return the lower bound index of x
    return ans;
}


//finding the floor and ceil
/*
Input: 
n=6, x=5, a=[3, 4, 7, 8, 8, 10]   

Output:
4

Explanation:
The floor and ceiling of 'x' = 5 are 4 and 7, respectively.
*/
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    int start = 0;
    int end = n - 1;
    int floor = -1; // Initialize floor to -1
    int ceil = -1;  // Initialize ceil to -1

    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (a[mid] == x) {
            floor = ceil = a[mid]; // If a[mid] is equal to x, it is both the floor and ceil
            break;
        } else if (a[mid] < x) {
            floor = a[mid]; // Update floor to the current element
            start = mid + 1; // Move to the right half
        } else {
            ceil = a[mid]; // Update ceil to the current element
            end = mid - 1; // Move to the left half
        }
    }

    // If floor or ceil is not found, update them accordingly
    
    return {floor, ceil};
}


//finding the first and last occurence of an ele
#include<bits/stdc++.h>

int firstOccurence(vector<int> arr,int n,int k){
    int start=0;
    int end=arr.size()-1;
   
    int first=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==k){
            first=mid;
            end=mid-1;
        }
        else if(arr[mid]>k){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return first;
}
int lastOccurence(vector<int> arr,int n,int k){
    int start=0;
    int end=arr.size()-1;
    int last=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==k){
            last=mid;
            start=mid+1;
        }
        else if(arr[mid]>k){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first=firstOccurence(arr,n,k);
    int last=lastOccurence(arr,n,k);

    if(first==-1){
        return {-1,-1};
    }

    return {first,last};
}


int findPosition(vector<int>& arr, int n, int k)
{
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]==k){
            return mid;
        }
        
        if(arr[low]<=arr[mid]){
            if(arr[low]<=k && k<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[high]>=k && arr[mid]<=k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}


int main(){
    vector<int> arr{12, 15, 18, 2, 4};
    int ans=findPosition(arr,5,2);
    cout<<ans;
}

