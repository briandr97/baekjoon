#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages);

int main(void) {
    vector<int> stages = { 1,2,3,3,4,5,5 };
    int N = 10;
    vector<int> answer;

    answer = solution(N, stages);
    for (int i = 0; i < N; i++) {
        printf("%d", answer[i]);
        if (i != N - 1) printf(",");
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double>probability;
    vector<int> count;
    count.assign(N+1, 0);

    // 1. 스테이지별 머물러있는 사람 수 세기
    for (int i = 0; i < stages.size(); i++) {
        count[stages[i]-1]++;
    }

    // 2. 확률 계산하기
    double temp;
    int n = stages.size();
    for (int i = 0; i < N; i++) {
        if (n == 0) temp = 0;
        else temp = (double)count[i] / n;
        n -= count[i];
        probability.push_back(temp);
    }

    // 3. answer 만들기
    double max;
    int max_idx;

    for (int j = 0; j < N; j++) {
        max = -1;
        for (int i = 0; i < N; i++) {
            if (probability[i] > max) {
                max = probability[i];
                max_idx = i + 1;
            }
        }
        probability[max_idx - 1] = -1;
        answer.push_back(max_idx);
    }

    return answer;
}