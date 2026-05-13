#include "kabupaten.cpp"
#include "penginapan.cpp"
#include "searching.cpp"
#include "sorting.cpp"
Penginapan *daftarPenginapan[V];

void inisialisasiData()
{
    // inisialisasi semua kota dengan nilai kosong
    for (int i = 0; i < V; i++)
        daftarPenginapan[i] = nullptr;

    // Tambahkan semua edge (jarak dalam km, sesuai peta)
    addEdge(0, 1, 13);    // Makassar - Gowa
    addEdge(0, 21, 32);   // Makassar - Maros
    addEdge(0, 20, 51);   // Makassar - Pangkep
    addEdge(1, 2, 57);    // Gowa - Takalar
    addEdge(1, 3, 91);    // Gowa - Jeneponto
    addEdge(1, 21, 18);   // Gowa - Maros
    addEdge(1, 18, 121);  // Gowa - Pinrang
    addEdge(1, 17, 140);  // Gowa - Sidrap
    addEdge(1, 6, 148);   // Gowa - Sinjai
    addEdge(2, 3, 45);    // Takalar - Jeneponto
    addEdge(3, 4, 47);    // Jeneponto - Bantaeng
    addEdge(3, 5, 120);   // Jeneponto - Bulukumba
    addEdge(4, 5, 52);    // Bantaeng - Bulukumba
    addEdge(4, 6, 115);   // Bantaeng - Sinjai
    addEdge(5, 6, 59);    // Bulukumba - Sinjai
    addEdge(5, 23, 80);   // Bulukumba - Kep. Selayar
    addEdge(6, 7, 69);    // Sinjai - Bone
    addEdge(6, 8, 102);   // Sinjai - Soppeng
    addEdge(7, 8, 74);    // Bone - Soppeng
    addEdge(7, 9, 107);   // Bone - Wajo
    addEdge(7, 10, 200);  // Bone - Luwu
    addEdge(8, 9, 60);    // Soppeng - Wajo
    addEdge(8, 16, 110);  // Soppeng - Enrekang
    addEdge(8, 17, 78);   // Soppeng - Sidrap
    addEdge(9, 10, 130);  // Wajo - Luwu
    addEdge(9, 16, 145);  // Wajo - Enrekang
    addEdge(10, 11, 25);  // Luwu - Palopo
    addEdge(10, 14, 138); // Luwu - Tana Toraja
    addEdge(10, 15, 160); // Luwu - Toraja Utara
    addEdge(11, 12, 85);  // Palopo - Luwu Utara
    addEdge(11, 13, 115); // Palopo - Luwu Timur
    addEdge(11, 15, 120); // Palopo - Toraja Utara
    addEdge(12, 13, 60);  // Luwu Utara - Luwu Timur
    addEdge(14, 15, 44);  // Tana Toraja - Toraja Utara
    addEdge(14, 16, 68);  // Tana Toraja - Enrekang
    addEdge(15, 16, 80);  // Toraja Utara - Enrekang
    addEdge(16, 17, 62);  // Enrekang - Sidrap
    addEdge(16, 18, 90);  // Enrekang - Pinrang
    addEdge(17, 18, 69);  // Sidrap - Pinrang
    addEdge(17, 19, 80);  // Sidrap - Barru
    addEdge(18, 19, 70);  // Pinrang - Barru
    addEdge(18, 22, 80);  // Pinrang - Pare-Pare
    addEdge(19, 20, 62);  // Barru - Pangkep
    addEdge(19, 22, 79);  // Barru - Pare-Pare
    addEdge(20, 21, 31);  // Pangkep - Maros
    addEdge(20, 22, 110); // Pangkep - Pare-Pare
    addEdge(21, 0, 32);   // Maros - Makassar

    // ----- Data Penginapan -----
    // Makassar (0)
    tambahPenginapan(daftarPenginapan[0], "Hotel Claro Makassar");
    tambahPenginapan(daftarPenginapan[0], "Swiss Belhotel");
    tambahPenginapan(daftarPenginapan[0], "Aryaduta Makassar");
    tambahPenginapan(daftarPenginapan[0], "The Rinra");
    tambahPenginapan(daftarPenginapan[0], "Hotel Gammara");
    // Gowa (1)
    tambahPenginapan(daftarPenginapan[1], "Hotel Gowa Indah");
    tambahPenginapan(daftarPenginapan[1], "Malino Highland");
    tambahPenginapan(daftarPenginapan[1], "Grand Sayang");
    tambahPenginapan(daftarPenginapan[1], "Hotel Rewako");
    tambahPenginapan(daftarPenginapan[1], "Wisata Malino");
    // Sinjai (6)
    tambahPenginapan(daftarPenginapan[6], "Hotel Sinjai");
    tambahPenginapan(daftarPenginapan[6], "Grand Rofina");
    tambahPenginapan(daftarPenginapan[6], "Sinjai Wisata");
    tambahPenginapan(daftarPenginapan[6], "Larea Rea");
    tambahPenginapan(daftarPenginapan[6], "Sinjai Indah");
}

