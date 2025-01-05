#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> count;
    count["null"] = 51;
    count["sfa"] = 21;
    count["gf"] = 324;
    count["sdaa"] = 129;
    count["aa"] = 14;

    if (count.count("msf") == 0) cout << "없음\n";

    for (auto pair : count) {
        cout << "Key : " << pair.first << "  Value : " << pair.second << "\n";
    }
}