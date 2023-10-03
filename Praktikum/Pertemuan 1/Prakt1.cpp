#include <iostream>
using namespace std;
class Bilangan{
    friend ostream& operator<<(ostream&, const Bilangan&);
    friend istream& operator>>(istream&, Bilangan&);
    public:
        Bilangan(int a0 = 0, float b0 = 0.0) : a(a0), b(b0) {}
        void banding_int(const Bilangan&, const Bilangan&);
        Bilangan& operator = (const Bilangan&);
        Bilangan operator + (const Bilangan&) const;
        Bilangan operator-()const;
    private:
        int a;
        float b;
};

ostream& operator << (ostream& out, const Bilangan& x){
    out << "Bagian integer : " << x.a << endl;
    out << "Bagian float : " << x.b << endl;
    return out;
}

void Bilangan::banding_int(const Bilangan& x, const Bilangan& y){
    if(x.a > y.a)
        cout << x.a << "::x lebih besar dari " << y.a << endl;
    else
        cout << y.a << "::x lebih besar dari " << x.a << endl;
}

Bilangan& Bilangan::operator = (const Bilangan& x){
    a = x.a;
    b = x.b;
    return *this;
}

istream& operator>>(istream& in, Bilangan&x){
    cout << "Masukkan bagian integer : ";
    in >> x.a;
    cout << "Masukkan bagian float : ";
    in >> x.b;
    return in;
}

Bilangan Bilangan::operator + (const Bilangan& x) const{
    Bilangan temp;
    temp.a = a + x.a;
    temp.b = b + x.b;
    return temp;
}

Bilangan Bilangan::operator - () const{
    Bilangan temp;
    temp.a = -a;
    temp.b = -b;
    return temp;
}

int main(){
    Bilangan s, t(-2, 3.14), d;
    cout << "Nilai awal s " << endl << s << endl;
    cout << "Nilai awal t dari deklarasi " << endl << t;
    s = t;
    cout << "Nilai s setelah diisi t " << endl << s << endl;
    cout << "Masukkan nilai-nilai objek d : " << endl;
    cin >> d;
    cout << "Setelah d + t => " << endl << d+t << endl;
    cout << "Setelah d dinegatifkan => " << endl << -d << endl;
}