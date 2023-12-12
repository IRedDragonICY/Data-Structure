#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int MAX_QUEUE_SIZE = 10;

struct Kerusakan {
    string jenis;
    double harga;

    Kerusakan() : jenis(""), harga(0.0) {}
};

class PengembalianMobil {
public:
    PengembalianMobil() : nomorReservasi(0), tanggalPengembalian(""), waktuPengembalian(""), lokasiPengembalian(""),
        kilometerAwal(0), kilometerAkhir(0), bahanBakar(0.0), kondisiMobil(""), totalHargaSewa(0.0), totalHargaKerusakan(0.0), identifikasiPelanggan("") {}

    PengembalianMobil(int nomorReservasi, string tanggalPengembalian, string waktuPengembalian, string lokasiPengembalian,
        int kilometerAwal, int kilometerAkhir, double bahanBakar, string kondisiMobil,
        double totalHargaSewa, double totalHargaKerusakan, string identifikasiPelanggan);
    int getNomorReservasi() {
        return nomorReservasi;
    }
    void tampilkanInfoPengembalian();
    double jumlahKilometer();
    double hitungDenda();
    void tambahKerusakan(string jenis, double harga);

private:
    int nomorReservasi;
    string tanggalPengembalian;
    string waktuPengembalian;
    string lokasiPengembalian;
    int kilometerAwal;
    int kilometerAkhir;
    double bahanBakar;
    string kondisiMobil;
    double totalHargaSewa;
    double totalHargaKerusakan;
    string identifikasiPelanggan;
    vector<Kerusakan> kerusakan;
};

PengembalianMobil::PengembalianMobil(int nomorReservasi, string tanggalPengembalian, string waktuPengembalian, string lokasiPengembalian,
    int kilometerAwal, int kilometerAkhir, double bahanBakar, string kondisiMobil,
    double totalHargaSewa, double totalHargaKerusakan, string identifikasiPelanggan)
    : nomorReservasi(nomorReservasi), tanggalPengembalian(tanggalPengembalian), waktuPengembalian(waktuPengembalian),
      lokasiPengembalian(lokasiPengembalian), kilometerAwal(kilometerAwal), kilometerAkhir(kilometerAkhir),
      bahanBakar(bahanBakar), kondisiMobil(kondisiMobil), totalHargaSewa(totalHargaSewa), totalHargaKerusakan(totalHargaKerusakan), identifikasiPelanggan(identifikasiPelanggan) {}

void PengembalianMobil::tampilkanInfoPengembalian() {
    cout << "Nomor Reservasi: " << nomorReservasi << endl;
    cout << "Tanggal Pengembalian: " << tanggalPengembalian << endl;
    cout << "Waktu Pengembalian: " << waktuPengembalian << endl;
    cout << "Lokasi Pengembalian: " << lokasiPengembalian << endl;
    cout << "Kilometer Awal: " << kilometerAwal << " km" << endl;
    cout << "Kilometer Akhir: " << kilometerAkhir << " km" << endl;
    cout << "Jumlah Kilometer: " << jumlahKilometer() << " km" << endl;
    cout << "Bahan Bakar: " << bahanBakar << " liter" << endl;
    cout << "Total Harga Sewa: Rp " << fixed << setprecision(2) << totalHargaSewa << endl;
    cout << "Kondisi Mobil: " << kondisiMobil << endl;

    if (kondisiMobil != "baik") {
        cout << "Kerusakan:" << endl;
        for (int i = 0; i < kerusakan.size(); i++) {
            cout << "  Jenis Kerusakan " << i + 1 << ": " << kerusakan[i].jenis << endl;
            cout << "  Harga Kerusakan " << i + 1 << ": Rp " << fixed << setprecision(2) << kerusakan[i].harga << endl;
        }

        cout << "Total Harga Kerusakan: Rp " << fixed << setprecision(2) << totalHargaKerusakan << endl;
    }

    cout << "Biaya Total: Rp " << fixed << setprecision(2) << totalHargaSewa + totalHargaKerusakan + hitungDenda() << endl;
    cout << "Denda: Rp " << fixed << setprecision(2) << hitungDenda() << endl;
}

double PengembalianMobil::jumlahKilometer() {
    return kilometerAkhir - kilometerAwal;
}

