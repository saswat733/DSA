#include<iostream>
using namespace std;
// int fact(int n){                     //factorial of number
//     int fac=1;
//     if(n==0){
//         return 1;
//     }
//     else{
//     fac=n*fact(n-1);
//     }
//     return fac;
// }
// int main(){
//     int a=5;
//     cout<<fact(a);

// }



// int pow(int n){                  //power of number
//     int power=1;
//     if(n==0){
//         return 1;
//     }
//     else{
//     power=2*pow(n-1);
//     }
//     return power;
// }
// int main(){
//     int a=3;
//     cout<<pow(a);

// }



// void count(int n){           //printing the count of number
//     if(n==0)
//         return;
//     else{
//         cout<<n<<endl;
//         count(n-1);
//     }
  
    
// }
// int main(){
//     int a=3;
//     count(a);
// }


// int fibo(int n){            //return the nth element in fibbonacci series
//     int fib=0;
//     if(n==0||n==1)
//         return n;
    
//     return fibo(n-2)+fibo(n-1);
  
// }
// int main(){
//     int a,b;
   
//     cout<<fibo(4);
  
// }



// int count(int n){              // Count Ways To Reach The N-th Stairs 
//     if(n==0){
//         return 1;
//     }
//     if(n<0){
//         return 0;
//     }

//     return count(n-2)+count(n-1);

// }
// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//     int num;
//     cout<<"number "<<i<<":";
//     cin>>num;
//     cout<<"answer "<<i<<":"<<count(num)<<endl;
//     }
// }


// #include<vector>                                 //program to convert integer to digit
// void convert(string arr[],int n){
//    if(n==0){
//     return ;
//    }
//    int last=n%10;
//    n=n/10;

//    convert(arr,n);
//    cout<<arr[last]<<" ";

// }
// int main(){
//     int n;
//     cin>>n;
//     string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
//     convert(arr,n);
// }




// int sorted(int arr[]){                       //program for checking whether the array is sorted or not
//         int ans=1;
//     for(int i=0;i<4;i++){
//         if(arr[i]>arr[i+1]){
//             ans=0;
//             break;
//         } 
//     }   
//     return ans;
// }
// int main(){
//     int arr[5]={1,22,33,44,55};
//     if(sorted(arr)){
//         cout<<"sorted";
//     }
//     else
//     cout<<"unsorted";
// }




// int issorted(int arr[],int size){                //recursive solution
//     if(size==0||size==1){
//         return true;
//     }
//     if(arr[0]>arr[1]){
//         return false;
//     }
//     else{
//         bool ans=issorted(arr+1,size-1);
//         return ans;
//     }
// }
// int main(){
//     int arr[5]={2,3,44,5,6};
//     int size=5;
//     int ans=issorted(arr,size);
//     if(ans){
//         cout<<"sorted";
//     }
//     else{
//         cout<<"unsorted";
//     }
// }




// int sum(int arr[],int size){                 //finding the sum of array using recurion
    
//     if(size==0){
//         return 0;
//     }
//     else{
//         int add=sum(arr,size-1)+arr[size-1];
//     return add;
//     }
// }
// int main(){
//     int a[5]={3,2,5,1,6};
//     cout<<sum(a,5);
// }



                                        //linear seacrh using recursion

