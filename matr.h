//
// Created by danai on 12.04.18.
//

#ifndef LAB02_PROG_MATR_H
#define LAB02_PROG_MATR_H

#include <ostream>
#include <cmath>

static int matrcount;

class matr {
public:
    matr(int s, double **a);
    matr(int s, double *a);
    explicit matr(int s);
    matr(matr& a);
    matr();

    ~matr();

    matr& operator=(matr a);

    matr operator+(const matr &a);
    matr operator-(const matr &a);
    matr operator*(const matr &a);
    matr operator*(double &a);
    friend matr operator*(double a, matr b);
    /*matr operator/(const matr &a);
    matr operator/(double &a);
    friend matr operator/(double a, matr b);*/

    int getNum() const;
    void setNum(int num);
    int getSize() const;
    void setSize(int size);
    double **getM() const;
    void setM(double **m);
    double getMcord(int i, int j) const;
    void setMcord(int i, int j, double x);

    const bool operator==(const matr &a);
    matr operator-();
    friend std::ostream &operator<<(std::ostream &os, const matr &matr1);

private:
    int num;
    int size;
    double **m;
};

#endif //LAB02_PROG_MATR_H