#include <iostream>
#include <iomanip>
using namespace std;

void printMatrix(int *matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << setw(size) << matrix[i * size + j];
		}
		cout << endl;
	}
}

int main()
{
	const unsigned int n = 3;
	int matrix[n][n] = { {3, 5, 5}, {4, 6, 1}, {1, 1, 1} };
	printMatrix(&matrix[0][0], n);
	return 0;
}