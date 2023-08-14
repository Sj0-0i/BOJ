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
			if (s[i - 1] == '(') { // 레이저
				st.pop(); // '(' 삭제
				ans += st.size(); // 막대의 개수 추가
			}
			else { // 쇠막대의 끝
				st.pop(); // 막대 개수 1 감소
				ans += 1; // 막대 1개 추가됨
			}
		}
	}

	cout << ans;
	return 0;
}

// https://chan9.tistory.com/39