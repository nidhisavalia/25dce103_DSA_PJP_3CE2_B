#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }

    // Add song at beginning
    void addBeginning(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        display();
    }

    // Add song at end
    void addEnd(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        display();
    }

    // Insert after a specific song
    void insertAfter(string target, string song) {
        Node* current = head;

        while (current != NULL && current->song != target) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Song not found" << endl;
            display();
            return;
        }

        Node* newNode = new Node(song);

        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != NULL) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }

        current->next = newNode;

        display();
    }

    // Remove first song
    void removeFirst() {
        if (head == NULL) {
            cout << "Playlist is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        delete temp;

        display();
    }

    // Count songs
    int countSongs() {
        int count = 0;
        Node* current = head;

        while (current != NULL) {
            count++;
            current = current->next;
        }

        return count;
    }

    // Display playlist
    void display() {
        Node* current = head;

        cout << "Playlist: ";

        while (current != NULL) {
            cout << current->song << " ";
            current = current->next;
        }

        cout << "\nCount: " << countSongs() << endl;
        cout << endl;
    }
};

int main() {
    Playlist p;

    p.addEnd("SongA");
    p.addEnd("SongB");
    p.addBeginning("SongC");
    p.insertAfter("SongA", "SongD");
    p.removeFirst();
    p.insertAfter("SongX", "SongE");

    return 0;
}