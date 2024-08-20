#include <iostream>
using namespace std;

/*
The time complexity of the merge sort algorithm is O(n log n), where n is the number of elements in the array. This time complexity arises because the algorithm divides the array into halves recursively until each subarray contains only one element, and then merges the subarrays back together in O(n) time.

The space complexity of the merge sort algorithm is O(n), where n is the number of elements in the array. This space complexity arises because the algorithm requires additional space to store the temporary subarrays during the merge process. The space required is proportional to the size of the input array.
*/

// Function to merge two sorted subarrays into a single sorted subarray
void merge(int arr[], int l, int r, int mid) {
    // Calculate the sizes of the two subarrays
    int n1 = mid - l + 1; // Size of left subarray
    int n2 = r - mid;     // Size of right subarray

    // Create temporary arrays to hold the elements of the two subarrays
    int leftarray[n1];    // Temporary array for the left subarray
    int rightarray[n2];   // Temporary array for the right subarray

    // Copy data from the original array to the temporary left subarray
    for (int i = 0; i < n1; i++) {
        leftarray[i] = arr[i + l];
    }

    // Copy data from the original array to the temporary right subarray
    for (int j = 0; j < n2; j++) {
        rightarray[j] = arr[mid + 1 + j];
    }

    // Merge the two temporary arrays back into the original array
    int i = 0;    // Index for the left subarray
    int j = 0;    // Index for the right subarray
    int index = l; // Index for the merged array

    // Compare elements from both subarrays and merge them in sorted order
    while (i < n1 && j < n2) {
        if (leftarray[i] <= rightarray[j]) {
            arr[index++] = leftarray[i++];
        } else {
            arr[index++] = rightarray[j++];
        }
    }

    // Copy the remaining elements of the left subarray, if any
    while (i < n1) {
        arr[index++] = leftarray[i++];
    }

    // Copy the remaining elements of the right subarray, if any
    while (j < n2) {
        arr[index++] = rightarray[j++];
    }
}

// Function to perform merge sort on the given array within the specified range
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Find the middle index to divide the array into two halves
        int mid = l + (r - l) / 2;

        // Recursively sort the first half of the array
        mergeSort(arr, l, mid);

        // Recursively sort the second half of the array
        mergeSort(arr, mid + 1, r);

        // Merge the sorted halves into a single sorted array
        merge(arr, l, r, mid);
    }
}

int main() {
    // Initialize the array to be sorted
    int arr[5] = {12, 4, 5, 26, 7};

    // Perform merge sort on the entire array
    mergeSort(arr, 0, 4);

    // Print the sorted array
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
