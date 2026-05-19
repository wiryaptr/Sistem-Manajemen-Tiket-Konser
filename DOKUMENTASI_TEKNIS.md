# DOKUMENTASI TEKNIS
## Sistem Manajemen Event & Tiket Konser

---

## 1. STRUKTUR DATA DASAR (struct)

### Event
```cpp
struct Event {
    int eventID;        // ID unik event
    char nama[100];     // Nama event
    char genre[50];     // Tipe genre (musik, olahraga, dll)
    char kota[50];      // Lokasi event
    int kapasitas;      // Total kapasitas tiket
    int terjual;        // Tiket yang sudah terjual
    float harga;        // Harga per tiket
    char tanggal[20];   // Tanggal event (dd-mm-yyyy)
};
```

### User
```cpp
struct User {
    char username[50];  // Nama pengguna (unique key)
    char password[50];  // Password
    int userID;         // ID unik user
};
```

### Node untuk Linked List
```cpp
struct NodeEvent {
    Event data;         // Data event
    NodeEvent* next;    // Pointer ke node berikutnya
    NodeEvent* prev;    // Pointer ke node sebelumnya (doubly linked)
};
```

### Node untuk Queue
```cpp
struct NodeQueue {
    int eventID;        // Event yang dipesan
    char username[50];  // User yang memesan
    int jumlahTiket;    // Jumlah tiket yang dipesan
    NodeQueue* next;    // Pointer ke node berikutnya
};
```

### Node untuk Stack
```cpp
struct NodeStack {
    int eventID;        // Event yang dibatalkan
    char username[50];  // User yang membatalkan
    int jumlahTiket;    // Jumlah tiket yang dibatalkan
    char tanggalBatal[20];  // Waktu pembatalan
    NodeStack* next;    // Pointer ke node berikutnya
};
```

### Node untuk BST
```cpp
struct NodeBST {
    Event data;         // Data event
    NodeBST* left;      // Subtree kiri (ID lebih kecil)
    NodeBST* right;     // Subtree kanan (ID lebih besar)
};
```

### Node untuk Graph
```cpp
struct NodeGraph {
    int eventID;        // Event yang terhubung
    NodeGraph* next;    // Pointer ke relasi berikutnya
};

struct AdjacencyListGraph {
    int eventID;        // ID event sebagai node
    NodeGraph* adjacencyList;  // Linked list relasi
};
```

---

## 2. LINKED LIST IMPLEMENTATION

### Class LinkedListEvent

**Private Members:**
- `NodeEvent* head` - Pointer ke node pertama
- `NodeEvent* tail` - Pointer ke node terakhir
- `int count` - Jumlah node

**Public Methods:**

#### insertEvent(Event data)
- **Kompleksitas**: O(1)
- **Penjelasan**: Menambah node baru di akhir list
- **Alur**:
  1. Buat node baru
  2. Jika head == null, jadikan head dan tail
  3. Jika tidak, append ke tail dan update tail pointer

#### deleteEvent(int eventID)
- **Kompleksitas**: O(n)
- **Penjelasan**: Mencari dan menghapus node berdasarkan ID
- **Alur**:
  1. Traversal dari head
  2. Jika ketemu, update pointer next/prev sesuai posisi
  3. Deallocate memory

#### displayAllEvents()
- **Kompleksitas**: O(n)
- **Penjelasan**: Menampilkan semua event dalam format tabel
- **Output**: Tabel dengan 8 kolom (ID, Nama, Genre, Kota, Kapasitas, Terjual, Harga, Tanggal)

#### findEventByID(int eventID)
- **Kompleksitas**: O(n)
- **Penjelasan**: Mencari event berdasarkan ID
- **Return**: Pointer ke Event atau nullptr jika tidak ditemukan

---

## 3. HASH TABLE IMPLEMENTATION

### Class HashTableUser

**Private Members:**
- `User** table` - Array of pointers ke User
- `int size` - Ukuran hash table (default: 100)

**Private Methods:**

