#include<iostream>
#include<vector>

using namespace std;

//Reverse an array
vector<int> rever(int n,vector<int> &nums,vector<int> &ans){
    if(n==0){
        return ans;
    }

    ans.push_back(nums[n-1]);
    return rever(n-1,nums,ans);
}

vector<int> reverseArray(int n, vector<int> &nums)
{
    // Write your code here.
    vector<int> ans;
    rever(n,nums,ans);
    return ans;

}



//factorial of a number

int factorial_of_number(int n){            
    int ans=1;
    if(n==0){
        return 1;
    }

    return factorial_of_number(n-1)*n;
}



// check for palindrome

string rev(string &str,int start,int end){
    if(start>=end){
        return str;
    }

    swap(str[start],str[end]);
    // cout<<str<<endl;
    return rev(str,start+1,end-1);
}

bool isPalindrome(string& str) {
    // Write your code here.
    string real=str;
    string ans=rev(str,0,str.length()-1);
   
    if(ans==real){
        return true;
    }

    return false;
   
}


//program to print fibbonacci seriess
/*
Generate Fibonacci numbers recursively. Base case: n <= 0, return result. Append sum to result, update a to b and b to a + b. Recur with n - 1 and updated a, b, and sum. Return result.
*/
vector<int> generate(int n,int a,int b,vector<int> &result,int sum){
    if(n<=0){
        return result;
    }

    result.push_back(sum);
    return generate(n-1, b, a+b,result, b);
}

vector<int> generateFibonacciNumbers(int n) {
    // Write your code here.
    int a=0;
    int b=1;
    vector<int> result;
    result=generate(n,a,b,result,a);
    return result;

}

int main(){
  string str="abcd";
  bool ans=isPalindrome(str);

  cout<<ans;
    
}