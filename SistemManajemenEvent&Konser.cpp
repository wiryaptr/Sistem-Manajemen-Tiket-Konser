#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

const int HASH_TABLE_SIZE = 100;
const int MAX_QUEUE_SIZE = 1000;

// visual tabel
void GarisTabel(int n) {
    cout << setfill('=') << setw(n) << "" << setfill(' ') << "\n";
}

string getCurrentDateString() {
    time_t t = time(nullptr);
    tm* lt = localtime(&t);
    char buf[16];
    strftime(buf, sizeof(buf), "%d-%m-%Y", lt);
    return string(buf);
}

// Linked List
struct Event {
    int eventID;
    string nama;   
    string genre;  
    string kota;
    int kapasitas;
    int terjual;
    float harga;
    string tanggal;
};

struct NodeEvent {
    Event data;
    NodeEvent* next;
    NodeEvent* prev;
};

NodeEvent* headEvent = nullptr;
NodeEvent* tailEvent = nullptr;
int countEvent = 0;

void insertEvent(Event data, bool verbose = true) {
    NodeEvent* newNode = new NodeEvent();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (headEvent == nullptr) {
        headEvent = tailEvent = newNode;
    } else {
        tailEvent->next = newNode;
        newNode->prev = tailEvent;
        tailEvent = newNode;
    }
    countEvent++;
    if (verbose) {
        cout << "[System] Event berhasil ditambahkan.\n";
    }
}

Event* cariEventID(int id) {
    NodeEvent* curr = headEvent;
    while (curr != nullptr) {
        if (curr->data.eventID == id) return &curr->data;
        curr = curr->next;
    }
    return nullptr;
}

void tampilkanSemuaEvent() {
    if (headEvent == nullptr) {
        cout << "Data event kosong.\n";
        return;
    }
    cout << "\n";
    GarisTabel(105);
    cout << left << setw(8) << "ID" << setw(25) << "Nama Event" << setw(15) << "Genre" << setw(15) << "Kota" << setw(10) << "Kuota" << setw(10) << "Terjual" << setw(12) << "Harga" << setw(15) << "Tanggal" << "\n";
    GarisTabel(105);

    NodeEvent* curr = headEvent;
    while (curr != nullptr) {
        cout << left << setw(8) << curr->data.eventID << setw(25) << curr->data.nama << setw(15) << curr->data.genre << setw(15) << curr->data.kota << setw(10) << curr->data.kapasitas << setw(10) << curr->data.terjual << fixed << setprecision(2) << setw(12) << curr->data.harga << setw(15) << curr->data.tanggal << "\n";
        curr = curr->next;
    }
    GarisTabel(105);
}

// Hash Table
struct User {
    string username;
    string password;
    int userID;
};

User* userTable[HASH_TABLE_SIZE] = {nullptr};
int userCounter = 0;
string currentUser = "";
bool isLoggedIn = false;

int hitungHash(string username) {
    int h = 0;
    for (char c : username) {
        h = (h * 31 + c) % HASH_TABLE_SIZE;
    }
    return h;
}

bool registerUser(string uname, string pass, int id, bool verbose = true) {
    int index = hitungHash(uname);
    int startIdx = index;

    while (userTable[index] != nullptr) {
        if (userTable[index]->username == uname) { 
            if (verbose) cout << "[!] Username sudah terdaftar!\n";
            return false;
        }
        index = (index + 1) % HASH_TABLE_SIZE;
        if (index == startIdx) {
            if (verbose) cout << "[!] Memori user penuh!\n";
            return false;
        }
    }
    userTable[index] = new User();
    userTable[index]->username = uname;
    userTable[index]->password = pass;
    userTable[index]->userID = id;
    if (verbose) cout << "[System] Registrasi sukses.\n";
    return true;
}

bool cekLoginUser(string uname, string pass) {
    int index = hitungHash(uname);
    int startIdx = index;

    while (userTable[index] != nullptr) {
        if (userTable[index]->username == uname) {
            return (userTable[index]->password == pass);
        }
        index = (index + 1) % HASH_TABLE_SIZE;
        if (index == startIdx) break;
    }
    return false;
}

// Queue
struct NodeQueue {
    int eventID;
    string username;
    int jumlahTiket;
    NodeQueue* next;
};

NodeQueue* queueFront = nullptr;
NodeQueue* queueRear = nullptr;
int queueSize = 0;

