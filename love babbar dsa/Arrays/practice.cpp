#include<iostream>
using namespace std;

int main(){
   int a[3][4]={{10,22,33,40},{1,39,44,11},{50,60,14,36}};
   for(int i=0;i<4;i++){
    for(int j=0;j<3;j++){
        cout<<a[j][i]<<" ";
    }
    cout<<endl;
}
    
}