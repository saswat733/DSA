#include<iostream>
using namespace std;
void factorial(int n)
{
    // Write your code here
    int result=1;
    for(int i=1;i<=n;i++){
        result=result*i;
    }
    cout<<result;
}
int main(){
    factorial(30);

}