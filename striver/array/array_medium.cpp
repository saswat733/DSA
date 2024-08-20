#include <bits/stdc++.h> 
#include<iostream>
using namespace std;


// ***********************************************************************************************

//two sum problem
/*
Input: ‘N’ = 5, ‘TARGET’ = 5
‘BOOK’ = [4, 1, 2, 3, 1] 

Output: YES
Explanation:
Sam can buy 4 pages book and 1 page book.
*/

//brute force time complexity nearing to O(n2)
string read(int n, vector<int> book, int target)
{
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=book[i]+book[j];
            if(sum==target){
                return "yes";
            }
        }
    }
    return "no";
}


//better approach using hashing time complexity O(n X logn)
#include<bits/stdc++.h>
string readd(int n, vector<int> book, int target)
{
    // Create a map to store integers encountered so far.
    map<int,int> mpp;
    
    // Iterate through the elements of the vector 'book'.
    for(int i=0; i<n; i++){
        // Extract the current integer 'a' from the vector.
        int a = book[i];
        
        // Calculate the integer required to reach the target sum.
        int more = target - a;
        
        // Check if the required integer exists in the map.
        if(mpp.find(more) != mpp.end()){
            // If found, return "YES" indicating that a pair exists.
            return "YES";
        }
        
        // If not found, add the current integer 'a' to the map with its index.
        mpp[a] = i;
    }
    
    // If the loop completes without finding a pair, return "NO".
    return "NO";
}


//best solution using 2pointer approach time complexity is O(n) + O(nlogn)
// space complexity is O(1)

string readdd(int n, vector<int> book, int target){
    int start=0;
    int end=n-1;
     sort(book.begin(),book.end());
    for(int i=0;i<n;i++){
        int sum=book[start]+book[end];
        if(sum>target){
            end--;
        }
        else if(sum<target){
            start++;
        }
        else{
            return "YES";
        }
    }
    return "NO";
}

//**************************************************************************************
// program to sort 0,1,2

//brute force approach would be using any sorting algorithm


//better approach time complexity is O(2n) and space complexity is O(1)
#include <bits/stdc++.h> 
void sortArrayy(vector<int>& arr, int n)
{
     int zeros=0;
    int ones=0;
    int twos=0;

    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zeros++;
        }
        else if(arr[i]==1){
            ones++;
        }
        else{
            twos++;
        }
    }
    int k=0;
    while(zeros>0){
        arr[k++]=0;
        zeros--;
    }
    while(ones>0){
        arr[k++]=1;
        ones--;
    }
    while(twos>0){
        arr[k++]=2;
        twos--;
    }
}


//best approach
//using dutch national flag algorithm
// time complexity: O(n) and space complexity:O(1)

#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[high],arr[mid]);
            high--;
        }
    }
}



//***************************************************************************
// majority element in an array


// brute force O(n2)
int majorityElement(vector<int> v) {
    for(int i=0;i<v.size();i++){
        int count=0;
        for(int j=i;j<v.size();j++){
            if(v[i]==v[j]){
                count++;
            }

            if(count>(v.size()/2)){
                return v[i];
            }
        }
    }
    return -1;
}


//better solution
//using unorderd map
// O(nlogn)+O(n)
int majorityElementt(vector<int> arr){
    unordered_map<int,int> mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]++;
    }
    int ans=0;
   
    for(auto i:mpp){
        if(i.second>(arr.size()/2)){
            ans=i.first;
        }
    }
    return ans;
}


//best solution using
//mooore's voting algorithm
// time complexity is O(n) space com:O(1)
int majorityele(vector<int> arr){
    int count=0;
    int ele;
    for(int i=0;i<arr.size();i++){
        if(count==0){
            count=1;
            ele=arr[i];
        }
        else if(arr[i]==ele){
            count++;
        }
        else{
            count--;
        }
    }
    return ele;
}

// ***********************************************************
// find maximum subarray sum

// brute force solution
long long maxSubarraySumm(vector<int> arr,int n){
    
   int maxi = INT_MIN; // Initialize maxi with the smallest possible value
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if(sum<0){
                sum=0;
            }
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}



