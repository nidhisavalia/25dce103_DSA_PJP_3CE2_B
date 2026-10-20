
#include <iostream>
using namespace std;

int main() {
    int hashTable[10];

    for (int i = 0; i < 10; i++) {
        hashTable[i] = -1;
    }

    int n, registration;

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter registration number: ";
        cin >> registration;

        int index = registration % 10;
        int count = 0;

        while (hashTable[index] != -1 && count < 10) {
            index = (index + 1) % 10;
            count++;
        }

        if (count == 10) {
            cout << "Parking lot is full!\n";
        } else {
            hashTable[index] = registration;
            cout << "Vehicle parked at slot " << index << endl;
        }
    }

    cout << "\nFinal parking slots:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";

        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];

        cout << endl;
    }

    return 0;
}
