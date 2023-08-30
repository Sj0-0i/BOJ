#include <bits/stdc++.h>
using namespace std;

int l, c;
int arr[17];
char s[17];
bool isused[17];

bool aeiou(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void func(int k, int st) {
    if (k == l) {
        bool chk = false;
        int cnt1 = 0; // 모음 개수
        int cnt2 = 0; // 자음 개수

        for (int i = 0; i < l; i++) {
            if (aeiou(s[arr[i]])) 
                cnt1++;
            else cnt2++;
        }
        if (cnt1 >= 1 && cnt2 >= 2) 
            chk = true;

        if (chk) {
            for (int i = 0; i < l; i++)
                cout << s[arr[i]];
            cout << "\n";
        }
    }

    for (int i = st; i < c; i++) {
        arr[k] = i;
        func(k + 1, i + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;

    for (int i = 0; i < c; i++) 
        cin >> s[i];
    sort(s, s + c);
    func(0, 0);

    return 0;
}