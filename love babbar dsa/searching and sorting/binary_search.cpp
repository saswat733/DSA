
                //program for printing the root of the number with precision

#include<iostream>
#include<vector>
using namespace std;
// int binary(int n){
//     int target=n;
//     int start=0;
//     int end=n;
//     int ans=-1;
//     int mid=start+(end-start)/2;
//     while(start<=end){
//         if(mid*mid==target){
//             return mid;
//         }
//         if (mid*mid>target){
//             end=mid-1;
//         }
//         else{
//             ans=mid;
//             start=mid+1;
//         }
//         mid=start+(end-start)/2;
//     }
//     return ans;
// }

   

// int main(){
//     int arr[5]={12,34,2,30,5};
//     int n;
//     cout<<"enter the number:";
//     cin>>n;
//     int ans=binary(n);
//     cout<<"the ans is "<<ans<<endl;

//     int precision;
//     cout<<"enter precision:";
//     cin>>precision;
//     double step=0.1;
//     double finalans=ans;
//     for(int i=0;i<precision;i++){
//         for(double j=finalans;j*j<=n;j=j+step){
//             finalans=j;
//         } 
//         step=step/10;
//     }
//     cout<<"final ans is:"<<finalans;
// }


                        //program for getting the row and column index of ele in 2D array

// int main(){
//     int m=3;
//     int n=4;
//     int a[m][n]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//     int start=0;
//     int target;
//     cout<<"enter:";
//     cin>>target;
//     int totalsize=12;
//     int end=totalsize-1;
//     int mid=start+(end-start)/2;
//     while(start<=end){
//         int rowindex=mid/n;
//         int colindex=mid%n;
//         int ele=a[rowindex][colindex];
//         if(ele==target){
//             cout<<rowindex<<" "<<colindex;
//         }
//         if(ele>target){
//             end=mid-1;
//         }
//         else{
//             start=mid+1;
//         }
//         mid=start+(end-start)/2;
//     }
// }



                                        //program for printing the index of number in nearly sorted number
// int binary(vector<int> a,int n){
//     int start=0;
//     int end=a.size()-1;
//     int mid=start+(end-start)/2;
//     while(start<=end){
//         if(a[mid]==n){
//             return mid;
//         }
//         if(a[mid-1]==n){
//             return mid-1;
//         }
//         if(a[mid+1]==n){
//             return mid+1;
//         }
//         if(a[mid]<n){
//             start= mid+2;
//         }
//         else{
//             end= mid-2;
//         }
       
//         mid=start+(end-start)/2;
//     }
//     return -1;
// }

// int main(){
//     vector<int> a{10,3,40,20,50,80};
//     int target;
//     cout<<"enter:";
//     cin>>target;
//     int ans=binary(a,target);
//     cout<<"answer is "<<ans;

// }


                                        // program for printing dividend of a number 
// int binary(int number,int divisor){
//     int start=0;
//     int end=number;
//     int ans=-1;
//     int mid=start+(end-start)/2;
//     while(start<=end){
//         if(mid*divisor==number){
//             return mid;
//         }
//         if(mid*divisor<number){
//             start=mid+1;
//             ans=mid;
//         }
//         else{
//             end=mid-1;
//         }
//         mid=start+(end-start)/2;
//     }
//     return ans;
// }

// int main(){
//     int number;
//     cout<<"number:";
//     cin>>number;
//    int divisor;
//     cout<<"enter:";
//     cin>>divisor;
//     int ans=binary(number,divisor);
//     cout<<"answer is "<<ans;

// }


// int binary(vector<int> a){               //program for prnting the unique element
//     int start=0;
//     int end=a.size()-1;
//     int ans=-1;
//     int mid=start+(end-start)/2;
//     while(start<=end){
//         if(a[mid]!=a[mid+1] && a[mid]!=a[mid-1]){
//             return mid;
//         }
//         if(a[mid]==a[mid+1]){
//             start=mid+2;
//         }
//         else{
//             ans=mid;
//             end=mid-1;
//         }
//         mid=start+(end-start)/2;
//     }
//     return ans;
// }
// int main(){
//     vector<int> a{1,1,2,2,3,3,4,4,600,600,7,4,4};

//     int ans=binary(a);
//     cout<<"answer is "<<ans;

// }



                                        //program for finding the first and last occurence
