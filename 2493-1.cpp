#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

    stack<pair<int, int> > s;  // index, height
    int n, height;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> height;

        while (!s.empty()) {
            // ����ž �߰����� ��
            if (height < s.top().second) { 
                cout << s.top().first << " ";
                break;
            }
            // ����ž ã�� ������ ��� pop
            s.pop();
        }
        // ����ž�� ���ٸ�
        if (s.empty()) {
            cout << 0 << " ";
        }
        // ���� ���̸� ���ÿ� Ǫ��
        s.push(make_pair(i + 1, height));
    }

	return 0;
}