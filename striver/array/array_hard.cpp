#include<iostream>
#include<vector>        //for pascal always use nCr for formulas

using namespace std;

//pascal triangle

//printing the pascal triangle
vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans;

    vector<int> row;
     for(int i=1;i<=N;i++){
        int c=1;
     for(int j=1;j<=i;j++){
        row.push_back(c);
        c=c*(i-j)/j;
     }
     ans.push_back(row);
    }
    return ans;
}

//given Row and column find the element present there in pascal's triangle

//we will use nCr formula 
//brute force
//time complexity:O(r) and space complexity is O(n)
long long FindInPascal(int r,int n){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}


//printing the nth row from pascal triangle
//time complexity :O(nXr) 
//brute force
vector<int> findRowOfPascalTriangle(int n){
    vector<int> ans;
    for(int i=1;i<=n;i++){
        int result=FindInPascal(i-1,n-1);
        ans.push_back(result);
    }
    return ans;
}


//better solution
//time complexity:O(n) space:O(1)
vector<int> findRowOfPascalTrianglee(int n){
    vector<int> ans;
    int result=1;
    ans.push_back(1);
    for(int i=1;i<n;i++){
        result=result*(n-i);
        result=result/i;
        ans.push_back(result);
    }
    return ans;
}


//****************************************************************************
//majority element grater than n/3
#include<bits/stdc++.h>

//brute force
//time complexity:O(n2) and space complexity:O(1)
vector<int> majorityElementt(vector<int> arr){
    vector<int> ans;
    for(int i=0;i<arr.size();i++){
        if(ans.size()==0 || ans.back()!=arr[i]){
            int count=0;
            for(int j=i;j<arr.size();j++){
                if(arr[i]==arr[j]){
                    count++;
                }
            }

            if(count>(arr.size()/3)){
                ans.push_back(arr[i]);
            }
        }
    }
}


//using unordered mapping better solution
//time complexity: O(n) as worst case for unorderd map
vector<int> majorityElement(vector<int> v) {
	vector<int> ans;
    int target=v.size()/3;
   unordered_map<int,int> mppp;
   for(int i=0;i<v.size();i++){
        mppp[v[i]]++; //if the element doen't appear then it automatically take the element and count it
        if(mpp[v[i]]==((n.size()/3)+1)){
            ans.push_back(v[i]);
        }
   }
   //O(2log2)
    sort(ans.begin(),ans.end());
   return ans;
}

//optimal solution using moore's voting algo
#include<bits/stdc++.h>

//time complexity:O(2n) and space complexity: O(1)
vector<int> majorityElement(vector<int> v){
    int cnt1=0;
    int cnt2=0;
    int num1=INT_MIN;
    int num2=INT_MIN;
    for(int i=0;i<v.size();i++){
        if(cnt1==0 && num2!=v[i]){
            cnt1=1;
            num1=v[i];
        }
        else if(cnt2==0 && num1!=v[i]){
            cnt2=1;
            num2=v[i];
        }
        else if(v[i]==num1){
            cnt1++;
        }
        else if(v[i]==num2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ls;
    cnt1=cnt2=0;
    for(int i=0;i<v.size();i++){
        if(num1==v[i]){
            cnt1++;
        }
        if(num2==v[i]){
            cnt2++;
        }
    }
    int mini=(int)(v.size()/3)+1;
    if(cnt1>=mini){
        ls.push_back(num1);
    }
    if(cnt2>=mini){
        ls.push_back(num2);
    }
    sort(ls.begin(),ls.end());

    return ls;

}


//********************************************************************


// three sum problem

//brute force
//#include <vector>
//time complexity:O(n3) and space complexity:varies based on ele

vector<vector<int>> triplet(int n,vector<int> &nums){

    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}


//better approach 
//time complexity:O(n2)X log(M)
//space complexity:
#include<bits/stdc++.h>

// Function to find unique triplets that sum up to zero

vector<vector<int>> triplet(int n, vector<int> &nums) {

    // Create a set to store unique triplets
    set<vector<int>> st;

    // Iterate through each element in the input vector
    for (int i = 0; i < n; i++) {
        
        // Create a set to store unique elements seen so far
        set<int> hashSet;

        // Iterate through each element after the current element
        for (int j = i + 1; j < n; j++) {

            // Calculate the third element required to make the sum zero
            int third = -(nums[i] + nums[j]);

            // Check if the third element exists in the hashSet
            if (hashSet.find(third) != hashSet.end()) {

                // If found, create a triplet vector and insert into the set
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end()); // Sort the triplet vector
                st.insert(temp); // Insert the sorted triplet into the set
            }

            // Insert the current element into the hashSet
            hashSet.insert(nums[j]);
        }
    }

    // Convert the set of triplets to a vector and return
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//optimal solution
//time complexity: O(nlogn)+O(nXn)
// space complexity : O(no.of unique triplets)
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &nums) {
    vector<vector<int>> ans; // Initialize a vector to store the triplets
    sort(nums.begin(), nums.end()); // Sort the input array

    // Loop through each element of the array
    for (int i = 0; i < n; i++) {
        // If the current element is the same as the previous one, skip it
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int j = i + 1; // Pointer for the next element after the current one
        int k = n - 1; // Pointer for the last element

        // Loop while j is less than k
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k]; // Calculate the sum of the triplet

            // If the sum is less than zero, move the j pointer to the right
            if (sum < 0) {
                j++;
            }
            // If the sum is greater than zero, move the k pointer to the left
            else if (sum > 0) {
                k--;
            }
            // If the sum is zero, found a triplet
            else {
                vector<int> temp = {nums[i], nums[j], nums[k]}; // Create a triplet
                ans.push_back(temp); // Add the triplet to the result vector

                j++; // Move j pointer to the right
                k--; // Move k pointer to the left

                // Skip duplicates
                while (j < k && nums[j] == nums[j - 1]) {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
            }
        }
    }
    return ans; // Return the vector of triplets
}


