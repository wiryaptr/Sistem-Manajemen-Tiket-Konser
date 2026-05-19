# CONTOH SKENARIO PENGGUNAAN
## Sistem Manajemen Event & Tiket Konser

---

## Skenario 1: User Pertama Kali Menggunakan Program

### Step 1: Register Akun Pertama
```
SISTEM MANAJEMEN EVENT & TIKET KONSER
====================================================
1. Register
2. Login
3. Keluar
----------------------------------------------------
Pilihan: 1

--- REGISTER ---
Username: aryawirya
Password: pass123

✓ User berhasil didaftarkan!
```

### Step 2: Login dengan Akun Baru
```
Pilihan: 2

--- LOGIN ---
Username: aryawirya
Password: pass123

✓ Login berhasil! Selamat datang, aryawirya!
```

### Step 3: Tambah Event Pertama
```
   MENU UTAMA - aryawirya
============================================================
1.  Tambah Event
2.  Lihat Semua Event
...
Pilihan: 1

--- TAMBAH EVENT ---
ID Event: 101
Nama Event: Coldplay Live Concert 2026
Genre: Musik International
Kota: Jakarta
Kapasitas: 5000
Harga per Tiket: 750000
Tanggal (dd-mm-yyyy): 25-06-2026

✓ Event berhasil ditambahkan!
```

### Step 4: Tambah Event Kedua
```
Pilihan: 1

--- TAMBAH EVENT ---
ID Event: 102
Nama Event: K-POP Festival 2026
Genre: K-Pop
Kota: Jakarta
Kapasitas: 3000
Harga per Tiket: 500000
Tanggal (dd-mm-yyyy): 15-07-2026

✓ Event berhasil ditambahkan!
```

### Step 5: Lihat Semua Event
```
Pilihan: 2

====================================================================================================
ID   Nama Event              Genre          Kota           Kapasitas Terjual Harga        Tanggal        
====================================================================================================
101  Coldplay Live Concert   Musik Intl     Jakarta        5000      0       750000.00    25-06-2026    
102  K-POP Festival 2026     K-Pop          Jakarta        3000      0       500000.00    15-07-2026    
====================================================================================================
```

### Step 6: Cari Event
```
Pilihan: 3

--- CARI EVENT ---
Masukkan nama event: Coldplay

✓ Event ditemukan!
ID: 101
Nama: Coldplay Live Concert 2026
Genre: Musik International
Kota: Jakarta
Kapasitas: 5000
Tiket Terjual: 0
Harga: 750000.00
Tanggal: 25-06-2026
```

### Step 7: Tambah Relasi Event (Graph)
```
Pilihan: 11

--- TAMBAH RELASI EVENT ---
Masukkan ID Event 1: 101
Masukkan ID Event 2: 102

✓ Relasi antar event berhasil ditambahkan!
```

### Step 8: Lihat Relasi Event
```
Pilihan: 12

==================================================
RELASI ANTAR EVENT
==================================================
Event 101 terhubung dengan: 102 
Event 102 terhubung dengan: 101 
==================================================
```

### Step 9: Lihat BST Event
```
Pilihan: 5

Daftar Event (Sorted by ID):
============================================================
ID   Nama Event              Genre          Kota           
============================================================
101  Coldplay Live Concert   Musik Intl     Jakarta        
102  K-POP Festival 2026     K-Pop          Jakarta        
============================================================
```

### Step 10: Logout
```
Pilihan: 13

✓ Logout berhasil!
```

---

## Skenario 2: Membeli Tiket dan Antrian

### Kondisi Awal
- User: aryawirya (sudah login)
- Event 101: Coldplay, 5000 kapasitas, 0 terjual
- Event 102: K-POP, 3000 kapasitas, 0 terjual

### Step 1: Pesan Tiket untuk Event 101
```
Pilihan: 6

--- PESAN TIKET ---

====================================================================================================
ID   Nama Event              Genre          Kota           Kapasitas Terjual Harga        Tanggal        
====================================================================================================
101  Coldplay Live Concert   Musik Intl     Jakarta        5000      0       750000.00    25-06-2026    
102  K-POP Festival 2026     K-Pop          Jakarta        3000      0       500000.00    15-07-2026    
====================================================================================================

Masukkan ID Event: 101
Jumlah Tiket: 5

✓ Tiket berhasil dipesan!
✓ Anda masuk antrian (Posisi: 1)
```

