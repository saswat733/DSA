

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
int lowerBoundd(vector<int> arr, int n, int x) {
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


//****************************************************************
//program for finding the ele in rotated sorted array
#include <bits/stdc++.h> 
// Include necessary headers for your code

// Function to find the position of an element k in a rotated sorted array arr

int findPosition(vector<int>& arr, int n, int k) {
    // Initialize low and high indices for binary search
    int low = 0, high = n - 1;
    
    // Perform binary search
    while (low <= high) {
        // Calculate mid index
        int mid = low + (high - low) / 2;

        // If k is found at mid, return mid
        if (arr[mid] == k) {
            return mid;
        }
        
        // If left half is sorted
        if (arr[low] <= arr[mid]) {
            // If k lies within the range of the left half, update high
            if (arr[low] <= k && k <= arr[mid]) {
                high = mid - 1;
            } 
            // Otherwise, search in the right half
            else {
                low = mid + 1;
            }
        } 
        // If right half is sorted
        else {
            // If k lies within the range of the right half, update low
            if (arr[high] >= k && arr[mid] <= k) {
                low = mid + 1;
            } 
            // Otherwise, search in the left half
            else {
                high = mid - 1;
            }
        }
    }
    
    // If k is not found, return -1
    return -1;
}


//************************************************************************
//search in rotated sorted array there might be some duplicates
#include <vector>

bool searchInARotatedSortedArrayII(std::vector<int>& arr, int k) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k) {
            return true;
        }

        // Handle duplicates by moving low and high pointers
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            ++low;
            --high;
        } else if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (arr[mid] < k && k <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return false;
}

//***************************************************************************

//find the lowest elemetn from the rotated sorted array
int findMin(vector<int>& arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX; // Initialize ans with maximum possible value

    while (low <= high) {
        // If the current segment is already sorted, return the minimum element
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break; // Found the minimum element
        }

        // Calculate the mid point of the current segment
        int mid = low + (high - low) / 2;

        // If the middle element is less than or equal to the last element of the segment,
        // then the minimum element is in the left half of the segment
        if (arr[mid] <= arr[high]) {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        } else { // If the middle element is greater than the last element of the segment,
                 // then the minimum element is in the right half of the segment
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
    }

    return ans;
}



//******************************************************************************
//program for finding how many time array have been rotated
#include<bits/stdc++.h> // This includes all standard C++ libraries

/*
Input: 'n' = 5 , ‘arr’ = [3, 4, 5, 1, 2]

Output: 3 

Explanation:
If we rotate the array [1 ,2, 3, 4, 5] right '3' times then we will get the 'arr'. Thus 'r' = 3.

*/
int findKRotation(vector<int> &arr){
    int low=0;
    int high=arr.size()-1;
    int ans=INT_MAX; // Initialize ans with maximum possible value
    int index=-1; // Initialize index to -1, indicating no minimum element found yet

    while(low<=high){
        // If the current segment is already sorted, set ans to the minimum of the segment
        if(arr[low]<=arr[high]){
            // If the first element of the segment is less than ans, update ans and index
            if(arr[low]<ans){
                ans=arr[low];
                index=low;
            }
            break; // Found the minimum element, exit the loop
        }

        // Calculate the mid point of the current segment
        int mid=(low+high)/2;

        // If the first half of the segment is sorted
        if(arr[low]<=arr[mid]){
            // If the first element of the segment is less than ans, update ans and index
            if(arr[low]<ans){
                ans=arr[low];
                index=low;
            }
            low=mid+1; // Move low pointer to the right half
        }
        else{ // If the second half of the segment is sorted
            // If the middle element of the segment is less than ans, update ans and index
            if(arr[mid]<ans){
                ans=arr[mid];
                index=mid;
            }
            high=mid-1; // Move high pointer to the left half
        }
    }
    // Return the index of the minimum element
    return index;
}

//*****************************************************************************

//find the unique element 
int singleNonDuplicate(vector<int>& arr)
{
    int n = arr.size(); // Size of the input array

    // If there's only one element in the array, it must be the non-duplicate
    if(n == 1){
        return arr[0];
    }

    // If the first element is not equal to the second, it's the non-duplicate
    if(arr[0] != arr[1]){
        return arr[0];
    }

    // If the last element is not equal to the second last, it's the non-duplicate
    if(arr[n-1] != arr[n-2]){
        return arr[n-1];
    }

    // Perform binary search to find the single non-duplicate element
    int low = 0, high = n - 2; // Define the search range

    while(low <= high){
        int mid = (low + high) / 2; // Calculate the middle index

        // If the middle element is not equal to its adjacent elements, it's the non-duplicate
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]){
            return arr[mid];
        }

        // If we are on the left side and the current element is equal to its left neighbor,
        // or if we are on the right side and the current element is equal to its right neighbor,
        // move the low pointer to the right to skip this pair of elements
        if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
           (mid % 2 == 0 && arr[mid] == arr[mid + 1])){
            low = mid + 1;
        } else { // Otherwise, move the high pointer to the left
            high = mid - 1;
        }
    }

    return -1; // No single non-duplicate found
}


//******************************************************************************
//binary search to find the peak element
int findPeakElement(vector<int> &arr) {
    int n = arr.size();

    // Check if there's only one element in the array
    if (n == 1) {
        return 0;
    }

    // Check if the first element is a peak
    if (arr[0] > arr[1]) {
        return 0;
    }

    // Check if the last element is a peak
    if (arr[n - 1] > arr[n - 2]) {
        return n - 1;
    }

    // Binary search to find the peak
    int low = 1;
    int high = n - 2;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if the middle element is a peak
        if ((arr[mid] > arr[mid - 1]) && (arr[mid] > arr[mid + 1])) {
            return mid;
        } else if (arr[mid] > arr[mid - 1]) { // If the middle element is increasing, move right
            low = mid + 1;
        } else { // If the middle element is decreasing, move left
            high = mid - 1;
        }
    }

    return -1; // Peak not found
}

//*******************************************************************************
#include<math.h>

int main(){
    int a=6;
    int b=sqrt(a);
    cout<<b;
}

