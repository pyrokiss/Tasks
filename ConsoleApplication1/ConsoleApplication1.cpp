#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>
using namespace std;

void print_matrix(int** matr, int size) { //функция выводит матрицу.
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << setw(size) << matr[i][j];
		}
		cout << endl;
	}
}
void clear(int** matr, int n) { //функция очищает память.
    for (int i = 0; i < n; i++) {
        delete[] matr[i];
    }
    delete[] matr;
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

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите размерность матрицы: ";
    cin >> n;
    if (n <= 0) {
        cout << "Такой матрицы не существует!" << endl;
    }
    else {
        int** matrix = new int* [n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
        }

        cout << "Заполните матрицу: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        cout << "Ваша матрица be like: " << endl;
        print_matrix(matrix, n);

        cout << "Определитель матрицы be like: " << get_determ(matrix, n) << endl;
        clear(matrix, n);
    }
    return 0;
}