//best solution
// kadane's algorithm
// space complexity:O(1) and time:O(n)
int maxSubArray(vector<int>& arr) {
    int max_current = arr[0];
    int max_global = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        max_current = max(arr[i], max_current + arr[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    return max_global;
}





// **********************************************
// find the right most superior elements

vector<int> superiorElements(vector<int>&a) {
     vector<int> ans;
    for(int i = 0; i < a.size(); i++) {
        bool isMax = true;
        for(int j = i; j < a.size(); j++) {
            if(a[i] <= a[j]) {
                isMax = false;
                break;
            }
        }
        
        if(isMax) {
            ans.push_back(a[i]);
        }
    }
    sort(ans.begin(), ans.end());

    // Print debug information
    cout << "Superior elements found: ";
    cout<<ans.size();
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return ans;
}



//****************************************************************
//stocks problems
//best time to buy and sell stocks
// time:O(n) space:O(1)
int bestTimeToBuyAndSellStock(vector<int>&prices) {
    int mini=prices[0];
    int maxProfit=0;
    for(int i=0;i<prices.size();i++){
        int cost=prices[i]-mini;
        maxProfit=max(mini,cost);
        mini=min(prices[i],mini);

    }

    return maxProfit;
   
}

//***************************************************************************

// arrage the array elements in alternate +ve -ve sequence


//brute force time complexity:O(n)+O(n/2) and space complexity:O(n)
vector<int> alternateNumbers(vector<int>&a){
    vector<int> positiveArr;
    vector<int> negativeArr;
    for(int i=0;i<a.size();i++){
        if(a[i]>0){
            positiveArr.push_back(a[i]);
        }
        else{
            negativeArr.push_back(a[i]);
        }
    }
   for(int i=0;i<a.size()/2;i++){
    a[2*i]=positiveArr[i];
    a[2*i+1]=negativeArr[i];
   }
   return a;
}

//optimal approach
// time compl:O(n) and space complex:O(n)
vector<int> alternateNumberss(vector<int> &a){
    int pos = 0;
    int neg = 1;
    vector<int> b(a.size()); // resize b to the same size as a

    for (int i = 0; i < a.size(); i++) {
        if (a[i] > 0) {
            b[pos] = a[i];
            pos += 2;
          
        } else {
            b[neg] = a[i];
            neg += 2;
           
        }
    }

    return b;
}

#include<vector>
//best approach
// time complexity min:O(N) max:O(N/2)+O(n) space complexity:O(n)
vector<int> alternateNumbersss(vector<int> &a){
    vector<int> pos,neg;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]>0){
            pos.push_back(a[i]);
        }
        else{
            neg.push_back(a[i]);
        }
    }

    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            a[index]=pos[i];
            index++;
        }
    }
    else{
        for(int i=0;i<pos.size();i++){
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        int index=pos.size()*2;
        for(int i=pos.size();i<pos.size();i++){
            a[index]=neg[i];
            index++;
        }

    }
    return a;
}


//******************************************************************
// print the next permutation

//brute force approach
/*
1. generate all the permutations
2. linear search
3. next index
*/

//better approach using STL
vector<int> nextGreaterPermutation(vector<int> &A) {
    next_permutation(A.begin(),A.end());
    return A;
}

//best approach
// vector<int> nextGreaterPermutationn()



//superior elements

//brute force
//time complexity:O(n2) space complexity:O(n)

vector<int> superiorElementss(vector<int>&a) {
    vector<int> ans;
    for(int i=0;i<a.size();i++){
        bool leader=true;
        for(int j=i+1;j<a.size();j++){
            if(a[j]>=a[i]){
                leader=false;
                break;
            }
        }
        if(leader==true){
            ans.push_back(a[i]);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}



//optimal approach
//we will move from backward and store the maxi
#include <vector>
#include <algorithm>
#include <climits> // For INT_MIN
using namespace std;

// Function to find superior elements in a vector
// time complexity:O(n)+O(nlogn) space complexity:not using any space we just use a vector for returning

vector<int> superiorElementsss(vector<int>& a) {
    int maxi = INT_MIN; // Initialize the maximum element encountered so far
    vector<int> ans;    // Initialize vector to store superior elements

    // Iterate through the vector from the end
    for (int i = a.size() - 1; i >= 0; i--) {
        // If the current element is greater than the maximum encountered so far
        if (a[i] > maxi) {
            ans.push_back(a[i]); // Add it to the superior elements vector
        }
        maxi = max(maxi, a[i]); // Update the maximum element encountered
    }

    // Sort the superior elements vector in ascending order
    sort(ans.begin(), ans.end());

    return ans; // Return the vector of superior elements
}

//*********************************************************


// Longest Successive Elements 


//brute force
// Function to perform linear search
bool linearSearch(vector<int> a, int n) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == n) {
            return true;
        }
    }
    return false;
}

