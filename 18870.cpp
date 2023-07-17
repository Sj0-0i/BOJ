#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int N;
vector<int> vec;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    // �ߺ��� ������� �ʰ� �ش� ������ ���� ���� �����ؾ� ��.
    while (N--) {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    // set�� �ߺ��� �����ϸ鼭 sort�� ��
    set<int> s(vec.begin(), vec.end());
    vector<int> v(s.begin(), s.end());

    for (int n : vec) {
        // find �Լ��� ���⵵ = O(N) -> �ð� �ʰ�
        auto it = lower_bound(v.begin(), v.end(), n);
        cout << it - v.begin() << " ";
    }
}