#include <iostream>
#define maks 5
using namespace std;

class Stack {
    friend ostream& operator<<(ostream&, const Stack&);
public:
    Stack();
    int penuh(int);
    int kosong(int);
    void cetak();
    void push(char);
    char pop();
private:
    char A[maks];
    int banyak;
};

ostream& operator<<(ostream& out, const Stack& s) {
    out << "\nIsi stack: ";
    for (int i = 0; i < s.banyak; i++)
        out << s.A[i] << " ";
    return out;
}

Stack::Stack() {
    banyak = 0;
    for (int i = 0; i < maks; i++)
        A[i] = '0';
}

int Stack::penuh(int s) {
    return s == maks ? 1 : 0;
}

int Stack::kosong(int s) {
    return s == 0 ? 1 : 0;
}

void Stack::cetak() {
    cout << "\nIsi stack: ";
    for (int i = 0; i < banyak; i++)
        cout << A[i] << " ";
}

void Stack::push(char x) {
    cout << "\nElemen masuk: " << x;
    if (penuh(banyak))
        cout << " Stack penuh";
    else if (A[0] == '0') {
        A[0] = x;
        banyak++;
    } else {
        for (int i = banyak; i >= 0; i--)
            A[i + 1] = A[i];
        A[0] = x;
        banyak++;
    }
}

char Stack::pop() {
    cout << "\nPop stack, elemen yang di-pop: " << A[0];
    char temp = A[0];
    for (int i = 0; i < banyak; i++)
        A[i] = A[i + 1];
    A[banyak] = '0';
    banyak--;
    return temp;
}

int main() {
    Stack stack;
    for (char c = 'a'; c < 'd'; c++) {
        stack.push(c);
        stack.cetak();
    }
    char p = stack.pop();
    stack.cetak();
    cout << "\nCetak pakai overloading: " << stack;
}