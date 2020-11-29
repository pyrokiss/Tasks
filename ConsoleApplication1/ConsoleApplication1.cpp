#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>
#include <typeinfo>
using namespace std;

class matrix {
    public:
        int N;

        int get_determinant() {
        
        }
};

const int N_10 = 10;
//const int N_20 = 20;

void clear(int** matr, int n) { //функция очищает память.
    for (int i = 0; i < n; i++) {
        delete[] matr[i];
    }
    delete[] matr;
}

void print_matrix(int** matr, int size) { //функция выводит матрицу.
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(size) << matr[i][j];
        }
        cout << endl;
    }
}

int get_determ(int** matr, int n) { //функция ищет определитель рекурсивно.
    if (n == 1) {
        return matr[0][0];
    }
    else if (n == 2) {
        return (matr[0][0] * matr[1][1]) - (matr[0][1] * matr[1][0]);
    }
    else if (n > 2) {
        int d = 0;
        for (int k = 0; k < n; k++) {
            int** m = new int* [n - 1];
            for (int i = 0; i < n - 1; i++) {
                m[i] = new int[n - 1];
            }
            for (int i = 1; i < n; i++) {
                int t = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    m[i - 1][t] = matr[i][j];
                    t++;
                }
            }
            d += pow(-1, k + 2) * matr[0][k] * get_determ(m, n - 1);
            clear(m, n - 1);
        }
        return d;
    }
    else {
        cout << "Такой матрицы не существует" << endl;
    }
}

int** test_10() {
    int** matrix = new int* [N_10];
    for (int i = 0; i < N_10; i++) {
        matrix[i] = new int[N_10];
    }
    
    int test_10[N_10][N_10] = { 
        {4, 1, 6, 5, 7, 9, 4, 2, 4, 2},
        {6, 2, 6, 1, 3, 4, 1, 9, 2, 2},
        {1, 9, 8, 4, 1, 1, 8, 4, 7, 5},
        {3, 8, 2, 9, 2, 5, 6, 2, 1, 7},
        {6, 1, 4, 3, 9, 7, 3, 6, 5, 1},
        {3, 7, 2, 4, 4, 2, 4, 3, 7, 5},
        {4, 6, 1, 3, 8, 1, 6, 5, 1, 3},
        {5, 1, 3, 9, 4, 6, 6, 2, 5, 2},
        {7, 1, 7, 3, 5, 1, 3, 7, 6, 2},
        {2, 5, 4, 7, 7, 9, 6, 5, 3, 6} };
    
    for (int i = 0; i < N_10; i++) {
        for (int j = 0; j < N_10; j++) {
            matrix[i][j] = test_10[i][j];
        }
    }
    return matrix;
}

/*int** test_20() {
    int** matrix = new int* [N_20];
    for (int i = 0; i < N_20; i++) {
        matrix[i] = new int[N_20];
    }

    int test_20[N_20][N_20] = {
        {4, 1, 6, 5, 7, 9, 4, 2, 4, 2, 2, 5, 4, 7, 7, 9, 6, 5, 3, 6},
        {6, 2, 6, 1, 3, 4, 1, 9, 2, 2, 7, 1, 7, 3, 5, 1, 3, 7, 6, 2},
        {1, 9, 8, 4, 1, 1, 8, 4, 7, 5, 5, 1, 3, 9, 4, 6, 6, 2, 5, 2},
        {3, 8, 2, 9, 2, 5, 6, 2, 1, 7, 4, 6, 1, 3, 8, 1, 6, 5, 1, 3},
        {6, 1, 4, 3, 9, 7, 3, 6, 5, 1, 3, 7, 2, 4, 4, 2, 4, 3, 7, 5},
        {3, 7, 2, 4, 4, 2, 4, 3, 7, 5, 6, 1, 4, 3, 9, 7, 3, 6, 5, 1},
        {4, 6, 1, 3, 8, 1, 6, 5, 1, 3, 3, 7, 2, 4, 4, 2, 4, 3, 7, 5},
        {5, 1, 3, 9, 4, 6, 6, 2, 5, 2, 4, 6, 1, 3, 8, 1, 6, 5, 1, 3},
        {7, 1, 7, 3, 5, 3, 8, 2, 9, 2, 5, 6, 2, 1, 7, 6, 2, 1, 7, 7},
        {2, 5, 4, 7, 7, 9, 6, 5, 3, 6, 3, 8, 2, 9, 2, 5, 6, 2, 1, 7},
        {2, 5, 4, 7, 7, 9, 6, 5, 3, 6, 4, 1, 6, 5, 7, 9, 4, 2, 4, 2},
        {7, 1, 7, 3, 5, 1, 3, 7, 6, 2, 6, 2, 6, 1, 3, 4, 1, 9, 2, 2},
        {5, 1, 3, 9, 4, 6, 6, 2, 5, 2, 1, 9, 8, 4, 1, 1, 8, 4, 7, 5},
        {4, 6, 1, 3, 8, 1, 6, 5, 1, 3, 3, 8, 2, 9, 2, 5, 6, 2, 1, 7},
        {3, 7, 2, 4, 4, 2, 4, 3, 7, 5, 6, 1, 4, 3, 9, 7, 3, 6, 5, 1},
        {4, 6, 1, 3, 8, 1, 6, 5, 1, 3, 3, 7, 2, 4, 4, 2, 4, 3, 7, 5},
        {3, 8, 2, 9, 2, 5, 6, 2, 1, 7, 4, 6, 1, 3, 8, 1, 6, 5, 1, 3},
        {4, 7, 7, 9, 6, 5, 3, 6, 4, 1, 5, 1, 3, 9, 4, 6, 6, 2, 5, 2},
        {4, 1, 1, 8, 4, 7, 5, 5, 1, 3, 7, 1, 7, 3, 5, 1, 3, 7, 6, 2},
        {3, 9, 4, 6, 6, 2, 5, 2, 4, 6, 2, 5, 4, 7, 7, 9, 6, 5, 3, 6} };

    for (int i = 0; i < N_20; i++) {
        for (int j = 0; j < N_20; j++) {
            matrix[i][j] = test_20[i][j];
        }
    }
    return matrix;
}*/

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Матрица 10х10:" << endl;
    print_matrix(test_10(), N_10);
    cout << "Определитель: " <<get_determ(test_10(), N_10) << endl;
    clear(test_10(), N_10);
    /*cout << "Матрица 20х20:" << endl;
    print_matrix(test_20(), N_20);
    cout << "Определитель: " << get_determ(test_20(), N_20) << endl;
    clear(test_20(), N_20);*/
    return 0;
}



