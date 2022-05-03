#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<vector>
using namespace std;

double left[5][5] = { {0,0,0.02,0,0},{0,0.1,0.07,0.01,0},{0.05,1,0,0,0},{0,0.1,0.07,0.01,0},{0,0,0.02,0,0} };
double right[5][5] = { {0,0,0.02,0,0},{0,0.01,0.07,0.1,0},{0,0,0,1,0.05},{0,0.01,0.07,0.1,0},{0,0,0.02,0,0} };
double up[5][5] = { {0,0,0.05,0,0},{0,0.1,1,0.1,0},{0.02,0.07,0,0.07,0.02},{0,0.01,0,0.01,0}, {0,0,0,0,0} };
double down[5][5] = { {0,0,0,0,0}, {0,0.01,0,0.01,0}, {0.02,0.07,0,0.07,0.02}, {0,0.1,1,0.1,0}, {0,0,0.05,0,0} };

vector< vector<int> >board;
int temp[5][5] = { 0 };
int n;
int result = 0;

int main(void) {
	int x = n / 2 + 1;
	int y = n / 2 + 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		board.emplace_back();
		for (int j = 0; j < n; j++) {
			int t;
			scanf("%d", &t);
			board[i].emplace_back(t);
		}
	}
}

void check(int x, int y, int dir) {
	double* direction;
	switch (dir) {
	case 1:
		direction = &left[0][0];
		temp[i][j] = board[x][y] * left[i][j];
		break;
	case 2:
		direction = &right[0][0];
		temp[i][j] = board[x][y] * right[i][j];
		break;
	case 3:
		direction = &up[0][0];
		temp[i][j] = board[x][y] * up[i][j];
		break;
	case 4:
		direction = &down[0][0];
		temp[i][j] = board[x][y] * down[i][j];
		break;
	default:
		break;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int nx = x + i - 2;
			int ny = y + i - 2;
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				result += board[x][y] * *(direction+i*5+j);
			}
			
			
		}
	}
}