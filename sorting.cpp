/*
================= BAGIAN INI DIKERJAKAN OLEH FIRAYANTI ===============
FIRAYANTI TIDAK DAPAT MEMAKAI GITHUB KARENA VSCODE NYA EROR
JADI KODE NYA DIKIRIM OLEH HARRY KRISTIANTO
*/

#ifndef SORTING_CPP
#define SORTING_CPP

#include "penginapan.cpp"
#include "kabupaten.cpp"
#include <vector>
#include <algorithm>
using namespace std;
// Insertion Sort
// Urutkan lantai berdasarkan jumlah kamar kosong
struct DataLantai {
    string namaLantai;
    int jumlahKosong;
};

// Hitung kamar kosong di satu lantai
int hitungKamarKosong(Kamar daftarKamar[], int jumlahKamar) {
    int kosong = 0;
    for (int i = 0; i < jumlahKamar; i++)
        if (!daftarKamar[i].terisi) kosong++;
    return kosong;
}

// Kumpulkan semua lantai dari BST ke vector (inorder)
void kumpulkanLantai(Lantai* root, vector<DataLantai> &data) {
    if (root == nullptr) return;
    kumpulkanLantai(root->kiri, data);
    DataLantai dl;
    dl.namaLantai   = root->namaLantai;
    dl.jumlahKosong = hitungKamarKosong(root->daftarKamar, root->jumlahKamar);
    data.push_back(dl);
    kumpulkanLantai(root->kanan, data);
}

// Insertion sort descending berdasarkan jumlahKosong
void insertionSortLantai(vector<DataLantai> &data) {
    int n = data.size();
    for (int i = 1; i < n; i++) {
        DataLantai key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].jumlahKosong < key.jumlahKosong) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Tampil lantai suatu hotel urut kamar kosong terbanyak
void sortingKamarKosong(Lantai* rootLantai, string namaHotel) {
    vector<DataLantai> data;
    kumpulkanLantai(rootLantai, data);
    insertionSortLantai(data);

    cout << "\n========================================\n";
    cout << " KAMAR KOSONG PER LANTAI - " << namaHotel << "\n";
    cout << " (Insertion Sort: terbanyak ke tersedikit)\n";
    cout << "========================================\n";
    for (auto &x : data)
        cout << "  " << x.namaLantai
             << " : " << x.jumlahKosong
             << " kamar kosong\n";
}


// Sorting memakai merge sort, di urutkan kota terdekat dan terjauh
struct DataKota {
    string namaKota;
    int jarak;     // hasil Dijkstra dari kota asal
};

// Merge untuk merge sort
void merge(vector<DataKota> &data, int left, int mid, int right) {
    vector<DataKota> L(data.begin() + left,  data.begin() + mid  + 1);
    vector<DataKota> R(data.begin() + mid+1, data.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < (int)L.size() && j < (int)R.size()) {
        if (L[i].jarak <= R[j].jarak) data[k++] = L[i++];
        else                           data[k++] = R[j++];
    }
    while (i < (int)L.size()) data[k++] = L[i++];
    while (j < (int)R.size()) data[k++] = R[j++];
}

void mergeSort(vector<DataKota> &data, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(data, left,    mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
}

// Dijkstra return array jarak (tidak print)
vector<int> dijkstraJarak(int src) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u])
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
    }
    return dist;
}

// Tampil semua kota diurutkan jarak dari kota asal
void sortingKotaTerdekat(int kotaAsal) {
    vector<int> dist = dijkstraJarak(kotaAsal);

    vector<DataKota> data;
    for (int i = 0; i < V; i++) {
        if (i == kotaAsal) continue; // skip kota asal
        DataKota dk;
        dk.namaKota = kotaName[i];
        dk.jarak    = dist[i];
        data.push_back(dk);
    }

    mergeSort(data, 0, data.size() - 1);

    cout << "\n========================================\n";
    cout << " JARAK KOTA DARI " << kotaName[kotaAsal] << "\n";
    cout << " (Merge Sort: terdekat ke terjauh)\n";
    cout << "========================================\n";
    for (auto &x : data) {
        cout << "  " << x.namaKota << " : ";
        if (x.jarak == INT_MAX)
            cout << "tidak terjangkau\n";
        else
            cout << x.jarak << " km\n";
    }
}

#endif