void enqueueTiket(int id, string uname, int jml) {
    if (queueSize >= MAX_QUEUE_SIZE) {
        cout << "[!] Antrian penuh.\n";
        return;
    }
    NodeQueue* newNode = new NodeQueue();
    newNode->eventID = id;
    newNode->username = uname;
    newNode->jumlahTiket = jml;
    newNode->next = nullptr;

    if (queueFront == nullptr) {
        queueFront = queueRear = newNode;
    } else {
        queueRear->next = newNode;
        queueRear = newNode;
    }
    queueSize++;
    cout << "[System] Masuk antrian booking, nomor antrian: " << queueSize << "\n";
}

void tampilkanAntrian() {
    if (queueFront == nullptr) {
        cout << "Antrian kosong.\n";
        return;
    }
    cout << "\n";
    GarisTabel(55);
    cout << left << setw(8) << "No" << setw(15) << "Event ID" << setw(20) << "Username" << setw(10) << "Jumlah" << "\n";
    GarisTabel(55);

    NodeQueue* curr = queueFront;
    int no = 1;
    while (curr != nullptr) {
        cout << left << setw(8) << no << setw(15) << curr->eventID << setw(20) << curr->username << setw(10) << curr->jumlahTiket << "\n";
        curr = curr->next;
        no++;
    }
    GarisTabel(55);
}

// Stack
struct NodeStack {
    int eventID;
    string username;
    int jumlahTiket;
    string tanggalBatal;
    NodeStack* next;
};

NodeStack* stackTop = nullptr;

void pushStack(int id, string uname, int jml, string tgl) {
    NodeStack* newNode = new NodeStack();
    newNode->eventID = id;
    newNode->username = uname;
    newNode->jumlahTiket = jml;
    newNode->tanggalBatal = tgl;
    
    newNode->next = stackTop;
    stackTop = newNode;
}

bool popStack(int& id, string& uname, int& jml, string& tgl) {
    if (stackTop == nullptr) return false;
    NodeStack* temp = stackTop;
    
    id = temp->eventID;
    uname = temp->username;
    jml = temp->jumlahTiket;
    tgl = temp->tanggalBatal;

    stackTop = stackTop->next;
    delete temp;
    return true;
}

void tampilkanRiwayatBatal() {
    if (stackTop == nullptr) {
        cout << "Belum ada riwayat pembatalan.\n";
        return;
    }
    cout << "\n";
    GarisTabel(70);
    cout << left << setw(8) << "No" << setw(15) << "Event ID" << setw(20) << "Username" << setw(12) << "Jumlah" << setw(15) << "Tgl Batal" << "\n";
    GarisTabel(70);

    NodeStack* curr = stackTop;
    int no = 1;
    while (curr != nullptr) {
        cout << left << setw(8) << no << setw(15) << curr->eventID << setw(20) << curr->username << setw(12) << curr->jumlahTiket << setw(15) << curr->tanggalBatal << "\n";
        curr = curr->next;
        no++;
    }
    GarisTabel(70);
}

// Tree
struct NodeBST {
    Event data;
    NodeBST* left;
    NodeBST* right;
};

NodeBST* bstRoot = nullptr;

NodeBST* insertBSTNode(NodeBST* node, Event data) {
    if (node == nullptr) {
        NodeBST* newNode = new NodeBST();
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }
    if (data.eventID < node->data.eventID) {
        node->left = insertBSTNode(node->left, data);
    } else if (data.eventID > node->data.eventID) {
        node->right = insertBSTNode(node->right, data);
    }
    return node;
}

void inorderTraversal(NodeBST* node) {
    if (node != nullptr) {
        inorderTraversal(node->left);
        cout << left << setw(8) << node->data.eventID << setw(25) << node->data.nama << setw(15) << node->data.genre << setw(15) << node->data.kota << "\n";
        inorderTraversal(node->right);
    }
}

void tampilkanBST() {
    if (bstRoot == nullptr) {
        cout << "BST kosong.\n";
        return;
    }
    cout << "\n--- DATA EVENT BERDASARKAN ID (BST INORDER) ---\n";
    GarisTabel(63);
    cout << left << setw(8) << "ID" << setw(25) << "Nama Event" << setw(15) << "Genre" << setw(15) << "Kota" << "\n";
    GarisTabel(63);
    inorderTraversal(bstRoot);
    GarisTabel(63);
}

// Graph
struct NodeGraph {
    int eventID;
    NodeGraph* next;
};