double PengembalianMobil::hitungDenda() {
    double denda = 0.0;

    if (tanggalPengembalian != waktuPengembalian) {
        denda = 0.05 * (totalHargaKerusakan + bahanBakar);

        if (kondisiMobil != "baik") {
            for (int i = 0; i < kerusakan.size(); i++) {
                denda += kerusakan[i].harga;
            }
        }
    }
    return denda;
}

void PengembalianMobil::tambahKerusakan(string jenis, double harga) {
    Kerusakan kerusakannya;
    kerusakannya.jenis = jenis;
    kerusakannya.harga = harga;
    kerusakan.push_back(kerusakannya);
}

struct Node {
    PengembalianMobil mobil;
    Node* next;
    Node* prev;
    int prioritas;

    Node(PengembalianMobil mobil, int prioritas) : mobil(mobil), prioritas(prioritas), next(NULL), prev(NULL) {}
    Node() : mobil(), prioritas(0), next(NULL), prev(NULL) {}
    // Node jika pake tree
    Node* left;
    Node* right;
    Node* parent;
    int height;
    Node(PengembalianMobil mobil) : mobil(mobil), next(NULL), prev(NULL), left(NULL), right(NULL), parent(NULL), height(0) {}
};


class BST {
private:
    Node* root;
    
public:
    BST() : root(NULL) {}

    Node* getRoot() {
        return this->root;
    }

    Node* createNode(PengembalianMobil mobil) {
        Node* newNode = new Node(mobil);
        return newNode;
    }

    Node* insertNode(Node* node, PengembalianMobil mobil) {
        if (node == NULL) {
            cout << "Data berhasil ditambahkan ke dalam tree." << endl;
            node = createNode(mobil);
        } else if (mobil.getNomorReservasi() <= node->mobil.getNomorReservasi()) {
            cout << "Data berhasil ditambahkan ke dalam tree bagian kiri." << endl;
            node->left = insertNode(node->left, mobil);
            if (node->left) node->left->parent = node;
        } else if (mobil.getNomorReservasi() > node->mobil.getNomorReservasi()) {
            cout << "Data berhasil ditambahkan ke dalam tree bagian kanan." << endl;
            node->right = insertNode(node->right, mobil);
            if (node->right) node->right->parent = node;
        }
        return node;
    }


    void insert(PengembalianMobil mobil) {
        this->root = insertNode(this->root, mobil);
    }
    void display(Node* node) {
        // menampilkan data dengan inorder
        if (node == NULL) {
            return;
        }
        display(node->left);
        node->mobil.tampilkanInfoPengembalian();
        display(node->right);
    }
};

        
class doublyPriorityQueue {
public:
    Node* head;
    Node* tail;

    doublyPriorityQueue() : head(NULL), tail(NULL) {}
    
    ~doublyPriorityQueue() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void enqueue(PengembalianMobil data, int prioritas){
        Node* newNode = new Node(data, prioritas);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            Node* current = head;
            while (current != NULL && current->prioritas > prioritas) {
                current = current->next;
            }

            if (current == NULL) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else if (current == head) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
    }
    
    void dequeue(){
        if (head == NULL) {
            cout << "Antrian kosong. Tidak ada pengembalian mobil untuk dikeluarkan." << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }

        cout << "Pengembalian mobil berhasil dikeluarkan dari antrian." << endl;
    }
    
    void peek(){
        if (head == NULL) {
            cout << "Antrian kosong." << endl;
            return;
        }

        cout << "Isi Antrian:" << endl;
        cout << "  ";
        head->mobil.tampilkanInfoPengembalian();
    }

    void tampilkanIsi(){
        if (head == NULL) {
            cout << "Antrian kosong." << endl;
            return;
        }

        Node* current = head;
        int index = 1;

        cout << "Isi Antrian:" << endl;
        while (current != NULL) {
            cout << "  " << index << ". ";
            current->mobil.tampilkanInfoPengembalian();
            current = current->next;
            index++;
        }

        cout << "Jumlah data dalam antrian: " << index - 1 << endl;
    }
};




class Stack {
public:
    Stack() : top(NULL), count(0) {}
    ~Stack();

    void push(PengembalianMobil data);
    void pop();
    void tampilkanIsi();

private:
    Node* top;
    int count;
};

