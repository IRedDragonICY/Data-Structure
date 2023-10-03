#include <iostream>
using namespace std;
float Pangkat(float x, int n){
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n % 2 == 1){
        cout << "Masuk bagian ganjil" << endl;
        return Pangkat(x, n-1) * x;
    }
    if (n % 2 == 0){
        cout << "Masuk bagian genap" << endl;
        return Pangkat(x*x, n/2);
    }
}

int main(){
    cout << Pangkat(2, 5) << endl;
    return 0;
}