// int linear(int arr[],int n,int key){
//     cout<<"array is:"<<endl;
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     if(arr[0]==key){
//         return true;
//     }
//     if(n==0){
//         return false;
//     }
//     else{
//       bool ans=linear(arr+1,n-1,key);
//       return ans;
// }}
// int main(){
//     int a[5]={12,13,14,15,17};
//     int key;
//     cin>>key;
//     int ans=linear(a,5,key);
//     if(ans){
//         cout<<"yes present";
//     }
//     else{
//         cout<<"no";
//     }
    
// }



                                            //binary search using recursion


// int search(int arr[],int start,int end,int key){
//     cout<<"the array is:"<<endl;
//     for(int i=0;i<end;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     int mid=(start+end)/2;
//     cout<<"the mid ele is:"<<arr[mid]<<endl;
//     if(start>end){
//         return false;
//     }
//     if(arr[mid]==key){
//         return true;
//     }
//     if(arr[mid]<key){
//         return search(arr,mid+1,end,key);
//     }
//     else
//         return search(arr,0,mid-1,key);
// }
// int main(){
//     int arr[10]={12,13,14,15,16,19,39,49,55,67};
//     int key;
//     cin>>key;
//     int ans=search(arr,0,10,key);
//     if(ans){
//         cout<<"prsent";
//     }
//     else{
//         cout<<"absent";
//     }
// }




// #include<vector>                               //checking palindrome and reversing a string
// bool palindrome(string s,int start,int end){
//   if(start>=end){
//     return true;
//   }
//   if(s[start]!=s[end]){
//     return false;
//   }
//   else{
//     return palindrome(s,start+1,end-1);
//     }
// }
// void reverse(string &st,int start){
//  cout<<"call recieved :"<<st<<endl;
//   if(start>=st.length()-start){
//     return;
//   }
 
//     swap(st[start],st[st.length()-start-1]);
   
//     reverse(st,++start);
  
  

// }
// int main(){
//   string s="madammm";
//   cout<<s.length()<<endl;
//   reverse(s,0);
//   cout<<s<<endl;
//   bool ans=palindrome(s,0,s.length()-1);
//   if(ans){
//     cout<<"yes"<<endl;
//   }
//   else{
//     cout<<"no"<<endl;
//   }
// }





// int power(int a,int b){          //program for finding the power of number   
//   if(b==0){                      //optimised code
//     return 1;
//   }
//   if(b==1){
//     return a;
//   }
//   int ans=power(a,b/2);


//   //if b is even
//   if(b%2==0){
//      return ans*ans;
//   }
//   else{
//     return ans*ans*a;
//   }
// }


// // int power(int a,int b){              //mera code
// //   int ans=1;
// //   if(b==0){
// //     return 1;
// //   }
// //   else{
// //     ans=ans*a*power(a,--b);
// //   }
// //   return ans;

// // }
// int main(){
//   int a=3;
//   int b=11;
//   int ans=power(a,b);
//   cout<<ans;
// }



// void bubble_sort(int *arr,int size){             //bubble sort
//       for(int i=0;i<5;i++){
//     cout<<arr[i]<<" ";
//   }  
//       if(size==0||size==1){
//         return ;
//       }
      
//       for(int i=0;i<size-1;i++){
//           if(arr[i]>arr[i+1]){
//             swap(arr[i],arr[i+1]);
//           }
//       }

//       cout<<endl;
//       bubble_sort(arr,size-1);
     
// }


// void insertion_sort(int *arr,int size){                  //insertion sort
//       for(int i=0;i<5;i++){
//     cout<<arr[i]<<" ";
//   }  
//       if(size==0||size==1){
//         return ;
//       }

//       for(int i=0;i<size-1;i++){
//         int min=i;
//           if(arr[min]>arr[i+1]){
//             swap(arr[min],arr[i+1]);
//           }
//       }

//       cout<<endl;
//       insertion_sort(arr,size-1);
     
// }

// int main(){
//   int arr[5]={12,1,18,14,9};
//   insertion_sort(arr,5);
                                                
// }

// #include<vector>
// void merge(vector<int> &arr,int low,int mid,int high){
//   vector<int> brr;      //temporary array

//   int left=low;         //starting index of left array
//   int right=mid+1;        //starting index of right array

//   while(left<=mid && right<=high){
//     if(arr[left]<arr[right]){
//       brr.push_back(arr[left]);
//       left++;
//     }
//     else{
//       brr.push_back(arr[right]);
//       right++;
//     }
//   }


//   //if the elements left on the left array
//   while(left<=mid){
//     brr.push_back(arr[left]);
//     left++;
//   }
//   //if the elements left on the right array
//   while(right<=mid){
//     brr.push_back(arr[right]);
//     right++;
//   }

//   for(int i=0;i<=high;i++){
//     arr[i]=brr[i];
//   }

//   for(int i=0;i<high;i++){
//     cout<<brr[i]<<" ";
//   }
//   cout<<endl;
// }

// void mergesort(vector<int> &arr,int low,int high){
//   if(low>= high){
//     return;
//   }

//   int mid=low+(high-low)/2;


//   //left part sort krega
//   mergesort(arr,low,mid);

//   //right part sort karega
//   mergesort(arr,mid+1,high);

//   //merge
//   merge(arr,low,mid,high);

// }

																// C++ program for Merge Sort
// #include <bits/stdc++.h>
// using namespace std;

// // Merges two subarrays of array[].
// // First subarray is arr[begin..mid]
// // Second subarray is arr[mid+1..end]
// void merge(int array[], int const left, int const mid,
// 		int const right)
// {
// 	int const subArrayOne = mid - left + 1;
// 	int const subArrayTwo = right - mid;

// 	// Create temp arrays
// 	auto *leftArray = new int[subArrayOne],
// 		*rightArray = new int[subArrayTwo];

// 	// Copy data to temp arrays leftArray[] and rightArray[]
// 	for (auto i = 0; i < subArrayOne; i++)
// 		leftArray[i] = array[left + i];
// 	for (auto j = 0; j < subArrayTwo; j++)
// 		rightArray[j] = array[mid + 1 + j];

// 	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
// 	int indexOfMergedArray = left;

// 	// Merge the temp arrays back into array[left..right]
// 	while (indexOfSubArrayOne < subArrayOne
// 		&& indexOfSubArrayTwo < subArrayTwo) {
// 		if (leftArray[indexOfSubArrayOne]
// 			<= rightArray[indexOfSubArrayTwo]) {
// 			array[indexOfMergedArray]
// 				= leftArray[indexOfSubArrayOne];
// 			indexOfSubArrayOne++;
// 		}
// 		else {
// 			array[indexOfMergedArray]
// 				= rightArray[indexOfSubArrayTwo];
// 			indexOfSubArrayTwo++;
// 		}
// 		indexOfMergedArray++;
// 	}

// 	// Copy the remaining elements of
// 	// left[], if there are any
// 	while (indexOfSubArrayOne < subArrayOne) {
// 		array[indexOfMergedArray]
// 			= leftArray[indexOfSubArrayOne];
// 		indexOfSubArrayOne++;
// 		indexOfMergedArray++;
// 	}

// 	// Copy the remaining elements of
// 	// right[], if there are any
// 	while (indexOfSubArrayTwo < subArrayTwo) {
// 		array[indexOfMergedArray]
// 			= rightArray[indexOfSubArrayTwo];
// 		indexOfSubArrayTwo++;
// 		indexOfMergedArray++;
// 	}
// 	delete[] leftArray;
// 	delete[] rightArray;
// }

// // begin is for left index and end is right index
// // of the sub-array of arr to be sorted
// void mergeSort(int array[], int const begin, int const end)
// {
// 	if (begin >= end)
// 		return;

// 	int mid = begin + (end - begin) / 2;
// 	mergeSort(array, begin, mid);
// 	mergeSort(array, mid + 1, end);
// 	merge(array, begin, mid, end);
// }

// // UTILITY FUNCTIONS
// // Function to print an array
// void printArray(int A[], int size)
// {
// 	for (int i = 0; i < size; i++)
// 		cout << A[i] << " ";
// 	cout << endl;
// }

// // Driver code
// int main()
// {
// 	int arr[] = { 12, 11, 13, 5, 6, 7 };
// 	int arr_size = sizeof(arr) / sizeof(arr[0]);

// 	cout << "Given array is \n";
// 	printArray(arr, arr_size);

// 	mergeSort(arr, 0, arr_size - 1);

// 	cout << "\nSorted array is \n";
// 	printArray(arr, arr_size);
// 	return 0;
// }




// int partition(int arr[],int start,int end){						//quick sort using recursion

// 	//assuming the first ele as pivot
// 	int pivot=arr[start];

// 	int count=0;

// 	//git the right index for pivot element
// 	for(int i=start+1;i<=end;i++){
// 		if(arr[i]<=pivot){
// 		count++;
// 		}
// 	}


// 	//place pivot ele at right position
// 	int pivotindex=start+count;
	

// 	//place the pivt ele at its right index
// 	swap(arr[pivotindex],arr[start]);

// 	//left and right wala part sambhalenge
// 	int i=start,j=end;

// 	while(i<pivotindex && j>pivotindex){
// 		while(arr[i]<pivot){
// 			i++;
// 		}


// 		while(arr[j]>pivot){
// 			j--;
// 		}

// 		if(i<pivotindex && j>pivotindex){
// 			swap(arr[i++],arr[j--]);
// 		}
// 	}
// 	return pivotindex;

// }

// void quicksort(int arr[],int start,int end){
// 	//base case
// 	if(start>=end){
// 		return ;
// 	}
	
// 	//partition karenge
// 	int pivotele=partition(arr,start,end);

// 	//left part sort karenge
// 	quicksort(arr,start,pivotele-1);

// 	//right part sort karenge
// 	quicksort(arr,pivotele+1,end);


// }
// int main(){
// 	int arr[5]={12,2,17,5,40};
// 	quicksort(arr,0,5-1);

// 	for(int i=0;i<5;i++){
// 		cout<<arr[i]<<" ";
// 	}
// }



#include<vector>

// void subset(vector<int> nums,vector<int> output, int index, vector<vector<int>>& ans ){
// 	//base case
// 	if(index>=nums.size()){
// 		ans.push_back(output);
// 		return;
// 	}

// 	//exclude

// 	subset(nums,output,index+1,ans);

// 	//include 

// 	int ele=nums[index];
// 	output.push_back(ele);
// 	subset(nums,output,index+1,ans);

// }
// int main(){
// 	vector<int> nums{1,2,3};

// 	vector<vector<int>> ans;
// 	vector<int> output;
// 	int index=0;
// 	subset(nums,output,index,ans);
// 	for(int i=0;i<ans.size();i++){
// 		for(int j=0;j<ans[0].size();j++){
// 			cout<<ans[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
	
// }

void substr(string& str,string output,int index,vector<string>& ans){
	//base case
	if(index>=str.size()){
		ans.push_back(output);
		return;
	}

	//exclude case
	substr(str,output,index+1,ans);

	//include case 
	
	output.push_back(str[index]);
	substr(str,output,index+1,ans);
}
vector<string> subsequences(string str){
	
	// Write your code here
	vector<string> ans;
	string output;
	int index=0;
	substr(str,output,index,ans);
	return ans;
}


