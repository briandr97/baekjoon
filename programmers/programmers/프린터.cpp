#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int solution(vector<int> priorities, int location);

int main(void) {
    vector<int> priorities = { 2,1,3,2 };
    int location = 2;
    int answer = solution(priorities, location);
    printf("%d", answer);
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> sorted = priorities;
    vector<bool> prioBool;
    prioBool.assign(priorities.size(), false);

    sort(sorted.begin(), sorted.end(), greater<int>());

    int count = 0;
    int size = priorities.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (priorities[j] == sorted[count]) {
                if (prioBool[j] == false) {
                    prioBool[j] = true;
                    answer++;
                    count++;
                }
            }
            if (prioBool[location] == true) {
                return answer;
            }
        }
    }
    //return answer;
}