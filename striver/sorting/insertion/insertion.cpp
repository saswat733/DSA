#include<bits/stdc++.h>
using namespace std;

/*

Certainly! Let's dry run the provided `insertion_sort` function with an example array `{5, 2, 8, 1, 3}`:

**Initial Array:** {5, 2, 8, 1, 3}

1. **Pass 1 (i = 0)**:
   - The outer loop starts with `i = 0`, so the current element to be inserted is `5`.
   - Since it's the first element, it's already considered sorted.
   - After the first pass, the array remains unchanged: {5, 2, 8, 1, 3}

2. **Pass 2 (i = 1)**:
   - The outer loop now moves to `i = 1`, so the current element to be inserted is `2`.
   - The inner loop compares `2` with `5` (preceding element).
   - Since `2` is less than `5`, they are swapped, resulting in: {2, 5, 8, 1, 3}
   - Now, the array looks partially sorted with `2` in its correct position.
   
3. **Pass 3 (i = 2)**:
   - The outer loop now moves to `i = 2`, so the current element to be inserted is `8`.
   - The inner loop compares `8` with `5`, no swap needed.
   - After the inner loop, the array remains unchanged: {2, 5, 8, 1, 3}
   - Since `8` is greater than the preceding element `5`, it stays in its position.

4. **Pass 4 (i = 3)**:
   - The outer loop now moves to `i = 3`, so the current element to be inserted is `1`.
   - The inner loop compares `1` with `8`, `5`, and `2`, and swaps them accordingly.
   - After the inner loop, the array becomes: {1, 2, 5, 8, 3}
   - `1` is inserted in its correct sorted position, shifting other elements to the right.

5. **Pass 5 (i = 4)**:
   - The outer loop now moves to `i = 4`, so the current element to be inserted is `3`.
   - The inner loop compares `3` with `8` and `5` and swaps them accordingly.
   - After the inner loop, the array becomes: {1, 2, 3, 5, 8}
   - `3` is inserted in its correct sorted position.

**Final Sorted Array:** {1, 2, 3, 5, 8}

Thus, the array has been successfully sorted using the Insertion Sort algorithm.




Here are the time and space complexities of the Insertion Sort algorithm:

    Time Complexity:
        Best Case: O(n)O(n) - This occurs when the array is already sorted. In the best-case scenario, the inner loop doesn't need to perform any swaps.
        Average Case: O(n2)O(n2) - In the average case, each element needs to be compared and potentially swapped with every other element in the worst case, resulting in quadratic time complexity.
        Worst Case: O(n2)O(n2) - This occurs when the array is sorted in reverse order. In the worst-case scenario, for each element, the inner loop needs to compare it with all previous sorted elements and perform swaps to move it to its correct position.

    Space Complexity:
        O(1)O(1) - Insertion Sort is an in-place sorting algorithm, meaning it doesn't require additional space other than the input array itself. The space complexity remains constant regardless of the size of the input array.
*/
#include <vector>

void insertion_sort(std::vector<int> &arr) {
    // Outer loop iterates through each element of the array
    for (int i = 0; i < arr.size(); i++) {
        int j = i; // Initialize a variable j to keep track of the current element's index

        // Inner loop runs until j > 0 and the element at index j - 1 is greater than the element at index j
        while (j > 0 && arr[j - 1] > arr[j]) {
            // Swap the current element with its preceding element
            std::swap(arr[j - 1], arr[j]);

            // Move to the previous element for comparison
            j--;
        }
    }
}


void recursive_insertion(vector<int> &arr,int n,int index){
    if(index==n-1){
        return;
    }

    for(int i=index;i>0;i--){
        if(arr[i]<arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
    }

    recursive_insertion(arr,n,index+1);
}


int main(){
    vector<int> arr{12,3,4,2,70};
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    recursive_insertion(arr,arr.size(),0);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}