### Step 2: Lihat Antrian
```
Pilihan: 7

============================================================
No   Event ID        Username             Jumlah Tiket   
============================================================
1    101             aryawirya            5              
============================================================
```

### Step 3: Pesan Tiket untuk Event 102
```
Pilihan: 6

Masukkan ID Event: 102
Jumlah Tiket: 3

✓ Tiket berhasil dipesan!
✓ Anda masuk antrian (Posisi: 2)
```

### Step 4: Lihat Antrian (Updated)
```
Pilihan: 7

============================================================
No   Event ID        Username             Jumlah Tiket   
============================================================
1    101             aryawirya            5              
2    102             aryawirya            3              
============================================================
```

### Step 5: Lihat Semua Event (Status Update)
```
Pilihan: 2

====================================================================================================
ID   Nama Event              Genre          Kota           Kapasitas Terjual Harga        Tanggal        
====================================================================================================
101  Coldplay Live Concert   Musik Intl     Jakarta        5000      5       750000.00    25-06-2026    
102  K-POP Festival 2026     K-Pop          Jakarta        3000      3       500000.00    15-07-2026    
====================================================================================================
```

---

## Skenario 3: Pembatalan dan Undo

### Kondisi Awal
- Event 101: 5000 kapasitas, 5 terjual
- Event 102: 3000 kapasitas, 3 terjual
- Antrian: 2 pembelian

### Step 1: Batalkan 2 Tiket Event 101
```
Pilihan: 8

--- BATALKAN TIKET ---
Masukkan ID Event: 101
Jumlah Tiket: 2

✓ Tiket berhasil dibatalkan!
```

### Step 2: Lihat Riwayat Pembatalan
```
Pilihan: 10

======================================================================
No   Event ID        Username             Jumlah Tiket Tanggal Batal 
======================================================================
1    101             aryawirya            2            Thu May 16...
======================================================================
```

### Step 3: Batalkan 1 Tiket Event 102
```
Pilihan: 8

--- BATALKAN TIKET ---
Masukkan ID Event: 102
Jumlah Tiket: 1

✓ Tiket berhasil dibatalkan!
```

### Step 4: Lihat Riwayat (Updated)
```
Pilihan: 10

======================================================================
No   Event ID        Username             Jumlah Tiket Tanggal Batal 
======================================================================
1    102             aryawirya            1            Thu May 16...
2    101             aryawirya            2            Thu May 16...
======================================================================
```

### Step 5: Lihat Event (Tiket Berkurang)
```
Pilihan: 2

====================================================================================================
ID   Nama Event              Genre          Kota           Kapasitas Terjual Harga        Tanggal        
====================================================================================================
101  Coldplay Live Concert   Musik Intl     Jakarta        5000      3       750000.00    25-06-2026    
102  K-POP Festival 2026     K-Pop          Jakarta        3000      2       500000.00    15-07-2026    
====================================================================================================
```

### Step 6: Undo Pembatalan (LIFO)
```
Pilihan: 9

✓ Undo pembatalan berhasil! Tiket kembali dijual.
```

### Step 7: Lihat Event (Tiket Restore)
```
Pilihan: 2

====================================================================================================
ID   Nama Event              Genre          Kota           Kapasitas Terjual Harga        Tanggal        
====================================================================================================
101  Coldplay Live Concert   Musik Intl     Jakarta        5000      4       750000.00    25-06-2026    
102  K-POP Festival 2026     K-Pop          Jakarta        3000      2       500000.00    15-07-2026    
====================================================================================================

// Tiket event 102 kembali dari 2 menjadi 3 (LIFO - pembatalan terakhir di-undo lebih dulu)
```

### Step 8: Undo Lagi
```
Pilihan: 9

✓ Undo pembatalan berhasil! Tiket kembali dijual.
```

### Step 9: Lihat Event (Tiket Restore Lagi)
```
Pilihan: 2

====================================================================================================
ID   Nama Event              Genre          Kota           Kapasitas Terjual Harga        Tanggal        
====================================================================================================
101  Coldplay Live Concert   Musik Intl     Jakarta        5000      5       750000.00    25-06-2026    
102  K-POP Festival 2026     K-Pop          Jakarta        3000      3       500000.00    15-07-2026    
====================================================================================================

// Sekarang event 101 juga restore, kembali menjadi 5
```

