#include "iostream"
using namespace std;
int main()
{

    //  * * * * * * * *
    //  *             *
    //  * * * * * * * *
    // int n;
    // cin>>n;
    // for (int i = 0; i < 3; i++)
    // {
    //     if (i == 0  || i == 2)
    //     {
    //         for(int j=0;j<5;j++){
    //             cout<<"* ";
    //         }

    //     }
    //     else{
    //      cout<<"* ";
    //      for(int j=0;j<5-2;j++){
    //         cout<<"  ";

    //      }
    //      cout<<"* ";

    //     }
    //     cout << endl;
    // }

    // 2nd way to solve the same problem

    /* for(int i=0;i<3;i++){
          if(i==0 || i==2){
              for(int j=0;j<5;j++){
              cout<<"*";
              }
              cout<<endl;
          }
          else{
              for(int j=0;j<5;j++){
                  if(j==0 || j==4){
                      cout<<"*";
                  }
                  else{
                      cout<<" ";
                  }
              }
              cout<<endl;

          }

       }*/

    // for(int i=0;i<3;i++){
    //     if(i==0 || i==2){
    //         for(int j=0;j<5;j++){
    //             cout<<"* ";
    //         }
    //     }
    //     else{
    //         for(int j=0;j<5;j++){
    //        if(j==0 || j==4){
    //         cout<<"* ";
    //        }
    //        else{
    //         cout<<"  ";
    //        }

    //         }
    //     }
    //     cout<<endl;
    // }

    /*

     *
     **
     ***
     ****

    */
    //    int n;
    //    cin>>n;
    //    for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    //    }

    /*
                1
                12
                123
                1234
                12345
     */
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){

    //     for(int j=1;j<i+2;j++){
    //         cout<<j;
    //     }
    //     cout<<endl;
    // }

    // for(int i=0;i<n;i++){

    //     for(int j=0;j<i+1;j++){
    //         cout<<j+1;
    //     }
    //     cout<<endl;
    // }

    /*
                12345
                1234
                123
                12
                1

    */
    //    int n;
    //    cin>>n;
    //    for(int i=0;i<n;i++){

    //         for(int j=0;j<n-i;j++){
    //             cout<<j+1;
    //         }
    //         cout<<endl;
    //     }

    /*
     *
     * *
     * * *
     */
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<i+1;j++){
    //         cout<<"* ";
    //     }
    //     // for(int j=1;j<i;j++){
    //     //     cout<<"*";
    //     // }
    //     cout<<endl;
    // }
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<n-i;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    /*
        ***********
        *        *
        *       *
        *      *
        *     *
        *    *
        *   *
        *  *
        * *
        *

    */

    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     if (i == 0 || i == n-1)
    //     {
    //         for (int j = 0; j < n - i; j++)
    //         {
    //             cout << "* ";
    //         }
    //     }
    //     else
    //     {
    //         cout << "* ";
    //         for (int j = 1; j < n - i - 1; j++)
    //         {
    //             cout << "  ";
    //         }
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(i==n-1||j==n-1||j==n-i-1){
    //        cout<<"*";
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

    /*
     *
     * *
     *   *
     * * * *
     */
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i;j++){
    //         cout<<" ";
    //     }
    //    for(int j=0;j<n;j++){
    //     if(j==0||i==n-1||j==i){
    //     cout<<"* ";

    //     }
    //     else{
    //         cout<<"  ";
    //     }
    //    }

    //     cout<<endl;
    // }

    /*
     *
     * *
     * * *
     * * * *
     * * *
     * *
     *
     */
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<i+1;j++){
    //         cout<<"* ";
    //     }

    //     // cout<<endl;

    //     cout<<endl;
    // }
    // // cout<<endl;
    // for(int i=0;i<n;i++){
    //      for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     // cout<<endl;
    //     for(int j=0;j<n-i;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;

    // }



/*

        *
       * *
      *   *
     *     *
     *     *
      *   *
       * *
        *

*/
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<2*i+1;j++){
    //         if(j==2*i||j==0){
    //         cout<<"*";
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }



    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<2*n-1;j++){
    //         if(j==(2*n-2*i-1)-1||j==0){
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }


