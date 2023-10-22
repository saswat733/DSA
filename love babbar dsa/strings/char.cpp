#include<iostream>
using namespace std;

void print(char a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}
int length(char a[]){
    int count=0;
    for(int i=0;a[i]!='\0';i++){
        count++;
    }
    return count;
}

void reverse(char a[],int n){
    int start=0;
    int end=n-1;
    while(start<=end){
        swap(a[start],a[end]);
        start++;
        end--;
    }
    cout<<a;

}

bool palindrome(char a[],int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        if(a[s]!=a[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
char tolowercase(char ch[],int n){
     char temp;
    for(int i=0;i<n;i++){
    if(ch[i]>='a' && ch[i]<='z'){
        return ch[i];
    }
    else{
        temp=ch[i]+32;
        return temp;
    }
    }
    return temp;
}

int main(){
    char a[10];
    cout<<"enter:";
    cin>>a;
    int lengthh=length(a);
    cout<<lengthh<<endl;
    // reverse(a,lengthh);
    // cout<<"palindrom or not:"<<palindrome(a,lengthh);
    cout<<"char:"<<tolowercase(a,lengthh)<<endl;
    cout<<"char:"<<tolowercase(a,lengthh)<<endl;
    // cout<<"char:"<<tolowercase()<<endl;
}