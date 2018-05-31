//#include <cstdlib>
#include <iostream>
#include <cmath>
#include "vect.h"
#include "matr.h"

using namespace std;

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
matr obr(matr a) {
    int n = a.getSize();
    matr obr_matr(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int m = n - 1;
            matr tmp_matr(m);
            tmp_matr = rmij(a, i, j);
            obr_matr.setMcord(i, j, pow(-1.0, i + j + 2) * det(tmp_matr) / det(a));
            delete &tmp_matr;
        }
    }
    return obr_matr;
}
int main(){
    setlocale(LC_ALL, "Russian");
    int s;
    cout << "введите размерность матрицы: ";
    cin >> s;
    double *aa = new double [s*s], *ab = new double [s], *e = new double [s*s], *o = new double [s*s];
    //создание единичной матрицы
    for(int i=0; i<s; i++) {
        for(int j=0; j<s; j++) {
            e[s*i + j]=0;
            if(i==j) e[s*i + j]=1;
        }
    }
    matr em(s, e);
    //cout << em << endl;
    //создание единичной матрицы
    cout << "введите матрицу коэфициентов: " << endl << "(";
    for(int i = 0; i < s*s; i++) cin >> aa[i];
    cout << ")" << endl;
    matr mp(s, aa), om(s);
    om = obr(mp);
    cout << "введённая матрица: " << endl << mp << endl << om << endl;
    cout << "введите вектор ответов: " << endl << "(";
    for(int i = 0; i < s; i++)  cin >> ab[i];
    cout << ")" << endl;
    vect va(s, ab);
    cout << "введённый вектор: " << endl << va << endl;

    vect a(s);
    const double eps = 0.001; //желаемая точность
    double* TempX = new double[s];
    double norm; // норма, определяемая как наибольшая разность компонент столбца иксов соседних итераций.
    do {
        for (int i = 0; i < s; i++) {
            TempX[i] = va.getVi(i);
            for (int g = 0; g < s; g++) if (i != g) TempX[i] -= mp.getMcord(i, g) * a.getVi(g);
            TempX[i] /= mp.getMcord(i, i);
        }
        norm = fabs(a.getVi(0) - TempX[0]);
        for (int h = 0; h < s; h++) {
            if (fabs(a.getVi(h) - TempX[h]) > norm) norm = fabs(a.getVi(h) - TempX[h]);
            a.setVi(h, TempX[h]);
        }
    } while (norm > eps);
    delete[] TempX;
    cout << "ответ:" << a;


}