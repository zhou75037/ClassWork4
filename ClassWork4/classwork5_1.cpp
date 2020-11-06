#include<stdio.h>
#include<cmath>
int value[10] = { 1,2,3,4,5,6,7,8,9,10 };
int num[3][3] = { 0 };
bool IsPrime(int x1, int x2);
int moves[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

bool IsPrime(int x1, int x2) {

	int i = 2;
	int sum = x1 + x2;
	if (sum == 1 || sum == 2)
	{
		return false;
	}
	for (i = 2; i <= sqrt(sum); i++) {
		if (sum % i == 0)
			return true;
	}
	return false;
}

bool check() {
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 4; i++) {
			int x, y;
			x = j / 3;
			y = j % 3;
			int px = x + moves[i][0];
			int py = y + moves[i][1];
			if (px < 0 || py < 0 || px>2 || py>2) {
				continue;
			}
			if (num[px][py] == 0)
				continue;
			if (IsPrime(num[x][y], num[px][py]))
				return false;
		}
	}
	return true;
}
void swap(int i, int j) {
	int tmp;
	/*	int ix, iy;
	int jx, jy;
	ix = i / 3;
	iy = i % 3;
	jx = j / 3;
	jy = j % 3;
	tmp = num[ix][iy];
	num[ix][iy] = num[jx][jy];
	num[jx][jy] = tmp;*/
	tmp = value[i];
	value[i] = value[j];
	value[j] = tmp;
}
void FillNum(int n) {


	if (n == 9 && check()) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf(" %d ", num[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < 10; i++) {
		swap(i, n);
		int x, y;
		x = i / 3;
		y = i % 3;
		num[x][y] = value[i];
		FillNum(n + 1);
		swap(i, n);
	}
}

int main() {
	FillNum(0);
	return 1;
}