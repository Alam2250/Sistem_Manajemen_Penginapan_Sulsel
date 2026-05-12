#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "sistem_kamar.cpp"
using namespace std;

// Struktur Node Kamar
struct Kamar {
    string idKamar;
    string namaPemesan;
    vector<Kamar> daftarKamar;
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