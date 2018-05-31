//
// Created by danai on 06/04/2018.
//

#include <iostream>
#include "vect.h"
#include "matr.h"

vect::vect(int d, double *x) {
    num = vectcount;
    vectcount++;
    dim = d;
    v = new double [dim];
    for(int i = 0; i < dim; i++) v[i] = x[i];
    std::cout << "*конструктор vect(int d, double *x) создал вектор №" << num << "*" << std::endl;
}
vect::vect(int d) {
    num = vectcount;
    vectcount++;
    dim = d;
    v = new double [dim];
    for(int i = 0; i < dim; i++) v[i] = 0;
    std::cout << "*конструктор vect(int d) создал вектор №" << num << "*" << std::endl;
}
vect::vect(vect& a) {
    num = vectcount;
    vectcount++;
    dim = a.dim;
    v = new double [dim];
    for(int i = 0; i < dim; i++) v[i] = a.v[i];
    std::cout << "*конструктор vect(vect& b) создал вектор №" << num << "*" << std::endl;

}
vect::vect() {
    num = vectcount;
    vectcount++;
    dim = 0;
    v = new double [dim];
    for(int i = 0; i < dim; i++) v[i] = 0;
    std::cout << "*конструктор vect() создал вектор №" << num << "*" << std::endl;
}

vect::~vect() {
    std::cout << "*деструктор ~vect() удалил вектор №" << num << "*" << std::endl;
    //delete [] v;
}

vect &vect::operator=(const vect a) {
    dim = a.dim;
    v = new double [dim];
    for(int i = 0; i < dim; i++) v[i] = a.v[i];
    return *this;
}

vect vect::operator+(const vect &a) {
    if(dim != a.dim) {
        vect res;
        return res;
    }
    vect res(dim);
    for(int i = 0; i < dim; i++) res.v[i] = a.v[i] + v[i];
    return res;
}
vect vect::operator-(const vect &a) {
    if(dim != a.dim) {
        vect res;
        return res;
    }
    vect res(dim);
    for(int i = 0; i < dim; i++) res.v[i] = a.v[i] - v[i];
    return res;
}
vect vect::operator*(const vect &a) {
    if(dim != a.dim) {
        vect res;
        return res;
    }
    vect res(dim);
    for(int i = 0; i < dim; i++) res.v[i] = a.v[i] * v[i];
    return res;
}
vect vect::operator*(double a) {
    vect res(dim);
    for(int i = 0; i < dim; i++) res.v[i] = a * v[i];
    return res;
}
vect operator*(double a, vect b) {
    vect res(b.dim);
    for(int i = 0; i < b.dim; i++) res.v[i] = a * b.v[i];
    return res;
}
/*vect vect::operator/(const vect &a) {
    if(dim != a.dim) {
        vect res;
        return res;
    }
    vect res(dim);
    for(int i = 0; i < dim; i++) res.v[i] = a.v[i] / v[i];
    return res;
}
vect vect::operator/(double &a) {
    vect res(dim);
    for(int i = 0; i < dim; i++) res.v[i] = a / v[i];
    return res;
}
vect operator/(double a, vect b) {
    vect res(b.dim);
    for(int i = 0; i < b.dim; i++) res.v[i] = a / b.v[i];
    return res;
}*/

int vect::getNum() const            {return num;}
void vect::setNum(int num)          {vect::num = num;}
int vect::getDim() const            {return dim;}
void vect::setDim(int dim)          {vect::dim = dim;}
double *vect::getV() const          {return v;}
void vect::setV(double *v)          {vect::v = v;}
double vect::getVi(int i) const     {return v[i];}
void vect::setVi(int i, double x)   {v[i] = x;}

const bool vect::operator==(const vect &a) {
    if (dim != a.dim) return false;
    for(int i = 0; i < dim; i++) if (v[i] != a.v[i]) return false;
    return true;
}
vect vect::operator-() {
    vect res(dim, v);
    for(int i = 0; i < res.dim; i++) res.v[i] = -1*res.v[i];
    return res;
}
double vect::operator[](int i) {
    return v[i];
}
std::ostream &operator<<(std::ostream &os, const vect &vect1) {
    os << "num: " << vect1.num << std::endl << "dim: " << vect1.dim << std::endl << "v: (";
    for(int i = 0; i < vect1.dim - 1; i++) os << vect1.v[i] << " ";
    os << vect1.v[vect1.dim - 1] << ")";
    return os;
}
