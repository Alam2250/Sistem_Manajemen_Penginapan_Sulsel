#include "Kabupaten.cpp"
#include "sistem_lantai.cpp"
#include "sistem_kamar.cpp"

int main() {
    //Tambahkan semua edge (jarak dalam km, sesuai peta)
    addEdge(0,  1,  13);   // Makassar - Gowa
    addEdge(0,  21, 32);   // Makassar - Maros
    addEdge(0,  20, 51);   // Makassar - Pangkep
    addEdge(1,  2,  57);   // Gowa - Takalar
    addEdge(1,  3,  91);   // Gowa - Jeneponto
    addEdge(1,  21, 18);   // Gowa - Maros
    addEdge(1,  18, 121);  // Gowa - Pinrang
    addEdge(1,  17, 140);  // Gowa - Sidrap
    addEdge(1,  6,  148);  // Gowa - Sinjai
    addEdge(2,  3,  45);   // Takalar - Jeneponto
    addEdge(3,  4,  47);   // Jeneponto - Bantaeng
    addEdge(3,  5,  120);  // Jeneponto - Bulukumba
    addEdge(4,  5,  52);   // Bantaeng - Bulukumba
    addEdge(4,  6,  115);  // Bantaeng - Sinjai
    addEdge(5,  6,  59);   // Bulukumba - Sinjai
    addEdge(5,  23, 80);   // Bulukumba - Kep. Selayar
    addEdge(6,  7,  69);   // Sinjai - Bone
    addEdge(6,  8,  102);  // Sinjai - Soppeng
    addEdge(7,  8,  74);   // Bone - Soppeng
    addEdge(7,  9,  107);  // Bone - Wajo
    addEdge(7,  10, 200);  // Bone - Luwu
    addEdge(8,  9,  60);   // Soppeng - Wajo
    addEdge(8,  16, 110);  // Soppeng - Enrekang
    addEdge(8,  17, 78);   // Soppeng - Sidrap
    addEdge(9,  10, 130);  // Wajo - Luwu
    addEdge(9,  16, 145);  // Wajo - Enrekang
    addEdge(10, 11, 25);   // Luwu - Palopo
    addEdge(10, 14, 138);  // Luwu - Tana Toraja
    addEdge(10, 15, 160);  // Luwu - Toraja Utara
    addEdge(11, 12, 85);   // Palopo - Luwu Utara
    addEdge(11, 13, 115);  // Palopo - Luwu Timur
    addEdge(11, 15, 120);  // Palopo - Toraja Utara
    addEdge(12, 13, 60);   // Luwu Utara - Luwu Timur
    addEdge(14, 15, 44);   // Tana Toraja - Toraja Utara
    addEdge(14, 16, 68);   // Tana Toraja - Enrekang
    addEdge(15, 16, 80);   // Toraja Utara - Enrekang
    addEdge(16, 17, 62);   // Enrekang - Sidrap
    addEdge(16, 18, 90);   // Enrekang - Pinrang
    addEdge(17, 18, 69);   // Sidrap - Pinrang
    addEdge(17, 19, 80);   // Sidrap - Barru
    addEdge(18, 19, 70);   // Pinrang - Barru
    addEdge(18, 22, 80);   // Pinrang - Pare-Pare
    addEdge(19, 20, 62);   // Barru - Pangkep
    addEdge(19, 22, 79);   // Barru - Pare-Pare
    addEdge(20, 21, 31);   // Pangkep - Maros
    addEdge(20, 22, 110);  // Pangkep - Pare-Pare
    addEdge(21, 0,  32);   // Maros - Makassar (sudah ada, untuk simetri)

    // a) Dijkstra: Makassar(0) -> Palopo(11)
    dijkstra(0, 11);

    // b) MST + path: Sinjai(6) -> Makassar(0)
    primMST_and_path(6, 0);

    cout << "\n";

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
    // 1. Pilih Lantai
    cout << "Pilih Lantai (Lantai-1/Lantai-2/Lantai-3): "; cin >> inputLantai;
    Lantai* L = cariLantai(root, inputLantai);

    if (L != nullptr) {
        // 2. Pilih Kamar
        cout << "Masukkan Nomor Kamar: "; cin >> inputKamar;
        
        bool ketemu = false;
        for (auto& k : L->daftarKamar) {
            if (k.nomorKamar == inputKamar) {
                ketemu = true;
                cekDanPesan(k); // 3. Panggil validasi (Batal jika terisi)
                break;
            }
        }
        if (!ketemu) cout << "Kamar tidak terdaftar." << endl;
    } else {
        cout << "Lantai tidak ditemukan!" << endl;
    }
    break;
        }
    } while (pilihan != 0);

    return 0;
}

