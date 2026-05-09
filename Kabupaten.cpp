#include <bits/stdc++.h>
#include "searching.cpp"
using namespace std;
const int INF = INT_MAX;
const int V = 24;

// Nama 24 kabupaten/kota Sulawesi Selatan
string kotaName[] = {
    "Makassar", "Gowa", "Takalar", "Jeneponto", "Bantaeng", "Bulukumba", "Sinjai","Bone",
    "Soppeng", "Wajo", "Luwu", "Palopo", "Luwu Utara", "Luwu Timur", "Tana Toraja", "Toraja Utara",
    "Enrekang", "Sidrap", "Pinrang", "Barru", "Pangkep", "Maros", "Pare-Pare", "Kep. Selayar"
};

vector<pair<int,int>> adj[V];
void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
// a) DIJKSTRA: path dari Makassar ke Palopo
void dijkstra(int src, int dst) {
    vector<int> dist(V, INF), prev(V, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Rekonstruksi path
    vector<int> path;
    for (int cur = dst; cur != -1; cur = prev[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());

    cout << "\n========================================\n";
    cout << " a) Dijkstra: " << kotaName[src] << " -> " << kotaName[dst] << "\n";
    cout << "========================================\n";
    cout << " Path  : ";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << kotaName[path[i]];
        if (i + 1 < (int)path.size()) cout << " -> ";
    }
    cout << "\n Jarak : " << dist[dst] << " km\n";
}

// b) MST (Prim) + jalur terpendek Sinjai -> Makassar via MST
void primMST_and_path(int src, int dst) {
    // Prim's Algorithm
    vector<int> key(V, INF), parent(V, -1);
    vector<bool> inMST(V, false);
    key[0] = 0;

    for (int i = 0; i < V; i++) {
        // Pilih vertex dengan key terkecil yang belum di MST
        int u = -1;
        for (int j = 0; j < V; j++)
            if (!inMST[j] && (u == -1 || key[j] < key[u])) u = j;

        inMST[u] = true;
        for (auto [v, w] : adj[u])
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
    }

    // Cetak MST
    cout << "\n========================================\n";
    cout << " b) Minimum Spanning Tree (Prim's)\n";
    cout << "========================================\n";
    int totalMST = 0;
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            cout << "   " << kotaName[parent[i]] << " <--> " << kotaName[i]
                 << " (" << key[i] << " km)\n";
            totalMST += key[i];
        }
    }
    cout << " Total bobot MST: " << totalMST << " km\n";

    // Bangun adjacency list dari MST lalu BFS untuk cari path src->dst
    vector<vector<int>> mstAdj(V);
    for (int i = 1; i < V; i++)
        if (parent[i] != -1) {
            mstAdj[parent[i]].push_back(i);
            mstAdj[i].push_back(parent[i]);
        }

    vector<int> prevBFS(V, -1);
    vector<bool> vis(V, false);
    queue<int> q;
    q.push(src); vis[src] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : mstAdj[u])
            if (!vis[v]) { vis[v]=true; prevBFS[v]=u; q.push(v); }
    }

    vector<int> path;
    for (int cur = dst; cur != -1; cur = prevBFS[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());

    // Hitung total jarak path
    int totalPath = 0;
    for (int i = 0; i + 1 < (int)path.size(); i++) {
        int u = path[i], v = path[i+1];
        for (auto [nb, w] : adj[u])
            if (nb == v) { totalPath += w; break; }
    }

    cout << "\n----------------------------------------\n";
    cout << " Jalur terpendek via MST: "
         << kotaName[src] << " -> " << kotaName[dst] << "\n";
    cout << "----------------------------------------\n";
    cout << " Path  : ";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << kotaName[path[i]];
        if (i + 1 < (int)path.size()) cout << " -> ";
    }
    cout << "\n Jarak : " << totalPath << " km\n";
}

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
    return 0;
}