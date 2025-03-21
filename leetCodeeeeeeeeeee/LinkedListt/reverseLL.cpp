/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-11-27.  
           
  TIME: 12:56 AM.
*/
#include <iostream>
#include "stack"
#include "queue"
using namespace std;
 struct ListNode {
         int val;
         ListNode *next;
        ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };


ListNode* rotate(ListNode* head) {

}
ListNode* rotateRight(ListNode* head, int k) {
}
//-------------------
int main(){
    return 0;
}


ListNode* reverseList(ListNode* head) {
    stack<int> stack;
    while (head->next){
        stack.push(head->val);
        //delete head delete frpm start
        ListNode* temp= head;
        head=head->next;
        delete temp;
    }
    ListNode* head1 = head;
    while(!stack.empty()){
        ListNode* addNode = new ListNode(stack.top());
        stack.pop();
        //insert ata end
        head1->next = addNode;
        head1=head1->next;
    }

/* Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            Node *newNode = new Node(value);
            temp->next = newNode;
            newNode->next = nullptr;*/
}

//-------------------
// Function to convert queue to linked list and return the head
ListNode* queueToLinkedList(queue<int>& q3) {
    ListNode* head = nullptr;  // Head of the linked list
    ListNode* tail = nullptr;  // Tail of the linked list

    // Create linked list from the queue q3
    while (!q3.empty()) {
        // Create a new node with the value from the front of the queue
        ListNode* l3 = new ListNode(q3.front());

        // Pop the front element from the queue
        q3.pop();

        // If the linked list is empty, the new node becomes both the head and tail
        if (head == nullptr) {
            head = l3;    // Head points to the first node
            tail = l3;    // Tail also points to the first node
        } else {
            tail->next = l3;  // Link the current tail to the new node
            tail = l3;        // Update the tail to the new node
        }
    }

    // Return the head of the linked list
    return head;
}
//-------------------
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // PUSH L1,L2 TO QUEUE
    queue<int>q1;
    queue<int>q2;
    for(ListNode* temp = l1 ; temp!=nullptr ; temp=temp->next){
        q1.push(temp->val);
    }
    for(ListNode* temp = l2 ; temp!=nullptr ; temp=temp->next){
        q2.push(temp->val);
    }
    // HELPING QUEUE TO STORE SUM
    queue<int>q3;
    // HELPING FIELD FOR WHILE LOOP
    int carry=0;
    int Q1=0;
    int Q2=0;

    while(!q1.empty()||!q2.empty()){
        // CHECK IF QUEUE HAVE VALUE IF NOT THEN ASSIGN 0
        Q1 = !q1.empty() ? q1.front() : 0;
        Q2 = !q2.empty() ? q2.front() : 0;

        //ADDING Q1 Q2 AND CARRY IF <= 10 THEN GENERATE CARRY
        /*if((Q1 + Q2 + carry) >= 10){
            q3.push((Q1 + Q2 + carry) / 10);
            carry= (Q1 + Q2 + carry) % 10;
        }else{
            q3.push(Q1 + Q2 + carry);
            carry=0;
        }*/
        int sum = Q1 + Q2 + carry;
        carry = sum / 10;  // Calculate new carry
        q3.push(sum % 10); // Push the current digit (mod 10)

        // POP FROM BOTH QUEUES IF THEY ARE NOT EMPTY
        if (!q1.empty()) q1.pop();
        if (!q2.empty()) q2.pop();
    }
    //CHECK IF CARRAY IS STILL THEN PUSH
    if(carry!=0){
        q3.push(carry);
    }
    // MAKE LL AGAIN WITH THESE VALUES
    return queueToLinkedList(q3);
}