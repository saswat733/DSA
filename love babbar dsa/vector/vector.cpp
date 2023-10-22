#include<iostream>
#include<vector>
using namespace std;
int find(vector<int> arr){
    int ans=0;
    for(int i=0;i<arr.size();i++){
        ans=ans^arr[i];
    }
    return ans;
}
int main(){    
    // vector<int> arr(10);
    // for(int i=0;i<10;i++){
    //     cin>>arr[i];
    // }
    // vector<int> drr{1,2,3,4,5,6,7};
    // arr.pop_back();
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<arr.capacity()<<endl;
    // cout<<arr.size()<<endl;
    // cout<<drr.empty();



                                //program to find the unique element from the given array
        
        // int n;
        // cin>>n;
        // vector<int> arr(n);
        // for(int i=0;i<n;i++){
        //     cin>>arr[i];
        // }
        // int answer=find(arr);
        // cout<<answer;

                                //program to do union of two arrays

        // vector<int> arr{12,13,14,15};
        // vector<int> brr{16,17,18};

        // vector<int> crr;
        // for(int i=0;i<arr.size();i++){
        //     crr.push_back(arr[i]);
        // }
        // cout<<"first time:"<<endl;
        // for(int i=0;i<crr.size();i++){
        //     cout<<crr[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<brr.size();i++){
        //     crr.push_back(brr[i]);
        // }
        // cout<<"second time:"<<endl;
        // for(int i=0;i<crr.size();i++){
        //     cout<<crr[i]<<" ";
        // }

                                        //program to find the intersection of two arrays
        
        
        // vector<int> arr{10,11,12,13,14,15};
        // vector<int> brr{11,19,20,13};
        // vector<int> crr;
        // for(int i=0;i<arr.size();i++){
        //     for(int j=0;j<brr.size();j++){
        //         if(arr[i]==brr[j]){
        //             crr.push_back(arr[i]);
        //         }
        //         
        //     }
        // }
        // for(int i=0;i<crr.size();i++){
        //     cout<<crr[i]<<" ";
        // }


                                        //print the pair of numbers which give the value equal to sum
                        
        // vector<int> arr{10,20,30,40};
        // int sum =70;
        // for(int i=0;i<arr.size();i++){
        //     for(int j=i+1;j<arr.size();j++){
        //         for(int k=j+1;k<arr.size();k++){

        //         int add=arr[i]+arr[j]+arr[k];
        //         if(sum==add){
                    
        //             cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
        //         }
        //         }
                
        //     }
        // }
       

                                                //program to sort 1 and 0            --->   0 0 0 0 1 1 1 1 1 1
                                                //agar hame 0 mila toh use right shift krdenge or agar 1 mila toh use left krenge 
        // vector<int> arr{0,0,1,1,0,1,1,1,0,0,1};
        // int start=0;
        // int end=arr.size()-1;
        // int i=0;
        // while(i!=end){         //i++ hoga jitne baar 0 encounter hoga or end decrease hoga jitne baar 1 ayga so jaise hi done equal honge then yeh break hojyga 
        //     if(arr[i]==0){
        //         swap(arr[start],arr[i]);
        //         start++;
        //         i++;
        //     }
        //     if(arr[i]==1){
        //         swap(arr[i],arr[end]);
        //         end--;
        //         // i++;

        //     }
        // }



        // for(auto val:arr){
        //     cout<<val<<" ";                         //new technique
        // }


        vector<int> arr{10,-18,6,5,-2,-6,111,1};
        // for(int i=0;i<arr.size();i++){                   //method 1
        //     for(int j=i+1;j<arr.size();j++){
        //         if(arr[j]<arr[i]){
        //             swap(arr[j],arr[i]);

        //         }
        //     }
        // }

        // int start=0;                     //method 2
        // int end=arr.size()-1;
        // int i=0;
        // while(i!=end){
        //     if(arr[i]>0){
        //         swap(arr[i],arr[end]);
        //         end--;
        //     }
        //     else if(arr[i]<0){
        //         swap(arr[i],arr[start]);
        //         start++;
        //         i++;
        //     }
        // }

        for(auto val:arr){
            cout<<val<<" ";
        }




                                                        
      
     


}