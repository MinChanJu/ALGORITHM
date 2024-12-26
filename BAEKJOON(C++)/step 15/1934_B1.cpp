#include <iostream>
#include <sstream>

using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        output << lcm(A, B) << "\n";
    }
    
    cout << output.str();
}

int gcd(int a, int b) {
    if (a == 0) return b;
    else if (b == 0) return a;
    else if (a > b) return gcd(a%b, b);
    else return gcd(a, b%a);
}

int lcm(int a, int b) {
    int GCD = gcd(a, b);
    return a*b/GCD;
}