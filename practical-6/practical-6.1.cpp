#include <iostream>
using namespace std;

class Node {
public:
    string page;
    Node* next;

    Node(string p) {
        page = p;
        next = NULL;
    }
};

class Browser {
    Node* top;

public:
    Browser() {
        top = NULL;
    }

    // Visit a new page
    void visit(string page) {
        Node* newNode = new Node(page);

        newNode->next = top;
        top = newNode;

        cout << "Visited: " << page << endl;
        displayCurrent();
    }

    // Go back
    void back() {
        if (top == NULL) {
            cout << "No history to go back" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;

        delete temp;

        displayCurrent();
    }

    void displayCurrent() {
        if (top == NULL)
            cout << "Current Page: No page" << endl;
        else
            cout << "Current Page: " << top->page << endl;

        cout << endl;
    }
};

int main() {
    Browser b;

    b.visit("Google");
    b.visit("YouTube");
    b.visit("Wikipedia");

    b.back();
    b.back();
    b.back();
    b.back();

    return 0;
}