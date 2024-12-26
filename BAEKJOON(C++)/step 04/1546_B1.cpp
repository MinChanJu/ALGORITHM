#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    double score[N];
    int max = 0;
    for (int i = 0; i < N; i++) {
        double num;
        cin >> num;
        score[i] = num;
        if (max < num) max = num;
    }

    double sum = 0;
    for (int i = 0; i < N; i++) {
        score[i] = (score[i]/max)*100;
        sum += score[i];
    }
    cout << sum/N << "\n";
    
}