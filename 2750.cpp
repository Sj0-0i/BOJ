#include <iostream>
using namespace std;

int main() {
    int N, temp;
    int arr[N];

    cin >> N;
 
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int j = 0; j < N - 1; j++)
        for (int k = j + 1; k < N; k++) {
            if (arr[j] > arr[k]) {
                temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
            }
        }

    for (int l = 0; l < N; l++) {
        if (l + 1 < N && arr[l] == arr[l + 1])
            continue;
        cout << arr[l] << "\n";
    }
}