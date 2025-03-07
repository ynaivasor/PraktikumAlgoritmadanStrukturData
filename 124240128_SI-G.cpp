#include <iostream>
#include <string>
using namespace std;

//menyimpan data lagu
struct Lagu {
    string judul;
    string penyanyi;
    string genre;
    int tahun;
};

//array statis untuk menyimpan lagu
Lagu daftar_lagu[100];
int jmlh_lagu = 0; 

// Fungsi untuk menampilkan daftar lagu
void tampilkanLagu() {
    if (jmlh_lagu == 0) {
        cout << "Playlist Kosong" << endl;
        return;
    }
    cout << "DAFTAR LAGU" << endl;
    for (int i = 0; i < jmlh_lagu; i++) {
        cout << i + 1 << ". " << daftar_lagu[i].judul << " - " << daftar_lagu[i].penyanyi << endl;
    }
}

// Bubble Sort untuk mengurutkan lagu berdasarkan judul
void bubbleSort() {
    for (int i = 0; i < jmlh_lagu - 1; i++) {
        for (int j = 0; j < jmlh_lagu - i - 1; j++) {
            if (daftar_lagu[j].judul > daftar_lagu[j + 1].judul) {
                swap(daftar_lagu[j], daftar_lagu[j + 1]);
            }
        }
    }
}

// Binary Search untuk mencari lagu berdasarkan judul
int binarySearch(string cariJudul) {
    int kiri = 0, kanan = jmlh_lagu - 1;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (daftar_lagu[tengah].judul == cariJudul)
            return tengah;
        else if (daftar_lagu[tengah].judul < cariJudul)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }
    return -1; // Lagu tidak ditemukan
}

// Fungsi untuk menambahkan lagu
void tambahLagu() {
    int jumlah;
    cout << "Masukkan jumlah lagu yang ingin ditambahkan: ";
    cin >> jumlah;

    if (jmlh_lagu + jumlah > 100) {
        cout << "Kapasitas daftar lagu tidak mencukupi untuk menambahkan " << jumlah << " lagu.\n";
        return;
    }

    cin.ignore(); 
    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan Judul Lagu ke-" << (jmlh_lagu + 1) << ": ";
        getline(cin, daftar_lagu[jmlh_lagu].judul);
        cout << "Masukkan Penyanyi     : ";
        getline(cin, daftar_lagu[jmlh_lagu].penyanyi);
        cout << "Masukkan Genre Lagu   : ";
        getline(cin, daftar_lagu[jmlh_lagu].genre);
        cout << "Masukkan Tahun Rilis  : ";
        cin >> daftar_lagu[jmlh_lagu].tahun;
        cin.ignore(); 
        cout << " " << endl;
        jmlh_lagu++;
    }

    bubbleSort(); 
    cout << "Lagu berhasil ditambahkan!" << endl;
}

// Fungsi untuk mencari lagu
void cariLagu() {
    if (jmlh_lagu == 0) {
        cout << "Daftar lagu kosong" << endl;
        return;
    }

    string cariJudul;
    cout << "Masukkan judul lagu yang dicari: ";
    cin.ignore();
    getline(cin, cariJudul);

    bubbleSort();

    int hasil = binarySearch(cariJudul);
    if (hasil != -1) {
        cout << "Judul Lagu   : " << daftar_lagu[hasil].judul << endl;
        cout << "Penyanyi     : " << daftar_lagu[hasil].penyanyi << endl;
        cout << "Genre Lagu   : " << daftar_lagu[hasil].genre << endl;
        cout << "Tahun Rilis  : " << daftar_lagu[hasil].tahun << endl;
    } else {
        cout << "Lagu tidak ditemukan dalam daftar!" << endl;
    }
}

//Menu utama
int main() {
    int pilihan;
    char kembaliMenu;

    do {
        cout << "===== PLAYLIST LAGU ====="<<endl;
        tampilkanLagu();
        cout << "=========================" << endl;
        cout << " " << endl;
        cout << "1. Tambah Lagu"<<endl;
        cout << "2. Cari Lagu"<<endl;
        cout << "3. Keluar"<<endl;
        cout << "Pilih menu: "; cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahLagu();
                break;
            case 2:
                cariLagu();
                break;
            case 3:
                exit (0);
            case 'n':
                exit (0);
            default:
                cout << "Pilihan tidak valid" << endl;
        }

        if (pilihan != 4) {
            cout << "Kembali ke menu utama? (y/n): ";
            cin >> kembaliMenu;
            if (kembaliMenu == 'y' || kembaliMenu == 'Y') {
                system("cls"); 
            }
        }
    } while (kembaliMenu == 'y' || kembaliMenu == 'Y' || pilihan != 3);

    return 0;
}