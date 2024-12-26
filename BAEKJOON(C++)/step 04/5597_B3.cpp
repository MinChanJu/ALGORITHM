#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int student[31] = {0};
    for (int _ = 0; _ < 28; _++) {
        int a;
        cin >> a;
        student[a] = 1;
    }

    for (int i = 1; i <= 30; i++) {
        if (student[i] == 0) cout << i << "\n";
    }
    
}