//**************************************************************************************
//four sum

//brute force approach
//tiem complexity:O(n4 X logn)


//better approach
//time complexity: O(n3)
#include<bits/stdc++.h>

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> result;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                        vector<int> ans={nums[i],nums[j],nums[k],nums[l]};
                        sort(ans.begin(),ans.end());
                        result.insert(ans);
                    }
                }
            }
        }
    }
    vector<vector<int>> temp(result.begin(),result.end());

    return temp;
}


//better approach
//time complexity: O(n3 X logn)
//space complexity: O(n) we are using extra space so we need to eliminate this
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> st;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<int> hashSet;
            for (int k = j + 1; k < n; k++) {
                int fourth = target - (nums[i] + nums[j] + nums[k]);
                if (hashSet.find(fourth) != hashSet.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                    sort(temp.begin(), temp.end()); // Sort the quadruplet vector
                    st.insert(temp); // Insert the sorted quadruplet into the set
                }
                hashSet.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


//optimal approach
//time complexity: O(n2 X n) approx O(n3)
//space com:used just for returning
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(j!=(i+1) && nums[j]==nums[j-1]){
                continue;
            }
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum==target){
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++,l--;
                    while(k<l && nums[k]==nums[k-1]){
                        k++;
                    }
                    while(k<l && nums[l]==nums[l+1]){
                        l--;
                    }
                }
                else if(sum<target){
                    k++;
                }
                else{
                    l--;
                }
            }
        }
    }
    return ans;
}


//*********************************************************************************************
//longest subarray with zero sum

//brute force using mapp
int getLongestZeroSumSubarrayLength(vector<int> &arr){
	int presum=arr[0];
	int remainder=0;
	int k=0;
	int n=arr.size()
	unordered_map<int,int> mpp;
	int count=0;
	for(int i=0;i<n;i++){
		presum+=arr[i];
		remainder=presum-k;
		count+=mpp[remainder];
		mpp[presum]++;
	}

	return count;
}


//optimal solution using hashing
#include <vector>
#include <unordered_map> // Include necessary header for unordered_map
//time complexity : O(n)
// space complexity:O(n) for hashing map in worst case the map can store all the elements
int getLongestZeroSumSubarrayLength(std::vector<int> &arr) {
    int sum = 0; // Initialize sum to keep track of cumulative sum
    int n = arr.size(); // Get the size of the input array

    // Create a map to store the sum and its corresponding index
    std::unordered_map<int, int> mpp;

    int maxi = 0; // Initialize maxi to keep track of the maximum length of the subarray with zero sum

    // Iterate through all the elements of the array
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Update the cumulative sum

        // Check if the current sum is zero, if so, update maxi to the current index + 1
        if (sum == 0) {
            maxi = i + 1;
        } else {
            // Check if the current sum is present in the map
            if (mpp.find(sum) != mpp.end()) {
                // If the sum is found in the map, update maxi with the maximum of current maxi
                // and the difference between current index and the index where the sum was found previously
                maxi = std::max(maxi, i - mpp[sum]);
            } else {
                // If the sum is not found in the map, store the sum along with its index in the map
                mpp[sum] = i;
            }
        }
    }

    return maxi; // Return the maximum length of the subarray with zero sum
}


//*************************************************************************************

//printing the number of subarray with XOR k

//brute force
//time complexity:O(n3) 
int subarraysWithSumK(vector<int> a, int b) {
    int n = a.size();
    int count = 0;
    
    // Iterate through all possible subarrays
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int xorr = 0;
            // Calculate XOR of the current subarray
            for (int k = i; k <= j; k++) {
                xorr = xorr ^ a[k];
            }
            // If XOR of the subarray equals b, increment count
            if (xorr == b) {
                count++;
            }
        }
    }
    return count;
}


//better solution





//*************************************************************************
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    vector<int> ans;
    int count;
     unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    } 

    for (auto it : mpp) {
        if(it.second==2){
            ans.push_back(it.first);
        }
    }
    for(auto it:mpp){
        
    }
}
int main(){
    
  vector<int> arr={2, 2, 1, 3, 1, 1, 3, 1, 1};
  vector<int> ans=majorityElementt(arr);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<' ';
  }
  
}