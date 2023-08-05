#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int result, input;
    string res = "DCBAE";

    // 1이 4개면 E = res[4]
    // 1이 0개면 D = res[0]
    for (int r = 0; r < 3; r++) {
        result = 0;
        for (int c = 0; c < 4; c++) {
            cin >> input;
            result += input;
        }
        cout << res[result] << '\n';
    }
}