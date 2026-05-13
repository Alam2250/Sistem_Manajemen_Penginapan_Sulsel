#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include "sistem_lantai.cpp"
void cekDanPesan(Kamar &k) {
    if (k.isTerisi) {
        cout << ">> [BATAL] Kamar " << k.nomorKamar << " sudah terisi oleh " << k.namaPemesan << "!" << endl;
    } else {
        cout << "Masukkan Nama Pemesan: ";
        cin.ignore();
        getline(cin, k.namaPemesan);
        k.isTerisi = true;
        cout << ">> [BERHASIL] Pesanan diproses." << endl;
    }
}
