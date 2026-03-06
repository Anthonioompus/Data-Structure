#include <iostream>
#include <string>

using namespace std;

// 1. Pembuatan 2 Struct (Nilai & Mahasiswa)
struct Nilai {
    float absen, tugas, uts, uas, nilaiAkhir;
    char huruf;
};

struct Mahasiswa {
    string npm;
    string nama;
    Nilai n; // Nested struct 
};

int main() {
    // 2. Penyimpanan Array Maksimal 20 data
    Mahasiswa mhs[20];
    int jumlahData = 0;
    int pilihan;
    string cariNPM;
    bool ketemu;

    // 3. Looping Menu menggunakan do-while
    do {
        cout << "\n=== MENU DATA MAHASISWA ===\n";
        cout << "1. Input Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Edit Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer

        switch (pilihan) {
            case 1: // CREATE / INPUT
                if (jumlahData < 20) {
                    cout << "\n--- Input Data Mahasiswa ---\n";
                    cout << "NPM\t\t: "; getline(cin, mhs[jumlahData].npm);
                    cout << "Nama\t\t: "; getline(cin, mhs[jumlahData].nama);
                    cout << "Nilai Absen\t: "; cin >> mhs[jumlahData].n.absen;
                    cout << "Nilai Tugas\t: "; cin >> mhs[jumlahData].n.tugas;
                    cout << "Nilai UTS\t: "; cin >> mhs[jumlahData].n.uts;
                    cout << "Nilai UAS\t: "; cin >> mhs[jumlahData].n.uas;

                    // Rumus Nilai
                    mhs[jumlahData].n.nilaiAkhir = (mhs[jumlahData].n.absen * 0.10) + 
                                                   (mhs[jumlahData].n.tugas * 0.20) + 
                                                   (mhs[jumlahData].n.uts * 0.30) + 
                                                   (mhs[jumlahData].n.uas * 0.40);

                    // Konversi Huruf
                    if (mhs[jumlahData].n.nilaiAkhir > 80) {
                        mhs[jumlahData].n.huruf = 'A';
                    } else if (mhs[jumlahData].n.nilaiAkhir > 70) {
                        mhs[jumlahData].n.huruf = 'B';
                    } else if (mhs[jumlahData].n.nilaiAkhir > 60) {
                        mhs[jumlahData].n.huruf = 'C';
                    } else {
                        mhs[jumlahData].n.huruf = 'D';
                    }

                    jumlahData++;
                    cout << ">> Data berhasil disimpan!\n";
                } else {
                    cout << ">> Kuota penyimpanan penuh (Maksimal 20 data)!\n";
                }
                break;

            case 2: // READ / TAMPIL
                cout << "\n--- Daftar Data Mahasiswa ---\n";
                if (jumlahData == 0) {
                    cout << "Belum ada data mahasiswa.\n";
                } else {
                    for (int i = 0; i < jumlahData; i++) {
                        cout << i + 1 << ". NPM: " << mhs[i].npm 
                             << " | Nama: " << mhs[i].nama 
                             << " | Nilai Akhir: " << mhs[i].n.nilaiAkhir 
                             << " | Grade: " << mhs[i].n.huruf << endl;
                    }
                }
                break;

            case 3: // UPDATE / EDIT
                cout << "\n--- Edit Data Mahasiswa ---\n";
                cout << "Masukkan NPM yang ingin diedit: ";
                getline(cin, cariNPM);
                ketemu = false;

                for (int i = 0; i < jumlahData; i++) {
                    // Kunci mencari berdasarkan NPM
                    if (mhs[i].npm == cariNPM) { 
                        ketemu = true;
                        cout << "Data ditemukan! Silakan masukkan data baru:\n";
                        cout << "Nama Baru\t: "; getline(cin, mhs[i].nama);
                        cout << "Nilai Absen\t: "; cin >> mhs[i].n.absen;
                        cout << "Nilai Tugas\t: "; cin >> mhs[i].n.tugas;
                        cout << "Nilai UTS\t: "; cin >> mhs[i].n.uts;
                        cout << "Nilai UAS\t: "; cin >> mhs[i].n.uas;

                        // Hitung ulang nilai & grade
                        mhs[i].n.nilaiAkhir = (mhs[i].n.absen * 0.10) + 
                                              (mhs[i].n.tugas * 0.20) + 
                                              (mhs[i].n.uts * 0.30) + 
                                              (mhs[i].n.uas * 0.40);

                        if (mhs[i].n.nilaiAkhir > 80) mhs[i].n.huruf = 'A';
                        else if (mhs[i].n.nilaiAkhir > 70) mhs[i].n.huruf = 'B';
                        else if (mhs[i].n.nilaiAkhir > 60) mhs[i].n.huruf = 'C';
                        else mhs[i].n.huruf = 'D';

                        cout << ">> Data berhasil diupdate!\n";
                        break;
                    }
                }
                if (!ketemu) cout << ">> Data dengan NPM " << cariNPM << " tidak ditemukan!\n";
                break;

            case 4: // DELETE / HAPUS
                cout << "\n--- Hapus Data Mahasiswa ---\n";
                cout << "Masukkan NPM yang ingin dihapus: ";
                getline(cin, cariNPM);
                ketemu = false;

                for (int i = 0; i < jumlahData; i++) {
                    // Kunci menghapus berdasarkan NPM
                    if (mhs[i].npm == cariNPM) {
                        ketemu = true;
                        // Menggeser data di dalam array untuk menimpa data yang dihapus
                        for (int j = i; j < jumlahData - 1; j++) {
                            mhs[j] = mhs[j + 1];
                        }
                        jumlahData--;
                        cout << ">> Data berhasil dihapus!\n";
                        break;
                    }
                }
                if (!ketemu) cout << ">> Data dengan NPM " << cariNPM << " tidak ditemukan!\n";
                break;

            case 5: // KELUAR
                cout << "Keluar dari program. Terima kasih!\n";
                break;

            default:
                cout << ">> Pilihan tidak valid! Silakan pilih menu 1-5.\n";
        }
    } while (pilihan != 5);

    return 0;
}