// objects are the instance of class
// a empty class have the size of 1 ****

// two concepts ========>>>> padding and greedy alignment

// padding means it is like the number of data members * max datatype size  ===> the size of class is 8 bytes even if it have a char and int as private members as it add padding of 3

// #include <iostream>
// #include <string.h>
// using namespace std;

// class hero
// {
// private:
//     int height;
//     char level;

// public:
//     char *name;

//     hero()
//     {
//         cout << "constructor is called!" << endl;
//         name = new char[100];
//     }

//     // parameterarised constructor
//     hero(int height, char level, char name[])
//     {
//         // cout<<"the constrctor address is:"<<this<<endl;
//         // cout<<"constructor hu bhai!";

//         this->height = height;
//         this->level = level;
//         this->name = name;
//     }

//     hero(hero& temp){
//         char *ch=new char[strlen(temp.name)+1];
//         strcpy(ch,temp.name);
//         this->name=ch;
//         this->height=temp.height;
//         this->level=temp.level;
//     }

//     void print()
//     {
//         cout << "[ height:" << this->height;
//         cout << " level:" << this->level;
//         cout << " name:" << this->name;
//         cout << "]" << endl;
//     }
//     void setheight(int x)
//     {
//         height = x;
//     }

//     void setlevel(char a)
//     {
//         level = a;
//     }

//     void getheight()
//     {
//         cout << height;
//     }

//     void getlevel()
//     {
//         cout << level;
//     }
//     void setname(char name[])
//     {
//         strcpy(this->name, name);
//     }
// };

// int main()
// {

//     // declaring class statically
//     //  hero h1(10,'a');
//     //  h1.print();
//     //
//     // hero h2(h1);                    //copy constructor
//     // h2.print();

//     // h1.setheight(40);
//     // cout<<"the static heihgt is:";
//     // h1.getheight();cout<<endl;
//     // declaring class dynamically
//     // cout<<"the addres is:"<<&h1;
//     // cout<<endl;
//     // hero *h=new hero(10);

//     // h->setheight(5);
//     // cout<<"the dynamic heihgt is:";
//     // h->getheight();

//     // cout<<"size:"<<sizeof(h1);     prints 8 because of padding

//     // shallow copy and deep copy

//     //in shallow copy we access the same memory

//     // hero h1;
//     // h1.setheight(20);
//     // h1.setlevel('a');
//     // char namee[7] = "saswat";
//     // h1.setname(namee);
//     // // h1.setname(namee);
//     // h1.print();

//     // h1.name[0] = 'a';
//     // h1.print();

//     // hero h2(h1);
//     // h2.print();

//     //in deep copy another copy is created 

//     hero h1;
//     h1.setheight(20);
//     h1.setlevel('a');
//     char namee[7] = "saswat";
//     h1.setname(namee);
//     // h1.setname(namee);
//     h1.print();
//     hero h2(h1);
    
//     h2.print();

//     h1.name[0] = 'a';
//     h1.print();

//     h2.print();

// }



                                //operator overloading
#include<iostream>
using namespace std;

class b
{
private:
public:
    int a;
    void operator+ (b &obj){
        cout<<"heloo"<<endl;
    }
    void operator() (){
        cout<<"namaste "<<this->a<<endl;
    }

};



int main(){
    b obj1,obj2;
    obj1.a=4;
    obj2.a=5;
    obj1+obj2;
    obj1();
    obj2();


}