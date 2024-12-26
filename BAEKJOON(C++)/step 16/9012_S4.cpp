#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        bool success = true;
        int idx = 0;
        string input;
        cin >> input;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(') idx++;
            else if (input[i] == ')' && idx > 0) idx--;
            else success = false;
        }

        if (success && idx == 0) output << "YES" << "\n";
        else output << "NO" << "\n";
        
    }
    
    cout << output.str();
}

// #include <cstdio>
// #include <string>

// namespace fio {
//     const short BUFFER_SIZE = 1 << 14;

//     char readBuffer[BUFFER_SIZE] {};
//     short readIndex = BUFFER_SIZE;

//     char writeBuffer[BUFFER_SIZE] {};
//     short writeIndex = BUFFER_SIZE;

//     inline char ReadChar() {
//         if (readIndex == BUFFER_SIZE) {
//             fread(readBuffer, 1, BUFFER_SIZE, stdin);
//             readIndex = 0;
//         }
//         return readBuffer[readIndex++];
//     }

//     inline int ReadInt() {
//         int sum = 0;
//         int align = 1;
//         char now = ReadChar();

//         while (now <= 32) now = ReadChar();
//         if (now == '-') {
//             align = -1;
//             now = ReadChar();
//         }
//         while (48 <= now && now <= 57) {
//             sum = sum*10 + now-48;
//             now = ReadChar();
//         }

//         return sum*align;
//     }

//     inline std::string ReadString() {
//         std::string result = "";
//         char now = ReadChar();

//         while (now <= 32) now = ReadChar();
//         while (now > 32) {
//             result += now;
//             now = ReadChar();
//         }

//         return result;
//     }

//     inline void Flush() {
//         fwrite(writeBuffer, 1, writeIndex, stdout);
//         writeIndex = 0;
//     }

//     inline void WriteString(std::string strWrite) {
//         int length = strWrite.length();
//         int i = 0;
//         while (i < length) {
//             if (writeIndex >= BUFFER_SIZE) Flush();
//             writeBuffer[writeIndex++] = strWrite[i++];
//         }
//     }
// }

// using namespace fio;
// using namespace std;

// int main() {
//     int T = ReadInt();
//     for (int i = 0; i < T; i++) {
//         bool success = true;
//         short idx = 0;
//         string str = ReadString();
//         for (int i = 0; i < str.length(); i++) {
//             if (str[i] == '(') idx++;
//             else if (str[i] == ')' && idx > 0) idx--;
//             else success = false;
//         }

//         if (success && idx == 0) WriteString("YES\n");
//         else WriteString("NO\n");
//     }
    
//     Flush();
// }