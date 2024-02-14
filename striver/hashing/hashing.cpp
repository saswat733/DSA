#include<bits/stdc++.h>     
using namespace std;

//key learnings
// in map any data structure can be stored as key but in unordered map key can be only string ,char, int,float etc


//program for printing the count of elements in array using hashing
/*

size:
5
enter element: 1 3 2 1 3
5
1 4 2 3 12

2
0
1
2
0

*/


// int main(){
//     int n;
//     cout<<"size:"<<endl;
//     cin>>n;
//     int arr[n];
//     //filling the array with elements
//     cout<<"enter element: ";
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
        
//     }
//     //describing the hash array with all elements initialy as zero
//     int hash[13]={0};
//     //elements of array acts as index and increaes the value of individual elements in hash array
//     for(int i=0;i<n;i++){
//         hash[arr[i]]+=1;
//     }

//     //seraching for the given numbers in hash array
//     int q;
//     cin>>q;
//     while(q--){
//         int number;
//         cin>>number;
//         cout<<hash[number]<<endl;
//     }

// }



// problem-2 character hashing and solving
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    // Initialize hash array with all zeros
    int hash[26] = {0};

    // Calculate frequencies of each character in the input string
    for (char c : s) {
        hash[c - 'a']++;
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--) {
        char ch;
        cout << "Enter character to query: ";
        cin >> ch;

        // Check if the character is a lowercase letter
        if (ch >= 'a' && ch <= 'z') {
            cout << "Frequency of " << ch << ": " << hash[ch - 'a'] << endl;
        } else {
            cout << "Invalid character input. Please enter a lowercase letter." << endl;
        }
    }

    return 0;
}
*/


// using c++ stl mapping to make it more efficient hahsing as in map we stores only thos elements which are required

/*map stores all the key->value(frequency) pairs in sorted order according to key*/
                    // time complexity : O(logN) in all cases where N is no. f elements stored in map
/*

enter:
7
1 2 3 1 3 2 12
1->2
2->2
3->2
12->1
5
1 2 3 4 12
22201

*/
// int main(){
//     int n;
//     cout<<"enter:"<<endl;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>> arr[i];
//     }

//     //pre-compute mapp
//     map<int,int> mpp;
//     for(int i=0;i<n;i++){
//         mpp[arr[i]]++;
//     } 

//     //printing the mapp
//     for(auto it:mpp){
//         cout<<it.first<<"->"<<it.second<<endl;
//     }

//     int q;
//     cin>>q;
//     while(q--){
//         int num;
//         cin>>num;
//         //fetch
//         cout<<mpp[num];

//     }
//     return 0;

// }



//for string using mapp

/*
int main(){
    string s;
    cout<<"enter:"<<endl;
    cin>>s;

    map<char,int> mpp;

    for(int i=0;i<26;i++){
        mpp[s[i]-'a']++;
    }

    for(auto i:mpp){
        cout<<i.first<<"->"<<i.second<<endl;
    }

    int q;
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        cout<<mpp[ch-'a']<<" ";
    }
}

*/



                        // using unordered_map we will solve the questions this returns the mappings in unordered ways which is unsorted 
                    // time complexity is : O(1) for average and best case O(N) for worst case where N is no. of elements stored in map
/*

enter:
5
1 2 33 45 6
6->1
45->1
33->1
2->1
1->1
5
33 60 59 60 2
10001

*/

// int main(){
//     int n;
//     cout<<"enter:"<<endl;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>> arr[i];
//     }

//     //pre-compute mapp
//     unordered_map<int,int> mpp;
//     for(int i=0;i<n;i++){
//         mpp[arr[i]]++;
//     } 

//     //printing the mapp
//     for(auto it:mpp){
//         cout<<it.first<<"->"<<it.second<<endl;
//     }

//     int q;
//     cin>>q;
//     while(q--){
//         int num;
//         cin>>num;
//         //fetch
//         cout<<mpp[num];

//     }
//     return 0;

// }


void getFrequencies(vector<int>& v) {
    // Write Your Code Here
    vector<int> result;
    map<int,int> mpp;
    for(int i=0;i<v.size();i++){
        mpp[v[i]]++;
    }

    for(auto i:mpp){
       cout<<i.second
    }
    
    
}

int main(){
    vector<int> arr{1,2,3,1,1,4};
    getFrequencies(arr);
    // for(int i=0;i<result.size();i++){
    //     cout<<result[i];
    // }

}