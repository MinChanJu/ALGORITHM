#include <iostream>

using namespace std;

int main() {
    int reminder[42] = {0};

    for (int _ = 0; _ < 10; _++) {
        int i;
        cin >> i;
        reminder[i%42] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < 42; i++) {
        cnt += reminder[i];
    }

    cout << cnt << "\n";
    return 0;
}