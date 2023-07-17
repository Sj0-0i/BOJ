#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Id {
    int order;
    int age;
    string name;
};


bool comp(const Id& p1, const Id& p2) {
    if (p1.age < p2.age) 
        return true;
    else if (p1.age == p2.age) 
        return p1.order < p2.order;
    else 
        return false;
    
}

int N;
vector<Id> v;

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        Id n;
        cin >> n.age >> n.name;
        n.order = i;
        v.push_back(n);
    }

    sort(v.begin(), v.end(), comp); // 나이순 정렬 -> 가입순 comp로 비교

    for (auto c : v) 
        cout << c.age << " " << c.name << "\n";
    
}