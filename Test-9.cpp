#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Struktur Data Mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    string jurusan;
    float ipk;

    // Pointer untuk CDLL
    Mahasiswa *next, *prev;
};

// Global Pointer
Mahasiswa *head = nullptr;
Mahasiswa *tail = nullptr;

// Fungsi untuk membuat node baru
Mahasiswa* buatNode(string nim, string nama, string jurusan, float ipk) {
    Mahasiswa *baru = new Mahasiswa();
    baru->nim = nim;
    baru->nama = nama;
    baru->jurusan = jurusan;
    baru->ipk = ipk;
    baru->next = nullptr;
    baru->prev = nullptr;
    return baru;
}

// Fungsi Inisialisasi/Tambah Data di Akhir
void tambahMahasiswa(string nim, string nama, string jurusan, float ipk) {
    Mahasiswa *baru = buatNode(nim, nama, jurusan, ipk);

    if (head == nullptr) {
        head = baru;
        tail = baru;
        head->next = head;
        head->prev = head;
    } else {
        baru->prev = tail;
        baru->next = head;
        tail->next = baru;
        head->prev = baru;
        tail = baru;
    }
}

// Fungsi untuk menampilkan data secara memutar
void tampilkanData() {
    if (head == nullptr) {
        cout << "List Kosong!" << endl;
        return;
    }

    Mahasiswa *cur = head;
    cout << "================================================================" << endl;
    cout << left << setw(10) << "NIM" << setw(20) << "Nama" << setw(20) << "Jurusan" << setw(5) << "IPK" << endl;
    cout << "================================================================" << endl;

    do {
        cout << left << setw(10) << cur->nim 
             << setw(20) << cur->nama 
             << setw(20) << cur->jurusan 
             << setw(5) << fixed << setprecision(2) << cur->ipk << endl;
        cur = cur->next;
    } while (cur != head); // Berhenti saat kembali ke head

    cout << "================================================================" << endl;
    cout << "Catatan: Tail (" << tail->nama << ") terhubung kembali ke Head (" << head->nama << ")" << endl;
    cout << "================================================================\n" << endl;
}

int main() {
    // Menambah beberapa data mahasiswa
    tambahMahasiswa("23001", "Ahmad Fauzi", "Informatika", 3.85);
    tambahMahasiswa("23002", "Siti Aminah", "Sistem Informasi", 3.92);
    tambahMahasiswa("23003", "Budi Doremi", "Teknik Komputer", 3.50);
    tambahMahasiswa("23004", "Dewi Lestari", "Informatika", 3.75);
    cout << "\n================================================================" << endl;
    cout << "DATA MAHASISWA (CIRCULAR DOUBLE LINKED LIST)" << endl;
    tampilkanData();

    return 0;
}