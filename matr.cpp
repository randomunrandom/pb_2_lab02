//
// Created by danai on 12.04.18.
//

#include <iostream>
#include "matr.h"
#include "vect.h"

matr::matr(int s, double **a) {
    num = matrcount;
    matrcount++;
    size = s;
    m = new double*[size];
    for(int i = 0; i < size; i++) {
        m[i] = new double[size];
        for(int j = 0; j < size; j++) m[i][j] = a[i][j];
    }
    std::cout << "*конструктор matr(int, double[][]) создал вектор №" << num << "*" << std::endl;
}
matr::matr(int s, double *a) {
    num = matrcount;
    matrcount++;
    size = s;
    m = new double*[size];
    for(int i = 0; i < size; i++) {
        m[i] = new double[size];
        for(int j = 0; j < size; j++) m[i][j] = a[i*size + j];
    }
    std::cout << "*конструктор matr(int, double[]) создал вектор №" << num << "*" << std::endl;
}
matr::matr(int s) {
    num = matrcount;
    matrcount++;
    size = s;
    m = new double*[size];
    for(int i = 0; i < size; i++) {
        m[i] = new double[size];
        for(int j = 0; j < size; j++) m[i][j] = 0;
    }
    std::cout << "*конструктор matr(int) создал вектор №" << num << "*" << std::endl;
}
matr::matr(matr &a) {
    num = matrcount;
    matrcount++;
    size = a.size;
    m = new double*[size];
    for(int i = 0; i < size; i++) {
        m[i] = new double[size];
        for(int j = 0; j < size; j++) m[i][j] = a.m[i][j];
    }
    std::cout << "*конструктор matr(&vect) создал вектор №" << num << "*" << std::endl;
}
matr::matr() {
    num = matrcount;
    matrcount++;
    size = 0;
    m = new double*[size];
    for(int i = 0; i < size; i++) {
        m[i] = new double[size];
        for(int j = 0; j < size; j++) m[i][j] = 0;
    }
    std::cout << "*конструктор matr() создал вектор №" << num << "*" << std::endl;
}

matr::~matr() {
    std::cout << "*деструктор ~matr() удалил вектор №" << num << "*" << std::endl;

}

matr &matr::operator=(matr a) {
    size = a.size;
    m = new double*[size];
    for(int i = 0; i < size; i++) {
        m[i] = new double[size];
        for(int j = 0; j < size; j++) m[i][j] = a.m[i][j];
    }
    return *this;
}

matr matr::operator+(const matr &a) {
    if(size != a.size) {
        matr res;
        return res;
    }
    matr res(size);
    for(int i=0; i < size; i++) for(int j = 0; j < size; j++) res.m[i][j] = m[i][j] + a.m[i][j];
    return res;
}
matr matr::operator-(const matr &a) {
    if(size != a.size) {
        matr res;
        return res;
    }
    matr res(size);
    for(int i=0; i < size; i++) for(int j = 0; j < size; j++) res.m[i][j] = m[i][j] - a.m[i][j];
    return res;
}
matr matr::operator*(const matr &a) {
    if(size != a.size) {
        matr res;
        return res;
    }
    matr res(size);
    for(int i=0; i < size; i++) for(int j = 0; j < size; j++) {
        res.m[i][j] = 0;
        for(int k = 0; k < size; k++){
            res.m[i][j] += m[i][k] * a.m[k][j];
        }
    }
    return res;
}
matr matr::operator*(double &a) {
    matr res(size);
    for(int i=0; i < size; i++) for(int j = 0; j < size; j++) res.m[i][j] = m[i][j] * a;
    return res;
}
matr operator*(double a, matr b) {
    matr res(b.size);
    for(int i = 0; i < b.size; i++) for(int j = 0; j < b.size; j++) res.m[i][j] = a * b.m[i][j];
    return res;
}
/*matr matr::operator/(const matr &a) {
    if(size != a.size) {
        matr res;
        return res;
    }
    matr res(size);
    for(int i=0; i < size; i++) for(int j = 0; j < size; j++) res.m[i][j] = m[i][j] / a.m[i][j];
    return res;
}
matr matr::operator/(double &a) {
    matr res(size);
    for(int i=0; i < size; i++) for(int j = 0; j < size; j++) res.m[i][j] = m[i][j] / a;
    return res;
}
matr operator/(double a, matr b) {
    matr res(b.size);
    for(int i = 0; i < b.size; i++) for(int j = 0; j < b.size; j++) res.m[i][j] = a / b.m[i][j];
    return res;
}*/

int matr::getNum() const                    {return num;}
void matr::setNum(int num)                  {matr::num = num;}
int matr::getSize() const                   {return size;}
void matr::setSize(int size)                {matr::size = size;}
double **matr::getM() const                 {return m;}
void matr::setM(double **m)                 {matr::m = m;}
double matr::getMcord(int i, int j) const   {return m[i][j];}
void matr::setMcord(int i, int j, double x) {m[i][j] = x;}

const bool matr::operator==(const matr &a) {
    if(size != a.size) return false;
    for(int i = 0; i < size; i++) for(int j = 0; j < size; j++) if(m[i][j] != a.m[i][j]) return false;
    return true;
}
matr matr::operator-() {
    for(int i = 0; i < size; i++) for(int j = 0; j < size; j++) m[i][j] = -1 * m[i][j];
    return *this;
}

std::ostream &operator<<(std::ostream &os, const matr &matr1) {
    os << "num: " << matr1.num << std::endl << "size: " << matr1.size << std::endl << "v: " << std::endl << "((";
    for(int i = 0; i < matr1.size - 1; i++) {
        for(int j = 0; j < matr1.size - 1; j++) {
            os << matr1.m[i][j] << ", ";
        }
        os << matr1.m[i][matr1.size - 1] << "), " << std::endl << " (";
    }
    for(int j = 0; j < matr1.size - 1; j++) os << matr1.m[matr1.size - 1][j] << ", ";
    os << matr1.m[matr1.size - 1][matr1.size - 1] << "))";
    return os;
}

