#include <iostream>
#include <string>

using namespace std;

int kompres(string huruf[], int x) {
    int tulis = 0;
    int hitung = 1;

    for (int i = 0; i < x; i++) {

        if (i == x - 1 || huruf[i] != huruf[i + 1]) {
            
            huruf[tulis] = huruf[i];
            tulis++;

             if (hitung > 1) {
                huruf[tulis] = to_string(hitung);
                tulis++;
            }
            hitung = 1;
        } else {
            hitung++;
        }
    }
    return tulis;
}

int main() {
    string huruf[] = {"a", "a", "b", "b", "c"};
    int n = 5;

    int panjangBaru = kompres(huruf, n);
    cout << "Array sebelum kompresi: a, a, b, b, c " << endl;
    cout << "Array Hasil Kompresi: ";
    for (int i = 0; i < panjangBaru; i++) {
        cout << huruf[i] << " ";
    }
    
    return 0;
}