//
// Created by danai on 12.04.18.
//

#ifndef LAB02_PROG_MATR_H
#define LAB02_PROG_MATR_H

#include <ostream>

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
    matr rmij(matr m, int row, int col){
        int n = m.getSize();
        matr tmp_matr(n);
        int ki = 0;
        for (int i = 0; i < n; i++){
            if(i != row){
                for (int j = 0, kj = 0; j < n; j++){
                    if (j != col){
                        tmp_matr.setMcord(ki, kj, m.getMcord(i, j));
                        kj++;
                    }
                }
                ki++;
            }
        }
        return tmp_matr;
    }//создвёт новую матрицу без столбцов row и col
    int det(matr a) {
        double temp = 0;   //временная переменная для хранения определителя
        int k = 1, n = a.getSize();      //степень
        if(n < 1){
            std::cout<<"Не верный размер матрицы!!!" << std::endl;
            return 0;
        }
        else if (n == 1) temp = a.getMcord(0, 0);
        else if (n == 2) temp = a.getMcord(0, 0) * a.getMcord(1, 1) - a.getMcord(1, 0) * a.getMcord(0, 1);
        else {
            for(int i = 0; i < n; i++) {
                int m = n - 1;
                matr tmp_matr(m);
                tmp_matr = rmij(a, m, i);
                temp = temp + k * a.getMcord(0, i) * det(tmp_matr);
                k = -k;
                delete &tmp_matr;
            }
        }
        return temp;
    }
    matr transpon(matr a){
        int n = a.getSize();
        matr tmp_matr(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                tmp_matr.setMcord(i, j, a.getMcord(i, j));
        return tmp_matr;
    }
private:
    int num;
    int size;
    double **m;
};

#endif //LAB02_PROG_MATR_H