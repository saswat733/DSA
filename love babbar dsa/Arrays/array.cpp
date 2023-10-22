#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// program to find the min or max number from a given array using linear search
int main(){
int a[6]={-2,-100,0,-20,-5,-8};
int max=INT_MIN;             //assigning the min as minimum possible value
for(int i=0;i<6;i++){
    if(a[i]>max){            //if the number is less than min than update the min
        max=a[i];
    }
}
cout<<max;
return 0;
}
// program to reverse an array    10 80 20 70 30 60 40 50

// int a[8]={10,20,30,40,50,60,70,80};
// int n=8;
// int start=0;
// int end=n-1;
// while(start<=end){

//     if(start==end){
//         cout<<a[start];
//         start++;
//         end--;
//     }
//     else{

//         cout<<a[start]<<" ";
//         cout<<a[end]<<" ";
//         start++;
//         end--;
//     }

// }

// reversing an arrray   60 50 40 30 20 10
// int a[6]={10,20,30,40,50,60};
// int n=6;
// int start=0;
// int end=n-1;
// while(start<=end){
//     swap(a[start],a[end]);
//     start++;
//     end--;
// }
// for(int i=0;i<n;i++){
//     cout<<a[i]<<" ";
// }

// program to find the maximum and minimum digit from a multi dimensional array
// int a[3][4]={{10,22,33,40},{1,39,44,11},{50,60,14,36}};
// for(int i=0;i<3;i++){
//     for(int j=0;j<4;j++){
//         cout<<a[i][j]<<" ";
//     }
//     cout<<endl;
// }

// cout<<"maximum:"<<endl;
// int max=INT_MIN;
// for(int i=0;i<3;i++){
//     for(int j=0;j<4;j++){
//         if(max<a[i][j]){
//             max=a[i][j];
//         }
//     }
// }
// cout<<max<<endl;

// cout<<"minimum:"<<endl;
// int min=INT_MAX;
// for(int i=0;i<3;i++){
//     for(int j=0;j<4;j++){
//         if(min>a[i][j]){
//             min=a[i][j];
//         }
//     }
// }
// cout<<min<<endl;

// program to transpose the matrix   
/* 
10 1 50
22 39 60
33 44 14
20 30 60 */  
// int main(){
//  int a[3][4]={{10,22,33,20},{1,39,44,30},{50,60,14,60}};         //method 1
// int b[4][3];
//  cout<<"before transpose"<<endl;
//   for(int i=0;i<3;i++){
//     for(int j=0;j<4;j++){
//         cout<<a[i][j]<<" ";
//     }
//     cout<<endl;
// }
//  for(int i=0;i<4;i++){
//     for(int j=0;j<3;j++){
//         b[i][j]=a[j][i];
//     }
//  }
//  cout<<"after transpose"<<endl;

//  for(int i=0;i<4;i++){
//     for(int j=0;j<3;j++){
//         cout<<b[i][j]<<" ";
//     }
//     cout<<endl;
//  }
// }

// vector<vector<int>> arr;                ///vector form of printing 2 dimensional array
// vector<int> a{1,2,3,4};
// vector<int> b{5,6,7,8};
// vector<int> c{9,10,11,12};
// arr.push_back(a);
// arr.push_back(b);
// arr.push_back(c);
// for(int i=0;i<arr.size();i++){
//     for(int j=0;j<arr[0].size();j++){
//         cout<<arr[i][j]<<" ";
//     }
//     cout<<endl;
// }

// another way to declare the vector
// vector<vector<int>> arr(3,vector<int>(5,0));
//  for(int i=0;i<arr.size();i++){
//     for(int j=0;j<arr[i].size();j++){
//         cout<<arr[i][j]<<" ";
//     }
//     cout<<endl;
// }

// program to sortt colours
// time complexity: O(n+n)=O(n)
// space complexity : O(1)