// Function to find the length of the longest successive sequence of elements in a vector
int longestSuccessiveElements(vector<int>& a) {
    int largest = 1; // Initialize variable to store the length of the longest sequence
    
    // Iterate through each element of the vector
    for (int i = 0; i < a.size(); i++) {
        int x = a[i]; // Current element
        int count = 1; // Initialize count for the current sequence length
        
        // Iterate forward in the sequence until the next element is found
        while (linearSearch(a, x + 1) == true) {
            x = x + 1; // Move to the next element
            count = count + 1; // Increment the count
        }
        
        // Update the length of the longest sequence
        largest = max(largest, count);
    }
    
    return largest; // Return the length of the longest sequence
}



//better solution
//we take three variables cnt,lastsmaller,longest and we first sort array and go linearly looking for the lastsmaller ele and if it encounters the we increase the count or else we restart the count and linerly we also save the longest subsequence
int longestSuccessiveElementss(vector<int>& a) {
    // Check if the input vector is empty
    if (a.size() == 0) {
        return 0; // If empty, return 0 as there are no elements
    }

    // Sort the vector in ascending order
    sort(a.begin(), a.end());

    // Initialize variables
    int n = a.size(); // Number of elements in the vector
    int lastSmaller = INT_MIN; // Initialize lastSmaller to the smallest possible integer
    int cnt = 0; // Initialize counter for consecutive elements
    int longest = 1; // Initialize variable to store the length of the longest consecutive sequence

    // Iterate through the sorted vector
    for (int i = 0; i < n; i++) {
        // If the current element is one more than the previous element
        if (a[i] - 1 == lastSmaller) {
            cnt += 1; // Increment the count of consecutive elements
            lastSmaller = a[i]; // Update the lastSmaller to the current element
        }
        // If the current element is not equal to the lastSmaller
        else if (a[i] != lastSmaller) {
            cnt = 1; // Reset the count to 1
            lastSmaller = a[i]; // Update the lastSmaller to the current element
        }
        // Update the length of the longest consecutive sequence
        longest = max(longest, cnt);
    }

    return longest; // Return the length of the longest consecutive sequence
}


//optimal approach
/*
1. put everything in set.
2. 
*/


//time complexity:O(1)[bext case] O(n)[worst case]
//space complexity:O(n)

int longestSuccessiveElementsss(vector<int> &a){
    int n=a.size();
    int longest=1;
    if(n==0){
        return 0;
    }

    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }

    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt=cnt+1;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;
}


//zero matrix

//brute force
#include <bits/stdc++.h> 
//time complexity is O(n x m)xO(n+m)+O(nxm)===O(n3)

/*
mark every element in row and column of the 0 as -1 and the afterwards make all the -1 as 0
*/
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                //setting the row elements as -1
                for(int k=0;k<m;k++){
                    if(matrix[i][k]!=0){
                        matrix[i][k]=-1;
                    }
                }
                //setting the col elements as -1
                for(int l=0;l<n;l++){
                    if(matrix[l][j]!=0){
                        matrix[l][j]=-1;
                    }
                }
            }
        }
    }

    //change all the -1 as 0
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==-1){
                matrix[i][j]=0;
            }
        }
    }
    return matrix;
}


//better solution
//time complexity: O(n x m)+O(n x m)  space complexity:O(n)+O(m)
vector<vector<int>> zeroMatrixx(vector<vector<int>> &matrix, int n, int m){
    int col[m]={0};
    int row[n]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]||col[j]){
                matrix[i][j]=0;

            }
        }
    }
    return matrix;

}


//best solution

//time complexity: (2mn) space complexity:O(1);

