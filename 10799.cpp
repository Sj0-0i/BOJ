#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	stack<char> st;
	int ans = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			st.push(s[i]);
		else {
			if (s[i - 1] == '(') { // ������
				st.pop(); // '(' ����
				ans += st.size(); // ������ ���� �߰�
			}
			else { // �踷���� ��
				st.pop(); // ���� ���� 1 ����
				ans += 1; // ���� 1�� �߰���
			}
		}
	}

	cout << ans;
	return 0;
}

// https://chan9.tistory.com/39