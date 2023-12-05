#include <iostream> 
#define maks 5 
using namespace std;

class Queue { 
    friend ostream& operator<<(ostream&, const Queue&); 
public : 
    Queue(); 
    int penuh(int); 
    int kosong(int); 
    void cetak(); 
    void enqueue(char); 
    char dequeue(); 
private : 
    char A[maks];
    int banyak;
};   

ostream& operator<<(ostream& out, const Queue& s){ 
    cout << "\nIsi Queue : "; 
    for (int i = 0; i < s.banyak; i++) 
        out << s.A[i] << " ";
    return out; 
}

Queue::Queue() { 
    banyak = 0; 
    for (int i = 0; i < maks; i++) 
        A[i] = '0'; 
} 

int Queue::penuh(int s){ 
    return s == maks ? 1 : 0; 
}
 
int Queue::kosong(int s){ 
    return s == 0 ? 1 : 0; 
} 

void Queue::cetak(){
    cout << "\nIsi Queue : "; 
    for (int i = 0; i < banyak; i++) 
        cout << A[i] << " "; 
} 

void Queue::enqueue(char x){  
    cout << "\nElemen : " << x << " masuk antrian"; 
    if (penuh(banyak)) 
        cout << "queue penuh"; 
    else if (A[0]=='0') { 
        A[0] = x; 
        banyak++; 
    } 
    else { 
        for (int i = banyak; i >= 0; i--)  
            A[i+1] = A[i]; 
        A[0] = x;
        banyak++;  
    } 
} 

char Queue::dequeue() { 
    char temp = A[--banyak]; 
    cout << "\nDequeue elemen --> " << temp; 
        A[banyak] = '0';
    return temp;
}

int main() { 
    Queue q; 
    for (char c = 'a'; c < 'd'; c++) { 
        q.enqueue(c); 
        cout << q;
    } 
    char p = q.dequeue(); 
    q.cetak(); 
    cout << "\n\nCetak pakai overloading : " << q; 
    return 0; 
}