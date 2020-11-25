#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const unsigned int n = 2; 
	int matrix[n][n] = { {3, 5}, {4, 6} };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(n) << matrix[i][j];
		}
		cout << endl;
	}

	if (n == 2) {
		int d = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
		cout << d << endl;
	}

	return 0;
}

