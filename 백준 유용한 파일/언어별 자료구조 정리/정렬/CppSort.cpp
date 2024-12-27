#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline void printOneVectorInt(vector<int> vec);
inline void printTwoVectorInt(vector<vector<int>> twoVec);
inline void printOneVectorStr(vector<string> oneVecStr);
inline void printTwoVectorStr(vector<vector<string>> twoVecStr);

bool compareOneInt(const int a, const int b);
bool compareTwoInt(const vector<int> a, const vector<int> b);
bool compareOneStr(const string a, const string b);
bool compareTwoStr(const vector<string> a, const vector<string> b);

int main() {
    // 정수
    vector<int> oneVecInt;
    vector<vector<int>> twoVecInt;

    // 기본 정렬 (정수)
    cout << "\n\n기본 정렬 (정수)\n\n";

    oneVecInt = { 6, 3, 5, 2, 7, 9, 1, 4, 8 };

    printOneVectorInt(oneVecInt);
    sort(oneVecInt.begin(), oneVecInt.end());
    printOneVectorInt(oneVecInt);
    
    twoVecInt = { { 1, 4, 6 }, { 8, 3, 2 }, { 2, 5, 9 } };
    
    printTwoVectorInt(twoVecInt);
    sort(twoVecInt.begin(), twoVecInt.end());
    printTwoVectorInt(twoVecInt);

    // 사용자 정의 정렬 (정수)
    cout << "\n\n사용자 정의 정렬 (정수)\n\n";

    oneVecInt = { 6, 3, 5, 2, 7, 9, 1, 4, 8 };

    printOneVectorInt(oneVecInt);
    sort(oneVecInt.begin(), oneVecInt.end(), compareOneInt);
    printOneVectorInt(oneVecInt);
    
    twoVecInt = { { 1, 4, 6 }, { 8, 3, 2 }, { 2, 5, 9 } };
    
    printTwoVectorInt(twoVecInt);
    sort(twoVecInt.begin(), twoVecInt.end(), compareTwoInt);
    printTwoVectorInt(twoVecInt);




    // 문자열
    vector<string> oneVecStr;
    vector<vector<string>> twoVecStr;

    // 기본 정렬 (문자열)
    cout << "\n\n기본 정렬 (문자열)\n\n";

    oneVecStr = { "test", "als", "민찬", "djg", "car", "asfnd", "asfldnvladsd" };

    printOneVectorStr(oneVecStr);
    sort(oneVecStr.begin(), oneVecStr.end());
    printOneVectorStr(oneVecStr);
    
    twoVecStr = { { "test", "als", "민찬" }, { "car", "dog", "big" }, { "hor", "sdk", "fgg" } };
    
    printTwoVectorStr(twoVecStr);
    sort(twoVecStr.begin(), twoVecStr.end());
    printTwoVectorStr(twoVecStr);

    // 사용자 정의 정렬 (정수)
    cout << "\n\n사용자 정의 정렬 (정수)\n\n";

    oneVecStr = { "test", "als", "민찬", "djg", "car", "asfnd", "asfldnvladsd" };

    printOneVectorStr(oneVecStr);
    sort(oneVecStr.begin(), oneVecStr.end(), compareOneStr);
    printOneVectorStr(oneVecStr);
    
    twoVecStr = { { "test", "als", "민찬" }, { "car", "dog", "big" }, { "hor", "sdk", "fgg" } };
    
    printTwoVectorStr(twoVecStr);
    sort(twoVecStr.begin(), twoVecStr.end(), compareTwoStr);
    printTwoVectorStr(twoVecStr);
}

bool compareOneInt(const int a, const int b) {
    return a > b;
}

bool compareTwoInt(const vector<int> a, const vector<int> b) {
    return a[2] > b[2];
}

bool compareOneStr(const string a, const string b) {
    return a.length() < b.length();
}

bool compareTwoStr(const vector<string> a, const vector<string> b) {
    return a[1] > b[1];
}

inline void printOneVectorInt(vector<int> oneVecInt) {
    for (int i : oneVecInt) {
        cout << i << " ";
    }
    cout << "\n";
}

inline void printTwoVectorInt(vector<vector<int>> twoVecInt) {
    cout << "-------------------------\n";
    for (vector<int> row : twoVecInt) {
        for (int i : row) {
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "-------------------------\n";
}

inline void printOneVectorStr(vector<string> oneVecStr) {
    for (string str : oneVecStr) {
        cout << str << " ";
    }
    cout << "\n";
}

inline void printTwoVectorStr(vector<vector<string>> twoVecStr) {
    cout << "-------------------------\n";
    for (vector<string> row : twoVecStr) {
        for (string str : row) {
            cout << str << " ";
        }
        cout << "\n";
    }
    cout << "-------------------------\n";
}