// int first(vector<int> a,int n){
//     int start=0;
//     int end=a.size();
//     int mid=start+(end-start)/2;
//     int ans=-1;
//     while(start<end){
//         if(a[mid]==n){
//             end=mid-1;
//             ans=mid;
//         }
//         else if(a[mid]<n){
//             start=mid+1;
//         }
//         else{
//             end=mid-1;
//         }
//         mid=start+(end-start)/2;
//     }
//     return ans;
// }
// int last(vector<int> a,int n){
//     int start=0;
//     int end=a.size();
//     int mid=start+(end-start)/2;
//     int ans=-1;
//     while(start<end){
//         if(a[mid]==n){
//             start=mid+1;
//             ans=mid;
//         }
//         else if(a[mid]<n){
//             start=mid+1;
//         }
//         else{
//             end=mid-1;
//         }
//         mid=start+(end-start)/2;
//     }
//     return ans;
// }

// int main(){
//     vector<int> a{3,4,5,1};
//     int n;
//     cout<<"enter:";
//     cin>>n;
//     int firstt=first(a,n);
//     int lastt=last(a,n);
//     cout<<firstt<<" "<<lastt;
// }



                                    //program for  printing the peak in mountain array

// int peak(vector<int> a){
//     int start=0;
//     int end=a.size()-1;
//     int mid=start+(end-start)/2;
//     while(start<end){
//         if(a[mid]<a[mid+1]){
//             start=mid+1;
//         }
//         else{
//             end=mid;
//         }
//         mid=start+(end-start)/2;
//     }
//     return a[start];
// }
// int main(){
//     vector<int> a{3,4,5,1};
//     int ans=peak(a);
//     cout<<ans;
// }



//                                 //program for printing the pivot element
// int pivot(vector<int> a){
//     int s=0;
//     int e=a.size();
//     int m=s+(e-s)/2;
//     while(s<e){
//         if(a[m]>a[0]){
//             s=m+1;
//         }
//         else{
//             e=m;
//         }
//         m=s+(e-s)/2;
//     }
//     return s;
// }

// int binary(vector<int> a,int start,int end,int key){
//     int s=start;
//     int e=end;
//     int mid=s+(e-s)/2;
//     while(s<e){
//         if(a[mid]==key){
//             return mid;
//         }
//         else if(a[mid]>key){
//             e=mid-1;
//             // ans=mid;
//         }
//         else{
//             s=mid+1;
//         }
//         mid=s+(e-s)/2;
//     }
//     return e;
// }

// int ele(vector<int> a,int key){
//     int pivotele=pivot(a);
//     int end=a.size();
//     int ans=-1;
//     cout<<pivotele;
//     cout<<binary(a,pivotele,end,key);
//     if(key>=a[pivotele] &&key<=a[end-1]){
//         return binary(a,pivotele,end,key);
//     }
//     else{
//         ans=binary(a,0,pivotele-1,key);
//     }
//     return ans;
// }
// int main(){
//     vector<int> a{2,20,0,1,3};
//     int ans=ele(a,2);
//     cout<<ans<<endl;
//     cout<<binary(a,0,4,2);
//     // cout<<a.size();
// }



// // int binary(vector<int> a,int key){
// //     int s=0;
// //     int e=a.size()-1;
// //     int mid=(s+e)/2;
// //     int ans=-1;
// //     while(s<e){
// //         if(a[mid]==key){
// //             return mid;
// //         }
// //         if(a[mid]>key){
// //             e=mid-1;
// //         }
// //         else{
// //             s=mid+1;
// //         }
// //         mid=(s+e)/2;
// //     }
// //     return s;
// // }

// // int main(){
// //     vector<int> a{0,1,2,3,4,5};
// //     int ans=binary(a,2);
// //     cout<<ans;
// // }



                    //program for printing the square root of a number

int square(int n){
    int start=0;
    int end=n;
    int mid=(start+end)/2;
    int ans=-1;
    while(start<end){
        if(mid*mid==n){
            return mid;
        }
        if(mid*mid>n){
            end=mid-1;
        }
        else{
            start=mid+1;
            ans=mid;
        }
        mid=(start+end)/2;
    }
    return ans;
}
int main(){
    int n;
    cout<<"enter:";
    cin>>n;
    int ans=square(n);
    cout<<ans;
}