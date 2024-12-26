#include <cstdio>

namespace fio {
    const short BUFFER_SIZE = 1 << 14;

    char readBuffer[BUFFER_SIZE];
    short readIndex = BUFFER_SIZE;

    inline char ReadChar() {
        if (readIndex == BUFFER_SIZE) {
            fread(readBuffer, 1, BUFFER_SIZE, stdin);
            readIndex = 0;
        }
        return readBuffer[readIndex++];
    }

    inline short ReadInt() {
        short sum = 0;
        bool align = true;
        char now = ReadChar();

        while (now <= 32) now = ReadChar();
        if (now == '-') {
            align = false;
            now = ReadChar();
        }
        while (48 <= now && now <= 57) {
            sum = sum*10 + now-48;
            now = ReadChar();
        }

        return align ? sum : -sum;
    }

    char writeBuffer[BUFFER_SIZE];
    short writeIndex = 0;

    inline void Flush() {
        fwrite(writeBuffer, 1, writeIndex, stdout);
        writeIndex = 0;
    }

    inline void WriteString(const char* str) {
        while (*str != '\0') {
            writeBuffer[writeIndex++] = *str++;
            if (writeIndex == BUFFER_SIZE) Flush();
        }
    }
}

using namespace fio;

int main() {
    short N = ReadInt();
    short num[N];
    short idx = 0;
    for (idx = 0; idx < N; idx++) num[idx] = ReadInt();
    idx = 0;

    short box[N];
    short boxIdx = 0;

    short cur = 1;
    while (cur <= N) {
        if (num[idx] == cur) idx++;
        else if (boxIdx > 0 && box[boxIdx-1] == cur) boxIdx--;
        else {
            if (idx >= N) break;
            box[boxIdx++] = num[idx++];
            cur--;
        }
        cur++;
    }

    if (cur <= N) WriteString("Sad\n");
    else WriteString("Nice\n");

    Flush();
}