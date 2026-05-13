//  ===================== Bagian HARRY KRISTIANTO ====================

#ifndef SEARCHING_CPP
#define SEARCHING_CPP
#include "penginapan.cpp"

struct HasilCari {
    string namaKota;
    string namaHotel;
    string namaLantai;
    string nomorKamar;
    string namaPemesan;
};

// =====================================================
//   Helper: Kumpulkan semua kamar terisi
// =====================================================
void kumpulkanKamar(Lantai* lantai, string namaHotel, string namaKota,
                    HasilCari hasil[], int &total) {
    if (lantai == nullptr) return;
    for (int i = 0; i < lantai->jumlahKamar; i++) {
        if (lantai->daftarKamar[i].terisi) {
            hasil[total].namaKota    = namaKota;
            hasil[total].namaHotel   = namaHotel;
            hasil[total].namaLantai  = lantai->namaLantai;
            hasil[total].nomorKamar  = lantai->daftarKamar[i].nomorKamar;
            hasil[total].namaPemesan = lantai->daftarKamar[i].namaPemesan;
            total++;
        }
    }
    kumpulkanKamar(lantai->kiri,  namaHotel, namaKota, hasil, total);
    kumpulkanKamar(lantai->kanan, namaHotel, namaKota, hasil, total);
}

int kumpulkanSemuaPemesanan(Penginapan* daftarPenginapan[],
                             string kotaName[], int V,
                             HasilCari hasil[]) {
    int total = 0;
    for (int i = 0; i < V; i++) {
        Penginapan* hotel = daftarPenginapan[i];
        while (hotel != nullptr) {
            kumpulkanKamar(hotel->rootLantai, hotel->nama,
                           kotaName[i], hasil, total);
            hotel = hotel->next;
        }
    }
    return total;
}

// =====================================================
//   Tampil satu hasil
// =====================================================
void tampilHasil(HasilCari &h) {
    cout << "----------------------------------------\n";
    cout << " Nama Pemesan : " << h.namaPemesan << "\n";
    cout << " Kota         : " << h.namaKota    << "\n";
    cout << " Hotel        : " << h.namaHotel   << "\n";
    cout << " Lantai       : " << h.namaLantai  << "\n";
    cout << " Kamar        : " << h.nomorKamar  << "\n";
    cout << "----------------------------------------\n";
}

// =====================================================
//   LINEAR SEARCH — cari by nama pengguna
// =====================================================
void linearSearch(Penginapan* daftarPenginapan[],
                  string kotaName[], int V, string namaCari) {
    cout << "\n========================================\n";
    cout << " Linear Search: \"" << namaCari << "\"\n";
    cout << "========================================\n";

    const int MAX = 500;
    HasilCari hasil[MAX];
    int total = kumpulkanSemuaPemesanan(daftarPenginapan, kotaName, V, hasil);

    bool ketemu = false;
    for (int i = 0; i < total; i++) {
        if (hasil[i].namaPemesan == namaCari) {
            tampilHasil(hasil[i]);
            ketemu = true;
        }
    }
    if (!ketemu)
        cout << " Tidak ditemukan pemesanan atas nama \""
             << namaCari << "\"\n";
}

// =====================================================
//   BINARY SEARCH — cari by nama hotel (sorted A-Z)
// =====================================================
struct DataHotel {
    string namaHotel;
    string namaKota;
};

int kumpulkanSemuaHotel(Penginapan* daftarPenginapan[],
                         string kotaName[], int V,
                         DataHotel hotelArr[]) {
    int total = 0;
    for (int i = 0; i < V; i++) {
        Penginapan* p = daftarPenginapan[i];
        while (p != nullptr) {
            hotelArr[total].namaHotel = p->nama;
            hotelArr[total].namaKota  = kotaName[i];
            total++;
            p = p->next;
        }
    }
    return total;
}

void sortHotel(DataHotel arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].namaHotel > arr[j+1].namaHotel)
                swap(arr[j], arr[j+1]);
}

int binarySearchHotel(DataHotel arr[], int n, string namaCari) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].namaHotel == namaCari)       return mid;
        else if (arr[mid].namaHotel < namaCari)   low  = mid + 1;
        else                                       high = mid - 1;
    }
    return -1;
}

void binarySearch(Penginapan* daftarPenginapan[],
                  string kotaName[], int V, string namaCari) {
    cout << "\n========================================\n";
    cout << " Binary Search Hotel: \"" << namaCari << "\"\n";
    cout << "========================================\n";

    const int MAX_HOTEL = 200;
    DataHotel hotelArr[MAX_HOTEL];
    int total = kumpulkanSemuaHotel(daftarPenginapan, kotaName, V, hotelArr);
    sortHotel(hotelArr, total);

    int idx = binarySearchHotel(hotelArr, total, namaCari);
    if (idx == -1) {
        cout << " Hotel \"" << namaCari << "\" tidak ditemukan.\n";
        return;
    }

    cout << " Hotel ditemukan!\n";
    cout << "----------------------------------------\n";
    cout << " Nama Hotel : " << hotelArr[idx].namaHotel << "\n";
    cout << " Kota       : " << hotelArr[idx].namaKota  << "\n";
    cout << "----------------------------------------\n";

    // Tampil semua pemesan di hotel ini
    const int MAX_HASIL = 500;
    HasilCari hasil[MAX_HASIL];
    int totalKamar = kumpulkanSemuaPemesanan(daftarPenginapan, kotaName, V, hasil);

    bool adaPemesan = false;
    for (int i = 0; i < totalKamar; i++) {
        if (hasil[i].namaHotel == namaCari) {
            tampilHasil(hasil[i]);
            adaPemesan = true;
        }
    }
    if (!adaPemesan)
        cout << " Belum ada kamar yang dipesan di hotel ini.\n";
}

#endif