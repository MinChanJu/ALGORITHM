#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> array;
    array.push_back(12);
    array.push_back(2);
    array.push_back(67);
    array.push_back(23);

    for (int x : array) cout << x << " ";
    cout << "\n";

    cout << "size : " << array.size() << "\n";
    cout << "array[3] : " << array[3] << "\n";
    cout << "empty : " << array.empty() << "\n";
    cout << "front : " << array.front() << "\n";
    cout << "back : " << array.back() << "\n";
    cout << "size : " << array.size() << "\n";

    array.erase(array.begin()+0);
    for (int x : array) cout << x << " ";
    cout << "\n";
    array.pop_back();
    for (int x : array) cout << x << " ";
    cout << "\n";
    array.erase(array.begin()+1);
    for (int x : array) cout << x << " ";
    cout << "\n";

    array.clear();
    cout << "clear + empty : " << array.empty() << "\n";

    vector<int> arrayInit = {2,4,1};
    for (int x : arrayInit) cout << x << " ";
    cout << "\n";
}