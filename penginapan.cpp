#include "sistem_lantai.cpp"
#include "kabupaten.cpp"




// =====================================================
//              LINKED LIST PENGINAPAN
// =====================================================

struct Penginapan {

    string nama;
    Kamar* rootKamar;
    Penginapan* next;
};

// head linked list tiap kota
Penginapan* daftarPenginapan[V];

// tambah penginapan
void tambahPenginapan(int kota, string namaHotel) {

    Penginapan* baru = new Penginapan;

    baru->nama = namaHotel;
    baru->rootKamar = new Kamar("A1");
    baru->rootKamar->kiri = new Kamar("B1");
    baru->rootKamar->kanan = new Kamar("B2");
    baru->terisi = false;
    baru->next = NULL;

    if (daftarPenginapan[kota] == NULL) {

        daftarPenginapan[kota] = baru;
    }
    else {

        Penginapan* temp = daftarPenginapan[kota];

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = baru;
    }
}

// tampil penginapan
void tampilPenginapan(int kota) {

    cout << "\n========================================\n";
    cout << " Daftar Penginapan di "
         << kotaName[kota] << endl;
    cout << "========================================\n";

    Penginapan* temp = daftarPenginapan[kota];

    int no = 1;

    while (temp != NULL) {

        cout << no << ". "
             << temp->nama;

        if (temp->terisi)
            cout << " [TERISI]";
        else
            cout << " [KOSONG]";

        cout << endl;

        temp = temp->next;
        no++;
    }
}

// pesan penginapan
void pesanPenginapan(int kota, int pilihan, string namaUser) {

    Penginapan* temp = daftarPenginapan[kota];

    int no = 1;

    while (temp != NULL && no < pilihan) {

        temp = temp->next;
        no++;
    }

    if (temp != NULL) {
        string idKamar;
        cout << "Masukkan Kode Kamar (A1/B1/B2, dll): ";
        cin >> idKamar;

        pesanKamar(temp->rootKamar, idKamar, namaUser);
       
    }

    if (temp->terisi) {

        cout << "\n========================================\n";
        cout << " Maaf " << namaUser << endl;
        cout << " Penginapan sudah terisi!\n";
        cout << " Akses ditolak.\n";
        cout << "========================================\n";
    }
    else {

        temp->terisi = true;

        cout << "\n========================================\n";
        cout << " PEMESANAN BERHASIL\n";
        cout << "========================================\n";

        cout << " Nama Pengguna : "
             << namaUser << endl;

        cout << " Kota Tujuan   : "
             << kotaName[kota] << endl;

        cout << " Penginapan    : "
             << temp->nama << endl;
    }
}


// =====================================================
//                          MAIN
// =====================================================

int main() {

    // inisialisasi linked list
    for (int i = 0; i < V; i++) {
        daftarPenginapan[i] = NULL;
    }

    // =================================================
    //              DATA PENGINAPAN
    // =================================================

    // Makassar
    tambahPenginapan(0, "Hotel Claro Makassar");
    tambahPenginapan(0, "Swiss Belhotel");
    tambahPenginapan(0, "Aryaduta Makassar");
    tambahPenginapan(0, "The Rinra");
    tambahPenginapan(0, "Hotel Gammara");

    // Gowa
    tambahPenginapan(1, "Hotel Gowa Indah");
    tambahPenginapan(1, "Malino Highland");
    tambahPenginapan(1, "Grand Sayang");
    tambahPenginapan(1, "Hotel Rewako");
    tambahPenginapan(1, "Wisata Malino");

    // Sinjai
    tambahPenginapan(6, "Hotel Sinjai");
    tambahPenginapan(6, "Grand Rofina");
    tambahPenginapan(6, "Sinjai Wisata");
    tambahPenginapan(6, "Larea Rea");
    tambahPenginapan(6, "Sinjai Indah");

    // =================================================
    //                  GRAPH EDGE
    // =================================================

    addEdge(0, 1, 13);
    addEdge(1, 6, 148);
    addEdge(6, 7, 69);
    addEdge(7, 10, 200);
    addEdge(10, 11, 25);

    // =================================================
    //              INPUT PENGGUNA
    // =================================================

    string namaUser;

    cout << "========================================\n";
    cout << " SISTEM PEMESANAN PENGINAPAN\n";
    cout << "========================================\n";

    cout << "Masukkan nama pengguna : ";
    getline(cin, namaUser);

    // tampil daftar kota
    cout << "\nDaftar Kota:\n";

    for (int i = 0; i < V; i++) {

        cout << i << ". "
             << kotaName[i] << endl;
    }

    int pilihKota;

    cout << "\nPilih kota tujuan : ";
    cin >> pilihKota;

    // tampil penginapan
    tampilPenginapan(pilihKota);

    int pilihHotel;

    cout << "\nPilih nomor penginapan : ";
    cin >> pilihHotel;

    // proses pemesanan
    pesanPenginapan(
        pilihKota,
        pilihHotel,
        namaUser
    );

    // contoh pemanggilan dijkstra
    dijkstra(0, 11);

    cout << endl;

    return 0;
}