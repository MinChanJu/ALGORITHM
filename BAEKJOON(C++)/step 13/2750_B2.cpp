#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void selectionSort(int array[], int size);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;

    int num[N];

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    sort(num, num+N);

    for (int i = 0; i < N; i++) {
        output << num[i] << "\n";
    }

    cout << output.str();
}