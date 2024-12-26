#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct User {
    int id;
    int age;
    string name;
} User;

bool compare(User a, User b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;
    
    User users[N];
    for (int i = 0; i < N; i++) {
        users[i].id = i;
        cin >> users[i].age;
        cin >> users[i].name;
    }

    sort(users, users+N, compare);
    
    for (int i = 0; i < N; i++) {
        output << users[i].age << " " << users[i].name << "\n";
    }

    cout << output.str();
}

bool compare(User a, User b) {
    if (a.age == b.age) return a.id < b.id;
    return a.age < b.age;
}