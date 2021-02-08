#ifndef MATRIXLIB_TMATRIX_H
#define MATRIXLIB_TMATRIX_H

#include "MyVector.h"

template<class T>
class TMatrix : public Vector<Vector<T>> {
public:
    TMatrix(int size = 0);

    TMatrix(const TMatrix<T> &matrix);

    TMatrix(const Vector<Vector<T>> &vector);

    ~TMatrix();

    T &operator()(int row, int col) const;

    TMatrix<T> &operator=(const TMatrix<T> &matrix);

    TMatrix<T> operator+(const TMatrix<T> &matrix);

    bool operator==(const TMatrix<T> &matrix) const;
    bool operator!=(const TMatrix<T> &matrix) const;

    template<class T1>
    friend istream &operator>>(istream &istr, const TMatrix &matrix);

    template<class T1>
    friend ostream &operator<<(ostream &ostr, const TMatrix &matrix);
};

template<class T>
TMatrix<T>::TMatrix(int size) : Vector<Vector<T>>(size, Vector<T>()) {
    for (int i = 0; i < size; ++i) {
        this->x[i] = Vector<T>(size - i, 0);
    }
}

template<class T>
TMatrix<T>::TMatrix(const Vector<Vector<T>> &vector):Vector<Vector<T>>(vector) {}

template<class T>
TMatrix<T>::~TMatrix() = default;

template<class T>
TMatrix<T>::TMatrix(const TMatrix<T> &matrix): Vector<Vector<T>>(matrix) {}

template<class T>
TMatrix<T> &TMatrix<T>::operator=(const TMatrix<T> &matrix) {
    if (this != &matrix) {
        if (this->length != matrix.length) {
            delete[] this->x;
            this->length = matrix.length;
            this->x = new Vector<T>[matrix.length];
            for (int i = 0; i < matrix.length; ++i) {
                this->x[i] = matrix.x[i];
            }
        }
        for (int i = 0; i < this->length; ++i) {
            this->x[i] = matrix.x[i];
        }
    }
    return *this;
}

template<class T>
T &TMatrix<T>::operator()(int row, int col) const {
    if(row<0 || row>=this->length)
        throw -1;
    if(col<0 || col>=this->length)
        throw -1;
    return this->x[row][col - row];
}

template<class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &matrix) {
    return Vector<Vector<T>>::operator+(matrix);
}

template<class T1>
istream &operator>>(istream &istr, const TMatrix<T1> &matrix) {
    for (int i = 0; i < matrix.length; ++i) {
        istr >> matrix.x[i];
    }
    return istr;
}

template<class T1>
ostream &operator<<(ostream &ostr, const TMatrix<T1> &matrix) {
    for (int i = 0; i < matrix.length; ++i) {
        ostr << matrix.x[i];
        ostr << "\n";
    }
    return ostr;
}

template<class T>
bool TMatrix<T>::operator==(const TMatrix<T> &matrix) const {
    if (this->length != matrix.length)
        return false;
    for (int i = 0; i < this->length; i++)
        if (this->x[i] != matrix.x[i])
            return false;
    return true;
}

template<class T>
bool TMatrix<T>::operator!=(const TMatrix<T> &matrix) const {
    return !(*this == matrix);
}


#endif