int main()
{
    inisialisasiData();

    int menuUtama;
    do
    {
        cout << "\n========================================\n";
        cout << "   SISTEM PENGINAPAN SULAWESI SELATAN\n";
        cout << "========================================\n";
        cout << " 1. Lihat Rute Antar Kota (Dijkstra)\n";
        cout << " 2. Lihat MST Antar Kota (Prim)\n";
        cout << " 3. Pesan Penginapan\n";
        cout << " 4. Cari Pemesanan (Linear Search by Nama)\n";
        cout << " 5. Cari Hotel (Binary Search by Nama Hotel)\n";
        cout << " 6. Kamar Kosong per Lantai (Insertion Sort)\n";
        cout << " 7. Urutan Kota Terdekat (Merge Sort)\n";
        cout << " 0. Keluar\n";
        cout << "Pilih : ";
        cin >> menuUtama;
        cin.ignore();

        // ---- Menu 1: Dijkstra ----
        if (menuUtama == 1)
        {
            cout << "\nDaftar Kota:\n";
            for (int i = 0; i < V; i++)
                cout << "  " << i << ". " << kotaName[i] << "\n";
            int src, dst;
            cout << "Kota asal  (nomor): ";
            cin >> src;
            cout << "Kota tujuan(nomor): ";
            cin >> dst;
            cin.ignore();
            dijkstra(src, dst);
        }

        // ---- Menu 2: MST ----
        else if (menuUtama == 2)
        {
            cout << "\nDaftar Kota:\n";
            for (int i = 0; i < V; i++)
                cout << "  " << i << ". " << kotaName[i] << "\n";
            int src, dst;
            cout << "Kota asal  (nomor): ";
            cin >> src;
            cout << "Kota tujuan(nomor): ";
            cin >> dst;
            cin.ignore();
            primMST_and_path(src, dst);
        }

        // ---- Menu 3: Pesan Penginapan ----
        else if (menuUtama == 3)
        {
            string namaUser;
            cout << "\nMasukkan nama pengguna : ";
            getline(cin, namaUser);

            // Pilih kota
            cout << "\nDaftar Kota:\n";
            for (int i = 0; i < V; i++)
                cout << "  " << i << ". " << kotaName[i] << "\n";
            int pilihKota;
            cout << "Pilih kota tujuan : ";
            cin >> pilihKota;
            cin.ignore();

            if (pilihKota < 0 || pilihKota >= V)
            {
                cout << "Kota tidak valid.\n";
                continue;
            }

            // Tampil penginapan
            cout << "\n========================================\n";
            cout << " Penginapan di " << kotaName[pilihKota] << "\n";
            cout << "========================================\n";
            tampilPenginapan(daftarPenginapan[pilihKota]);

            if (daftarPenginapan[pilihKota] == nullptr)
                continue;

            int pilihHotel;
            cout << "Pilih nomor penginapan : ";
            cin >> pilihHotel;
            cin.ignore();

            Penginapan *hotel = getPenginapan(daftarPenginapan[pilihKota], pilihHotel);
            if (hotel == nullptr)
            {
                cout << "Penginapan tidak ditemukan.\n";
                continue;
            }

            cout << "\n>> Penginapan dipilih: " << hotel->nama << "\n";

            // Tampil lantai
            int menuHotel;
            do
            {
                cout << "\n--- MENU HOTEL: " << hotel->nama << " ---\n";
                cout << " 1. Lihat Status Lantai & Kamar\n";
                cout << " 2. Pesan Kamar\n";
                cout << " 3. Check Out Kamar\n";
                cout << " 0. Kembali\n";
                cout << "Pilih : ";
                cin >> menuHotel;
                cin.ignore();

                if (menuHotel == 1)
                {
                    cout << "\nStatus Lantai & Kamar:\n";
                    tampilLantai(hotel->rootLantai);
                }
                else if (menuHotel == 2)
                {
                    // Pilih lantai
                    cout << "Pilih Lantai (A1 / B1 / B2 / C1 / C2 / C3 / C4): ";
                    string namaLantai;
                    getline(cin, namaLantai);

                    Lantai *L = cariLantai(hotel->rootLantai, namaLantai);
                    if (L == nullptr)
                    {
                        cout << "Lantai tidak ditemukan!\n";
                        continue;
                    }

                    // Tampil kamar di lantai
                    cout << "Kamar di " << namaLantai << ":\n";
                    tampilKamar(L->daftarKamar, L->jumlahKamar);

                    // Pilih kamar
                    string nomorKamar;
                    cout << "Masukkan nomor kamar : ";
                    getline(cin, nomorKamar);

                    pesanKamar(L->daftarKamar, L->jumlahKamar,
                               nomorKamar, namaUser);
                }
                else if (menuHotel == 3)
                {
                    string namaLantai, nomorKamar;
                    cout << "Pilih Lantai (A1 / B1 / B2 / C1 / C2 / C3 / C4): ";
                    getline(cin, namaLantai);

                    Lantai *L = cariLantai(hotel->rootLantai, namaLantai);
                    if (L == nullptr)
                    {
                        cout << "Lantai tidak ditemukan!\n";
                        continue;
                    }

                    cout << "Masukkan nomor kamar : ";
                    getline(cin, nomorKamar);
                    checkoutKamar(L->daftarKamar, L->jumlahKamar, nomorKamar);
                }

            } while (menuHotel != 0);
        }

        // ---- Menu 4: Linear Search ----
        else if (menuUtama == 4)
        {
            string namaCari;
            cout << "\nMasukkan nama pengguna yang dicari : ";
            getline(cin, namaCari);
            linearSearch(daftarPenginapan, kotaName, V, namaCari);
        }

        // ---- Menu 5: Binary Search ----
        else if (menuUtama == 5)
        {
            string namaCari;
            cout << "\nMasukkan nama hotel yang dicari : ";
            getline(cin, namaCari);
            binarySearch(daftarPenginapan, kotaName, V, namaCari);
        }
        else if (menuUtama == 6)
        {
            // Pilih kota
            for (int i = 0; i < V; i++)
                cout << "  " << i << ". " << kotaName[i] << "\n";
            int pilihKota;
            cout << "Pilih kota : ";
            cin >> pilihKota;
            cin.ignore();

            // Pilih hotel
            tampilPenginapan(daftarPenginapan[pilihKota]);
            int pilihHotel;
            cout << "Pilih nomor hotel : ";
            cin >> pilihHotel;
            cin.ignore();

            Penginapan *hotel = getPenginapan(daftarPenginapan[pilihKota], pilihHotel);
            if (hotel == nullptr)
            {
                cout << "Hotel tidak ditemukan.\n";
                continue;
            }

            sortingKamarKosong(hotel->rootLantai, hotel->nama);
        }

        // ---- Menu 7: Merge Sort kota terdekat ----
        else if (menuUtama == 7)
        {
            for (int i = 0; i < V; i++)
                cout << "  " << i << ". " << kotaName[i] << "\n";
            int kotaAsal;
            cout << "Pilih kota asal : ";
            cin >> kotaAsal;
            cin.ignore();
            sortingKotaTerdekat(kotaAsal);
        }

    } while (menuUtama != 0);

    cout << "\nTerima kasih telah menggunakan sistem penginapan.\n";
    return 0;
}