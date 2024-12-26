#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int num[5], sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> num[i];
        sum += num[i];
    }

    sort(num, num+5);
    
    output << sum/5 << "\n" << num[2] << "\n";

    cout << output.str();
}