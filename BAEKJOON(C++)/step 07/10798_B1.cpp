#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char A[5][15];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 15; j++) {
            A[i][j] = 10;
        }
    }
    

    stringstream output;

    for (int i = 0; i < 5; i++) {
        int index = 0;
        char ch;
        while ((ch = cin.get()) != 10) {
            A[i][index] = ch;
            index++;
        }
    }

    for (int j = 0; j < 15; j++) {
       for (int i = 0; i < 5; i++) {
            if (A[i][j] != 10) output << A[i][j];
       }
    }

    cout << output.str() << "\n";
}