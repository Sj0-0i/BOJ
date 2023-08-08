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

        for (auto c : s1) a[c - 'a']++; // ù ��° ���ڿ��� �� ���ڴ� ����+1
        for (auto c : s2) a[c - 'a']--; // �� ��° ���ڿ��� �� ���ڴ� ����-1

        // 0�� �ƴ� �迭�� ��Ұ� ���� ���, ������ �ٸ� ���ڰ� �����ϹǷ� false
        bool isPos = true;
        
        for (int i : a) 
            if (i != 0) isPos = false;
        

        if (isPos) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}