### Step 10: Lihat Riwayat (Sudah Kosong)
```
Pilihan: 10

Tidak ada riwayat pembatalan.
```

---

## Skenario 4: Sorting Event

### Kondisi Awal (3 Event)
```
101 - Coldplay           - Kapasitas: 5000  - Terjual: 5
102 - K-POP Festival     - Kapasitas: 3000  - Terjual: 3
103 - Jazz Night         - Kapasitas: 1000  - Terjual: 10
```

### Sort by Kapasitas
```
Pilihan: 4

--- URUTKAN EVENT ---
1. Sort by ID
2. Sort by Kapasitas
3. Sort by Tiket Terjual
Pilihan: 2

✓ Data berhasil diurutkan!

====================================================================================================
ID   Nama Event              Genre          Kota           Kapasitas Terjual Harga        Tanggal        
====================================================================================================
103  Jazz Night             Jazz           Jakarta        1000      10      500000.00    10-07-2026    
102  K-POP Festival 2026     K-Pop          Jakarta        3000      3       500000.00    15-07-2026    
101  Coldplay Live Concert   Musik Intl     Jakarta        5000      5       750000.00    25-06-2026    
====================================================================================================

// Terurut dari kapasitas terkecil ke terbesar: 1000 → 3000 → 5000
```

### Sort by Tiket Terjual
```
Pilihan: 4

--- URUTKAN EVENT ---
1. Sort by ID
2. Sort by Kapasitas
3. Sort by Tiket Terjual
Pilihan: 3

✓ Data berhasil diurutkan!

====================================================================================================
ID   Nama Event              Genre          Kota           Kapasitas Terjual Harga        Tanggal        
====================================================================================================
102  K-POP Festival 2026     K-Pop          Jakarta        3000      3       500000.00    15-07-2026    
101  Coldplay Live Concert   Musik Intl     Jakarta        5000      5       750000.00    25-06-2026    
103  Jazz Night             Jazz           Jakarta        1000      10      500000.00    10-07-2026    
====================================================================================================

// Terurut dari terjual terkecil ke terbesar: 3 → 5 → 10
```

---

## Skenario 5: Multiple Users

### Register User Kedua
```
Pilihan: 13 (Logout)

✓ Logout berhasil!

Pilihan: 1 (Register)
Username: budi_santoso
Password: pass456

✓ User berhasil didaftarkan!

Pilihan: 2 (Login)
Username: budi_santoso
Password: pass456

✓ Login berhasil! Selamat datang, budi_santoso!
```

### Pesan Tiket dengan User Kedua
```
Pilihan: 6 (Pesan Tiket)
ID Event: 101
Jumlah Tiket: 10

✓ Tiket berhasil dipesan!
✓ Anda masuk antrian (Posisi: 2)
```

### Lihat Antrian
```
Pilihan: 7

============================================================
No   Event ID        Username             Jumlah Tiket   
============================================================
1    101             aryawirya            5              
2    102             aryawirya            3              
3    101             budi_santoso         10             
============================================================
```

---

## Test Case Checklist

- [x] Register berhasil
- [x] Login berhasil
- [x] Tambah event
- [x] Lihat event
- [x] Cari event (Linear Search)
- [x] Sort event (by ID, Kapasitas, Terjual)
- [x] Lihat BST
- [x] Pesan tiket (Queue)
- [x] Lihat antrian
- [x] Batalkan tiket (Stack push)
- [x] Lihat riwayat
- [x] Undo pembatalan (Stack pop - LIFO)
- [x] Tambah relasi (Graph edge)
- [x] Lihat relasi (Graph display)
- [x] Logout
- [x] Multiple users

---

## Notes

- Setiap operasi di-trace dengan output yang jelas
- Struktur data terintegrasi dengan baik
- FIFO terbukti pada Queue (antrian terurut)
- LIFO terbukti pada Stack (undo pembatalan terbalik)
- BST menampilkan data terurut by ID
- Linear Search menemukan data dengan partial match
- Graph menunjukkan relasi dua arah (undirected)

