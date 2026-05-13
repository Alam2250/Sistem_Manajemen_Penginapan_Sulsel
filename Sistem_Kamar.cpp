// ==================== BAGIAN INI DIKERJAKAN OLEH NURFAIZAH ==================

#ifndef SISTEM_KAMAR_CPP
#define SISTEM_KAMAR_CPP // pencegahan agar tidak terjadi duplikasi include
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX_KAMAR = 10;

struct Kamar {
    string nomorKamar;
    string namaPemesan;
    bool terisi;

    Kamar() {
        nomorKamar  = "";
        namaPemesan = "-";
        terisi = false;
    }
};
void tambahKamar(Kamar daftarKamar[], int &jumlahKamar, string nomor) {
    if (jumlahKamar >= MAX_KAMAR) {
        cout << ">> [Gagal] Kapasitas kamar penuh!" << endl;
        return;
    }
    daftarKamar[jumlahKamar].nomorKamar = nomor;
    daftarKamar[jumlahKamar].terisi     = false;
    daftarKamar[jumlahKamar].namaPemesan = "-";
    jumlahKamar++;
}

void pesanKamar(Kamar daftarKamar[], int jumlahKamar,
                string nomor, string nama) {
    for (int i = 0; i < jumlahKamar; i++) {
        if (daftarKamar[i].nomorKamar == nomor) {
            if (daftarKamar[i].terisi) {
                cout << ">> [Ditolak] Kamar " << nomor
                     << " sudah terisi oleh "
                     << daftarKamar[i].namaPemesan << "." << endl;
            } else {
                daftarKamar[i].terisi      = true;
                daftarKamar[i].namaPemesan = nama;
                cout << ">> [Berhasil] Kamar " << nomor
                     << " dipesan atas nama " << nama << "." << endl;
            }
            return;
        }
    }
    cout << ">> [Gagal] Kamar " << nomor << " tidak ditemukan!" << endl;
}

void checkoutKamar(Kamar daftarKamar[], int jumlahKamar, string nomor) {
    for (int i = 0; i < jumlahKamar; i++) {
        if (daftarKamar[i].nomorKamar == nomor) {
            if (!daftarKamar[i].terisi) {
                cout << ">> Kamar " << nomor << " sudah kosong." << endl;
            } else {
                cout << ">> Pengunjung " << daftarKamar[i].namaPemesan
                     << " telah check out dari kamar " << nomor << "." << endl;
                daftarKamar[i].terisi      = false;
                daftarKamar[i].namaPemesan = "-";
            }
            return;
        }
    }
    cout << ">> [Gagal] Kamar " << nomor << " tidak ditemukan!" << endl;
}
void tampilKamar(Kamar daftarKamar[], int jumlahKamar) {
    if (jumlahKamar == 0) {
        cout << "   (Belum ada kamar)" << endl;
        return;
    }
    for (int i = 0; i < jumlahKamar; i++) {
        cout << "   Kamar " << daftarKamar[i].nomorKamar << " : ";
        if (daftarKamar[i].terisi)
            cout << "TERISI (" << daftarKamar[i].namaPemesan << ")";
        else
            cout << "KOSONG";
        cout << endl;
    }
}
#endif
