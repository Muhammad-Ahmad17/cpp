#include "iostream"
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
class LinkedList{
private:
    Node* head;
    int size;
public:
     LinkedList(){
         head= nullptr;
         size=0;
     }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    void insertAtStart(int value){
         Node* temp = new Node(value);
         temp->next=head;
         head = temp;
         size++;
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    void insertAtEnd(int value){
        if(head== nullptr){
           insertAtStart(value);
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            Node *newNode = new Node(value);
            temp->next = newNode;
            newNode->next = nullptr;
            size++;
        }
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    void insertAtPosition(int value,int index){
         if(index < 0 || index > getSize()){
             cerr << "\nPosition " << index << " is out of bound\n";
         }else if(index==0){
             insertAtStart(value);
         }else if(index==getSize()){
             insertAtEnd(value);
         }else{
             Node* temp = head;
             for(int i=0 ; i<index-1 ; i++){
                 temp=temp->next;
             }
             Node* newNode = new Node(value);
             newNode->next=temp->next;
             temp->next=newNode;
             size++;
         }
     }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    void traverse(){
        if(head== nullptr){
            cerr << "list not exist to traverse:(\n";
        } else {
            cout << "HEAD -> ";
            for (Node* temp=head ; temp!=nullptr ; temp=temp->next) {
                cout << temp->data << " -> ";
            }
            cout << "NULL\n";
        }
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    void deleteFromStart(){
         if(head==nullptr){
             cerr << " List not exist\n";
         }else {
             Node *temp = head;
             head = head->next;
             delete temp;
             size--;
         }
     }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    void deleteFromEnd() {
        if (head == nullptr) {
            cerr << " List not exist\n";
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            size--;
        } else {
            Node *temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            Node* toDelete = temp->next;  // Store the last node to delete
            temp->next = nullptr;         // Detach the last node
            delete toDelete;
            size--;
        }
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    void deleteFromPosition(int index) {
        if (index < 0 || index > getSize()-1) {
            cerr << "\nPosition " << index << " is out of bound\n";
        } else if (index == 0) {
            deleteFromStart();
        } else if (index == getSize() - 1) {
            deleteFromEnd();
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node* toDelete = temp->next;  // Node to delete
            temp->next = toDelete->next;   // Bypass the node
            delete toDelete;                // Free memory
            size--;                         // Decrement size
        }
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    void search(int target){
        int index=0;
         for (Node* temp=head ; temp!=nullptr ; temp=temp->next) {
             if (temp->data==target) {
                 cout << "Element " << target << " found at index " << index ;
                 return;
             }
             index++;
         }
         cout << "Element " << target << " not found in list";
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int getSize() const  {
        return size;
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    void swapAlternative(){
        if(head== nullptr){
            cerr << "list not exist to traverse:(\n";
        } else {
            for (Node* temp=head ; temp!=nullptr && temp->next!=nullptr ; temp=temp->next->next) {
                 swap(temp->data,temp->next->data);
            }
        }
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void sorting(){
        for (Node* temp=head ; temp!=nullptr ; temp=temp->next) {
            for (Node* temp1=head->next ; temp1 != nullptr ; temp1=temp1->next) {
                if(temp->data>temp1->data){
                    swap(temp->data, temp1->data);
                }
            }
        }
    }
};

int main(){
    LinkedList list;
    list.insertAtEnd(27);
    list.insertAtStart(35);
    list.insertAtStart(11);
    list.insertAtEnd(88);
    list.insertAtPosition(12,4);
    cout << "Current size of list:" << list.getSize() << "\n" ;
    list.traverse();
    list.deleteFromPosition(3);
    cout << "Current size of list:" << list.getSize() << "\n" ;
    list.traverse();
    cout << "Current size of list sort:" << list.getSize() << "\n" ;
    list.swapAlternative();
   // list.search(27);
    cout << "Swap Alternative:\n";
    list.traverse();

    return 0;
}