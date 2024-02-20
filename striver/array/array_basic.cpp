#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;


                //function to get the largest element it is the brute force approach having O(nlogn) TC
void sort_array(vector<int> &arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int largestElement(vector<int> &arr, int n) {
    sort_array(arr,n);
    return arr[n-1];
    
}

//optimised way having time complexity of O(n)


int largestElement(vector<int> &arr, int n) {
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

// function to get second largest and second smallest element its time complexity is O(nlogn) it is brute fore approach
void sortArray(vector<int> &arr){
    for(int i=0;i<arr.size()-1;i++){
        int mini=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
            swap(arr[mini],arr[i]);
    }
    // return arr;
}
vector<int> getSecondOrderElements(int n, vector<int> a) {
    sortArray(a);
    vector<int> result;
    result.push_back(a[n-2]);
    result.push_back(a[1]);
    return result;
}


//more optimised solution for finding the second largest and second smallest elements in O(2n)
int secondLargest(int n,vector<int> a){
    int max = a[0];
    int smax = INT_MIN; // Initialize with a value smaller than any element

    for (int i = 1; i < n; i++) { // Start from i = 1
        if (a[i] > max) {
            smax = max;
            max = a[i];
        } else if (a[i] > smax && a[i] != max) {
            smax = a[i];
        }
    }
    return smax;
}

int secondSmallest(int n,vector<int> a){
    int small = INT_MAX; // Initialize with a large value
    int Ssmall = INT_MAX; // Initialize with a large value
    for(int i=n-1;i>=0;i--){
         if (a[i] < small) {
            Ssmall = small;
            small = a[i];
        } else if (a[i] < Ssmall && a[i] != small) {
            Ssmall = a[i];
        }
    }
    return Ssmall;
}
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int sLargest=secondLargest(n,a);
    int sSmallest=secondSmallest(n,a);

    return {sLargest,sSmallest};

}



//program to check whether array is sorted or not
int isSorted(int n, vector<int> arr) {
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return 0;
        }

    }
    return 1;
}


//brute force for this problem is storing the elements in stack and if the top element of stack is same to the element going to be inserted we move ahead
//program to remove duplicate from arrays and give the count of new array
int removeDuplicates(vector<int> &arr, int n) {
    int count=0;
	for(int i=0;i<n;i++){
        if(arr[i]!=arr[i+1]){
            count++;
        }
    }
    return count;

}

//left rotating aan array by 1
#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    reverse(arr.begin(),arr.begin()+1);
    reverse(arr.begin()+1,arr.end());
    reverse(arr.begin(),arr.end());
    return arr;
}


//left rotating the array by d places
vector<int> rotateArray(vector<int> arr, int k) {
    int size = arr.size();
    k = k % size; // Adjust k in case it's greater than the array size

    reverse(arr.begin() + k, arr.end()); // Reverse the remaining elements
    reverse(arr.begin(), arr.begin() + k); // Reverse the first k elements
    reverse(arr.begin(), arr.end()); // Reverse the whole array

    return arr;
}


//move all zeros to end
vector<int> moveZeros(int n, vector<int> a) {
    int count=0;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            count++;
        }
        else{
            ans.push_back(a[i]);
        }
    }
    while(count>0){
        ans.push_back(0);
        count--;
    }

    return ans;
}

//linear search for the idex of element
int linearSearch(int n, int num, vector<int> &arr)
{
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            return i;
        }
    }
    return -1;
}

//merge two sorted array in sorted form

vector < int > sortedArray(vector < int > a, vector < int > b) {
    vector<int> result;
    for(int i=0;i<a.size();i++){
        result.push_back(a[i]);
    }
    for(int i=0;i<b.size();i++){
       result.push_back(b[i]);
    }
    sort(result.begin(),result.end());
    vector<int> ans;
    for(int i=0;i<result.size();i++){
        if(result[i]!=result[i+1]){
            ans.push_back(result[i]);
        }
    }

    return ans;
}

//get the unique element
#include<vector>

void getSingleElement(vector<int> &arr){
	// Write your code here.	
    unordered_map<int,int> ans;
    for(int i=0;i<arr.size();i++){
        ans[arr[i]]++;
    }

    for(auto i:ans){
        if(i.second==1){
            cout<<i.first;
        }
    }
}

int main(){
    vector<int> arr{8,8,9,9,10};

    // vector<int> result;
    // int ans=getSingleElement(arr);
    // result=sortedArray(brr,arr);
    // for(int i=0;i<result.size();i++){
    //     cout<<result[i]<<" ";
    // }
    // cout<<ans;
    // getSingleElement(arr);
    int ans=secondLargest(arr.size(),arr);
    int Ans=secondSmallest(arr.size(),arr);
    cout<<Ans;
}
