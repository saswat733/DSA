#include<iostream>
using namespace std;

int pivot(int arr[],int start,int end){
    int pivotele=arr[start];
    //since we consider the first element as pivot ele so we start from  start+1
    int i=start+1;
    int j=end;
    
    while(i<=j){

        //check for the gratter ele if the greater is found the loop will break 
        while(arr[i]<=pivotele && i<=end){
            i++;
        }
        //chekc for the smaller ele if it is found the loop break 
        while(arr[j]>pivotele && j>=start+1){
                    j--;
        }
        // now the smaller ele from right and larger ele from left will be swapped
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    // atlast wee swap the first and the pivot index ele
    swap(arr[start],arr[j]);
    return j;
}
void quick_sort(int arr[],int start,int end){
    if(start<end){
        int pivotIndex=pivot(arr,start,end);
        quick_sort(arr,start,pivotIndex-1);
        quick_sort(arr,pivotIndex+1,end);

    }
}

int main(){
    int arr[7]={12,3,5,1,7,4,9};
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quick_sort(arr,0,7-1);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }

}