#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<vector>
#include<tuple>
#include<iostream>
using namespace std;

int board[8][8] = { 0 };
int boardCopy[8][8] = { 0 };
vector< tuple<int, int, int> >cctv;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int n, m;

bool out(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return true;
	else
		return false;
}

void move(int x, int y, int direction) {
	int d = direction % 4;
	int nx = x;
	int ny = y;
	while (1) {
		nx += dx[d];
		ny += dy[d];
		if (out(nx, ny) || boardCopy[nx][ny] == 6)
			break;
		else if (boardCopy[nx][ny] != 0)
			continue;
		else
			boardCopy[nx][ny] = 7;
	}
}

int main(void) {
	//입력
	scanf("%1d %1d", &n, &m);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &board[i][j]);
			if (board[i][j] != 0 && board[i][j] != 6)
				cctv.push_back({ i,j,board[i][j] });
			if (board[i][j] == 0)
				ans++;
		}
	}

	//체크
	for (int i = 0; i < (1 << (2 * cctv.size())); i++) {
		copy(&board[0][0], &board[0][0]+64, &boardCopy[0][0]);
		int direction = i;
		for (int j = 0; j < cctv.size(); j++) {
			int d = direction % 4;
			direction /= 4;
			int x = get<0>(cctv[j]);
			int y = get<1>(cctv[j]);
			int k = get<2>(cctv[j]);

			switch (k) {
			case 1:
				move(x, y, d);
				break;
			case 2:
				move(x, y, d);
				move(x, y, d + 2);
				break;
			case 3:
				move(x, y, d);
				move(x, y, d + 1);
				break;
			case 4:
				move(x, y, d);
				move(x, y, d + 1);
				move(x, y, d + 2);
				break;
			case 5:
				move(x, y, d);
				move(x, y, d + 1);
				move(x, y, d + 2);
				move(x, y, d + 3);
				break;
			default:
				break;
			}
		}
		int c = 0;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				if (boardCopy[a][b] == 0)
					c++;
			}
		}
		ans = c < ans ? c : ans;
	}

	printf("%d\n", ans);
}
