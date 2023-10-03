#include <iostream>
using namespace std;
void cari(int x, int n){
    static int i ;
    if (n == 0)
        cout << "Bilangan tidak ditemukan" << endl;
    if (x == n)
        cout << "Bilangan ditemukan setelah perulangan ke-" << i << endl;
    else{
        i++;
        cari(x, n-1);
    }
}

int main(){
    cari(14, 9);
    system("pause");
    return 0;
}