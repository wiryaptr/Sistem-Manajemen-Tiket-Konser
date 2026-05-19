# README - Sistem Manajemen Event & Tiket Konser

## Quick Start

### Kompilasi
```bash
cd SistemMEvent
g++ -o SistemManajemenEvent.exe SistemManajemenEvent.cpp -std=c++17
```

### Menjalankan Program
```bash
./SistemManajemenEvent.exe
```

## Fitur Utama

1. **Manajemen User** - Register dan Login
2. **Manajemen Event** - Tambah, lihat, cari, dan urutkan event
3. **Manajemen Tiket** - Pesan tiket dan masuk antrian
4. **Pembatalan Tiket** - Batalkan tiket dan fitur undo
5. **Pencarian Cepat** - Search event by ID menggunakan BST
6. **Relasi Event** - Tambahkan relasi antar event dengan graph

## Struktur Data yang Digunakan

✓ Linked List - Penyimpanan event  
✓ Hash Table - Manajemen user  
✓ Queue - Antrian pembelian tiket  
✓ Stack - Riwayat pembatalan  
✓ Binary Search Tree (BST) - Pencarian event cepat  
✓ Graph - Relasi antar event  
✓ Sorting Manual - Bubble Sort  
✓ Searching Manual - Linear & Binary Search  

## File Documentation

- `LAPORAN.md` - Laporan lengkap project
- `DOKUMENTASI_TEKNIS.md` - Dokumentasi teknis setiap struktur data
- `SistemManajemenEvent.cpp` - Source code utama

## Contoh Penggunaan

### 1. Register User Baru
```
Menu: 1 (Register)
Username: john_doe
Password: password123
```

### 2. Login
```
Menu: 2 (Login)
Username: john_doe
Password: password123
```

### 3. Tambah Event
```
Menu: 1 (Tambah Event)
ID Event: 1
Nama Event: Concert Coldplay 2026
Genre: Music
Kota: Jakarta
Kapasitas: 5000
Harga per Tiket: 750000
Tanggal (dd-mm-yyyy): 25-06-2026
```

### 4. Pesan Tiket
```
Menu: 6 (Pesan Tiket)
Masukkan ID Event: 1
Jumlah Tiket: 2
```

### 5. Batalkan Tiket
```
Menu: 8 (Batalkan Tiket)
Masukkan ID Event: 1
Jumlah Tiket: 1
```

### 6. Undo Pembatalan
```
Menu: 9 (Undo Pembatalan)
// Otomatis restore tiket yang dibatalkan
```

## System Requirements

- C++ Compiler (GCC, Clang, MSVC)
- Standard Library (iostream, cstring, iomanip, cctype, ctime)
- OS: Windows, Linux, atau MacOS

## Notes

- Semua struktur data diimplementasikan dari scratch (tanpa STL)
- Program menggunakan CLI (Command Line Interface)
- Password disimpan dalam plaintext (hanya untuk project)
- Memory management menggunakan dynamic allocation

## Author

**NIM**: 046  
**Nama**: Arya Wirya  
**Tahun**: 2026

---

**Laporan Lengkap**: Lihat `LAPORAN.md`  
**Dokumentasi Teknis**: Lihat `DOKUMENTASI_TEKNIS.md`
