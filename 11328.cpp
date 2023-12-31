#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int a[26] = {}; 
        string s1, s2;
        cin >> s1 >> s2;

        for (auto c : s1) a[c - 'a']++; // 첫 번째 문자열의 각 문자는 개수+1
        for (auto c : s2) a[c - 'a']--; // 두 번째 문자열의 각 문자는 개수-1

        // 0이 아닌 배열의 요소가 있을 경우, 개수가 다른 문자가 존재하므로 false
        bool isPos = true;
        
        for (int i : a) 
            if (i != 0) isPos = false;
        

        if (isPos) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}