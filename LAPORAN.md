# SISTEM MANAJEMEN EVENT & TIKET KONSER
## Laporan Final Project Struktur Data

---

### 1. PENDAHULUAN

Sistem Manajemen Event & Tiket Konser adalah aplikasi berbasis Command Line Interface (CLI) yang mengimplementasikan seluruh materi Struktur Data yang telah dipelajari dalam satu semester. Project ini dirancang untuk mengelola data event, user, tiket, dan relasi antar event dengan memanfaatkan berbagai struktur data secara terintegrasi.

---

### 2. DAFTAR STRUKTUR DATA YANG DIGUNAKAN

#### 2.1 Linked List (Doubly Linked List)
- **Fungsi**: Menyimpan daftar event secara dinamis
- **Alasan**: Memudahkan penambahan dan penghapusan event tanpa perlu re-allocation memory
- **Implementasi**: Menggunakan pointer `next` dan `prev` untuk navigasi dua arah
- **Operasi**:
  - `insertEvent()` - Menambah event baru di akhir list
  - `deleteEvent()` - Menghapus event berdasarkan ID
  - `displayAllEvents()` - Menampilkan semua event
  - `findEventByID()` - Mencari event berdasarkan ID

#### 2.2 Hash Table
- **Fungsi**: Menyimpan data user untuk login dan register
- **Alasan**: Pencarian user O(1) rata-rata, mencegah duplikasi username
- **Implementasi**: Menggunakan linear probing untuk collision handling
- **Hash Function**: `(hash * 31 + char) % table_size`
- **Operasi**:
  - `insertUser()` - Menambah user baru
  - `authenticateUser()` - Verifikasi login
  - `userExists()` - Cek keberadaan user
  - `getUser()` - Ambil data user

#### 2.3 Queue (FIFO)
- **Fungsi**: Menyimpan antrian pembelian tiket
- **Alasan**: Memastikan proses pembelian tiket adil (siapa duluan, duluan diproses)
- **Implementasi**: Menggunakan single linked list dengan front dan rear pointer
- **Operasi**:
  - `enqueue()` - Menambah pembeli ke antrian
  - `dequeue()` - Mengeluarkan pembeli dari antrian
  - `displayQueue()` - Menampilkan daftar antrian

#### 2.4 Stack (LIFO)
- **Fungsi**: Menyimpan riwayat pembatalan tiket untuk fitur undo
- **Alasan**: Pembatalan yang terakhir akan di-undo lebih dulu (LIFO principle)
- **Implementasi**: Menggunakan single linked list dengan top pointer
- **Operasi**:
  - `push()` - Menyimpan riwayat pembatalan
  - `pop()` - Mengambil riwayat pembatalan (undo)
  - `displayRiwayat()` - Menampilkan riwayat pembatalan

#### 2.5 Binary Search Tree (BST)
- **Fungsi**: Pencarian cepat event berdasarkan ID
- **Alasan**: Untuk optimasi pencarian dengan struktur yang terorganisir (O(log n))
- **Implementasi**: Recursive insertion dan search
- **Operasi**:
  - `insert()` - Menambah event ke BST
  - `search()` - Mencari event berdasarkan ID
  - `displayInorder()` - Tampilkan event terurut

#### 2.6 Graph (Adjacency List)
- **Fungsi**: Merepresentasikan relasi/hubungan antar event
- **Alasan**: Menunjukkan event mana saja yang terhubung (genre sama, kota sama, dll)
- **Implementasi**: Undirected graph dengan adjacency list
- **Operasi**:
  - `addNode()` - Menambah node event
  - `addEdge()` - Menambah relasi antar event
  - `displayGraph()` - Tampilkan relasi event

#### 2.7 Sorting (Manual)
- **Algoritma**: Bubble Sort
- **Jenis Sorting**:
  1. By Event ID
  2. By Kapasitas
  3. By Tiket Terjual
- **Implementasi**: Manual sorting tanpa menggunakan STL sort()

#### 2.8 Searching (Manual)
- **Tipe Searching**:
  1. **Linear Search** - Cari event berdasarkan nama
  2. **Binary Search** - Cari dalam array yang sudah ter-sort (opsional)
