#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<vector>
using namespace std;

int input[2][15];
vector<int>dp;

int main(void) {
	//ют╥б
	int days;
	scanf("%d", &days);
	for (int i = 0; i < days; i++) {
		scanf("%d %d", &input[0][i], &input[1][i]);
		dp.push_back(0);
	}
	dp.push_back(0);
	//dynamic programing
	for (int i = 0; i <= days; i++) {
		if (i) dp[i] = dp[i] > dp[i - 1] ? dp[i] : dp[i - 1];
		int next = i + input[0][i];
		if (next < dp.size())
			dp[next] = dp[next] > dp[i] + input[1][i] ? dp[next] : dp[i] + input[1][i];
	}
	printf("%d", dp[days]);
}
