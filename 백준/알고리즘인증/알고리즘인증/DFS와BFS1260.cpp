#include <iostream>
#include <vector>
#include <queue>
#define for(X) for(int i=1;i<=X;i++)
#define MAX 1001
using namespace std;

bool visited[MAX] = { false };
int map[MAX][MAX] = { 0 };
int N, M, S;

void DFS(int v) {
	visited[v] = true;
	cout << v << " ";
	for (N) {
		if (visited[i] == false && map[v][i] == 1)
			DFS(i);
	}
}

void BFS(int v) { //DFS���� visited�� ���� true�� �������� ������ �ݴ�� �ۼ��Ѵ�.
	queue<int> q;
	cout << v << ' ';
	visited[v] = false;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (N) {
			if (visited[i] == true && map[v][i] == 1) {
				cout << i << ' ';
				visited[i] = false;
				q.push(i);
			}
		}
	}
}

int main(void) {
	int x, y;
	queue<int> q;

	cin >> N >> M >> S;
	for (M) {
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;
	}
	
	DFS(S);
	cout << endl;
	BFS(S);
}