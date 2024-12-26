#include <iostream>

using namespace std;

int main() {
    int A,B,C;
    cin >> A;
    cin >> B;
    cin >> C;
    cout << (A+B)%C << endl << ((A%C) + (B%C))%C << endl;
    cout << (A*B)%C << endl << ((A%C) * (B%C))%C << endl;
    return 0;
}