- **Implementasi**: Tanpa menggunakan STL find()

---

### 3. ALUR INTEGRASI SISTEM

```
START
  ↓
[MENU AWAL]
├─ Register → Hash Table (tambah user)
├─ Login → Hash Table (verifikasi user)
└─ Keluar → END

[MENU UTAMA - User Logged In]
├─ Tambah Event
│  ├─ Linked List (tambah event)
│  ├─ BST (insert event untuk index cepat)
│  └─ Graph (tambah node event)
│
├─ Lihat Semua Event
│  └─ Linked List (traversal all events)
│
├─ Cari Event
│  ├─ Linear Search (cari by nama)
│  └─ BST (cari by ID - lebih cepat)
│
├─ Urutkan Event
│  └─ Sorting Manual (Bubble Sort)
│
├─ Pesan Tiket
│  ├─ Linked List (update kapasitas terjual)
│  └─ Queue (masuk antrian)
│
├─ Batalkan Tiket
│  ├─ Linked List (update kapasitas terjual)
│  └─ Stack (push riwayat pembatalan)
│
├─ Undo Pembatalan
│  ├─ Stack (pop riwayat)
│  └─ Linked List (restore kapasitas)
│
├─ Tambah Relasi Event
│  └─ Graph (addEdge antara dua event)
│
├─ Lihat Relasi Event
│  └─ Graph (display adjacency list)
│
└─ Logout → kembali MENU AWAL
```

---

### 4. FITUR-FITUR UTAMA

#### 4.1 Manajemen User
- **Register**: User baru didaftarkan ke Hash Table
- **Login**: Verifikasi username dan password dari Hash Table
- **Password Security**: Password disimpan plaintext (untuk keperluan project)

#### 4.2 Manajemen Event
- **Tambah Event**: Event disimpan di Linked List, indexed di BST, dan node di Graph
- **Lihat Event**: Menampilkan semua event dengan format tabel
- **Hapus Event**: Menghapus event dari Linked List (dapat ditambahkan)
- **Cari Event**: Linear Search berdasarkan nama event

#### 4.3 Manajemen Tiket & Antrian
- **Pesan Tiket**: 
  - Update jumlah tiket terjual di event
  - Masukkan pembeli ke Queue
- **Antrian**: FIFO queue untuk pembeli tiket
- **Lihat Antrian**: Menampilkan urutan pembeli di antrian

#### 4.4 Pembatalan & Undo
- **Batalkan Tiket**: Kurangi tiket terjual, simpan ke Stack
- **Undo Pembatalan**: Pop dari Stack, restore jumlah tiket
- **Riwayat Pembatalan**: Tampilkan semua pembatalan yang pernah dilakukan

#### 4.5 Pencarian Cepat
- **BST Search**: Pencarian event by ID O(log n) rata-rata
- **Linear Search**: Pencarian event by nama O(n)

#### 4.6 Relasi Event
- **Tambah Relasi**: Hubungkan dua event di Graph
- **Tampilkan Relasi**: Lihat event mana saja yang terhubung

---

### 5. KOMPLEKSITAS WAKTU (BIG-O)

| Operasi | Struktur | Kompleksitas | Penjelasan |
|---------|----------|--------------|-----------|
| Insert Event | Linked List | O(1) | Append di akhir |
| Delete Event | Linked List | O(n) | Search + delete |
| Find Event | Linked List | O(n) | Linear search |
| Insert User | Hash Table | O(1) | Average case |
| Authenticate | Hash Table | O(1) | Average case |
| Enqueue | Queue | O(1) | Append di rear |
| Dequeue | Queue | O(1) | Remove dari front |
| Push | Stack | O(1) | Append di top |
| Pop | Stack | O(1) | Remove dari top |
| Insert BST | BST | O(log n) | Average case, O(n) worst |
| Search BST | BST | O(log n) | Average case, O(n) worst |
| Add Edge | Graph | O(1) | Append node |
| Bubble Sort | Array/LL | O(n²) | Worst case |
| Linear Search | Array/LL | O(n) | Worst case |
| Binary Search | Sorted Array | O(log n) | Divide and conquer |

---

### 6. KEPATUHAN TERHADAP KETENTUAN

