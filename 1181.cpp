#include <iostream> 
#include <algorithm> 
using namespace std;

int cmp(string a, string b) {
    // 1. ���̰� ���ٸ�, ���������� 
    if (a.length() == b.length())
        return a < b;
    // 2. ���̰� �ٸ��ٸ�, ª�� ������ 
    else
        return a.length() < b.length();
}
// ������ ũ�⶧���� ���������� ���� 
string word[20000];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> word[i];

    sort(word, word + N, cmp);

    for (int i = 0; i < N; i++) {
        // �ߺ��� ��� �ѹ��� ��� 
        if (word[i] == word[i - 1])
            continue;
        cout << word[i] << "\n";
    }

    return 0;
}