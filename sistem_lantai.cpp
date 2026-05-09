#include <iostream>
#include <string>
#include <map>

using namespace std;

// Struktur Node Kamar
struct Kamar {
    string idKamar;
    string namaPemesan;
    bool isTerisi;
    Kamar *kiri, *kanan;

    Kamar(string id) {
        idKamar = id;
        namaPemesan = "-";
        isTerisi = false;
        kiri = kanan = nullptr;
    }
};

// Fungsi untuk mencari kamar berdasarkan ID (menggunakan DFS)
Kamar* cariKamar(Kamar* root, string id) {
    if (root == nullptr) return nullptr;
    if (root->idKamar == id) return root;

    Kamar* hasilKiri = cariKamar(root->kiri, id);
    if (hasilKiri != nullptr) return hasilKiri;

    return cariKamar(root->kanan, id);
}

// Fungsi untuk memesan kamar
void pesanKamar(Kamar* root, string id, string nama) {
    Kamar* target = cariKamar(root, id);

    if (target == nullptr) {
        cout << ">> [Gagal] Kamar " << id << " tidak ditemukan!" << endl;
    } else if (target->isTerisi) {
        cout << ">> [Ditolak] Akses Ditolak! Kamar " << id << " sudah terisi oleh " << target->namaPemesan << "." << endl;
    } else {
        target->isTerisi = true;
        target->namaPemesan = nama;
        cout << ">> [Berhasil] Kamar " << id << " telah dipesan atas nama " << nama << "." << endl;
    }
}

// Fungsi untuk menampilkan status seluruh kamar
void tampilkanStatus(Kamar* root) {
    if (root == nullptr) return;
    
    cout << "[" << root->idKamar << "] " << (root->isTerisi ? "TERISI (" + root->namaPemesan + ")" : "KOSONG") << endl;
    tampilkanStatus(root->kiri);
    tampilkanStatus(root->kanan);
}

int main() {
    // --- Membangun Struktur Pohon ---
    
    // Lantai 3 (Root)
    Kamar* A1 = new Kamar("A1");

    // Lantai 2 (Terhubung ke A1)
    Kamar* B1 = new Kamar("B1");
    Kamar* B2 = new Kamar("B2");
    A1->kiri = B1;
    A1->kanan = B2;

    // Lantai 1 (C1, C2 ke B1 | C3, C4 ke B2)
    B1->kiri = new Kamar("C1");
    B1->kanan = new Kamar("C2");
    B2->kiri = new Kamar("C3");
    B2->kanan = new Kamar("C4");

    int pilihan;
    string idInput, namaInput;

    do {
        cout << "\n--- SISTEM PENGINAPAN BINARY TREE ---" << endl;
        cout << "1. Tampilkan Status Kamar" << endl;
        cout << "2. Pesan Kamar" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: "; cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nStatus Kamar Saat Ini:" << endl;
                tampilkanStatus(A1);
                break;
            case 2:
                cout << "Masukkan Kode Kamar (A1/B1/B2/C1-C4): "; cin >> idInput;
                cout << "Masukkan Nama Anda: "; cin >> namaInput;
                pesanKamar(A1, idInput, namaInput);
                break;
        }
    } while (pilihan != 0);

    return 0;
}