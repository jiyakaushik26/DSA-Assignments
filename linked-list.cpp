#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        head = NULL;
    }

    // Insert at Front
    void insertFront(int x)
    {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
    }

    // Insert at End
    void insertEnd(int x)
    {
        Node* temp = new Node(x);

        if (head == NULL)
        {
            head = temp;
            return;
        }

        Node* curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = temp;
    }

    // Insert at Position 
    void insertPosition(int pos, int x)
    {
        if (pos <= 1)
        {
            insertFront(x);
            return;
        }

        Node* temp = new Node(x);
        Node* curr = head;

        for (int i = 1; i < pos - 1 && curr != NULL; i++)
        {
            curr = curr->next;
        }

        if (curr == NULL)
        {
            cout << "Invalid Position\n";
            delete temp;
            return;
        }

        temp->next = curr->next;
        curr->next = temp;
    }

    // Delete Front
    void deleteFront()
    {
        if (head == NULL)
            return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete Last
    void deleteLast()
    {
        if (head == NULL)
            return;

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* curr = head;

        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }

        delete curr->next;
        curr->next = NULL;
    }

    // Delete at Position (1-based indexing)
    void deletePosition(int pos)
    {
        if (head == NULL)
            return;

        if (pos == 1)
        {
            deleteFront();
            return;
        }

        Node* curr = head;

        for (int i = 1; i < pos - 1 && curr != NULL; i++)
        {
            curr = curr->next;
        }

        if (curr == NULL || curr->next == NULL)
        {
            cout << "Invalid Position\n";
            return;
        }

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    // Search
    bool search(int key)
    {
        Node* curr = head;

        while (curr != NULL)
        {
            if (curr->data == key)
                return true;

            curr = curr->next;
        }

        return false;
    }

    // Display
    void display()
    {
        Node* curr = head;

        while (curr != NULL)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }

        cout << "NULL\n";
    }
    int length()
    {
        int count = 0;
        Node* curr = head;

        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }

        return count;
    }
};

int main()
{
    LinkedList list;

    
    return 0;
}