// vector<int> arr{1,0,1,1,2,2,0,2,2,0};                    //method 1
// int zero,one,two;
// zero=one=two=0;  //since only constants are used that why space complexity is constant
// for(int i=0;i<arr.size();i++){
//   if(arr[i]==0){
//     zero++;
//   }
//   else if(arr[i]==1){
//     one++;
//   }
//   else{
//     two++;
//   }
// }
// int i=0;
// while(zero--){
//   arr[i]=0;
//   i++;
// }
// while(one--){
//   arr[i]=1;
//   i++;
// }
// while(two--){
//   arr[i]=2;
//   i++;
// }
// for(int i=0;i<arr.size();i++){
//   cout<<arr[i]<<" ";
// }

// vector<int> arr{1,0,1,1,2,2,0,2,2,0};            //method 2
// for(int i=0;i<arr.size();i++){
//   for(int j=i+1;j<arr.size();j++){
//       if(arr[i]>arr[j]){
//         int temp=arr[i];
//         arr[i]=arr[j];
//         arr[j]=temp;
//       }
//   }
// }

// for(int i=0;i<arr.size();i++){

// program to print the duplicate numbers

// for(int i=0;i<a.size();i++){
//     for(int j=i+1;j<a.size();j++){
//       if(a[i]==a[j]){
//         cout<<a[j]<<" ";
//         break;
//       }
//     }
// }

// sort(a.begin(),a.end());             //method 2 first sort and then compaare the adjacent elements
// for(int i=0;i<a.size()-1;i++){
//   if(a[i]==a[i+1]){
//     cout<<a[i];
//   }
// }

// vector<int> a{1,20,3,40,5,66,5};           //program to print the max and second max number without sorting and with just one for loop

// int max2,max1;
// max1=max2=0;
// for(int i=0;i<a.size();i++){
//   if(a[i]>max1){
//     max2=max1;
//     max1=a[i];
//   }
//   if(max2<a[i] && a[i]<max1){
//     max2=a[i];
//   }
// }
// cout<<max2<<" "<<max1;

// program to find the misssing element from the array with duplicates;
// method 1
// time complexity: O(n)
// space complexity: O(1)
/*     vector<int> a{1,5,3,4,4};
        for(int i=0;i<a.size();i++){                //in this program we first make every element negative except the one which is missing
          int index=abs(a[i]);                      //here we are making sur that we have all indexes as positive
          if(a[index-1]>0){           //here we are comparing the element whether they are positive if they are then they are multiply with -1
            a[index-1]*=-1;
          }
        }

        //printing the negative elements
        for(auto val:a){
          cout<<val<<" ";
        }
        cout<<endl;

        //the element which is not negative , its index is our answer
        for(int i=0;i<a.size();i++){
          if(a[i]>0){
            cout<<i+1;
          }
        }

*/

// vector<int> a{5,3,3,3,1};

// for(int i=0;i<a.size();i++){
//   int index=a[i]-1;
//   if(a[i]!=a[index]){
//     swap(a[i],a[index]);
//   }
//   else{
//     ++i;
//   }
// }

// for(int i=0;i<a.size();i++){
//   if(a[i]!=i+1){
//     cout<<i+1<<" ";
//   }
// }

// program to find the first repeating element
// vector<int> a{1,3,7,4,4,6};          //method 1
// for(int i=0;i<a.size();i++){           //time complexity:O(n^2)   space complexity:O(1)
//   for(int j=i+1;j<a.size();j++){         //it is not a optimised solution
//     if(a[i]==a[j]){
//       cout<<i+1;
//       return i+1;
//     }

//   }
// }
// return -1;

// method 2

/*        vector<int> a{6,3,3,4,4,6};    //we will count if there exist  more than 1 element than count value will increase
        for(int i=0;i<a.size();i++){
          int count=0;
          for(int j=i+1;j<a.size();j++){
            if(a[i]==a[j]){
              count++;
            }
          }
          if(count==1){       //we checked if count value is increased if it is than return the index
            cout<<i+1<<" ";
            break;
          }
        }
*/

// program to swap alternate elements
/*         int a[6]={1,2,3,4,5,6};
         for(int i=0;i<6;i++){
           cout<<a[i]<<" ";
         }
         cout<<endl;

         for(int i=0;i<6;i=i+1){
           if(i<6){
             swap(a[i],a[i+1]);
             i++;
           }

         }

         for(int i=0;i<6;i++){
           cout<<a[i]<<" ";
         }
*/

