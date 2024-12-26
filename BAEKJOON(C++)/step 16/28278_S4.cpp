#include <iostream>
#include <deque>

namespace fio {
    inline void SetInputFile(FILE* file);

    inline char ReadChar();
    inline long ReadInt();
    inline std::string ReadString();

    inline int GetSize(long nWrite);
    inline void Flush();
    inline void WriteChar(char cWrite);
    inline void WriteInt(long nWrite , std::string end = "");
    inline void WriteString(std::string strWrite, std::string end = "");


    const int BUFFER_SIZE = 1 << 14;

    char readBuffer[BUFFER_SIZE]{};
    int readIndex = BUFFER_SIZE;
    FILE* inputFile = stdin;
    
    char writeBuffer[BUFFER_SIZE]{};
    int writeIndex = 0;


    inline void SetInputFile(FILE* file) {
        inputFile = file;
    }


    inline char ReadChar() {
        if (readIndex == BUFFER_SIZE) {
            fread(readBuffer, 1, BUFFER_SIZE, inputFile);
            readIndex = 0;
        }
        return readBuffer[readIndex++];
    }

    inline long ReadInt() {
        long sum = 0;
        long align = 1;
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

    inline std::string ReadString() {
        char cRead = ReadChar();
        std::string result;

        while (cRead <= 32) cRead = ReadChar();

        while (cRead >= 33)
        {
            result += cRead;
            cRead = ReadChar();
        }

        return result;
    }


    inline int GetSize(long nWrite) {
        int nSize = 1;

        if (nWrite < 0) nWrite = -nWrite;

        while (nWrite >= 10) {
            nWrite /= 10;
            nSize++;
        }

        return nSize;
    }

    inline void Flush() {
        fwrite(writeBuffer, 1, writeIndex, stdout);
        writeIndex = 0;
    }

    inline void WriteChar(char cWrite) {
        if (writeIndex >= BUFFER_SIZE) Flush();

        writeBuffer[writeIndex++] = cWrite;
    }

    inline void WriteInt(long nWrite, std::string end) {
        int nSize = GetSize(nWrite);

        if (nSize + writeIndex >= BUFFER_SIZE) Flush();

        if (nWrite < 0) {
            nWrite = -nWrite;
            writeBuffer[writeIndex++] = '-';
        }

        int nNext = nSize + writeIndex;

        while (nSize--) {
            writeBuffer[nSize + writeIndex] = nWrite % 10 + 48;
            nWrite /= 10;
        }

        writeIndex = nNext;
        WriteString(end);
    }

    inline void WriteString(std::string strWrite, std::string end) {
        strWrite += end;
        int nIndex = 0;
        int nLength = strWrite.length();

        if (writeIndex + nLength + 1 >= BUFFER_SIZE) Flush();

        while (nLength--) writeBuffer[writeIndex++] = strWrite[nIndex++];
    }
}

using namespace fio;
using namespace std;

int main() {
    FILE* file = fopen("../input.txt", "r");
    if (!file) file = stdin;
    SetInputFile(file);

    deque<int> stack;

    int N = ReadInt();

    while (N--) {
        int p = ReadInt();
        if (p == 1) {
            int x = ReadInt();
            stack.push_back(x);
        } else if (p == 2) {
            if (stack.empty()) WriteString("-1\n");
            else {
                WriteInt(stack.back(), "\n");
                stack.pop_back();
            }
        } else if (p == 3) WriteInt(stack.size(), "\n");
        else if (p == 4) WriteInt(stack.empty(), "\n");
        else {
            if (stack.empty()) WriteString("-1\n");
            else WriteInt(stack.back(), "\n");
        }
    }

    Flush();
}