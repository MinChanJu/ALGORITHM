#include <cstdio>
#include <cstdint>

namespace fio {
    const short BUFFER_SIZE = 1 << 14;

    char readBuffer[BUFFER_SIZE] {};
    short readIndex = BUFFER_SIZE;

    inline char ReadChar() {
        if (readIndex == BUFFER_SIZE) {
            fread(readBuffer, 1, BUFFER_SIZE, stdin);
            readIndex = 0;
        }
        return readBuffer[readIndex++];
    }

    char writeBuffer[BUFFER_SIZE] {};
    short writeIndex = 0;

    inline void Flush() {
        fwrite(writeBuffer, 1, writeIndex, stdout);
        writeIndex = 0;
    }

    inline void WriteString(const char* str) {
        while (*str != '\0') {
            writeBuffer[writeIndex++] = *str++;
            if (writeIndex >= BUFFER_SIZE) Flush();
        }
    }
}

using namespace fio;

int main() {
    char now = ReadChar();

    bool success = true;
    bool start = true;
    bool num[50];
    short idx = 0;

    while (!(start && now == '.')) {
        if (now == '.') {
            if (idx == 0 && success) WriteString("yes\n");
            else WriteString("no\n");

            success = true;
            start = true;
            idx = 0;
            now = ReadChar();
        } else {
            if (now == '(' && idx < 50 ) num[idx++] = 1;
            else if (now == '[' && idx < 50) num[idx++] = 0;
            else if (now == ')' && idx > 0 && num[idx-1] == 1) idx--; 
            else if (now == ']' && idx > 0 && num[idx-1] == 0) idx--; 
            else if (now == '('|| now == '[' || now == ')' || now == ']') success = false;
            
            start = false;
        }

        now = ReadChar();
    }

    Flush();
}