/**
  Copyright (c) 2024

  Name: MUHAMMAD AHMAD.

  Project Name: PF.

  Date: 2024-10-24.

  TIME: 6:13 PM.
*/
//#include <iostream>
//using namespace std;
//#define MAX 100 // Maximum size of the stack
//
//class StackArray {
//private:
//    int arr[MAX]; // Array to store stack elements
//    int top;      // Index of the top element
//
//public:
//    // Constructor to initialize stack
//    StackArray() {
//        top = -1;
//    }
//
//    // Push operation: Adds element to the top of the stack
//    void push(int x) {
//        if (top >= (MAX - 1)) {
//            cout << "Stack Overflow\n";
//            return;
//        }
//        arr[++top] = x;
//        cout << x << " pushed to stack\n";
//    }
//
//    // Pop operation: Removes the top element
//    void pop() {
//        if (top < 0) {
//            cout << "Stack Underflow\n";
//            return;
//        }
//        int x = arr[top--];
//        cout << x << " popped from stack\n";
//    }
//
//    // Peek operation: Returns the top element without removing it
//    int peek() {
//        if (top < 0) {
//            cout << "Stack is Empty\n";
//            return -1;
//        }
//        return arr[top];
//    }
//
//    // Check if the stack is empty
//    bool isEmpty() {
//        return (top < 0);
//    }
//};
//
//int main() {
//    StackArray stack;
//    stack.push(10);
//    stack.push(20);
//    stack.push(30);
//    cout << "Top element is " << stack.peek() << endl;
//    stack.pop();
//    cout << "Top element is " << stack.peek() << endl;
//    return 0;
//}
#include "iostream"
using namespace std;

 class Stack{
 private:
     int* arr;       // dynamic array set size at run time
     int capacity;  // initial size
     int top;      // pointer to handle the stack top
 public:
     Stack(int size){
         arr = new int[size];
         capacity=size;
         top=-1;
     }
     virtual ~Stack() {
         delete[] arr;
     }

     bool isEmpty(){
         if (top==-1){
             return true;
         }
         return false ;
     }
     bool isfull(){
         if (top==-capacity){
             return true;
         }
         return false ;
     }

     void push(int value){
         if(isfull()){
             cerr << "Stack overflow";
         }
         arr[++top]=value;
         cout << value << " pushed on stack";
     }
     void pop(){
         if (isEmpty()){
             cerr << "Stack underflow";
         }
         cout << arr[top--] << " is poped";
     }
     int peek(){
         if (isEmpty()){
             cerr << "Stack underflow";
         } else{
         return arr[top];
         }
     }

 };

 int main(){
     Stack stack(5);
     //cout << stack.isfull();
     stack.push(34);
     stack.push(30);
     stack.push(38);
     stack.push(37);
     stack.push(34);

     cout << stack.isEmpty();
     return 0;
 }