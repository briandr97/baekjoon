#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <cctype>

// 다른 사람의 풀이 보고 감명받아서 다시 품
// 도움이 많이 되었음

using namespace std;
string solution(string new_id);

int main(void) {
    string new_id = "abcdefghijklmn.p";
    string answer = solution(new_id);
    cout << answer << endl;
}

string solution(string new_id) {
    string answer = "";
    string temp = "";
    // 조건1 : 대소문자 치환
    for (char& c : new_id)
        if (isupper(c)) c = tolower(c);

    // 조건2 : 소문자, 숫자, -, _, . 제외하고 삭제
    for (char& c : new_id)
        if (isdigit(c) || islower(c) || c == '-' || c == '_' || c == '.')
            temp.push_back(c);
    new_id = temp;
    temp.clear();
    
    // 조건3 : 연속된 온점 삭제
    char b = ' ';
    for (char& c : new_id) {
        if (c == '.' && b == '.');
        else temp.push_back(c);
        b = c;
    }
    new_id = temp;
    temp.clear();

    // 조건4 : 처음과 끝 온점 제거
    while (!new_id.empty() && new_id[0] == '.')
        new_id.erase(new_id.begin());
    while (!new_id.empty() && new_id.back() == '.')
        new_id.pop_back();

    // 조건5 : 빈 문자열이면 'a' 대입
    if (new_id.empty()) new_id.push_back('a');

    //조건6 : 16자 이상이면 15자로 자르기
    if (new_id.size() > 15) new_id.erase(15);
    if (new_id.back() == '.') new_id.pop_back();

    // 조건7 : 길이가 2자 이하라면 
    while (new_id.size() < 3) new_id.push_back(new_id.back());

    answer = new_id;
    return answer;
}