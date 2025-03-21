/**
  Copyright (c) 2024

  Name: MUHAMMAD AHMAD.

  Project Name: PF.

  Date: 2024-11-02.

  TIME: 6:45 PM.
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

int detactLargestSubSortedPart(Node* head) {
    // If list is empty
    if (!head) return -1;

    // Sliding pointers
    Node* ptr1 = head;
    Node* ptr2 = head->next;

    // Initial max and current sublist lengths
    int maxSubList = 1;
    int currSubList = 1;
    int key = ptr1->data; // Value of the largest sublist

    // Traverse the list
    while (ptr2 != nullptr) {
        if (ptr1->data == ptr2->data) {
            currSubList++; // Increment current sublist count
        } else {
            // Update maxSubList if current sublist is longer
            if (currSubList > maxSubList) {
                maxSubList = currSubList;
                key = ptr1->data; // Store the value of the largest sublist
            }
            currSubList = 1; // Reset current sublist count
        }
        ptr1 = ptr2;
        ptr2 = ptr2->next;
    }

    // Final check in case the longest sublist is at the end
    if (currSubList > maxSubList) {
        maxSubList = currSubList;
        key = ptr1->data;
    }
    return key;
}

// BY THR WHY WE REALLY DONT NEED TO KEEP TRACK OF
// maxSubList (SIZE) AS WE JUST NEED THE VALUE OF THAT SUBLIST
// maxSubList RETURN HOW MANY TIMES KEY REPETED

Node* removeElements(Node* head, int val) {// UPDATE HEAD TO NEXT IF IT IS EQUAL TO GIVEN VALUE
//    while (head != nullptr && head->data == val) {
//        head = head->next;
//    }
    Node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        if (temp->next->data == val) {
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

// Utility function to add a node at the end of the list
void appendNode(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

// Utility function to print the linked list
void traverse(Node* head){
    if(head== nullptr){
        cerr << " HEAD -> NULL :(\n";
    } else {
        cout << "HEAD -> ";
        for (Node* temp=head ; temp!=nullptr ; temp=temp->next) {
            cout << temp->data << " -> ";
        }
        cout << "NULL\n";
    }
}
int main() {
    // FAILED CASES TWO PART WITH SAME COUNT LIKE 1,1,1 AND 2,2,2
    Node* head = nullptr;
    appendNode(head, 1);
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 2);
    appendNode(head, 2);
    appendNode(head, 4);
    appendNode(head, 4);
    appendNode(head, 4);
    appendNode(head, 4);

    traverse(head);

    // Detect the most frequent sublist value
    int val = detactLargestSubSortedPart(head);
    cout << "Most frequent sublist value: " << val << endl;

    // Remove nodes with the detected value
    head = removeElements(head, val);
    traverse(head);

    return 0;
}

//=============================================
/*
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    Node* removeElements(Node* head, int val) {

        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->data == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode* temp = head;
        while (temp->next != nullptr && temp != nullptr) {
            if (temp->val == temp->next->val) {
                int key = temp->val;
                Node* removeElements(temp,key);
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
 */