#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N, M;
    cin >> N >> M;

    int num[N];
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    int answer = num[0]+num[1]+num[2];
    
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                int cur = num[i]+num[j]+num[k];
                if (cur <= M) {
                    if (answer > M) answer = cur;
                    else if (M-cur < M-answer) answer = cur;
                }
            }
        }
    }
    
    output << answer << "\n";
    
    cout << output.str();
}