#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <cctype>

// �ٸ� ����� Ǯ�� ���� ����޾Ƽ� �ٽ� ǰ
// ������ ���� �Ǿ���

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
    // ����1 : ��ҹ��� ġȯ
    for (char& c : new_id)
        if (isupper(c)) c = tolower(c);

    // ����2 : �ҹ���, ����, -, _, . �����ϰ� ����
    for (char& c : new_id)
        if (isdigit(c) || islower(c) || c == '-' || c == '_' || c == '.')
            temp.push_back(c);
    new_id = temp;
    temp.clear();
    
    // ����3 : ���ӵ� ���� ����
    char b = ' ';
    for (char& c : new_id) {
        if (c == '.' && b == '.');
        else temp.push_back(c);
        b = c;
    }
    new_id = temp;
    temp.clear();

    // ����4 : ó���� �� ���� ����
    while (!new_id.empty() && new_id[0] == '.')
        new_id.erase(new_id.begin());
    while (!new_id.empty() && new_id.back() == '.')
        new_id.pop_back();

    // ����5 : �� ���ڿ��̸� 'a' ����
    if (new_id.empty()) new_id.push_back('a');

    //����6 : 16�� �̻��̸� 15�ڷ� �ڸ���
    if (new_id.size() > 15) new_id.erase(15);
    if (new_id.back() == '.') new_id.pop_back();

    // ����7 : ���̰� 2�� ���϶�� 
    while (new_id.size() < 3) new_id.push_back(new_id.back());

    answer = new_id;
    return answer;
}