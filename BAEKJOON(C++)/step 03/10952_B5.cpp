#include <iostream>

using namespace std;

int main() {
    while (1) {
        int A, B;
        cin >> A >> B;
        
        if (A+B == 0) break;

        cout << A+B << "\n";
    }
    
    return 0;
}