// program for printing the duplicate element;
// int find(vector<int> arr){
//     int ans=0;

//     //doing xor of all the elements
//    for(int i=0;i<arr.size();i++){
//     ans=ans^arr[i];
//    }

//    //doing xor of all the elements from 1 to n-1;
//    for(int j=1;j<arr.size();j++){
//     ans=ans^j;
//    }
//     return ans;
// }
// int main(){
//     int n;
//         cin>>n;
//         vector<int> arr(n);
//         for(int i=0;i<n;i++){
//             cin>>arr[i];
//         }
//         int answer=find(arr);
//         cout<<answer;

// }

// program to find the intersection of array most optimised solution

// int main(){
//   vector<int> a{1,2,3,3,4,5};
//   vector<int> b{3,5,6};
//   vector<int> c;
//   int i=0,j=0;
//  while(i<a.size()&&j<b.size()){
//   if(a[i]<b[j]){
//     i++;
//   }
//   else if(a[i]>b[j]){
//     j++;
//   }
//   else{
//     c.push_back(a[i]);
//     i++;
//     j++;
//   }
//  }
//   for(int k=0;k<c.size();k++){
//     cout<<c[k]<<" ";
//   }
// }

// program for printing the pair of numbers equal to sum

// int main(){
//   vector<int> a{1,2,3,4,5};
//   int sum=12;
//   for(int i=0;i<a.size();i++){
//     for(int j=i+1;j<a.size();j++){
//       for(int k=j+1;k<a.size();k++)
//           if(a[i]+a[j]+a[k]==sum){
//             cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
//             break;
//           }
//     }
//     // break;
//   }
// }

// int main()
// {

//   vector<int> arr{1, 0, 1, 1, 1, 1, 0, 1, 0, 0}; // program for sorting 0 1 2
  // for (int i = 0; i < arr.size(); i++)
  // {
  //   for (int j = i + 1; j < arr.size(); j++)
  //   {
  //     if (arr[i] > arr[j])
  //     {
  //       int temp = arr[i];
  //       arr[i] = arr[j];
  //       arr[j] = temp;
  //     }
  //   }
  // }



                            //method 2
//   int i=0,zero=0,one=1,two=2;
//   while(i<arr.size()){
//     if(arr[i]==0){
//       zero++;
//       i++;
//     }
//     else if(arr[i]==1){
//       one++;
//       i++;
//     }
//     else{
//       two++;
//       i++;
//     }
//   }
//   int j=0;
//   while(zero--){
//     arr[j]=0;
//     j++;
//   }
//   while(one--){
//     arr[j]=1;
//     j++;
//   }
//   while(two--){
//     arr[j]=2;
//     j++;
//   }

//   for(int i=0;i<arr.size();i++){
//     cout<<arr[i]<<" ";
//   }
// }



// int left=0,right=arr.size()-1;          //method 3 most optimised solution
// while(left<right){
//   while(arr[left]==0 && left<right){
//     left++;
//   }
//   while(arr[right]==1 && left<right){
//     right--;
//   }
  
//   if(left<right){
//     swap(arr[left],arr[right]);
//     left++;
//     right--;
//   }

// }

// for(int i=0;i<arr.size();i++){
//   cout<<arr[i]<<" ";
// }
// }


                                      //program for removing duplicate elements
// void print(vector<int> a){
//   for(int i=0;i<a.size();i++){
//     cout<<a[i]<<" ";
//   }
// }

// void duplicate(int a[],int n){
//   int j=1;
//   for(int i=1;i<n;i++){
//     if(a[i]!=a[i-1]){
//       a[j]=a[i];
//       j++;
//     }
//     cout<<endl;
//     cout<<"iteration:"<<i<<endl;
//     for(int i=0;i<n;i++){
//     cout<<a[i]<<" ";
//   }
//   }
//   cout<<endl;
//   // 
  
//   // return 0;
// }




// void reverse(int a[],int n){         //program for reversing an array

//   int start=0;
//   int end=n-1;
//   while(start!=end){
//     swap(a[start],a[end]);
//     start++;
//     end--;
//   }
// }




