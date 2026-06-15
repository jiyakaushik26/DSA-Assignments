#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
   int data;
   Node* next;
   Node(int x) {
      data = x;
      next = NULL;
   }
};

class LinkedList {
public:
   Node* head;
   LinkedList() {
      head = NULL;
   }
   void insertFront(int x) {
      Node* newNode = new Node(x);
      newNode->next = head;
      head = newNode;
   }
   void insertEnd(int x);
   void insertPosition(int pos, int x);
   void deleteFront() {
      if (head == NULL)return;
      Node* temp = head;
      head = head -> next;
      delete temp;
   }
   void deleteLast();
   void deletePosition(int pos);
   bool search(int key);

   int length() {
      int n = 0;
      Node* temp = head;
      while (temp != NULL) {
         n++;
         temp = temp->next;
      }
      return n;
   };

   void display() {
      Node* temp = head;

      while (temp != NULL) {
         cout << temp->data << " ";
         temp = temp->next;
      }
      cout << endl;
   }
};


int main() {

   //LinkedList* l1 = new LinkedList();
   LinkedList l1;

   l1.insertFront(30);
   l1.insertFront(20);
   l1.insertFront(10); // 10 20 30

   // display
   l1.display();
   // length of ll
   cout << l1.length() << endl;

   l1.deleteFront();
   l1.display();
   return 0;
}