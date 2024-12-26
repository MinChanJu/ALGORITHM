#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N, M;
    cin >> N >> M;

    string num[N+1];
    map<string, int> S;

    string name;
    for (int i = 0; i < N; i++) {
        cin >> name;
        S[name] = i+1;
        num[i+1] = name;
    }

    for (int i = 0; i < M; i++) {
        cin >> name;
        if (name[0] < 58) output << num[stoi(name)] << "\n";
        else output << S[name] << "\n";
    }
    
    
    cout << output.str();
}