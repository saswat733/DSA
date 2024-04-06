#include<iostream>
#include<string>
#include<stack>
using namespace std;


// Maximum Nesting Depth Of The Parentheses 

int maxDepth(string s) {
	int count=0;
    int maxCount=0;
    int i=0;
   for(char c:s){
    if(c=='('){
        count++;
        
        if(maxCount<count){
            maxCount=count;
        }
    }
    if(c==')'){
        count--;
    }
    
   }
   return maxCount;
}

// reverse a single string
string reverseSingleString(string &str){
	int start=0;
    int end=str.length()-1;
    while(start<=end){
        swap(str[start++],str[end--]);
    }
    return str;
}

//program for reversing the word of sentence

//brute force using stack
string reverseString(string str) {
    // Create a stack to store words
    stack<string> st;
    // Append a space at the end of the input string to ensure the last word is processed
    str += " ";
    // Initialize an empty string to store a word
    string word = "";
    // Iterate through each character in the input string
    for (int i = 0; i < str.length(); i++) {
        // If the current character is a space, it indicates the end of a word
        if (str[i] == ' ') {
            // Push the word onto the stack
            st.push(word);
            // Reset the word for the next iteration
            word = "";
        } else {
            // If the current character is not a space, append it to the current word
            word += str[i];
        }
    }

    // Initialize an empty string to store the reversed string
    string ans = "";
    // Pop each word from the stack and append it to the result string
    while (st.size() != 1) {
        ans += st.top() + " ";
        st.pop();
    }
    // Append the last word without space
    ans += st.top();

    // Return the reversed string
    return ans;
}


//optimal code
#include <stack>
#include <string>

using namespace std;

string reverseString(string s) {
    stack<string> words;
    string temp = "";

    for (char ch : s) {
        if (ch == ' ') {
            if (!temp.empty()) {
                words.push(temp);
                temp = "";
            }
        } else {
            temp += ch;
        }
    }

    // Push the last word
    if (!temp.empty()) {
        words.push(temp);
    }

    // Reconstruct the string
    string ans = "";
    while (!words.empty()) {
        ans += words.top();
        words.pop();
        if (!words.empty()) {
            ans += " ";
        }
    }

    return ans;
}


//getting the odd numbers from string
string largestOddNumber(string num) {
        int test=num;
        if(test%2!=0){
            return num;
        }
        else{
            int max=0;
            stirng ans="";
            for(int a:num){
                if(a%2!=0){
                    max=a;
                }
                if(max>ans){
                    ans=to_string(max);
                }
            }
            return ans;
        }
        return -1;
}

int main(){
    string s="saswat singh";
    string ans=reverseString(s);
    cout<<ans;
}