struct AdjacencyListGraph {
    int eventID;
    NodeGraph* adjacencyList;
};

AdjacencyListGraph graphList[100];
int graphTotalNodes = 0;

int cariIndexGraph(int id) {
    for (int i = 0; i < graphTotalNodes; i++) {
        if (graphList[i].eventID == id) return i;
    }
    return -1;
}

void tambahNodeGraph(int id) {
    if (cariIndexGraph(id) == -1 && graphTotalNodes < 100) {
        graphList[graphTotalNodes].eventID = id;
        graphList[graphTotalNodes].adjacencyList = nullptr;
        graphTotalNodes++;
    }
}

void hubungkanEdgeGraph(int id1, int id2) {
    int idx1 = cariIndexGraph(id1);
    int idx2 = cariIndexGraph(id2);

    if (idx1 == -1 || idx2 == -1) {
        cout << "[!] Salah satu ID Event tidak ditemukan di graph.\n";
        return;
    }

    NodeGraph* n1 = new NodeGraph();
    n1->eventID = id2;
    n1->next = graphList[idx1].adjacencyList;
    graphList[idx1].adjacencyList = n1;

    NodeGraph* n2 = new NodeGraph();
    n2->eventID = id1;
    n2->next = graphList[idx2].adjacencyList;
    graphList[idx2].adjacencyList = n2;

    cout << "[System] Relasi graph berhasil dipasang.\n";
}

void tampilkanGraph() {
    if (graphTotalNodes == 0) {
        cout << "Graph kosong.\n";
        return;
    }
    cout << "\n--- MAP REKOMENDASI RELASI EVENT (GRAPH) ---\n";
    for (int i = 0; i < graphTotalNodes; i++) {
        cout << "Event " << graphList[i].eventID << " terhubung ke: ";
        NodeGraph* curr = graphList[i].adjacencyList;
        if (curr == nullptr) {
            cout << "-";
        } else {
            while (curr != nullptr) {
                cout << curr->eventID << " ";
                curr = curr->next;
            }
        }
        cout << "\n";
    }
    GarisTabel(50);
}

// Output .txt
void simpanKeFile() {
    ofstream fEvent("database_event.txt");
    NodeEvent* curr = headEvent;
    while (curr != nullptr) {
        fEvent << curr->data.eventID << "\n" << curr->data.nama << "\n" << curr->data.genre << "\n" << curr->data.kota << "\n" << curr->data.kapasitas << "\n" << curr->data.terjual << "\n" << curr->data.harga << "\n" << curr->data.tanggal << "\n";
        curr = curr->next;
    }
    fEvent.close();

    ofstream fUser("database_user.txt");
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        if (userTable[i] != nullptr) {
            fUser << userTable[i]->username << "\n" << userTable[i]->password << "\n" << userTable[i]->userID << "\n";
        }
    }
    fUser.close();
}

void muatDariFile() {
    ifstream fEvent("database_event.txt");
    if (fEvent.is_open()) {
        Event ev;
        while (fEvent >> ev.eventID) {
            fEvent.ignore();
            getline(fEvent, ev.nama); 
            getline(fEvent, ev.genre);
            getline(fEvent, ev.kota);
            fEvent >> ev.kapasitas;
            fEvent >> ev.terjual;
            fEvent >> ev.harga;
            fEvent.ignore();
            getline(fEvent, ev.tanggal);

            insertEvent(ev, false);
            bstRoot = insertBSTNode(bstRoot, ev);
            tambahNodeGraph(ev.eventID);
        }
        fEvent.close();
    }

    ifstream fUser("database_user.txt");
    if (fUser.is_open()) {
        string uname, pass;
        int id;
        while (getline(fUser, uname)) {
            getline(fUser, pass);
            fUser >> id;
            fUser.ignore();

            registerUser(uname, pass, id, false);
            if (id > userCounter) userCounter = id;
        }
        fUser.close();
    }
}

