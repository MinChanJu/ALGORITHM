#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int index = 0, num[9];
    char ch;
    while ((ch = cin.get()) > 40) num[index++] = ch-48;

    sort(num, num+index, greater<int>());
    
    for (int i = 0; i < index; i++) output << num[i];

    cout << output.str() << "\n";
}