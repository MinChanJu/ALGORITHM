#include <iostream>
#include <sstream>

using namespace std;

long gcd(long a, long b);
long lcm(long a, long b);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    long A, B, C, D;
    cin >> A >> B >> C >> D;
    long LCM = lcm(B,D);
    long x = (A*LCM/B) + (C*LCM/D);
    long GCD = gcd(x, LCM);
    output << x/GCD << " " << LCM/GCD << "\n";
    
    cout << output.str();
}

long gcd(long a, long b) {
    if (a == 0) return b;
    else if (b == 0) return a;
    else if (a > b) return gcd(a%b, b);
    else return gcd(a, b%a);
}

long lcm(long a, long b) {
    return a*b/gcd(a, b);
}