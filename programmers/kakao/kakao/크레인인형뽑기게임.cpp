#define _CRT_SECURE_NO_WARNGINGS
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
int solution(vector<vector<int>> board, vector<int> moves);

int main(void) {
    vector<vector<int>> board = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};

    int answer = solution(board, moves);
    printf("%d", answer);
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> bucket;
    int temp;
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            temp = board[j][moves[i] - 1];
            board[j][moves[i] - 1] = 0;

            if (temp != 0) {
                if (bucket.size() > 0) {
                    if (bucket.back() != temp)
                        bucket.push_back(temp);
                    else {
                        bucket.pop_back();
                        answer += 2;
                    }
                }
                else
                    bucket.push_back(temp);
                break;
            }
        }
    }

    return answer;
}