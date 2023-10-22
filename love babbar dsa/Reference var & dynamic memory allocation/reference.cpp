// #include<iostream>
// using namespace std;
// //when the variable adress is passed to another variable without creating another address and both the variables acts on same memory 
// void update(int &a){        //just passing the reference of the variable
//     a++;
// }
// int main(){
//     int a=5;
//     int &b=a;           //creating a reference variable
//     int c=10;
//     cout<<b<<endl;
//     b++;
//     cout<<a<<endl;
//     a++;
//     cout<<b<<endl;
//     cout<<a<<endl;
//     cout<<"value of c:"<<c<<endl;
//     update(c);
//     cout<<"value of c:"<<c;

// }




        //dynamic meomory allocation of array


// #include <iostream>
// using namespace std;
// int sum(int arr[],int n){
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=arr[i];
//     }
//     return sum;
// }
// int main(){
//     int n;
//     cout<<"enter:";
//     cin>>n;
//     int *arr=new int[n];       //it takes 8 memory extra in stack and remaining in heap

//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     int ans=sum(arr,n);
//     cout<<"sum:"<<ans;

// }




            //dynamic memory allocation of 2D array

#include<iostream>
using namespace std;
// int main(){
//     int row;
//     cin>>row;
//     int col;
//     cin>>col;
//     int **arr=new int*[row];          //creating the 2D array
    
//     for(int i=0;i<row;i++){
//         arr[i]=new int[col];
//     }

//     //taking input
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             cin>>arr[i][j];
//         }
//     }


//     //taking output
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }


//     //deleting the memory

//      for(int i=0;i<row;i++){
//        delete [] arr[i];
//     }

//     delete []arr;




// }



#include<vector>                //creating a jaggered array
int main(){
    int row;
    cin>>row;
    vector<int> a;
    int **arr=new int*[row];
    for(int i=0;i<row;i++){
        int col;
       cout<<"enter column:";
       cin>>col;
       a.push_back(col);
       arr[i]=new int[col];

        cout<<endl;
       cout<<"input:";
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }

    

    //output
    for(int i=0;i<row;i++){
        for(int j=0;j<a[i];j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


     // Deallocate the memory when done
    for (int i = 0; i < row; i++) {
        delete[] arr[i]; // Delete each row
    }
    delete[] arr; // Delete the array of row pointers



}