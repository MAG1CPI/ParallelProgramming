//Cache optimization-optimized
#include <iostream>
#include <sys/time.h>
using namespace std;

unsigned long int innerproduct(int* vect, int** matrix, int* sum, int size) {
	for (int i = 0; i < size; i++)
		sum[i] = 0;

	struct timeval tvBegin, tvEnd;
	gettimeofday(&tvBegin, NULL);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			sum[i] += matrix[j][i] * vect[j];
		}
	}
	gettimeofday(&tvEnd, NULL);

	return 1000000 * (tvEnd.tv_sec - tvBegin.tv_sec) + tvEnd.tv_usec - tvBegin.tv_usec;
}

int main() {
	int size = 5000;
	int count = 40;

	/********initializate********/

	int* vect = new int[size];
	for (int i = 0; i < size; i++)
		vect[i] = i;

	int** matrix = new int* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = i + j;

	int* sum = new int[size];
	for (int i = 0; i < size; i++)
		sum[i] = 0;

	/********test********/

	unsigned long int diff = 0;

	size = 5000, count = 40;
	for (int i = 0; i < count; i++)
		diff += innerproduct(vect, matrix, sum, size);
	cout << "|5000/40 \t|\t" << diff << "\t|" << endl;

	diff = 0;
	size = 4000, count = 50;
	for (int i = 0; i < count; i++)
		diff += innerproduct(vect, matrix, sum, size);
	cout << "|4000/50 \t|\t" << diff << "\t|" << endl;

	diff = 0;
	size = 3000, count = 80;
	for (int i = 0; i < count; i++)
		diff += innerproduct(vect, matrix, sum, size);
	cout << "|3000/80 \t|\t" << diff << "\t|" << endl;

	diff = 0;
	size = 2000, count = 100;
	for (int i = 0; i < count; i++)
		diff += innerproduct(vect, matrix, sum, size);
	cout << "|2000/100\t|\t" << diff << "\t|" << endl;

	diff = 0;
	size = 1500;
	for (int i = 0; i < count; i++)
		diff += innerproduct(vect, matrix, sum, size);
	cout << "|1500/100\t|\t" << diff << "\t|" << endl;

	diff = 0;
	size = 1000;
	for (int i = 0; i < count; i++)
		diff += innerproduct(vect, matrix, sum, size);
	cout << "|1000/100\t|\t" << diff << "\t|" << endl;

	diff = 0;
	size = 500, count = 500;
	for (int i = 0; i < count; i++)
		diff += innerproduct(vect, matrix, sum, size);
	cout << "|500/500 \t|\t" << diff << "\t|" << endl;

	diff = 0;
	size = 100;
	for (int i = 0; i < count; i++)
		diff += innerproduct(vect, matrix, sum, size);
	cout << "|100/500 \t|\t" << diff << "\t|" << endl;

	size = 5000;

	/****************/

	delete[] vect;
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
	delete[] sum;

}

