#ifndef MATRIXLIB_SMATRIX_H
#define MATRIXLIB_SMATRIX_H

#include "MyVector.h"

template<class T>
class SMatrix : public Vector<Vector<T>> {
protected:
    int lowerBandwidth = 0;
    int upperBandwidth = 0;
public:
    SMatrix(int size = 0, int lowerBandwidth = 0, int upperBandwidth = 0);
    SMatrix(const SMatrix<T> &matrix);
    SMatrix(const Vector<Vector<T>> &vector);

    ~SMatrix();

    T &operator()(int row, int col) const;
    SMatrix<T> &operator=(const SMatrix<T> &matrix);
    SMatrix<T> operator+(const SMatrix<T> &matrix);
    bool operator==(const SMatrix<T> &matrix) const;
    bool operator!=(const SMatrix<T> &matrix) const;

    template<class T1>
    friend istream &operator>>(istream &istr, const SMatrix &matrix);

    template<class T1>
    friend ostream &operator<<(ostream &ostr, const SMatrix &matrix);
};

template<class T>
SMatrix<T>::SMatrix(int size, int lowerBandwidth, int upperBandwidth) : Vector<Vector<T>>(size, Vector<T>()) {
    int maxBandwidth = size - 1;
    if(lowerBandwidth > maxBandwidth || upperBandwidth > maxBandwidth)
        throw -1;
    this->lowerBandwidth = lowerBandwidth;
    this->upperBandwidth = upperBandwidth;

    int upper_span = upperBandwidth;
    int lower_span = 0;
    int span = lower_span + upper_span + 1;
    this->x[0] = Vector<T>(span, 0);

    for (int i = 1; i < size; ++i) {
        if(lower_span < lowerBandwidth)
            lower_span++;
        if(upper_span > (size-1)-i)
            upper_span--;
        span = lower_span + upper_span + 1;
        this->x[i] = Vector<T>(span, 0);
    }
}

template<class T>
SMatrix<T>::SMatrix(const Vector<Vector<T>> &vector):Vector<Vector<T>>(vector) {
    if(vector.length>=3){
        this->upperBandwidth = vector.x[0].length-1;
        this->upperBandwidth = vector.x[vector.length-1].length-1;
    }
}

template<class T>
SMatrix<T>::~SMatrix() = default;

template<class T>
SMatrix<T>::SMatrix(const SMatrix<T> &matrix): Vector<Vector<T>>(matrix) {
    if(matrix.length>=3){
        this->upperBandwidth = matrix.x[0].length-1;
        this->upperBandwidth = matrix.x[matrix.length-1].length-1;
    }
}

template<class T>
SMatrix<T> &SMatrix<T>::operator=(const SMatrix<T> &matrix) {
    if (this != &matrix) {
        if (this->length != matrix.length) {
            delete[] this->x;
            SMatrix<T>(matrix.length, matrix.lowerBandwidth, matrix.upperBandwidth);
        }
        for (int i = 0; i < this->length; ++i) {
            this->x[i] = matrix.x[i];
        }
    }
    return *this;
}

template<class T>
T &SMatrix<T>::operator()(int row, int col) const {
    if(row<0 || row>=this->length)
        throw -1;
    if(col<0 || col>=this->length)
        throw -1;

    int upper_shift = (this->length-1)-row-this->upperBandwidth;
    if(col+upper_shift >= this->length)
        throw -1;

    int lower_shift = row - this->lowerBandwidth;
    if(lower_shift > 0)
        col -= lower_shift;

    if(col < 0)  throw -1;

    return this->x[row][col];
}

template<class T>
SMatrix<T> SMatrix<T>::operator+(const SMatrix<T> &matrix) {
    return Vector<Vector<T>>::operator+(matrix);
}

template<class T>
bool SMatrix<T>::operator==(const SMatrix<T> &matrix) const {
    if (this->length != matrix.length) return false;
    for (int i = 0; i < this->length; i++)
        if (this->x[i] != matrix.x[i]) return false;
    return true;
}

template<class T>
bool SMatrix<T>::operator!=(const SMatrix<T> &matrix) const {
    return !(*this == matrix);
}


template<class T1>
istream &operator>>(istream &istr, const SMatrix<T1> &matrix) {
    for (int i = 0; i < matrix.length; ++i)
        istr >> matrix.x[i];
    return istr;
}

template<class T1>
ostream &operator<<(ostream &ostr, const SMatrix<T1> &matrix) {
    for (int i = 0; i < matrix.length; ++i) {
        ostr << matrix.x[i];
        ostr << "\n";
    }
    return ostr;
}

#endif
