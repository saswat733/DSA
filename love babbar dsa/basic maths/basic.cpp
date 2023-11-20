#include <iostream>
using namespace std;
#include<math.h>
int decimal(int n){
    int binaryno=0;
    int i=0;

        while(n>0){
            int bit=n%2;
            binaryno=bit*pow(10,i++)+binaryno;
            n=n/2;
        }
        return binaryno;
    }

int compliment(int n){
    int m=n;
    int mask=0;
    while(n!=0){
        mask=(mask<<1) | 1;
        m=m>>1;

    }
    int ans=(~n) & mask;
    return ans;
}
bool ispow(int n){
    int ans=1;
    for(int i=0;i<=30;i++){
    
    if(ans==n){
        return true;
        cout<<ans;
    }
    int ans=ans*2;
   }
   return false;
}


                            //checking whether the number is palindrome or not

    // int n;
    // cin>>n;
    // int pali=n;
    // int number=0;
    // while(n>0){
    //     int lastdigit=n%10;
    //     n=n/10;
    //     number=(number*10)+lastdigit;
    //         }
    // if(number==pali){
    //     cout<<"yes it is palindrome";
    // }
    // else{
    //     cout<<"fuck ";
    // }


                        //code for checking the armstrong number
    
    // int n;
    // cin>>n;
    // int original=n;
    // int armstrong=0;
    // while(n>0){
    //     int lastdigit=n%10;
    //     n=n/10;
    //     armstrong=armstrong+(lastdigit*lastdigit*lastdigit);
    // }
    // if(armstrong==original){
    //     cout<<"yes it is armstrong number";
    // }
    // else{
    //     cout<<"fuck";
    // }


                            //printing all the prime numbers count using SIEVE OF ERATORSTHENES
// #include<vector>
//  int countPrimes(int n) {
//         int count=0;
//         vector<bool> prime(n+1,true);
//         prime[0]=prime[1]=false;
//         for(int i=2;i<n;i++){
//             if(prime[i]){
//                 count++;
//                 for(int j=2*i;j<n;j=j+i){
    
//                     prime[j]=0;
//                 }
                
//             }
//         }
//         return count;
//     }
// int main(){
//     cout<<countPrimes(10);

// }    
   
    

                                            //program for getting GCD using EUCLIDEAN ALGORITHM
// int main(){
//     int a=12;
//     int b=9;
//     int gcd=0;
//    while(a>0 && b>0){
//     if(a>b){
//         a=a%b;
//     }
//     else{
//         b=b%a;
//     }
//    }
//     if(a==0){
//         cout<<b;
//     }
//     else{
//         cout<<a;
//     }
//     // cout<<gcd;
// }




int main(){
    int n;
    cout<<"enter:";
    cin>>n;
    while(n!=0){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
            n=n/i;
            break;
        }
    }
    }
    
}