// void merge(vector<int> a,int m,vector<int> b,int n){       //program for merging two arrays in sorted form
//   vector<int> c;
//   for(int i=0;i<m;i++){
//     c.push_back(a[i]);
//   }
//   for(int i=0;i<n;i++){
//     c.push_back(b[i]);
//   }
//   sort(c.begin(),c.end());
//   print(c);
// }
// void mergee(int a[],int m,int b[],int n,int c[]){
//     int i=0,j=0,k=0;
//     while(i<m && j<n){
//       if(a[i]<b[j]){
//         c[k++]=a[i++];
//       }
//       else{
//         c[k++]=b[j++];
//       }
//     }
//     while (i<m)
//     {
//       c[k++]=a[i++];
//     }
//     while (j<n)
//     {
//       c[k++]=b[j++];
//     }
   
    
// }




// int move(int a[],int n){         //program for moving all zeroes to end
//   int k=0;
//   int i=0;
//   while(i<=n){
//     if(a[i]!=0){
//       a[k]=a[i];
//       i++;
//       k++;
//     }
//     else{
//       i++;
//     }
//   }
//     return k;
// }



// void move(int arr[],int n){      //method 2
//   int k=0;
//   for(int i=0;i<n;i++){
//     if(arr[i]!=0){
//       swap(arr[k++],arr[i]);
//     }
//   }

// }



                              //program for rotating an array with an index
//  void rotate(vector<int> a,int val){
  // int b[n];
  //   for(int i=0;i<n;i++){
  //     b[(i+val)%n]=a[i];
  //   }
  //    for(int i=0;i<n;i++){
  //   cout<<b[i]<<" ";
  // }


//   int k=val%a.size();
//   cout<<k;
//   cout<<endl;
//   reverse(a.begin(),a.end());
//   reverse(a.begin(),a.begin()+k);
//   reverse(a.begin()+k,a.end());
//     for(int i=0;i<a.size();i++){
//     cout<<a[i]<<" ";
//   }

  
//  }
// int main(){
//  vector<int> a{12,0,3,10,3,5,20};
//   rotate(a,3);
// }



                                  //program for printing the sum of the two array


// void sum(int arr[],int brr[]){
//   int i=4,j=1,carry=0;
//   vector<int> ans;
//   while(i>=0 && j>=0){
//     int val1=arr[i];
//     int val2=brr[j];

//     int sum=val1+val2+carry;

//     carry=sum/10;
//     sum=sum%10;
//     ans.push_back(sum);
//     i--;
//     j--;
//   }
//   while(i>=0){
//     int sum=arr[i]+carry;
//     carry=sum/10;
//     sum=sum%10;
//     ans.push_back(sum);
//     i--;
//   }
//   while(j>=0){
//     int sum=arr[j]+carry;
//     carry=sum/10;
//     sum=sum%10;
//     ans.push_back(sum);
//     j--;
//   }
//   reverse(ans.begin(),ans.end());
//   for(int i=0;i<ans.size();i++){
//     cout<<ans[i]<<" ";
//   }
// }




// void sum(int arr[],int brr[]){
//   int x=0,y=0;int sum=0;
//   vector<int> a;
//   for(int i=0;i<5;i++){
//     x=x*10+arr[i];
//   }
//   for(int j=0;j<2;j++){
//     y=y*10+arr[j];
//   }
//   sum=x+y;
//   while(sum!=0){
//     int remainder=sum%10;
//     a.push_back(remainder);
//     sum=sum/10;
//   }
//   reverse(a.begin(),a.end());
//   for(int i=0;i<a.size();i++){
//     cout<<a[i]<<" ";
//   }

// }
// int main(){
//   int arr[5]={1,2,3,4,8};
//   int brr[2]={1,2};
//   sum(arr,brr);
  
// }

// int main(){
//   int arr[5]={23,40,1,5,6};
//   for(int i=0;i<5;i++){
//     for(int j=i+1;j<5;j++){
//       if(arr[i]<arr[j]){
//         int temp=arr[i];
//         arr[i]=arr[j];
//         arr[j]=temp;
//       }
//     }
//   }

//   for(int i=0;i<5;i++){
//     cout<<arr[i]<<" ";
//   }
// }

