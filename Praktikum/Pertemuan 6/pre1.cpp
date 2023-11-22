#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    // Membuat tumpukan asli
    stack<char> tumpukan;
    tumpukan.push('a');
    tumpukan.push('b');
    tumpukan.push('c');
    tumpukan.push('d');
    tumpukan.push('e');
    tumpukan.push('f');
    

    // Membuat dua vector untuk menampung elemen tumpukan
    vector<char> stack1, stack2;

    // Ukuran tumpukan asli
    int n = tumpukan.size();

    // Memindahkan setengah elemen ke stack1
    for(int i = 0; i < n/2; ++i) {
        cout<< "(Sebelum) Isi stack1: ";
        for (char c : stack1){
            cout << c << "|";
        }
        cout << endl;
        stack1.push_back(tumpukan.top());
        tumpukan.pop();
        cout<< "(Sesudah) Isi stack1: ";
        for (char c : stack1){
            cout << c << "|";
        }
        cout << endl;
    }

    // Memindahkan sisa elemen ke stack2
    while(!tumpukan.empty()) {
        cout<< "(Sebelum) Isi stack2: ";
        for (char c : stack2){
            cout << c << "|";
        }
        cout << endl;
        stack2.push_back(tumpukan.top());
        tumpukan.pop();
        cout<< "(Sesudah) Isi stack2: ";
        for (char c : stack2){
            cout << c << "|";
        }
        cout << endl;
    }

    // Menampilkan elemen-elemen di stack1
    cout << "Stack1: ";
    for(char c : stack1) cout << c << " ";
    cout << endl;

    // Menampilkan elemen-elemen di stack2
    cout << "Stack2: ";
    for(char c : stack2) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
