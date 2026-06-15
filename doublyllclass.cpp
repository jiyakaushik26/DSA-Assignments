#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

void insertFront(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);

    if(head == NULL) {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertEnd(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);

    if(head == NULL) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void deleteNode(Node* &head, Node* &tail, int value) {

    Node* curr = head;

    while(curr && curr->data != value)
        curr = curr->next;

    if(curr == NULL)
        return;

    if(curr == head)
        head = head->next;

    if(curr == tail)
        tail = tail->prev;

    if(curr->prev)
        curr->prev->next = curr->next;

    if(curr->next)
        curr->next->prev = curr->prev;

    delete curr;
}

void print(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertEnd(head, tail, 10);
    insertEnd(head, tail, 20);
    insertEnd(head, tail, 30);

    insertFront(head, tail, 5);

    deleteNode(head, tail, 20);

    print(head);

    return 0;
}