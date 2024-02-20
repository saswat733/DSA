#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// in selection we divide the array into two subarray one which is sorted and the one which is unsorted
//and we eventually swap the elements from unsorted array into sorted array based on the favourable position
//due to which sorted array increaes and unsorted array decreases

//Time complexity: O(N^2) space complexity: O(1)


/*

Sample Input 1:

6
2 13 4 1 3 6 

Sample Output 1:

1 2 3 4 6 13 

Explanation Of Sample Input 1:

 Select 1 and swap with element at index 0. arr= {1,13,4,2,3,6}

 Select 2 and swap with element at index 1. arr= {1,2,4,13,3,6}

 Select 3 and swap with element at index 2. arr= {1,2,3,13,4,6}

 Select 4 and swap with element at index 3. arr= {1,2,3,4,13,6}

 Select 6 and swap with element at index 4. arr= {1,2,3,4,6,13}


*/

void selection_sort(vector<int> &arr){
    // as the last element is already sorted so we take n-1
    for(int i=0;i<arr.size()-1;i++){
        // take the index of first element
        int mini=i;

        //checking if there is anyother element which is more smaller than the current element and we atke i+1 as the starting elements are being sorted
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        //we swap the current element with the most smallest ele from unsorted array
        swap(arr[mini],arr[i]);

    }
}
int main(){
    vector<int> arr{23,10,5,4,7};
    selection_sort(arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}