vector<vector<int>> zeroMatrixxx(vector<vector<int>> &matrix, int n, int m) {
	//col[m] ===> matrix[0][..]
    //row[n] ===> matrix[..][0]
    
    int col0=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                //marking the i'th row
                matrix[i][0]=0;
                //marking the j'th col
                
                //this is bcoz we divide the column hash in col0 and remaining matrix[0][0]==col0
                if(j!=0){
                    matrix[0][j]=0;
                }
                else
                    col0=0;
            }
        }
    }

    //excluding the hash table we will make every element as zero based on if 0 is there in hash table

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
                //check for the col row hash
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }

    //exceptional case when the first ele is 0
    if(matrix[0][0]==0){
        for(int i=0;i<m;i++){
            matrix[0][i]=0;
        }
    }

    // just in case if col0 becomes 0 then the whole col will become 0
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
    return matrix;
}



//**********************************************************************

//rotating the matrix by 90 deg
#include<vector>

//brute force
//time complexity: O(n X m) space complexity: O(n X m)

void rotateMatrixx(vector<vector<int>> &mat){
	  int n=mat.size();
	  int m=mat[0].size();
       vector<vector<int>> ans(m, vector<int>(n));
	  for(int i=0;i<n;i++){
		  for(int j=0;j<m;j++){
            ans[i][j]=mat[n-1-j][i];
		  }
	  }

     mat=ans;
}


//best solution
/*
1. transpose the matrix 
2. reverse the rows
*/

//time complex: O(n/2 * n/2)+ O(n/2) space complexity: we are doing it inplace
void rotateMatrix(vector<vector<int>> &mat){
	  int n=mat.size();
	  

	  for(int i=0;i<n-1;i++){
		  for(int j=i+1;j<n;j++){
			  swap(mat[i][j],mat[j][i]);
		  }
	  }

	  for(int i=0;i<n;i++){
		  reverse(mat[i].begin(),mat[i].end());
	  }
	
}


//*******************************************************************
//program to print the matrix in spiral form
// time complexity:O(m X n) space complexity: O(m X n)

//for this problem ther is only one solution so we just need to represent it in best way 
vector<int> spiralMatrix(vector<vector<int>>&a) {
    int n=a.size();
    int m=a[0].size();

    int left=0;
    int right=m-1;
    int top=0;
    int bottom=n-1;
    vector<int> ans;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(a[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(a[i][right]);
        }
        right--;
        if(top<=bottom){

        for(int i=right;i>=left;i--){
            ans.push_back(a[bottom][i]);
        }
        bottom--;
        }
        if(left<=right){

        for(int i=bottom;i>=top;i--){
            ans.push_back(a[i][left]);
        }
        left++;
        }
    }

    return ans;

}


//*********************************************************************
//returning the subarrays which equals the sum k

//brute force
// time complexity:O(n^3)
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int count=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
        int sum=0;
            for(int k=i;k<=j;k++){
                sum=sum+arr[k];
            }
            if(sum==k){
                count++;
            }
        }
    }
    return count;
}

//better solution
// time complexity:O(n^2)
int findAllSubarraysWithGivenSummm(vector<int> &arr,int k){
    int count=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+arr[j];
        if(sum==k){
            count++;
        }
        }
    }
    return count;
}
//optimal solution
int findAllSubarraysWithGivenSumm(vector<int> &arr,int k){
    int count=0;
    int left=0;
    int right=0;
    int sum=arr[0];
    int n=arr.size();
    while(right<n){
        if(sum==k){
            count++;
        }
        while(sum>k && left<right){
            sum-=arr[left];
            left++;
            if(sum==k){
                count++;
            }
        }
       

        right++;
        if(right<n){
            sum+=arr[right];
        }
    }
    return count;
}
//also 
// using prefix sum technique along with mapp
// time complexity:O(n X log n) and space compllexity:O(n) 
int findAllSubarraysWithGivenSum(vector<int>& arr, int k) {
    int count = 0;
    int preSum = 0;

    unordered_map<int, int> mpp; // Using unordered_map for better performance
    mpp[0] = 1;

    for (int i = 0; i < arr.size(); i++) {
        preSum += arr[i]; // Accumulate the prefix sum
        int remove = preSum - k;
        count += mpp[remove]; // Increment count if the complement exists
        mpp[preSum]++; // Update the frequency of the prefix sum
    }

    return count;
}


int main() {
    vector<int> arr={3, 1, 2, 4};
    int ans=findAllSubarraysWithGivenSummm(arr,6);
    cout<<ans;

   
}
