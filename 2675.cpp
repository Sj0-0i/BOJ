#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, n;
    string rep;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> n;
        cin >> rep;
        for (int j = 0; j < rep.length(); j++) {
            for (int k = 0; k < n; k++) {
                cout << rep[j];
            }
        }
        cout << "\n";
    }
    return 0;
}