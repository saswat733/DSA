#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
void sortArray(vector<int>& arr, int n)
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

int main(){
    vector<int> arr{0,1,0,1,2,0,0,0,2,1};
    sortArray(arr,arr.size());

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

}
