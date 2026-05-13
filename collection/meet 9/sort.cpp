#include <iostream>
using namespace std;

void cetakArray(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(string arr[], int n) {
    string temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) { 
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    string data[] = {"zebra", "ayam", "sapi", "kambing"};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Original Array: ";
    cetakArray(data, n);

    bubbleSort(data, n);

    cout << "Sorted Array (Descending): ";
    cetakArray(data, n);

    return 0;
}