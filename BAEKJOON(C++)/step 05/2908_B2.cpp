#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    cin >> A >> B;

    A = A/100 + A/10%10*10 + A%10*100;
    B = B/100 + B/10%10*10 + B%10*100;
    
    cout << (A > B ? A : B) << "\n";
}