#### hashFunction(const char* username)
- **Kompleksitas**: O(m) where m = length of username
- **Formula**: `(hash * 31 + char) % size`
- **Alur**:
  1. Iterasi setiap karakter username
  2. hash = (hash * 31 + char_value) % size
  3. Return hash value

**Public Methods:**

#### insertUser(const char* username, const char* password, int userID)
- **Kompleksitas**: O(1) average, O(n) worst case
- **Collision Handling**: Linear probing
- **Alur**:
  1. Hitung hash dari username
  2. Linear probing sampai menemukan empty slot
  3. Insert user di slot tersebut

#### authenticateUser(const char* username, const char* password)
- **Kompleksitas**: O(1) average
- **Alur**:
  1. Hitung hash username
  2. Linear probing cari user
  3. Compare password jika username ketemu
  4. Return true/false

#### userExists(const char* username)
- **Kompleksitas**: O(1) average
- **Penjelasan**: Cek apakah user sudah terdaftar

#### getUser(const char* username)
- **Kompleksitas**: O(1) average
- **Penjelasan**: Ambil pointer ke user untuk operasi lain

---

## 4. QUEUE IMPLEMENTATION

### Class QueueTiket

**Private Members:**
- `NodeQueue* front` - Pointer ke node pertama (yang akan diproses)
- `NodeQueue* rear` - Pointer ke node terakhir
- `int size` - Jumlah elemen dalam queue

**Public Methods:**

#### enqueue(int eventID, const char* username, int jumlahTiket)
- **Kompleksitas**: O(1)
- **Alur**:
  1. Buat node baru
  2. Jika queue kosong, jadikan front dan rear
  3. Jika tidak, append ke rear dan update rear

#### dequeue(int& eventID, char* username, int& jumlahTiket)
- **Kompleksitas**: O(1)
- **Alur**:
  1. Check jika front == null
  2. Ambil data dari front
  3. Move front ke next
  4. Delete node, return true

#### displayQueue()
- **Kompleksitas**: O(n)
- **Penjelasan**: Tampilkan semua elemen queue dalam urutan

#### isEmpty() & getSize()
- **Kompleksitas**: O(1)
- **Penjelasan**: Helper functions

---

## 5. STACK IMPLEMENTATION

### Class StackRiwayat

**Private Members:**
- `NodeStack* top` - Pointer ke node paling atas
- `int size` - Jumlah elemen

**Public Methods:**

#### push(int eventID, const char* username, int jumlahTiket, const char* tanggalBatal)
- **Kompleksitas**: O(1)
- **Alur**:
  1. Buat node baru
  2. Link ke top yang lama
  3. Update top ke node baru

#### pop(int& eventID, char* username, int& jumlahTiket, char* tanggalBatal)
- **Kompleksitas**: O(1)
- **Alur**:
  1. Check jika top == null
  2. Ambil data dari top
  3. Move top ke next
  4. Delete node, return true

#### displayRiwayat()
- **Kompleksitas**: O(n)
- **Penjelasan**: Tampilkan semua riwayat dalam urutan (LIFO)

---

## 6. BINARY SEARCH TREE IMPLEMENTATION

### Class BSTEvent

**Private Members:**
- `NodeBST* root` - Root dari tree

**Private Methods (Recursive):**

#### insertNode(NodeBST* node, Event data)
- **Kompleksitas**: O(log n) average, O(n) worst case (skewed tree)
- **Alur**:
  1. Jika node == null, buat node baru
  2. Jika data.eventID < node.eventID, insert ke kiri
  3. Jika data.eventID > node.eventID, insert ke kanan

#### searchNode(NodeBST* node, int eventID)
- **Kompleksitas**: O(log n) average
- **Alur**:
  1. Jika node == null, return null
  2. Jika eventID == node.eventID, return node
  3. Jika eventID < node.eventID, search kiri
  4. Jika eventID > node.eventID, search kanan

