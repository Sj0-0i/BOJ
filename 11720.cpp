#include <iostream>
using namespace std;

int main() {
    int n;
    int sum = 0;
    char num;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        sum += num - 48;// char형으로 받았으므로 0의 아스키코드 값 48 빼주기
    }
    cout << sum << "\n";

    return 0;
}