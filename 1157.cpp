#include <iostream> 
using namespace std;

int alpha[26], cnt = 0;
string input;

//아스키코드 : 대문자 65~90, 소문자 97~122 

int main() {
    int max = 0, max_ind = 0;

    cin >> input;

    // 빈도수 
    for (int i = 0; i < input.length(); i++) {
        if (input[i] < 97) alpha[input[i] - 65]++; // 대문자 
        else alpha[input[i] - 97]++; // 소문자 
    }

    for (int i = 0; i < 26; i++) {
        if (max < alpha[i]) {
            max = alpha[i];
            max_ind = i;
        }
    }

    // 가장 많이 사용된 알파벳이 여러 개인지 확인
    for (int i = 0; i < 26; i++) {
        if (max == alpha[i]) cnt++;
    }

    // 여러 개라면 ?, 아니면 대문자로 출력 
    if (cnt > 1) cout << "?";
    else cout << (char)(max_indx + 65);
}