// Sorting dan Searching
void urutkanEventBubble(int tipeSort) {
    if (headEvent == nullptr) return;
    bool swapped;
    NodeEvent* curr;

    do {
        swapped = false;
        curr = headEvent;
        while (curr->next != nullptr) {
            bool butuhTukar = false;
            if (tipeSort == 1) butuhTukar = (curr->data.eventID > curr->next->data.eventID);
            else if (tipeSort == 2) butuhTukar = (curr->data.kapasitas > curr->next->data.kapasitas);
            else if (tipeSort == 3) butuhTukar = (curr->data.terjual > curr->next->data.terjual);

            if (butuhTukar) {
                Event t = curr->data;
                curr->data = curr->next->data;
                curr->next->data = t;
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);
    cout << "[System] Sorting selesai.\n";
    simpanKeFile();
}

void cariEventLinear() {
    cout << "\n--- CARI EVENT ---\n";
    string target;
    cout << "Masukkan nama event: ";
    getline(cin, target);

    NodeEvent* curr = headEvent;
    bool ketemu = false;
    while (curr != nullptr) {
        // Menggunakan fungsi bawaan string objek .find()
        if (curr->data.nama.find(target) != string::npos) {
            ketemu = true;
            cout << "\n> Data Ditemukan:\n";
            cout << "ID: " << curr->data.eventID << " | Nama: " << curr->data.nama << "\n";
            cout << "Genre: " << curr->data.genre << " | Kota: " << curr->data.kota << "\n";
            cout << "Kuota: " << curr->data.kapasitas << " | Terjual: " << curr->data.terjual << "\n";
            cout << "Harga: " << fixed << setprecision(2) << curr->data.harga << "\n"; 
            cout << "Tanggal: " << curr->data.tanggal << "\n";
        }
        curr = curr->next;
    }
    if (!ketemu) cout << "[!] Event tidak ditemukan.\n";
}

// Menu 
void TambahEvent() {
    cout << "\n--- INPUT DATA EVENT ---\n";
    Event ev;
    cout << "ID Event    : "; cin >> ev.eventID; 
    cin.ignore(1000, '\n');
    cout << "Nama Event  : "; getline(cin, ev.nama);
    cout << "Genre       : "; getline(cin, ev.genre);
    cout << "Kota        : "; getline(cin, ev.kota);
    cout << "Kuota Tiket : "; cin >> ev.kapasitas;
    cout << "Harga Tiket : "; cin >> ev.harga; 
    cin.ignore(1000, '\n');
    cout << "Tanggal     : "; getline(cin, ev.tanggal);
    ev.terjual = 0;

    insertEvent(ev);
    bstRoot = insertBSTNode(bstRoot, ev);
    tambahNodeGraph(ev.eventID);
    simpanKeFile();
}

void PesanTiket() {
    cout << "\n--- FORM BOOKING TIKET ---\n";
    tampilkanSemuaEvent();
    int id, jml;
    cout << "Masukkan ID Event : "; cin >> id;
    cout << "Jumlah Tiket      : "; cin >> jml; 
    cin.ignore(1000, '\n');

    Event* ev = cariEventID(id);
    if (ev != nullptr) {
        if (ev->terjual + jml <= ev->kapasitas) {
            ev->terjual += jml;
            enqueueTiket(id, currentUser, jml);
            simpanKeFile();
        } else {
            cout << "[!] Sisa kuota tiket tidak cukup.\n";
        }
    } else {
        cout << "[!] ID Event tidak ditemukan.\n";
    }
}

void BatalkanTiket() {
    cout << "\n--- CANCEL/REFUND TIKET ---\n";
    int id, jml;
    cout << "Masukkan ID Event: "; cin >> id;
    cout << "Jumlah Tiket Batal: "; cin >> jml; 
    cin.ignore(1000, '\n');

    Event* ev = cariEventID(id);
    if (ev != nullptr) {
        if (ev->terjual >= jml) {
            ev->terjual -= jml;
            pushStack(id, currentUser, jml, getCurrentDateString());
            cout << "[System] Refund berhasil.\n";
            simpanKeFile();
        } else {
            cout << "[!] Input jumlah pembatalan salah.\n";
        }
    } else {
        cout << "[!] ID Event tidak valid.\n";
    }
}

void UndoBatal() {
    int id, jml;
    string uname, tgl;
    if (popStack(id, uname, jml, tgl)) {
        if (uname != currentUser) {
            // kembalikan ke stack karena bukan milik user sekarang
            pushStack(id, uname, jml, tgl);
            cout << "[!] Anda tidak berwenang meng-undo pembatalan pengguna lain.\n";
            return;
        }
        Event* ev = cariEventID(id);
        if (ev != nullptr) {
            ev->terjual += jml;
            cout << "[System] Undo sukses. Status tiket dikembalikan.\n";
            simpanKeFile();
        }
    } else {
        cout << "[!] Tidak ada riwayat pembatalan untuk di-undo.\n";
    }
}

void menuAdmin() {
    int pil;
    do {
        cout << "\n=== MENU ADMIN ===\n";
        cout << "1. Tambah Event Baru\n";
        cout << "2. Lihat Semua Event\n";
        cout << "3. Sorting Data Event\n";
        cout << "4. Lihat BST Urutan ID\n";
        cout << "5. Hubungkan Relasi Event (Graph)\n";
        cout << "6. Cetak Relasi Graph\n";
        cout << "7. Logout\n";
        cout << "Pilihan: "; cin >> pil; 
        cin.ignore(1000, '\n');

        switch(pil) {
            case 1: TambahEvent(); break;
            case 2: tampilkanSemuaEvent(); break;
            case 3: 
                cout << "Kriteria (1: ID, 2: Kuota, 3: Terjual): "; int t; cin >> t;
                cin.ignore(1000, '\n');
                urutkanEventBubble(t); tampilkanSemuaEvent(); break;
            case 4: tampilkanBST(); break;
            case 5: 
                int id1, id2; cout << "ID Event 1: "; cin >> id1; cout << "ID Event 2: "; cin >> id2;
                cin.ignore(1000, '\n');
                hubungkanEdgeGraph(id1, id2); break;
            case 6: tampilkanGraph(); break;
        }
    } while (pil != 7);
}

void menuUser() {
    int pil;
    do {
        cout << "\n=== DASHBOARD USER: " << currentUser << " ===\n";
        cout << "1. Lihat Jadwal Event\n";
        cout << "2. Cari Judul Event\n";
        cout << "3. Pesan Tiket\n";
        cout << "4. Cek Antrian Booking\n";
        cout << "5. Batalkan Tiket (Refund)\n";
        cout << "6. Undo Pembatalan Terakhir\n";
        cout << "7. Lihat Log Riwayat Refund\n";
        cout << "8. Logout\n";
        cout << "Pilihan: "; cin >> pil; 
        cin.ignore(1000, '\n');

        switch(pil) {
            case 1: tampilkanSemuaEvent(); break;
            case 2: cariEventLinear(); break;
            case 3: PesanTiket(); break;
            case 4: tampilkanAntrian(); break;
            case 5: BatalkanTiket(); break;
            case 6: UndoBatal(); break;
            case 7: tampilkanRiwayatBatal(); break;
            case 8: isLoggedIn = false; cout << "[System] Logout sukses.\n"; break;
        }
    } while (isLoggedIn);
}

void menuLoginUser() {
    int pil;
    string u, p;
    do {
        cout << "\n=== MENU MEMBER ===\n";
        cout << "1. Registrasi Akun\n";
        cout << "2. Login Member\n";
        cout << "3. Kembali\n";
        cout << "Pilihan: "; cin >> pil; 
        cin.ignore(1000, '\n');

        if (pil == 1) {
            cout << "Username baru: "; getline(cin, u);
            cout << "Password baru: "; getline(cin, p);
            if(registerUser(u, p, ++userCounter)) {
                simpanKeFile();
            }
        } else if (pil == 2) {
            cout << "Username: "; getline(cin, u);
            cout << "Password: "; getline(cin, p);
            if (cekLoginUser(u, p)) {
                currentUser = u;
                isLoggedIn = true;
                menuUser();
            } else {
                cout << "[!] Login gagal. Username atau password salah.\n";
            }
        }
    } while (pil != 3 && !isLoggedIn);
}

// Main Program 
int main() {
    muatDariFile();
    int role;
    string admU, admP;

    do {
        cout << "\n====================================\n";
        cout << "  SISTEM MANAJEMEN EVENT & TIKET\n";
        cout << "====================================\n";
        cout << "1. Login Admin\n";
        cout << "2. Menu User / Member\n";
        cout << "3. Exit Program\n";
        cout << "Pilihan: "; cin >> role; 
        cin.ignore(1000, '\n'); 

        if (role == 1) {
            cout << "Username Admin: "; getline(cin, admU);
            cout << "Password Admin: "; getline(cin, admP);
            if (admU == "admin" && admP == "admin123") {
                menuAdmin();
            } else {
                cout << "[!] Kredensial admin salah.\n";
            }
        } else if (role == 2) {
            menuLoginUser();
        }
    } while (role != 3);

    cout << "\nProgram selesai. Data aman tersimpan.\n";
    return 0;
}