/*

        ********
        ***  ***
        **    **
        *      *
        *      *
        **    **
        ***  ***
        ********

*/

    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i;j++){
    //         cout<<"*";
    //     }
    //     for(int j=0;j<2*i+1;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<n-i;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i+1;j++){
    //         cout<<"*";
    //     }
    //     for(int j=0;j<2*n-2*i-1;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<i+1;j++){
    //         cout<<"*";

    //     }
    //     cout<<endl;
    // }



/*

1
2*2
3*3*3
3*3*3
2*2
1

*/
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<2*i+1;j++){
    //         if(j%2!=0){
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<i+1;
    //         }
    //     }
        
    //     cout<<endl;
    // }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<2*n-2*i-1;j++){
    //         if(j%2!=0){
    //             cout<<"*";
    //         }
    //         else{

    //         cout<<n-i;
    //         }


    //     }
    //     cout<<endl;
    // }




/*

1
121
12321
1234321

*/
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int j;
    //     for( j=0;j<i+1;j++){
    //         cout<<j+1;
    //     }
    //     j--;
    //     for(;j>=1;j--){
    //         cout<<j;
    //     }
    //     cout<<endl;
    // }


/*

a
aba
abcba
abcdcba

*/
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int j;
    //     for( j=0;j<i+1;j++){
    //         char ch='a'+j;
    //         cout<<ch;
    //     }
    //     j=j-1;
    //     for(;j>=1;j--){
    //         char ch='a'+j-1;
    //         cout<<ch;
    //     }
    //     cout<<endl;
        
    // }

/*

        1
       232
      34543

*/
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i-1;j++){             //for space
    //         cout<<" ";
    //     }


    //     int k;

    //     for(int j=0;j<i+1;j++){             //for pyramid 1
    //         k=i+j+1;
    //         cout<<k;
    //     }

    //     k--;

    //     for(;k>i;k--){              //for pyramid 2
    //         cout<<k;
    //     }

    //     cout<<endl;
    // }



//     1
//    1 2
//   1   3
//  1     4
// 1 2 3 4 5



    // int n;
    // cin>>n;
   
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }
    //      int k=1;
    //    for(int j=0;j<2*i+1;j++){
        
    //     if(i==0||i==n-1){
    //         if(j%2==0){

    //             cout<<k;
    //             k+=1;
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }

    //     else{
    //         if(j==0){
    //             cout<<1;
    //         }
    //         else if(j==2*i+1-1){
    //             cout<<i+1;
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }
    //    }
    //     cout<<endl;
    // }

    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }
    //     int k=1;
    //     for(int j=0;j<2*i+1;j++){
    //         if(i==0 || i==n-1){                  // for printeing first and last rows since they are same
    //             if(j%2==0){
    //             cout<<k++;
    //             }
    //             else{
    //                 cout<<" ";
    //             }
    //         }
    //         else{                    //for printing the last and first column of rows in between
    //             if(j==0){
    //                 cout<<1;
    //             }
    //             else if (j==2*i)
    //             {
    //                 cout<<i+1;
    //             }
    //             else{
    //                 cout<<" ";
    //             }
                
    //         }
    //     }
    //     cout<<endl;
    // }


