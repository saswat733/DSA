#include<iostream>
#include<string.h>
#include<vector>
using namespace std;


                                                        //program to reverse the string and check palindrome




// bool validate(char ch){
//     if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
//                 return 1;
//     }
//     else{
//         return 0;
//     }

// }
// char tolower(char ch){
//     if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9')){
//         return ch;
//     }
//     else{
//         char temp=ch+32;
//         return temp;
//     }
// }
// bool palindrome(string s){
//     int st=0;
//     int e=s.length()-1;
    
//     while(st<=e){
//         if(s[st]!=s[e]){
//             return 0;
//         }
//         else{
//             st++;
//             e--;
//         }
//     }
    
       
    
//     return 1;
// }
// int main(){
//     string s = "race a car";
//     string temp;


//     //just removing the faltu characters
//     for(int i=0;i<s.length();i++){
//         if(validate(s[i])){
//             temp.push_back(s[i]);
//         }
//     }

//     //now conerting to lowercase
//     for(int i=0;i<temp.length();i++){
//         temp[i]=tolower(temp[i]);
//     }
//     cout<<"palindrome or not: "<<palindrome(temp);

// }




                                                    // program for adding string inplace of space



// int main(){
//     string s="saswat singh";
//     string temp;
//     for(int i=0;i<s.length();i++){
//         if(s[i]==' '){
//             temp.push_back('@');
//             temp.push_back('4');
//             temp.push_back('0');
//         }
//         else{
//             temp.push_back(s[i]);
//         }
//     }
//     cout<<temp;
    
// }



                                                //program to fin the maximum occurence of a character in string

// int main(){
//     string s="saswatttttaa singh";
//     int maxi=0;
//     char ch;
//     for(int i=0;i<s.length();i++){
//         int temp=s[i];
//         int count=0;
//         for(int j=i;j<s.length();j++){
//             if(s[j]==temp){
//                 count++;
//             }
//         }
//         if(count>maxi){
//             maxi=count;
//             ch=s[i];
//         }
//     }
//     cout<<maxi<<endl;
//     cout<<ch;
// }

#include<stack>
string removee(string s1){
    stack<char> st;

    int i=0;
    while(i<=s1.length()){
        if(st.empty()||s1[i]!=st.top()){
            st.push(s1[i]);
            i++;
        }
        else{
            st.pop();
            i++;
        }
    }
        string x="";
    if(st.empty()){
        while(!st.empty()){
            x=st.top()+x;
            st.pop();
        }
    }
   return x;
}

int main(){
  string s="abbaca";
cout<<removee(s);

}