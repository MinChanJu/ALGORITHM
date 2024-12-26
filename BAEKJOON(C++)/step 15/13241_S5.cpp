#include <iostream>
#include <sstream>

using namespace std;

long long int gcd(long long int a, long long int b);
long long int lcm(long long int a, long long int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    long long int A, B;
    cin >> A >> B;
    output << lcm(A, B) << "\n";
    
    cout << output.str();
}

long long int gcd(long long int a, long long int b) {
    if (a == 0) return b;
    else if (b == 0) return a;
    else if (a > b) return gcd(a%b, b);
    else return gcd(a, b%a);
}

long long int lcm(long long int a, long long int b) {
    int GCD = gcd(a, b);
    return a*b/GCD;
}