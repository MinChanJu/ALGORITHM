#include <cstdio>

namespace fio {
    inline char ReadChar();
    inline int ReadInt();


    const short BUFFER_SIZE = 1 << 14;

    char readBuffer[BUFFER_SIZE]{};
    int readIndex = BUFFER_SIZE;


    inline char ReadChar() {
        if (readIndex == BUFFER_SIZE) {
            fread(readBuffer, 1, BUFFER_SIZE, stdin);
            readIndex = 0;
        }
        return readBuffer[readIndex++];
    }

    inline int ReadInt() {
        int sum = 0;
        int align = 1;
        char now = ReadChar();

        while (now == 10 || now == 32) now = ReadChar();
        if (now == '-') {
            align = -1;
            now = ReadChar();
        }
        while (48 <= now && now <= 57) {
            sum = sum*10 + now-48;
            now = ReadChar();
        }

        return align*sum;
    }
}

using namespace fio;

int main() {
    int K = ReadInt();

    int stack[K];
    int idx = 0;
    while (K--) {
        int x = ReadInt();
        if (x == 0) idx--;
        else stack[idx++] = x;
    }
    
    for (int i = 0; i < idx; i++) K += stack[i];
    
    printf("%d\n", K+1);
}