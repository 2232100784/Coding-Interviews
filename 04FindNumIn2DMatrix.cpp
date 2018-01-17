#include <iostream>
#include <assert.h>
using namespace std;

void FindNumInMatrix(int *mat, int rows, int cols, int tar) {
	bool result = false;
	assert(mat != 0 && rows > 0 && cols > 0);
	int x = cols - 1;
	int y = 0;
	while (x>=0 && y<=rows) {
		int val = mat[y * cols + x];
		if (tar == val) {
			result = true;
			break;
		}
		else if (tar < val) 
			--x;
		else ++y;
	} 
	if (result)
	    cout << tar <<" found!" << endl;
	else
		cout << tar << " not found!" << endl;
	return;
}

void Test1() {
	int a[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	FindNumInMatrix(a[0], 4, 4, 6);
	return ;
}

void Test2() {
	int a[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	FindNumInMatrix(a[0], 4, 4, 17);
	return ;
}

int main() {
	Test1();
	Test2();
	return 0;
}
