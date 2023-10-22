
// #include<iostream>
// using namespace std;
// struct queue{
//     int size;
//     int front;
//     int rear;
//     int a[100];
// };

// void create(struct queue *q,int size){
//     q->size=size;
//     q->front=q->rear=-1;
//     q->a[q->size];
// }
// void enqueue(struct queue *q,int x){
//     if(q->rear==q->size-1){
//         printf("Queue is full\n");
//     }
//     else{
//         q->rear++;
//         q->a[q->rear]=x;
//     }
// }

// int dequeue(struct queue *q){
//     int x=-1;
//     if(q->front==q->rear){
//         printf("queueu is empty\n");
//     }
//     else{
//         q->front++;
//         x=q->a[q->front];
//     }
//     return x;
// }

// void displayy(struct queue q){
//     for(int i=q.front+1;i<=q.rear;i++){
//         printf("%d ",q.a[i]);
//     }
//     printf("\n");

// }
// int main(){
//     struct queue q;
//     // printf("enter the size:");
//     // scanf("%d",&q.size);
//     create(&q,5);
//     // q.front=q.rear=-1;
//     enqueue(&q,12);
//     enqueue(&q,17);
//     enqueue(&q,19);
//     int x=dequeue(&q);
//     cout<<"deleted ele: "<<x<<endl;
//     displayy(q);
//     cout<<q.front<<endl;
//     cout<<q.rear;

// }

// #include <iostream>
// using namespace std;
// int queue[100], n = 100, front = - 1, rear = - 1;
// void Insert() {
//    int val;
//    if (rear == n - 1)
//    cout<<"Queue Overflow"<<endl;
//    else {
//       if (front == - 1)
//       front = 0;
//       cout<<"Insert the element in queue : "<<endl;
//       cin>>val;
//       rear++;
//       queue[rear] = val;
//    }
// }
// void Delete() {
//    if (front == - 1 || front > rear) {
//       cout<<"Queue Underflow ";
//       return ;
//    } else {
//       cout<<"Element deleted from queue is : "<< queue[front] <<endl;
//       front++;
//    }
// }
// void Display() {
//    if (front == - 1)
//    cout<<"Queue is empty"<<endl;
//    else {
//       cout<<"Queue elements are : ";
//       for (int i = front; i <= rear; i++)
//       cout<<queue[i]<<" ";
//          cout<<endl;
//    }
// }
// int main() {
//    int ch;
//    cout<<"1) Insert element to queue"<<endl;
//    cout<<"2) Delete element from queue"<<endl;
//    cout<<"3) Display all the elements of queue"<<endl;
//    cout<<"4) Exit"<<endl;
//    do {
//       cout<<"Enter your choice : "<<endl;
//       cin>>ch;
//       switch (ch) {
//          case 1: Insert();
//          break;
//          case 2: Delete();
//          break;
//          case 3: Display();
//          break;
//          case 4: cout<<"Exit"<<endl;
//          break;
//          default: cout<<"Invalid choice"<<endl;
//       }
//    } while(ch!=4);
//    return 0;
// }



#include<iostream>
using namespace std;
int arr[10];
int front=-1,rear=-1,sizee=5;
   
void push(){
   int ele;
   if(rear==sizee-1){
      cout<<"queue is underflow";

   }
   else{
      if(front==-1){
      front=0;
      }
      else{
         rear++;
         cout<<"\nenter the element:";
         cin>>ele;
         arr[rear]=ele;
      }
   }
}
void deletee(){
   if(front==-1){
      cout<<"queue is underflow.";
   }
   else{
      cout<<"the deleted element is:"<<arr[front];
      front++;
   }
}
int main(){
   int choice;
   cout<<"1.push\n";
   cout<<"2.delete\n";
   cout<<"3.exit\n";
   do{
   cout<<"enter the choice:";
   cin>>choice;
   switch (choice)
   {
   case 1:
     push();
      break;
   case 2:
     deletee();
      break;
   case 3:
   cout<<"exit";
   break;
      default:
      cout<<"enter valid number"; 
   }
   }while(choice!=3);
}