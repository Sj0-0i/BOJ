#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int ans;

void Z(int y, int x, int size) {

    if (y == r && x == c) {
        cout << ans << '\n';
        return;
    }

    // r, c�� ���� ��и鿡 ����
    if (r < y + size && r >= y && c < x + size && c >= x) {
        // 1��и� Ž��
        Z(y, x, size / 2);
        // 2��и� Ž��
        Z(y, x + size / 2, size / 2);
        // 3��и� Ž��
        Z(y + size / 2, x, size / 2);
        // 4��и� Ž��
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else
        ans += size * size;

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;
    Z(0, 0, (1 << n));
    return 0;
}

// https://mygumi.tistory.com/284