#### inorderTraversal(NodeBST* node)
- **Kompleksitas**: O(n)
- **Urutan**: Left subtree → Node → Right subtree
- **Hasil**: Event terurut berdasarkan ID

**Public Methods:**

#### insert(Event data)
- Wrapper untuk insertNode recursive

#### search(int eventID)
- Wrapper untuk searchNode recursive

#### displayInorder()
- Tampilkan tree dengan inorder traversal

---

## 7. GRAPH IMPLEMENTATION

### Class GraphEvent

**Private Members:**
- `AdjacencyListGraph* adjacencyList` - Array of adjacency lists
- `int maxNodes` - Kapasitas maksimal
- `int totalNodes` - Jumlah node yang sudah ada

**Public Methods:**

#### findNodeIndex(int eventID)
- **Kompleksitas**: O(n)
- **Penjelasan**: Cari index array dari event ID

#### addNode(int eventID)
- **Kompleksitas**: O(1)
- **Alur**:
  1. Check jika event belum ada di graph
  2. Tambah event sebagai node

#### addEdge(int eventID1, int eventID2)
- **Kompleksitas**: O(1)
- **Alur** (Undirected graph):
  1. Cari index kedua event
  2. Tambah eventID2 ke adjacency list eventID1
  3. Tambah eventID1 ke adjacency list eventID2

#### displayGraph()
- **Kompleksitas**: O(n + m) where n = nodes, m = edges
- **Penjelasan**: Tampilkan semua relasi

---

## 8. SORTING IMPLEMENTATION

### Class SortingEvent

#### bubbleSort(NodeEvent*& head, int sortBy)
- **Algoritma**: Bubble Sort
- **Kompleksitas**: O(n²)
- **Alur**:
  1. Loop hingga tidak ada swap
  2. Compare adjacent nodes sesuai sortBy parameter
  3. Swap data jika diperlukan
  4. Repeat sampai list terurut

**Sort By Options:**
1. `sortBy == 1` - Sort by Event ID
2. `sortBy == 2` - Sort by Kapasitas
3. `sortBy == 3` - Sort by Tiket Terjual

---

## 9. SEARCHING IMPLEMENTATION

### Class SearchingEvent

#### linearSearch(NodeEvent* head, const char* namaEvent)
- **Algoritma**: Linear Search
- **Kompleksitas**: O(n)
- **Alur**:
  1. Traversal dari head
  2. Gunakan `strstr()` untuk partial match
  3. Return pointer ke event jika ditemukan

#### binarySearch(Event* arr, int left, int right, int eventID)
- **Algoritma**: Binary Search (Divide & Conquer)
- **Kompleksitas**: O(log n)
- **Persyaratan**: Array harus sudah terurut
- **Alur**:
  1. Hitung mid = (left + right) / 2
  2. Jika arr[mid] == eventID, return
  3. Jika arr[mid] > eventID, search kiri
  4. Jika arr[mid] < eventID, search kanan

---

## 10. SISTEM UTAMA (SistemManajemenEvent)

### Class SistemManajemenEvent

**Private Members:**
- `LinkedListEvent eventList` - Penyimpanan event
- `HashTableUser userTable` - Penyimpanan user
- `QueueTiket queueTiket` - Antrian pembelian
- `StackRiwayat stackRiwayat` - Riwayat pembatalan
- `BSTEvent bstEvent` - Index cepat event by ID
- `GraphEvent graphEvent` - Relasi antar event
- `char currentUser[50]` - User yang sedang login
- `bool isLoggedIn` - Status login
- `int userCounter` - Penghitung user baru

**Public Methods:**

#### tampilkanMenuAwal()
- Menu utama sebelum login
- Pilihan: Register, Login, Keluar

#### registerUser()
- Input username dan password
- Insert ke Hash Table

#### loginUser()
- Input username dan password
- Verifikasi dengan Hash Table

#### tampilkanMenuUtama()
- Menu setelah login (13 pilihan)

#### tambahEvent()
- Input data event
- Insert ke: Linked List, BST, Graph