✓ **Menggunakan semua struktur data yang diminta**:
- Linked List ✓
- Queue ✓
- Stack ✓
- Sorting ✓
- Searching ✓
- Hash Table ✓
- Tree (BST) ✓
- Graph ✓

✓ **Ketentuan Implementasi**:
- Diimplementasikan secara manual (from scratch) ✓
- Menggunakan Pointer ✓
- Menggunakan Struct ✓
- Program berbasis CLI ✓
- Tidak menggunakan STL container ✓

✓ **Ketentuan Tambahan**:
- Sorting diimplementasikan manual (Bubble Sort) ✓
- Searching diimplementasikan manual (Linear & Binary Search) ✓
- Hash Table memiliki hash function dan collision handling sendiri ✓
- Tree menggunakan node tree manual ✓
- Graph dibuat tanpa library ✓

---

### 7. CARA MENGGUNAKAN PROGRAM

#### 7.1 Kompilasi
```bash
cd SistemMEvent
g++ -o SistemManajemenEvent.exe SistemManajemenEvent.cpp -std=c++17
```

#### 7.2 Menjalankan
```bash
./SistemManajemenEvent.exe
```

#### 7.3 Menu Awal
```
1. Register - Daftar akun baru
2. Login - Login dengan akun yang terdaftar
3. Keluar - Keluar dari program
```

#### 7.4 Menu Utama (Setelah Login)
```
1. Tambah Event
2. Lihat Semua Event
3. Cari Event (Linear Search)
4. Urutkan Event
5. Lihat BST Event
6. Pesan Tiket
7. Lihat Antrian Tiket
8. Batalkan Tiket
9. Undo Pembatalan
10. Lihat Riwayat Pembatalan
11. Tambah Relasi Event
12. Lihat Relasi Event
13. Logout
```

---

### 8. CONTOH SKENARIO PENGGUNAAN

**Skenario: User ingin membeli tiket konser**

1. User pertama kali membuka program → Register (input ke Hash Table)
2. User Login → Hash Table verifikasi → Masuk menu utama
3. Tambah Event (Konser A) → Linked List + BST + Graph
4. Tambah Event (Konser B) → Linked List + BST + Graph
5. Tambah Relasi (Konser A ↔ Konser B) → Graph addEdge
6. Lihat Semua Event → Linked List traversal
7. Cari Event "Konser A" → Linear Search
8. Pesan Tiket Konser A (5 tiket) → Queue enqueue, update tiket terjual
9. Lihat Antrian → Queue display
10. Batalkan 2 tiket Konser A → Stack push riwayat, kurang tiket terjual
11. Undo pembatalan → Stack pop, restore tiket
12. Lihat Relasi Event → Graph display
13. Logout → Kembali menu awal

---

### 9. STRUKTUR FILE

```
SistemMEvent/
├── SistemManajemenEvent.cpp    (Source code utama)
├── SistemManajemenEvent.exe    (Executable)
└── LAPORAN.md                  (File ini)
```

---

### 10. KESIMPULAN

Sistem Manajemen Event & Tiket Konser berhasil mengintegrasikan seluruh struktur data yang dipelajari dalam satu sistem yang kohesif dan fungsional. Setiap struktur data memiliki peran penting dalam sistem dan saling terhubung secara logis.

Project ini mendemonstrasikan:
- Pemahaman mendalam tentang masing-masing struktur data
- Kemampuan mengintegrasikan berbagai struktur data
- Implementasi manual tanpa library
- Desain sistem yang scalable dan maintainable
- Penerapan prinsip OOP dalam C++

---

### 11. PENGEMBANGAN LEBIH LANJUT (Opsional)

Fitur-fitur yang dapat ditambahkan di masa depan:
1. File persistence (Save/Load event dari file)
2. GUI menggunakan Qt atau WinAPI
3. Database integration
4. Payment gateway untuk pembelian tiket
5. Email notification untuk konfirmasi tiket
6. Rating dan review untuk event
7. Rekomendasi event berdasarkan preferensi user
8. Multi-user session management
9. Statistik dan analytics

---

**NIM**: 046
**Nama**: Arya Wirya
**Tanggal**: 16 Mei 2026

