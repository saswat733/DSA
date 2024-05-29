#include<iostream>
using namespace std;

                        //program to check for the i'th bit is set or not

// brute force
// int main(){
//     int a=3;
//     int n=3;

//     if((a>>3)&1==1){
//         cout<<"true";
//     }
//     else{
//         cout<<"false";
//     }
// }


//  optimised approach

// int main(){
//     int n=13;
//     int a=3;

//     //mask
//     int mask=1<<(a-1);

//     if(n & mask){
//         cout<<"true";
//     }
//     else{
//         cout<<"false";
//     }

// }



                            //program to set the i'th bit of number

// int main(){
//     int n=13;
//     int i=2;

//     int masked = (1<<(i-1));
//     int ans=n|masked;

//     cout<<ans;

// }


                    //program to clear the i'th bit
    
// int main(){
//     int n=13;
//     int i=4;
    
//     int masked=(1<<(i-1));
//     int ans=n^masked;

//     cout<<ans; 
// }

                        //remove hte last(right most) set bit of the number

// int main(){
//     int n=214;
    
//     int m=n-1;
//     int ans=n&m;
//     cout<<ans;
// }


                    // find the positions of right most set bit
// int main(){
//     int n=13;
//     int m=n-1;
//     int ans=(n& (~m));
//     cout<<ans;
// }


                //program to find the even odd number

                //1. using AND operator

// int main(){
//     int n=5;
//     if(n&1){
//         cout<<"odd";
//     }
//     else{
//         cout<<"even";
//     }
// }

                //2. using mulitpliaction and division

// int main(){
//     int n=3;

//     //multiply and divide by 2 if the ans remains same as number than it is even else odd
//     int ans=(n/2)*2;
//     if(ans==n){
//         cout<<"even";
//         cout<<ans;
//     }
//     else{
//         cout<<"odd";
//         cout<<ans;
//     }
// }


                //using left and right shift operator

// int main(){
//     //for multiply use left shift
//     //for divide use right shift

//     int n=3;
//     int ans=(n>>1)<<1;
//     if(ans==n){
//         cout<<"even";
//     }
//     else{
//         cout<<"odd";
//     }
// }


            //chcekc if the number is power of 2
// int main(){
//     int n=4;
//     int ans=(n&(n-1));
//     if(ans==0){
//         cout<<"yes";
//     }
//     else{
//         cout<<"no";
//     }
// }




