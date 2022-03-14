//Superscalar optimization-optimized
#include <iostream>
#include <sys/time.h>
using namespace std;

unsigned long int sum(int* a, int size, long long int& result) {
	long long int sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0;

	struct timeval tvBegin, tvEnd;
	gettimeofday(&tvBegin, NULL);
	for (int i = 0; i < size; i+=4) {
		sum0 += a[i];
		sum1 += a[i+1];
		sum2 += a[i+2];
		sum3 += a[i+3];
	}
	sum0 += sum1 + sum2 + sum3;
	gettimeofday(&tvEnd, NULL);

	result = sum0;

	return 1000000 * (tvEnd.tv_sec - tvBegin.tv_sec) + tvEnd.tv_usec - tvBegin.tv_usec;
}


int main() {
	int size = 500000;
	int count = 50;

	/********initializate********/

	int* a = new int[size];
	for (int i = 0; i < size; i++)
		a[i] = i;

	long long int result = 0;

	/********test********/

	unsigned long int diff = 0;

	size = 500000, count = 50;
	for (int i = 0; i < count; i++)
		diff += sum(a, size, result);
	cout << "|500000/50 \t|\t" << diff << "\t|" << endl;

	diff = 0;
	size = 400000;
	for (int i = 0; i < count; i++)
		diff += sum(a, size, result);
	cout << "|400000/50 \t|\t" << diff << "\t|" << endl;

	diff = 0;
	size = 300000;
	for (int i = 0; i < count; i++)
		diff += sum(a, size, result);
	cout << "|300000/50 \t|\t" << diff << "\t|" << endl;

	diff = 0;
	size = 200000, count = 100;
	for (int i = 0; i < count; i++)
		diff += sum(a, size, result);
	cout << "|200000/100\t|\t" << diff << "\t|" << endl;

	diff = 0;
	size = 150000;
	for (int i = 0; i < count; i++)
		diff += sum(a, size, result);
	cout << "|150000/100\t|\t" << diff << "\t|" << endl;

	diff = 0;
	size = 100000;
	for (int i = 0; i < count; i++)
		diff += sum(a, size, result);
	cout << "|100000/100\t|\t" << diff << "\t|" << endl;

	diff = 0;
	size = 50000, count = 500;
	for (int i = 0; i < count; i++)
		diff += sum(a, size, result);
	cout << "|50000/500 \t|\t" << diff << "\t|" << endl;

	/****************/
	delete[] a;
}