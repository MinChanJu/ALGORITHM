#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
inline void printOneVector(vector<T> oneVec);
template <typename T>
inline void printTwoVector(vector<vector<T>> twoVecInt);

int main() {
    // 정수
    cout << "정수\n-------------------------\n";

    vector<int> oneVecInt = { 6, 3, 5, 2, 7, 9, 1, 4, 8 };

    printOneVector(oneVecInt);
    sort(oneVecInt.begin(), oneVecInt.end());
    printOneVector(oneVecInt);
    
    vector<vector<int>> twoVecInt = { { 1, 4, 6 }, { 8, 3, 2 }, { 2, 5, 9 } };
    
    printTwoVector(twoVecInt);
    sort(twoVecInt.begin(), twoVecInt.end(), [](vector<int> a, vector<int> b) -> bool {return a[1] < b[1];});
    printTwoVector(twoVecInt);


    // 문자열
    cout << "\n문자열\n-------------------------\n";

    vector<string> oneVecStr = { "test", "als", "민찬", "djg", "car", "asfnd", "asfldnvladsd" };

    printOneVector(oneVecStr);
    sort(oneVecStr.begin(), oneVecStr.end(), [](string a, string b) -> bool {return a.length() < b.length();});
    printOneVector(oneVecStr);
    
    vector<vector<string>> twoVecStr = { { "test", "alsaads", "민찬" }, { "car", "dogsdf", "big" }, { "hor", "sdka", "fgg" } };
    
    printTwoVector(twoVecStr);
    sort(twoVecStr.begin(), twoVecStr.end(), [](vector<string> a, vector<string> b) -> bool {
        if (a[1].length() == b[1].length()) return a[1] < b[1];
        return a[1].length() < b[1].length();
    });
    printTwoVector(twoVecStr);
}

template <typename T>
inline void printOneVector(vector<T> oneVec) {
    for (T element : oneVec) cout << element << " ";
    cout << "\n-------------------------\n";
}

template <typename T>
inline void printTwoVector(vector<vector<T>> twoVecInt) {
    for (vector<T> row : twoVecInt) {
        for (T element : row) {
            cout << element << " ";
        }
        cout << "\n";
    }
    cout << "-------------------------\n";
}