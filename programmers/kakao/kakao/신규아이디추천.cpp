#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <cctype>

using namespace std;
string solution(string new_id);

int main(void) {
    string new_id = "....y..i.g.d....s.df....d..d.........";
    string answer = solution(new_id);
    cout << answer << endl;
}

string solution(string new_id) {
    string answer = "";
    
    
    // 조건 1: 대소문자
    //string temp = "";
    for (int i = 0; i < new_id.size(); i++) {
        if (isupper(new_id[i])) {
            /*temp = new_id[i] + 32;
            new_id.replace(i, 1, temp);*/
            new_id[i] = tolower(new_id[i]);
        }
    }
    //cout << "조건1 " << new_id << endl;

    // 조건 2: 허용되지 않은 문자 제거
    for (int i = 0; i < new_id.size(); i++) {
        if (isdigit(new_id[i]) || islower(new_id[i]) || (new_id[i] == '-') || (new_id[i] == '_') || (new_id[i] == '.'))
            continue;
        else {
            new_id.erase(i, 1);
            i -= 1;
        }
    }
    //cout << "조건2 " << new_id << endl;

    // 조건 3: 연속된 마침표 제거
    int count = 0;
    int count_copy = 0;
    char c = ' ';
    new_id.push_back('n');
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '.' && new_id[i] == c) {
            count++;
        }
        else {
            if (count != 0) {
                count_copy = count;
                for (int j = i - 1; j >= 0; j--) {
                    new_id.erase(j, 1);
                    count--;
                    if (count == 0) break;
                }
                i -= count_copy;
                count = 0;
            }
        }
        c = new_id[i];
    }
    new_id.pop_back();
    //cout << "조건3 " << new_id << endl;

    // 조건 4: 처음과 끝 마침표 제거
    if (!new_id.empty() && new_id.front() == '.')
        new_id.erase(0, 1);
    if (!new_id.empty() && new_id.back() == '.')
        new_id.pop_back();
    //cout << "조건4 " << new_id << endl;

    // 조건 5: 빈 문자열일 시 "a"
    if (new_id.empty())
        new_id.push_back('a');
    //cout << "조건5 " << new_id << endl;

    // 조건 6: 16자 이상이면 15자로 제한
    if (new_id.size() > 15)
        new_id.erase(15);

    if (new_id.back() == '.')
        new_id.pop_back();
    //cout << "조건6 " << new_id << endl;

    // 조건 7: 2자 이하면 3으로 반복
    if (new_id.size() < 3) {
        char c = new_id.back();
        while (new_id.size() < 3)
            new_id.push_back(c);
    }
    //cout << "조건7 " << new_id << endl;

    answer = new_id;
    return answer;
}