
#include <iostream>
#include <iomanip> 
#include <time.h> 

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main() {
	srand((unsigned)time(NULL));

	int Low = -6;
	int High = 31;

	int rowCount = 7;
	int colCount = 5;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++) a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	Sort(a, rowCount, colCount);
	Print(a, rowCount, colCount);

	int S = 0;
	int k = 0;
	Calc(a, rowCount, colCount, S, k);
	cout << "S = "<< S << endl;
	cout<< "k = "<< k << endl;
	Print(a, rowCount, colCount);

	for (int i = 0; i < rowCount; i++) delete[] a[i];
	delete[] a;

	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) 
{
	for (int row = 0; row < rowCount; row++)
		for (int col = 0; col < colCount; col++)
			a[row][col] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount) 
{
	cout << endl;
	for (int row = 0; row < rowCount; row++) 
	{
		for (int col = 0; col < colCount; col++) 
			cout << setw(4) << a[row][col];
		cout << endl;
	}
	cout << endl;
}


bool WrongOrder(int a0, int a1, int a2, int b0, int b1, int b2) 
{
	if (a0 > b0) return true;
	if ((a0 == b0) && (a1 > b1)) return true;
	if ((a0 == b0) && (a1 == b1) && (a2 < b2)) return true;
	return false;
}

void Sort(int** a, const int rowCount, const int colCount) 
{
	for (int maxCol = colCount - 1; maxCol > 0; maxCol--) 
	{
		for (int col = 0; col < maxCol; col++) 
		{
			int colA = col;
			int colB = col + 1;
			if (WrongOrder(a[0][colA], a[1][colA], a[2][colA], a[0][colB], a[1][colB], a[2][colB]))
			{
				Change(a, colA, colB, rowCount);
			}
		}
	}
}

void Change(int** a, const int colA, const int colB, const int rowCount) {
	int tmp;
	for (int row = 0; row < rowCount; row++) 
	{
		tmp = a[row][colA];
		a[row][colA] = a[row][colB];
		a[row][colB] = tmp;
	}
}



void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int row = 0; row < rowCount; row++)
		for (int col = 0; col < colCount; col++)
			if (a[row][col] > 0 && !(row % 3 == 0 || col % 3 == 0))
			{
				S += a[row][col];
				k++;
				a[row][col] = 0;
			}
}










