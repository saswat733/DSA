#include<iostream>
#include<vector>
using namespace std;
void selection_sort(int a[],int n){
    for(int i=0;i<5-1;i++){
        int min=i;
        for(int j=i+1;j<5;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
  
        swap(a[min],a[i]);
    }
     for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    } 

}

void bubble_sort(int a[],int n){
      for(int i=0;i<5;i++){
        bool swapp=false;
       for(int j=0;j<5-i;j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
            swapp=true;
        }
       }
        if(swapp=false){
            break;
        }
}
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    } 
}


void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(j>=0){
            if(a[j]>temp){
                a[j+1]=a[j];
                j--;
            }
            else{
                break;
            }
        }
        a[j+1]=temp;
    }

     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    } 
}
int main(){
    int a[5]={10,1,9,3,6};
    selection_sort(a,5);
     
    

}

