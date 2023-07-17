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

    // 중복을 허용하지 않고 해당 값보다 작은 값을 선택해야 함.
    while (N--) {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    // set은 중복을 제거하면서 sort도 함
    set<int> s(vec.begin(), vec.end());
    vector<int> v(s.begin(), s.end());

    for (int n : vec) {
        // find 함수의 복잡도 = O(N) -> 시간 초과
        auto it = lower_bound(v.begin(), v.end(), n);
        cout << it - v.begin() << " ";
    }
}