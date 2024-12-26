#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int max = -1, maxI = -1, maxJ =-1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int a;
            cin >> a;
            if (a > max) {
                max = a;
                maxI = i;
                maxJ = j;
            }
        }
    }
    
    cout << max << "\n";
    cout << maxI+1 << " " << maxJ+1 << "\n";
}