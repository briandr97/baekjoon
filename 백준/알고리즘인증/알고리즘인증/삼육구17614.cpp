#include <iostream>
using namespace std;

int main()
{
    int n;
    int d = 10;
    int count = 0;
    int temp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        temp = i;
        while (temp > 0) {
            if (temp % d == 3 || temp % d == 6 || temp % d == 9) {
                count++;
            }
            temp /= 10;
        }
    }
    cout << count << endl;
    return 0;
}
