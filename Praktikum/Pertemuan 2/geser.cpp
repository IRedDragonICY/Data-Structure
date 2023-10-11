#include <iostream>
#define maks 5 
class Array1D{
    friend std::ostream& operator<<(std::ostream&,const Array1D&);
    friend std::istream& operator>>(std::istream&,Array1D&);
public:
    Array1D();
    void cetak();
    void geser_kiri();
    void geser_kanan();
private:
    char A[maks];
};
Array1D::Array1D(){
    for(int i=0;i<maks;i++)
        A[i]='0';
}
std::ostream& operator<<(std::ostream& out,const Array1D& x){
    for(int i=0;i<maks;i++)
        out << x.A[i] << " ";
    out << std::endl;
    return out;
}
std::istream& operator>>(std::istream& in,Array1D& x)
{ 
   int posisi; 
   std::cout<<"Mengisi array pada posisi ke : ";
   in >> posisi;
   if (posisi>=0 && posisi<maks){
       in>>x.A[posisi];
   }
   else
       std::cout <<"Anda memasukkan posisi di luar range ....";
       
   return in;
}
void Array1D::geser_kanan()
{
    int n = maks - 1;
    int temp = A[n];
    
     for (int i=n-1; i >= 0; --i)
        A[i+1] = A[i];
        
     A[0]=temp;   
}
void Array1D::geser_kiri()
{
     int n = maks;
     char temp = A[0];

     for (int i=0; i<n-1;++i)
         A[i]=A[i+1];

      A[n-1]=temp;   
}

int main(){
    Array1D x;
    std::cout<<"Array masih kosong : "<<x;
    std::cin>>x;
    std::cout<<"Isi Array saat ini : "<<x;
    x.geser_kiri();
    std::cout<<"Isi Array setelah digeser kiri : "<<x;
    x.geser_kanan();
    std::cout<<"Isi Array setelah digeser kanan : "<<x;
    return 0;
}
