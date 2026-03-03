#include <iostream>
#include <string> 

using namespace std;

int main() {
    int n;
    
    // input matriks
    cout << "Masukkan ukuran array (n): ";
    cin >> n;

    // untuk membuat array 2 dimensi
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    // untuk mengisi array
    cout << "Masukkan elemen array (pisahkan dengan spasi/enter):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // tampilan array awal sebelum di rotasi
    cout << "\nArray Awal:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // untuk menukar baris dan kolom
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }


    // Array Hasil
    cout << "\nArray Setelah Diputar 90 Derajat:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}