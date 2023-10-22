#include<iostream>                  //pointers always take same memory of 8 bits irrespective of the data type
using namespace std;
int main(){
    // int a=5;
    // int b=6;
    // int *p=&a;

    // cout<<"before:"<<p<<endl;
    // p=p+1;                                           //it will increase the address
    // cout<<"after:"<<p<<endl;

    // cout<<"b:"<<&b;




    // int arr[5]={12,13,14,15,16};        //array
    // int *p=arr;

    
    // cout<<*arr;
    // for(int i=0;i<5;i+=1){
    // // cout<<*(arr)+i<<" ";
    // // cout<<i[arr]<<" ";          //another method
    
    // // cout<<*(p+i)<<" ";
    // }




    // char ch[6]="abcde";
    // int a[5]={1,2,3,4,5};
    // cout<<a<<endl;
    // cout<<ch<<endl;         //print abcde

    // cout<<&ch[0];           //prints abcde
    

    // char a='x';         // gives error
    // char *p=&a;
    // cout<<p;


    // int a=5;
    // int *p=&a;
    // int **ptr=&p;        //double pointer
    // cout<<"a:"<<&a<<endl;
    // cout<<"p:"<<p<<endl;
    // cout<<"ptr:"<<*ptr<<endl;
    

    // int first=5;
    // int second=2;
    // int *ptr=&second;
    // *ptr=9;
    // cout<<first<<" "<<second;            //5 9


    // int first=6;
    // int *p=&first;
    // int *q=p;
    // (*q)++;
    // cout<<first<<endl;       // 7

    // int first=8;
    // int *p=&first;
    // cout<<(*p)++<<endl;      // 8
    // cout<<first<<endl;       //9


    // int *p=0;
    // int first=10;
    // *p = first;              //error ayga
    // cout<<*p<<endl;


    // int first=8;
    // int second=11;
    // int *third=&second;
    // first=*third;
    // *third=*third+2;
    // cout<<first<<" "<<second<<endl;  //11 13

    // float f=12.5;
    // float p=21.5;
    // float * ptr=&f;
    // (*ptr)++;
    // *ptr=p;
    // cout<<*ptr<<" "<<p<<" "<<f<<endl;       //21.5 21.5  21.5


    // int arr[6]={1,2,3,4};
    // cout<<arr<<" "<<&arr;            //same address print hoga

    // int *p=arr;
    // cout<<p[2]<<endl;           // 2

     
    

    // char arr[]="abcde";
    // char *p=&arr[1];
    // cout<<p<<endl;          //prints abcde
    // cout<<*p<<endl;          //prints a


    //   char arr[]="abcde";
    // char *p=&arr[0];
    // p++;
    // cout<<p;        //prints bcde


    // char str[]="saswat";
    // char *p=str;
    // cout<< str[0]<<" "<<p[0]<<endl;      //s s



    // int first=110;
    // int *p=&first;
    // int **q=&p;
    // int second=(**q)++ +9;
    // cout<<first<<" "<<second<<endl;     //111 119


    // int first=100;
    // int *p=&first;
    // int **q=&p;
    // int second=++(**q);
    // int *r=*q;
    // ++(*r);
    // cout<<first<<" "<<second;       //102 101
}   