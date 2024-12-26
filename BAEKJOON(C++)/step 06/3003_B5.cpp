#include <iostream>

using namespace std;

int main() {
    int chess[] = {1, 1, 2, 2, 2, 8};
    for (int i = 0; i < 6; i++) {
        int c;
        cin >> c;
        chess[i] -= c;
    }
    
    for (int i = 0; i < 6; i++) {
        cout << chess[i] << " ";
    }
    cout << "\n";
}