#include <iostream>
using namespace std;

int main() {
    int arr[] = {9, 2, 5, 2, 7, 6, 11, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int search = 2;
    
    int total_kemunculan = 0; 

    cout << "Data Array: {9, 2, 5, 2, 7, 6, 11, 2}" << endl;
    cout << "Angka yang dicari: " << search << "\n" << endl;

    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            cout << "Angka " << search << " ditemukan pada indeks ke-" << i << endl;
            total_kemunculan++; 
        }
    }

    if (total_kemunculan > 0) {
        cout << "\nTotal angka " << search << " muncul sebanyak " << total_kemunculan << " kali di dalam array tersebut." << endl;
    } else {
        cout << "\nAngka " << search << " tidak ditemukan dalam array." << endl;
    }

    return 0;
}