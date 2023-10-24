#include <iostream>
using namespace std;
template<class T>
class Array1D{
    template<class U>
    friend ostream& operator<<(ostream&, const Array1D<U>&);
    public:
        Array1D(int size = 0);
        Array1D(const Array1D<T>& v);
        ~Array1D(){
            delete[] element;
        }
        T& operator[](int i) const;
        int Size(){
            return size;
        }
        Array1D<T>& operator=(const Array1D<T>& v);
        Array1D<T> operator+()const;
        Array1D<T> operator+(const Array1D<T>& v) const;
        Array1D<T> operator-()const;
        Array1D<T> operator-(const Array1D<T>& v) const;
        Array1D<T> operator*(const Array1D<T>& v) const;
        Array1D<T>& operator+=(const T& x);
        Array1D<T>& ReSize(int sc);
        int size;
    private:
        
        T* element;
};

template<class T>
Array1D<T>::Array1D(int sz){
    if (sz < 0) throw std::invalid_argument("Invalid size for array initialization");
    size = sz;
    element = new T[sz];
}

template<class T>
Array1D<T>::Array1D(const Array1D<T>& v){
    size = v.size;
    element = new T[size];
    for (int i = 0; i < size; i++){
        element[i] = v.element[i];
    }
    
}

template<class T>
T& Array1D<T>::operator[](int i ) const{
    if (i < 0 || i >= size) throw std::out_of_range("Array index out of bounds");
    return element[i];
}

template<class T>
Array1D<T>& Array1D<T>::operator=(const Array1D<T>&v){
    if (this != &v){
        delete [] element;
        size = v.size;
        element=new T [size];
        for (int i = 0 ; i < size; i++ ){
            element[i]=v.element[i];
        }
    }
    return *this;
}

template<class T>
Array1D<T> Array1D<T>::operator+(const Array1D<T>& v) const {
    if(size != v.size) throw std::length_error("Size mismatch between arrays");
    Array1D<T> w(size);
    for (int i = 0; i < size; i++){
        w.element[i] = element[i] + v.element[i];
    }
    return w;
}

template<class T>
Array1D<T> Array1D<T>::operator-(const Array1D<T>& v) const{
    if(size != v.size) throw std::length_error("Size mismatch between arrays");
    Array1D<T> w(size);
    for (int i = 0; i < size; i++){
        w.element[i] = element[i] - v.element[i];
    }
    return w;
} 

template<class T>
Array1D<T> Array1D<T>::operator-()const{
    Array1D<T>w(size);
    for ( int i = 0; i < size; i++){
        w.element[i]=-element[i];
    }
    return w;
}

template<class T>
Array1D<T> Array1D<T>::operator*(const Array1D<T>& v) const{
    if(size != v.size) throw std::length_error("Size mismatch between arrays");
    Array1D<T> w(size);
    for (int i = 0; i < size; i++){
        w.element[i] = element[i] * v.element[i];
    }
    return w;
}

template<class T>
Array1D<T>& Array1D<T>::operator+=(const T& x){
    for (int i = 0; i < size; i++){
        element[i]+=x;
    }
    return *this;
}

template<class T>
ostream& operator<<(ostream& out, const Array1D<T>& x){
    for (int i = 0; i < x.size; i++){
        out << x[i] << " ";
    }
    return out;
}

template<class T>
Array1D<T>& Array1D<T>::ReSize(int sz){
    if (sz < 0) throw std::invalid_argument("Invalid size for array initialization");
    delete[] element;
    size = sz;
    element = new T[size]();
    return *this;
}