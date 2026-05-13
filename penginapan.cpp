// =========================== BAGIAN INI DIKERJAKAN OLEH RIDHO ANUGRAH ==========================
#ifndef SISTEM_PENGINAPAN_CPP
#define SISTEM_PENGINAPAN_CPP // pencegahan agar tidak terjadi duplikasi include
#include "sistem_lantai.cpp"

struct Penginapan
{
    string nama;
    Lantai *rootLantai;
    Penginapan *next;

    Penginapan(string n){
        nama = n;
        rootLantai = buatLantaiDefault();
        next = nullptr;
    }
};

// tambah penginapan
void tambahPenginapan(Penginapan* &head, string namaHotel)
{
    Penginapan *baru = new Penginapan(namaHotel);
    if (head == nullptr) {
        head = baru;
        return;
    }
    Penginapan* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = baru;
}

// tampil penginapan
void tampilPenginapan(Penginapan* head)
{
    if (head == nullptr) {
        cout << "   (Belum ada penginapan di kota ini)\n";
        return;
    }
    Penginapan* temp = head;
    int no = 1;
    while (temp != nullptr) {
        cout << "  " << no << ". " << temp->nama << "\n";
        temp = temp->next;
        no++;
    }
}

// pesan penginapan
// Ambil penginapan ke-n dari linked list (index mulai 1)
Penginapan* getPenginapan(Penginapan* head, int pilihan) {
    Penginapan* temp = head;
    int no = 1;
    while (temp != nullptr && no < pilihan) {
        temp = temp->next;
        no++;
    }
    return temp;
}

#endif