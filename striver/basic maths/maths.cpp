#include <iostream>
#include <cmath>
using namespace std;

long long binary(long long n) {
    long long binarynumber = 0;
    int i = 0;
    while (n > 0) {
        int bit = n % 2;
        binarynumber = bit * pow(10, i++) + binarynumber;
        n = n / 2;
    }
    return binarynumber;
}

int countt(long long n) {
    int count = 0;
    while (n != 0) {
        n = n / 10;
        count++;
    }
    return count;
}

long long addZeroes(long long n) {
    long long binaryNumber = binary(n);
    int count = countt(binaryNumber);
    long long answer = binaryNumber;
    for (int i = count; i < 32; i++) {
        answer = answer * 10;
    }
    return answer;
}

long long binaryToDecimal(long long n) {
    long long decimalNumber = 0;
    int i = 0;
    while (n != 0) {
        int digit = n % 10;
        decimalNumber += digit * pow(2, i);
        n /= 10;
        i++;
    }
    return decimalNumber;
}

int calcGCD(int n, int m){
    // Write your code here.
    int gcd=0;
    if(n>m){
        for(int i=1;i<=n;i++){
            if(n%i==0 && m%i==0){
                gcd=i;
            }
        }
    }
    else{
        for(int i=1;i<=m;i++){
            if(n%i==0 && m%i==0){
                gcd=i;
            }
        }
    }
    return gcd;
}
int main() {
    int answer=calcGCD(6,4);
    cout<<answer;
   
}