#### cariEventLinearSearch()
- Input nama event
- Linear search di Linked List

#### urutkanEvent()
- Pilih kriteria sorting
- Bubble sort di Linked List

#### pesanTiket()
- Input event ID dan jumlah
- Update Linked List (terjual)
- Enqueue ke Queue

#### batalkanTiket()
- Input event ID dan jumlah
- Update Linked List (kurangi terjual)
- Push ke Stack

#### undoPembatalan()
- Pop dari Stack
- Update Linked List (restore terjual)

#### tambahRelasi()
- Input dua event ID
- Add edge di Graph

#### run()
- Main entry point
- Loop menu hingga logout

---

## 11. FLOW DIAGRAM PROGRAM

```
┌─────────────────────────────┐
│    PROGRAM START            │
└──────────────┬──────────────┘
               │
       ┌───────▼──────────┐
       │  MENU AWAL       │
       ├──────────────────┤
       │ 1. Register      │
       │ 2. Login         │
       │ 3. Keluar        │
       └────┬────┬───┬────┘
            │    │   │
        ┌───┘    │   │
        │        │   │
    [REGISTER]   │   │    [KELUAR]
        │        │   │       │
        ▼        │   │       ▼
   [Hash Table]  │   │    [END]
        │        │   │
        │    ┌───┘   │
        │    │       │
        │[LOGIN]     │
        │    │       │
        │    ▼       │
        │[Hash Table]│
        │    │       │
        └────┼──┐    │
             │  │    │
             ▼  ▼    │
        [MENU UTAMA] │
        ├─ Tambah Event ──────┐
        ├─ Lihat Event        │
        ├─ Cari Event ────────┤
        ├─ Urutkan Event ──┐  │
        ├─ Lihat BST ──┐   │  │
        ├─ Pesan Tiket ├─┐ │  │
        ├─ Batalkan ───┤ │ │  │
        ├─ Undo ────────┤ │ │  │
        ├─ Relasi ──────┤ │ │  │
        └─ Logout ──┐   │ │ │  │
           │        │   │ │ │  │
           │        │   │ │ │  │
           │   ┌────┴─┬─┴─┴─┘  │
           │   │      │        │
           ▼   ▼      ▼        ▼
    [LL] [BST][Queue][Stack][Graph]
```

---

## 12. ANALISIS RUANG (SPACE COMPLEXITY)

| Struktur | Kompleksitas |
|----------|--------------|
| Linked List | O(n) |
| Hash Table | O(n) |
| Queue | O(n) |
| Stack | O(n) |
| BST | O(n) |
| Graph | O(n + m) |
| Keseluruhan | O(n) |

---

## 13. KESALAHAN UMUM DAN SOLUSI

### Memory Leak
- **Masalah**: Tidak menghapus pointer dengan `delete`
- **Solusi**: Selalu deallocate memory pada destructor

### Pointer Null
- **Masalah**: Akses pointer yang belum diinisialisasi
- **Solusi**: Check `== nullptr` sebelum akses

### Collision di Hash Table
- **Masalah**: Dua user dengan hash value sama
- **Solusi**: Gunakan linear probing

### Stack Overflow
- **Masalah**: Terlalu banyak recursive call
- **Solusi**: Konversi ke iterative atau increase stack size

### Double Free
- **Masalah**: Delete pointer dua kali
- **Solusi**: Set pointer ke nullptr setelah delete

---

## 14. TESTING CHECKLIST

- [ ] Register user berhasil
- [ ] Login user berhasil
- [ ] Tambah event berhasil
- [ ] Lihat semua event
- [ ] Cari event (linear search)
- [ ] Sort event (by ID, capacity, sold)
- [ ] Lihat BST inorder
- [ ] Pesan tiket (enqueue)
- [ ] Lihat antrian
- [ ] Batalkan tiket (push stack)
- [ ] Lihat riwayat
- [ ] Undo pembatalan (pop stack)
- [ ] Tambah relasi graph
- [ ] Lihat relasi graph
- [ ] Logout berhasil

