#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    long n;
    cin >> n;

    // for (int i = 1; i <= n - 2; i++) {
    //     cnt += ((n-i)*(n-i-1))/2;
    // }
    // output << cnt << "\n3\n";

    output << n*(n-1)*(n-2)/6 << "\n3\n";

    cout << output.str();
}