#include<bits/stdc++.h>

using namespace std;
/*

Sure, let's dry run the `bubbleSort` function with an example array `{5, 2, 8, 1, 3}`:

Initial Array: {5, 2, 8, 1, 3}

1. **Pass 1**:
    - Iteration 1: Compare 5 and 2, no swap (5 < 2 is false).
    - Iteration 2: Compare 5 and 8, no swap (5 < 8 is true). Swap 5 and 8.
    - Iteration 3: Compare 8 and 1, swap (8 < 1 is false).
    - Iteration 4: Compare 8 and 3, swap (8 < 3 is false).
    - Result: {2, 5, 1, 3, 8}

2. **Pass 2**:
    - Iteration 1: Compare 2 and 5, no swap (2 < 5 is true).
    - Iteration 2: Compare 5 and 1, swap (5 < 1 is false).
    - Iteration 3: Compare 5 and 3, swap (5 < 3 is false).
    - Result: {2, 1, 3, 5, 8}

3. **Pass 3**:
    - Iteration 1: Compare 2 and 1, swap (2 < 1 is false).
    - Iteration 2: Compare 2 and 3, no swap (2 < 3 is true).
    - Result: {1, 2, 3, 5, 8}

4. **Pass 4**:
    - Iteration 1: Compare 1 and 2, no swap (1 < 2 is true).
    - Result: {1, 2, 3, 5, 8}

Since no swaps were made in Pass 4, the array is sorted. 

The sorted array is: {1, 2, 3, 5, 8}

**Time Complexity:**
- In the worst-case scenario, where the array is in reverse sorted order, bubble sort will perform \(O(n^2)\) comparisons.

**Space Complexity:**
- Bubble sort is an in-place sorting algorithm, meaning it doesn't require any extra space other than the given array. Hence, its space complexity is \(O(1)\).

*/
void bubbleSort(std::vector<int>& arr, int n) {
    // Outer loop iterates through all elements except the last one
    for (int i = 0; i < n - 1; i++) {
        // Inner loop iterates through elements starting from index i+1
        // to compare each element with the next one.
        for (int j = i + 1; j < n; j++) {
            // If the current element is greater than the next element,
            // swap them to move the larger element towards the end.
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
            }
        }+
    }
}


void recursive_bubble(int n,vector<int> &arr){
    if(n==0){
        return;
    }
    for(int i=0;i<=n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    recursive_bubble(n-1,arr);
}

int main(){
    vector<int> arr{12,3,4,1,5};
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    recursive_bubble(arr.size()-1,arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}