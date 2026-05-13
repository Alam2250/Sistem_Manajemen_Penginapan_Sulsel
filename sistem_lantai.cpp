// =========================== BAGIAN INI DIKERJAKAN OLEH INRIANI ==========================

#ifndef SISTEM_LANTAI_CPP
#define SISTEM_LANTAI_CPP // pencegahan agar tidak terjadi duplikasi include
#include <iostream>
#include <string>
#include "sistem_kamar.cpp"
using namespace std;

// Struktur Node lantai
struct Lantai {
    string namaLantai;        // "Lantai-1", "Lantai-2", "Lantai-3"
    Kamar daftarKamar[MAX_KAMAR];    // array kamar (sistem kamar)
    int jumlahKamar;
    Lantai *kiri, *kanan;     // BST

    Lantai(string nama) {
        namaLantai = nama;
        jumlahKamar = 0;
        kiri = kanan = nullptr;
    }
};

// Cari lantai di BST
Lantai* cariLantai(Lantai* root, string namaLantai) {
    if (root == nullptr)                return nullptr;
    if (root->namaLantai == namaLantai) return root;

    // Cari ke kiri dulu, lalu kanan (DFS)
    Lantai* hasil = cariLantai(root->kiri, namaLantai);
    if (hasil != nullptr) return hasil;
    return cariLantai(root->kanan, namaLantai);
}

// Tampil seluruh lantai + kamar (inorder = urut nama)
void tampilLantai(Lantai* root) {
    if (root == nullptr) return;
    tampilLantai(root->kiri);
    cout << "  [" << root->namaLantai << "]\n";
    tampilKamar(root->daftarKamar, root->jumlahKamar);
    tampilLantai(root->kanan);
}

// Inisialisasi lantai default untuk sebuah penginapan
// 3 lantai, masing-masing 3 kamar
Lantai* buatLantaiDefault() {
    Lantai* A1 = new Lantai("A1");
    Lantai* B1 = new Lantai("B1");
    Lantai* B2 = new Lantai("B2");
    Lantai* C1 = new Lantai("C1");
    Lantai* C2 = new Lantai("C2");
    Lantai* C3 = new Lantai("C3");
    Lantai* C4 = new Lantai("C4");
    // Gambaran Tree
    //        A1
    //      /    \
    //    B1      B2
    //   /  \    /  \
    //  C1  C2  C3  C4


    A1->kiri  = B1;
    A1->kanan = B2;
    B1->kiri  = C1;
    B1->kanan = C2;
    B2->kiri  = C3;
    B2->kanan = C4;

    // Isi 5 kamar per node
    // A1
    tambahKamar(A1->daftarKamar, A1->jumlahKamar, "A101");
    tambahKamar(A1->daftarKamar, A1->jumlahKamar, "A102");
    tambahKamar(A1->daftarKamar, A1->jumlahKamar, "A103");
    tambahKamar(A1->daftarKamar, A1->jumlahKamar, "A104");
    tambahKamar(A1->daftarKamar, A1->jumlahKamar, "A105");
    // B1
    tambahKamar(B1->daftarKamar, B1->jumlahKamar, "B101");
    tambahKamar(B1->daftarKamar, B1->jumlahKamar, "B102");
    tambahKamar(B1->daftarKamar, B1->jumlahKamar, "B103");
    tambahKamar(B1->daftarKamar, B1->jumlahKamar, "B104");
    tambahKamar(B1->daftarKamar, B1->jumlahKamar, "B105");
    // B2
    tambahKamar(B2->daftarKamar, B2->jumlahKamar, "B201");
    tambahKamar(B2->daftarKamar, B2->jumlahKamar, "B202");
    tambahKamar(B2->daftarKamar, B2->jumlahKamar, "B203");
    tambahKamar(B2->daftarKamar, B2->jumlahKamar, "B204");
    tambahKamar(B2->daftarKamar, B2->jumlahKamar, "B205");
    // C1
    tambahKamar(C1->daftarKamar, C1->jumlahKamar, "C101");
    tambahKamar(C1->daftarKamar, C1->jumlahKamar, "C102");
    tambahKamar(C1->daftarKamar, C1->jumlahKamar, "C103");
    tambahKamar(C1->daftarKamar, C1->jumlahKamar, "C104");
    tambahKamar(C1->daftarKamar, C1->jumlahKamar, "C105");
    // C2
    tambahKamar(C2->daftarKamar, C2->jumlahKamar, "C201");
    tambahKamar(C2->daftarKamar, C2->jumlahKamar, "C202");
    tambahKamar(C2->daftarKamar, C2->jumlahKamar, "C203");
    tambahKamar(C2->daftarKamar, C2->jumlahKamar, "C204");
    tambahKamar(C2->daftarKamar, C2->jumlahKamar, "C205");
    // C3
    tambahKamar(C3->daftarKamar, C3->jumlahKamar, "C301");
    tambahKamar(C3->daftarKamar, C3->jumlahKamar, "C302");
    tambahKamar(C3->daftarKamar, C3->jumlahKamar, "C303");
    tambahKamar(C3->daftarKamar, C3->jumlahKamar, "C304");
    tambahKamar(C3->daftarKamar, C3->jumlahKamar, "C305");
    // C4
    tambahKamar(C4->daftarKamar, C4->jumlahKamar, "C401");
    tambahKamar(C4->daftarKamar, C4->jumlahKamar, "C402");
    tambahKamar(C4->daftarKamar, C4->jumlahKamar, "C403");
    tambahKamar(C4->daftarKamar, C4->jumlahKamar, "C404");
    tambahKamar(C4->daftarKamar, C4->jumlahKamar, "C405");

    return A1; // root adalah A1
}
#endif