//
// Created by danai on 06/04/2018.
//

#ifndef LAB02_PROG_VECT_H
#define LAB02_PROG_VECT_H

#include <ostream>

static int vectcount;

class vect{
public:
    vect(int d, double *x);
    explicit vect(int d);
    vect(vect& a);
    vect();

    ~vect();

    vect& operator=(vect a);

    vect operator+(const vect &a);
    vect operator-(const vect &a);
    vect operator*(const vect &a);
    vect operator*(double a);
    friend vect operator*(double a, vect b);
    /*vect operator/(const vect &a);
    vect operator/(double &a);
    friend vect operator/(double a, vect b);*/

    int getNum() const;
    void setNum(int num);
    int getDim() const;
    void setDim(int dim);
    double *getV() const;
    void setV(double *v);
    double getVi(int i) const;
    void setVi(int i, double x);

    const bool operator==(const vect &a);
    vect operator-();
    double operator[](int i);
    friend std::ostream &operator<<(std::ostream &os, const vect &vect1);

private:
    int num;
    int dim;
    double *v;
};

#endif //LAB02_PROG_VECT_H