Stack::~Stack() {
    while (top != NULL) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::push(PengembalianMobil data) {
    Node* newNode = new Node;
    newNode->mobil = data;
    newNode->next = top;
    top = newNode;
    count++;
}

void Stack::pop() {
    if (top == NULL) {
        cout << "Stack kosong. Tidak dapat melakukan pop." << endl;
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
    count--;
}

void Stack::tampilkanIsi() {
    if (top == NULL) {
        cout << "Stack kosong." << endl;
        return;
    }

    Node* current = top;
    int index = 1;

    cout << "Isi Stack:" << endl;
    while (current != NULL) {
        cout << "  " << index << ". ";
        current->mobil.tampilkanInfoPengembalian();
        current = current->next;
        index++;
    }

    cout << "Jumlah data dalam stack: " << count << endl;
}

class Queue {
public:
    Queue() : front(-1), rear(-1) {
        data = new PengembalianMobil[MAX_QUEUE_SIZE];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(PengembalianMobil item);
    void dequeue();
    bool isFull();
    bool isEmpty();
    void tampilkanIsi();

private:
    PengembalianMobil* data;
    int front;
    int rear;
};

void Queue::enqueue(PengembalianMobil item) {
    if (isFull()) {
        cout << "Antrian penuh. Pengembalian mobil tidak dapat ditambahkan." << endl;
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_QUEUE_SIZE;
    }

    data[rear] = item;
    cout << "Pengembalian mobil berhasil ditambahkan ke dalam antrian." << endl;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong. Tidak ada pengembalian mobil untuk dikeluarkan." << endl;
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_QUEUE_SIZE;
    }

    cout << "Pengembalian mobil berhasil dikeluarkan dari antrian." << endl;
}

bool Queue::isFull() {
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

bool Queue::isEmpty() {
    return front == -1 && rear == -1;
}

void Queue::tampilkanIsi() {
    if (isEmpty()) {
        cout << "Antrian kosong." << endl;
        return;
    }

    int i = front;
    cout << "Isi Antrian:" << endl;
    while (i != rear) {
        cout << "  ";
        data[i].tampilkanInfoPengembalian();
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    cout << "  ";
    data[rear].tampilkanInfoPengembalian();

    cout << "Jumlah data dalam antrian: " << (rear - front + 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE << endl;
}

int main() {
    Stack stack;
    Queue antrian;
    doublyPriorityQueue antrianPrioritas;
    BST tree;

    int jumlahMobilDipinjam, jumlahMobilDikembalikan;
    double totalHargaSewa;


    cout << "Masukkan Jumlah Mobil yang Dipinjam: ";
    cin >> jumlahMobilDipinjam;

    cout << "Masukkan Jumlah Mobil yang Dikembalikan: ";
    cin >> jumlahMobilDikembalikan;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < jumlahMobilDikembalikan; i++) {
        int nomorReservasi, kilometerAwal, kilometerAkhir;
        double bahanBakar;
        string tanggalPengembalian, waktuPengembalian, lokasiPengembalian, kondisiMobil, identifikasiPelanggan;

        cout << " Data pengembalian mobil ke " << i + 1 << endl;

        cout << "Masukkan Nomor Reservasi: ";
        cin >> nomorReservasi;

        cout << "Masukkan Nomor Identifikasi Pelanggan: ";
        cin.ignore();
        getline(cin, identifikasiPelanggan);

        cout << "Masukkan Tanggal Pengembalian (dd-mm-yyyy): ";
        cin.ignore();
        getline(cin, tanggalPengembalian);

        cout << "Masukkan Waktu Pengembalian (hh:mm): ";
        getline(cin, waktuPengembalian);

        cout << "Masukkan Lokasi Pengembalian: ";
        getline(cin, lokasiPengembalian);

        cout << "Masukkan Kilometer Awal: ";
        cin >> kilometerAwal;

        cout << "Masukkan Kilometer Akhir: ";
        cin >> kilometerAkhir;

        cout << "Masukkan Bahan Bakar(liter): ";
        cin >> bahanBakar;

        cout << "Masukkan Total Harga Sewa Mobil: Rp ";
      cin >> totalHargaSewa;

        cout << "Masukkan Kondisi Mobil (baik/tidak): ";
        cin >> kondisiMobil;

        double totalHargaKerusakan = 0.0;

        if (kondisiMobil != "baik") {
            string jenisKerusakan;
            double hargaKerusakan;

            while (true) {
                cout << "Masukkan Jenis Kerusakan:" << endl;
                cin.ignore();
                getline(cin, jenisKerusakan);

                if (jenisKerusakan.empty()) {
                    break;
                }

                cout << "Harga Kerusakan: Rp ";
                cin >> hargaKerusakan;

                totalHargaKerusakan += hargaKerusakan;

                char tambahLagi;
                cout << "Apakah ada kerusakan lagi? (Y/N): ";
                cin >> tambahLagi;

                if (tambahLagi != 'Y' && tambahLagi != 'y') {
                    break;
                }
            }
        }

        PengembalianMobil mobil(nomorReservasi, tanggalPengembalian, waktuPengembalian, lokasiPengembalian,
            kilometerAwal, kilometerAkhir, bahanBakar, kondisiMobil,
            totalHargaSewa, totalHargaKerusakan, identifikasiPelanggan);

        Node* newNode = new Node;
        newNode->mobil = mobil;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

    

        system("clear");
        cout << "=============================" << endl;
        cout << "Informasi Pengembalian Mobil ke-" << i + 1 << endl;
        cout << "=============================" << endl;
        tail->mobil.tampilkanInfoPengembalian();
    }

    Node* current = head;


    system("clear");
    bool isWithPriority = false;
    int menuPilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push ke Stack\n";
        cout << "2. Pop dari Stack\n";
        cout << "3. Enqueue ke Antrian\n";
        cout << "4. Dequeue dari Antrian\n";
        cout << "5. Enqueue ke Antrian dengan prioritas\n";
        cout << "6. Dequeue dari Antrian dengan prioritas\n";
        cout << "7  Insert Tree\n";
        cout << "8. Lihat Isi Stack\n";
        cout << "9. Lihat Isi Antrian\n";
        cout << "10. Menampilkan isi data dengan BST\n";
        cout << "11. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> menuPilihan;

        switch (menuPilihan) {
          case 1: {
                // Push ke Stack
                if (tail != NULL) {
                    stack.push(tail->mobil);
                    cout << "Data berhasil dipush ke Stack." << endl;
                } else {
                    cout << "Tidak ada data untuk dipush ke Stack." << endl;
                }
                break;
            }
            case 2:
                // Pop dari Stack
                stack.pop();
                cout << "Item teratas dihapus dari Stack." << endl;
                break;

            case 3: {
                // Enqueue ke Antrian
                if (tail != NULL) {
                    antrian.enqueue(tail->mobil);
                    cout << "Data berhasil dienqueue ke Antrian." << endl;
                } else {
                    cout << "Tidak ada data untuk dienqueue ke Antrian." << endl;
                }
                break;
            }
            case 4:
                // Dequeue dari Antrian
                antrian.dequeue();
                break;
            case 5: {
                // Enqueue ke Antrian dengan prioritas
                int prioritas;
                cout<<"Masukkan prioritas: ";cin>>prioritas;
                if (tail != NULL) {
                    antrianPrioritas.enqueue(current->mobil, prioritas);
                    cout << "Data berhasil dienqueue ke Antrian dengan prioritas." << endl;
                } else {
                    cout << "Tidak ada data untuk dienqueue ke Antrian dengan prioritas." << endl;
                }
                current = current->next;
                isWithPriority = true;
                break;
            }
            case 6:
                // Dequeue dari Antrian dengan prioritas
                antrianPrioritas.dequeue();
                break;
            case 7:
                // Insert Tree
                tree.insert(current->mobil);
                current = current->next;
                break;
    
            case 8: 
                stack.tampilkanIsi();
                break;            
            case 9:
                // Lihat Isi Antrian
                if (isWithPriority) {
                    antrianPrioritas.tampilkanIsi();
                }
                else {
                    antrian.tampilkanIsi();
                }
                break;
            case 10:
                // Menampilkan isi data dengan BST
                tree.display(tree.getRoot());
                break;
            case 11:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan masukkan opsi yang benar." << endl;
        }
    } while (menuPilihan != 11);

    return 0;
}