/*


  *****     *****
 *******   *******
********* *********
******************
  **************
    **********
      ******
        **

*/

    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }

    //     for(int j=0;j<2*i+1;j++){
    //         if(i==0||i==1){
    //             cout<<" ";
    //         }
    //         else{
    //             cout<<"*";
    //         }
    //     }

    //     for(int j=0;j<2*n-2*i-1;j++){
    //         cout<<" ";
    //     }

    //     for(int j=0;j<2*i+1;j++){
    //         if(i==0||i==1){
    //             cout<<" ";
    //         }
    //         else{
    //             cout<<"*";
    //         }
    //     }
        
    //     cout<<endl;
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<2*i;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<2*n-2*i-1;j++){
    //         cout<<"*";
    //     }
    //     for(int j=0;j<2*n-2*i-1;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

/*

1 2 3 4 5
2     5
3   5
4 5
5

*/
    // int n;
    // cin>>n;
    
    // for(int i=0;i<n;i++){
    //     int k=0;
    //     for(int j=0;j<2*n-2*i-1;j++){
            
    //         if(i==0){
    //             if(j%2!=0){
    //                 cout<<" ";
    //             }
    //             else{
    //                 cout<<k+1;
    //                 k++;
    //             }
    //         }
    //         else{
    //             if(j==0){
    //                 cout<<i+1;
    //             }
    //             if(j==2*n-2*i-3){
    //                 cout<<5;
    //             }
    //             else{
    //                 cout<<" ";
    //             }
    //         }
    //     }
    //     cout<<endl;
    // }



//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++){
//     for(int j=i+1;j<=n;j++){
//         if(i==0||i==n-1){
//         cout<<j;
//         }
//         else{
//             if(j==i+1||j==n){
//                 cout<<j;
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//     }
//     cout<<endl;
//    }



/*

     1
    121
   12321
  1234321
 123454321

*/
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i;j++){
    //         cout<<" ";
    //     }
    //     int k;
    //     for(k=1;k<=i+1;k++){
    //         cout<<k;
    //     }
    //     k-=2;
    //     for(;k>=1;k--){
    //             cout<<k;
    //     }
    //     cout<<endl;
    // }

/*

********1********
*******2*2*******
******3*3*3******
*****4*4*4*4*****
****5*5*5*5*5****

*/

    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<2*n-i-2;j++){
    //         cout<<"*";
    //     }
    //     for(int j=0;j<2*i+1;j++){
    //         if(j%2!=0){
    //         cout<<"*";
    //         }
    //         else{
    //             cout<<i+1;
    //         }
    //     }
    //      for(int j=0;j<2*n-i-2;j++){
    //         cout<<"*";
    //     }

    //     cout<<endl;
    // }

/*

1
2*3
4*5*6
7*8*9*10
11*12*13*14*15

*/
    // int n;
    // cin>>n;
    // int k=1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<2*i+1;j++){
    //         if(j%2!=0){
    //         cout<<"*";
    //         }
    //         else{
    //             cout<<k++;
    //         }
    //     }
    //     cout<<endl;
    // }


/*

*
*1*
*121*
*12321*
*121*
*1*
*

*/
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int k;
    //     for(k=0;k<=i;k++){
    //         if(k==0){
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<k;
    //         }
    //     }
    //     k-=2;
    //     for(;k>=0;k--){
    //         if(k==0){
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<k;
    //         }
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<n-1;i++){
    //     int j;
    //     for( j=0;j<n-i-1;j++){
    //         if(j==0){
    //         cout<<"*";
    //         }
    //         else{
    //             cout<<j;
    //         }
    //     }
    //     j-=2;
    //     for(;j>=0;j--){
    //         if(j==0){
    //             cout<<"*";
    //         }
    //         else{
    //         cout<<j;
    //         }
    //     }
    //     cout<<endl;
    // }

/*

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 17 18 19 20 21
22 23 24 25 26 27 28
29 30 31 32 33 34 35 36 
37 38 39 40 41 42 43 44 45

*/

    // int n;
    // cin>>n;
    //  int k=1;
    // for(int i=0;i<n;i++){
       
    //     for(int j=0;j<i+1;j++){
    //         cout<<k<<" ";
    //         k=k+1;
    //     }
    //     cout<<endl;
    // }

/*

    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

*/
    // int n;
    // cin>>n;
    // for(int i=1;i<=n;i++){
    //     int c=1;
    //     for(int j=0;j<n-i;j++){
    //         cout<<" ";
    //     }
    //     for(int j=1;j<=i;j++){
    //         cout<<c<<" ";
    //         c=c*(i-j)/j;                     //formula
    
    //     }
       
    //     cout<<endl;
    // }



}