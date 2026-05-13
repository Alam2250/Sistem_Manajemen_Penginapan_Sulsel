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
int main() {

    const int JUMLAH_KAMAR = 6;
    string kamar[JUMLAH_KAMAR];

    int pilihan, nomor;

    // Semua kamar awalnya kosong
    for (int i = 0; i < JUMLAH_KAMAR; i++) {
        kamar[i] = "Kosong";
    }

    do {
        cout << "\n===== SISTEM KAMAR PENGINAPAN =====" << endl;
        cout << "1. Lihat Status Kamar" << endl;
        cout << "2. Pesan Kamar" << endl;
        cout << "3. Check Out / Kosongkan Kamar" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << "\n===== STATUS KAMAR =====" << endl;

                for (int i = 0; i < JUMLAH_KAMAR; i++) {

                    cout << "Kamar [" << i << "] : ";

                    if (kamar[i] == "Kosong") {
                        cout << "KOSONG";
                    } else {
                        cout << "TERISI oleh " << kamar[i];
                    }

                    cout << endl;
                }
                break;

            case 2:
                cout << "\nMasukkan nomor indeks kamar (0-5) : ";
                cin >> nomor;

                if (nomor >= 0 && nomor < JUMLAH_KAMAR) {

                    if (kamar[nomor] == "Kosong") {

                        cout << "Masukkan nama pengunjung : ";
                        cin >> kamar[nomor];

                        cout << "Kamar berhasil dipesan." << endl;

                    } else {

                        cout << "Kamar sudah terisi oleh "
                             << kamar[nomor] << endl;
                    }

                } else {
                    cout << "Nomor kamar tidak valid." << endl;
                }
                break;

            case 3:
                cout << "\nMasukkan nomor indeks kamar (0-5) : ";
                cin >> nomor;

                if (nomor >= 0 && nomor < JUMLAH_KAMAR) {

                    if (kamar[nomor] == "Kosong") {

                        cout << "Kamar sudah kosong." << endl;

                    } else {

                        cout << "Pengunjung "
                             << kamar[nomor]
                             << " telah check out." << endl;

                        kamar[nomor] = "Kosong";
                    }

                } else {
                    cout << "Nomor kamar tidak valid." << endl;
                }
                break;

            case 4:
                cout << "\nTerima kasih telah menggunakan sistem penginapan."
                     << endl;
                break;

            default:
                cout << "Menu tidak tersedia." << endl;
        }

    } while (pilihan != 4);

    return 0;
}