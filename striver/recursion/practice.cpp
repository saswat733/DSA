#include<iostream>
#include<vector>
using namespace std;
vector<int> generateSubsets(vector<int> arr,int index,vector<int> result,int n,int k,int sum){
    if(index==n){

        for(int i=0;i<result.size();i++){
            sum=sum+result[i];
        }
        if(sum==k){
            return result;
        }
    }

    result.push_back(arr[index]);
    generateSubsets(arr,index+1,result,n,k,0);
    
    result.pop_back();
    generateSubsets(arr,index+1,result,n,k,0);

    return result;

}


//reverse the aray
vector<int> reverseArray(vector<int> arr,int n){
    
}

int main(){
    vector<int> arr{1,2,3};
    vector<int> result;
    int k=3;
    generateSubsets(arr,0,result,3,k,0);
}