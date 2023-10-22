#include <iostream>
using namespace std;
#include<vector>

    // int a[4][4] = {{10, 22, 33, 40}, {1, 39, 44, 11}, {50, 60, 14, 36}, {23, 5, 6, 0}};         //program to print the matrix in wave
    // for (int i = 0; i < 4; i++)
    // {

    //     if (i % 2 == 0)    //if column is even then top to bottom 
    //     {
    //         for (int j = 0; j < 4; j++)
    //         {
    //             cout << a[j][i] << " ";
    //         }
    //     }

    //     else   //else bottom to top
    //     {
    //         for (int j = 4 - 1; j >= 0; j--)
    //         {
    //             cout << a[j][i] << " ";
    //         }
    //     }
    // }



                                    //printing the matrix in spiral form
    
    // vector<vector <int>> a{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // vector<int> ans;
    // int m=a.size();
    // int n=a[0].size();
    // int total_ele=m*n;
    // int start_row=0;
    // int last_col=n-1;
    // int last_row=m-1;
    // int first_col=0;
    // int count=0;
    // while(count<total_ele){

    //     //print first row
    //     for(int i=first_col;i<last_col && count>total_ele;i++){
    //         ans.push_back(a[start_row][i]);
    //         count++;
    //     }
    //     start_row++;

    //     //print last column
    //     for(int i=start_row;i<=last_row && count>total_ele;i++){
    //         ans.push_back(a[last_col][i]);
    //         count++;
    //     }
    //     last_col--;

    //     //print last row
    //     for(int i=last_col;i>=first_col && count>total_ele;i--){
    //         ans.push_back(a[last_row][i]);
    //         count++;
    //     }
    //     last_row--;

    //     //print first column
    //     for(int i=last_row;i>=start_row && count>total_ele;i--){
    //         ans.push_back(a[first_col][i]);
    //         count++;
    //     }
    //     first_col++;

    // }
// }





// int main(){                                  //program for printing the maximum row index and sum
//     int a[4][3];
//     for(int i=0;i<3;i++){
//         for(int j=0;j<4;j++){
//             cin>>a[i][j];
//         }
//     }

//     for(int i=0;i<3;i++){
//         for(int j=0;j<4;j++){
//             cout<<a[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     int maxi=-1;
//     int index=-1;

//     for(int i=0;i<3;i++){
//     int sum=0;
//         for(int j=0;j<4;j++){
//             sum+=a[i][j];
//         }
//         if(sum>maxi){
//             maxi=sum;
//             index=i;
//         }

//     }
//         cout<<maxi<<endl;
//         cout<<index;

// }

                                                //program to rotate a 2D matrix by 90deg
// int main(){
//     vector<vector <int>> a{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
//     int m=a.size();
//     int n=a[0].size();
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cout<<a[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;
//     for(int i=0;i<m;i++){
//         for(int j=n-1;j>=0;j--){
//             cout<<a[j][i]<<" ";
//         }
//         cout<<endl;
//     }
// }


// int binary(vector<vector<int>> a,int key){               //binary search on a 2D matrix
//     int row=a.size();
//     int column=a[0].size();
//     int total=row*column;
   
//     int start=0;
//     int end=total;
//     int mid=start+(end-start)/2;
//     while(start<=end){
//        int ele=a[mid/column][mid%column];
//        if(ele==key){
//         return 1;
//        }
//        else if(ele>key){
//         end=mid-1;
//        }
//        else{
//         start=mid+1;
//        }
//        mid=start+(end-start)/2;
//     }
//     return 0;
// }
// int main(){
//     vector<vector <int>> a{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
//     binary(a,4);
// }



// int binary(vector<vector<int>> matrix,int target){   //program for searching the ele in 2D matrix II
//     int row=matrix.size();
//     int column=matrix[0].size();
//     int rowindex=0;
//     int colindex=column-1;
//     while(rowindex<row && colindex>=0){
//         int ele=matrix[rowindex][colindex];
//         if(ele==target){
//             return 1;
//         }
//         else if( ele<target){
//             rowindex++;
//         }
//         else{
//             colindex--;
//         }
//     }
   
//         return 0;
    

// }
// int main(){
//     vector<vector<int>> matrix{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    
//     if(binary(matrix,20)){
//         cout<<"yes";

//     }
//     else{
//         cout<<"no";
//     }

// }

int main(){
    int a[2][3]={{1,2,3},{4,5,6}};
    cout<<size(a[0]);
}