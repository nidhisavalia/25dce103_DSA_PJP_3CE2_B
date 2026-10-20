
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int hashTable[SIZE];

    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    int n, id;
    cout << "Enter number of student IDs: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter student ID: ";
        cin >> id;

        int h1 = id % SIZE;
        int h2 = 7 - (id % 7);
        int count = 0;
        int index = h1;

        while (hashTable[index] != -1 && count < SIZE) {
            count++;
            index = (h1 + count * h2) % SIZE;
        }

        if (count == SIZE) {
            cout << "Hash table is full or no slot is reachable!\n";
        } else {
            hashTable[index] = id;
            cout << "ID stored at slot " << index << endl;
        }
    }

    cout << "\nFinal Hash Table:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << "Slot " << i << ": ";
        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];
        cout << endl;
    }

    return 0;
}
