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
    
    
    // ���� 1: ��ҹ���
    //string temp = "";
    for (int i = 0; i < new_id.size(); i++) {
        if (isupper(new_id[i])) {
            /*temp = new_id[i] + 32;
            new_id.replace(i, 1, temp);*/
            new_id[i] = tolower(new_id[i]);
        }
    }
    //cout << "����1 " << new_id << endl;

    // ���� 2: ������ ���� ���� ����
    for (int i = 0; i < new_id.size(); i++) {
        if (isdigit(new_id[i]) || islower(new_id[i]) || (new_id[i] == '-') || (new_id[i] == '_') || (new_id[i] == '.'))
            continue;
        else {
            new_id.erase(i, 1);
            i -= 1;
        }
    }
    //cout << "����2 " << new_id << endl;

    // ���� 3: ���ӵ� ��ħǥ ����
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
    //cout << "����3 " << new_id << endl;

    // ���� 4: ó���� �� ��ħǥ ����
    if (!new_id.empty() && new_id.front() == '.')
        new_id.erase(0, 1);
    if (!new_id.empty() && new_id.back() == '.')
        new_id.pop_back();
    //cout << "����4 " << new_id << endl;

    // ���� 5: �� ���ڿ��� �� "a"
    if (new_id.empty())
        new_id.push_back('a');
    //cout << "����5 " << new_id << endl;

    // ���� 6: 16�� �̻��̸� 15�ڷ� ����
    if (new_id.size() > 15)
        new_id.erase(15);

    if (new_id.back() == '.')
        new_id.pop_back();
    //cout << "����6 " << new_id << endl;

    // ���� 7: 2�� ���ϸ� 3���� �ݺ�
    if (new_id.size() < 3) {
        char c = new_id.back();
        while (new_id.size() < 3)
            new_id.push_back(c);
    }
    //cout << "����7 " << new_id << endl;

    answer = new_id;
    return answer;
}