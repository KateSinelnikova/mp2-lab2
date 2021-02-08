#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

template <class T>
class Vector
{
public:
    int length;
    int capacity;
    T* x;
public:
    Vector<T>* vec;
    Vector();
    Vector(T _v);
    Vector(int rowsCount, T* _v);
    Vector(int rowsCount, T _v);
    Vector(const Vector<T>& _v);
    virtual ~Vector();

    void push_back(const T& elem);
    void reserve(unsigned int capacity);

    Vector<T> operator +(const Vector<T>& _v);
    Vector<T> operator -(Vector<T>& _v);
    Vector<T> operator *(Vector<T>& _v);
    Vector<T> operator /(Vector<T>& _v);
    Vector<T>& operator =(const Vector<T>& _v);
    T& operator[] (const int index);

    Vector<T>& operator ++();
    Vector<T>& operator --();
    Vector<T>& operator +=(Vector<T>& _v);
    Vector<T>& operator -=(Vector<T>& _v);

    bool operator ==(const Vector<T>& _v) const;
    bool operator !=(const Vector<T>& _v) const;

    template <class T1>
    friend ostream& operator<< (ostream& ostr, const Vector<T1> &A);
    template <class T1>
    friend istream& operator >> (istream& istr, Vector<T1> &A);

    int Length();
};

template <class T1>
ostream& operator<< (ostream& ostr, const Vector<T1> &A) {
    for (int i = 0; i < A.length; i++)
        ostr << A.x[i] << " ";
    return ostr;
}

template <class T1>
istream& operator >> (istream& istr, Vector<T1> &A) {
    for (int i = 0; i < A.length; i++)
        istr >> A.x[i];
    return istr;
}

#define MIN(a,b)(a>b?b:a)
#define MAX(a,b)(a>b?a:b)

template <class T>
Vector<T>::Vector()
{
    length = 0;
    x = 0;
    capacity = 0;
}
template <class T>
Vector<T>::Vector(T _v)
{
    length = 1;
    capacity = 1;
    x = new T [length];
    x[0] = _v;
}
template <class T>
Vector<T>::Vector(int rowsCount, T* _v)
{
    length = rowsCount;
    capacity = rowsCount;

    x = new T [length];
    for (int i = 0; i < length; i++)
        x[i] = _v[i];
}
template <class T>
Vector<T>::Vector(int rowsCount, T _v)
{
    length = rowsCount;
    capacity = rowsCount;
    x = new T [length];
    for (int i = 0; i < length; i++)
        x[i] = _v;
}
template <class T>
Vector<T>::Vector(const Vector<T>& _v)
{
    length = _v.length;
    capacity = _v.capacity;
    x = new T [length];
    for (int i = 0; i < length;i = i + 1)
        x[i] = _v.x[i];
}
template <class T>
Vector<T>::~Vector()
{
    length = 0;
    if (x != 0)
        delete [] x;
    x = 0;
}
template <class T>
Vector<T> Vector<T>::operator +(const Vector<T>& _v)
{
    Vector<T> res;
    res.length = MIN(length, _v.length);
    res.capacity = res.length;
    res.x = new T [res.length];
    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] + _v.x[i];
    }
    return res;
}
template <class T>
Vector<T> Vector<T>::operator -(Vector<T>& _v)
{
    Vector<T> res;
    res.length = MIN(length, _v.length);
    res.capacity = res.length;
    res.x = new T [res.length];
    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] - _v.x[i];
    }
    return res;
}
template <class T>
Vector<T> Vector<T>::operator *(Vector<T>& _v)
{
    Vector<T> res;
    res.length = MIN(length, _v.length);
    res.capacity = res.length;
    res.x = new T [res.length];
    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] * _v.x[i];
    }
    return res;
}
template <class T>
Vector<T> Vector<T>::operator /(Vector<T>& _v)

{
    Vector<T> res;
    res.length = MIN(length, _v.length);
    res.capacity = res.length;
    res.x = new T [res.length];
    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] / _v.x[i];
    }
    return res;
}
template <class T>
Vector<T>& Vector<T>::operator =(const Vector<T>& _v)
{
    if (this == &_v)
        return *this;

    length = _v.length;
    capacity = _v.length;
    x = new T [length];
    for (int i = 0; i < length; i++)
        x[i] = _v.x[i];
    return *this;
}
template <class T>
T& Vector<T>::operator[] (const int index)
{
    if ((index >= 0) && (index < length))
        return x[index];
    return x[0];
}

template <class T>
Vector<T>& Vector<T>::operator ++()
{
    for (int i = 0; i < length; i++)
        x[i]++;
    return *this;
}
template <class T>
Vector<T>& Vector<T>::operator --()
{
    for (int i = 0; i < length; i++)
        x[i]--;
    return *this;
}
template <class T>
Vector<T>& Vector<T>::operator +=(Vector<T>& _v)
{
    length = MIN(length, _v.length);
    for (int i = 0; i < length; i++)
    {
        x[i] += _v.x[i];
    }
    return *this;
}
template <class T>
Vector<T>& Vector<T>::operator -=(Vector<T>& _v)
{
    length = MIN(length, _v.length);
    for (int i = 0; i < length; i++)
    {
        x[i] -= _v.x[i];
    }
    return *this;
}
template <class T>
int Vector<T>::Length()
{
    return length;
}

template<class T>
bool Vector<T>::operator==(const Vector<T> &_v) const {
    if(this->length != _v.length)
        return false;
    for (int i = 0; i < this->length; i++)
        if (this->x[i] != _v.x[i])
            return false;
    return true;
}

template<class T>
bool Vector<T>::operator!=(const Vector<T> &_v) const {
    return !(*this == _v);
}

template<class T>
void Vector<T>::push_back(const T &elem) {
    if(this->length >= this->capacity)
        this->reserve(this->capacity + 1);
    this->x[this->length] = elem;
    this->length++;
}

template<class T>
void Vector<T>::reserve(unsigned int capacity) {
    if(this->x == 0){
        this->length = 0;
        this->capacity = 0;
    }
    T* buffer = new T[capacity];
    for (int i = 0; i < capacity; ++i) {
        buffer[i] = this->x[i];
    }
    this->capacity = capacity;
    if(this->x != 0)
        delete[] this->x;
    this->x = buffer;
}

#endif