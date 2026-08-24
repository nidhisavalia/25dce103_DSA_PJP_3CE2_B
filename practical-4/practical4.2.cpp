#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void deleteByValue(int value) {
        if (head == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Value not found!" << endl;
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    void displayForward() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void displayReverse(Node* temp) {
        if (temp == NULL)
            return;

        displayReverse(temp->next);
        cout << temp->data << " ";
    }

    void reversePrint() {
        displayReverse(head);
        cout << endl;
    }
};

int main() {
    LinkedList queue;

    queue.insertEnd(101);
    queue.insertEnd(102);
    queue.insertEnd(103);
    queue.insertEnd(104);
    queue.insertEnd(105);

    cout << "Forward Queue: ";
    queue.displayForward();

    queue.deleteByValue(103);

    cout << "After Deletion: ";
    queue.displayForward();

    cout << "Reverse Queue: ";
    queue.reversePrint();

    return 0;
}