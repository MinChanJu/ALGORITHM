#include <string>
#include <map>

using namespace std;

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

    inline long ReadInt() {
        long sum = 0;
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

    inline string ReadString() {
        string str = "";

        char now = ReadChar();

        while (0 <= now && now <= 32) now = ReadChar();
        while (now < 0 || now > 32) {
            str += now;
            now = ReadChar();
        }

        return str;
    }

    char writeBuffer[BUFFER_SIZE] {};
    short writeIndex = 0;

    inline void Flush() {
        fwrite(writeBuffer, 1, writeIndex, stdout);
        writeIndex = 0;
    }

    inline long GetSize(long n) {
        long size = 1;

        if (n < 0) n = -n;
        while (n >= 10) {
            size *= 10;
            n /= 10;
        }

        return size;
    }

    inline void WriteChar(char ch) {
        writeBuffer[writeIndex++] = ch;
        if (writeIndex >= BUFFER_SIZE) Flush();
    }

    inline void WriteInt(long n) {
        long size = GetSize(n);
        if (n < 0) {
            writeBuffer[writeIndex++] = '-';
            if (writeIndex >= BUFFER_SIZE) Flush();
            n = -n;
        }

        while (size) {
            writeBuffer[writeIndex++] = n/size + 48;
            if (writeIndex >= BUFFER_SIZE) Flush();
            n %= size;
            size /= 10;
        }

        WriteChar('\n');
    } 
}

using namespace fio;

int main() {
    int N = ReadInt();

    int cnt = 0;
    map<string, int> greet;
    while (N--) {
        string str = ReadString();
        if (str == "ENTER") greet.clear();
        else if (greet[str] == 0) {
            cnt++;
            greet[str] = 1;
        }
    }
    
    WriteInt(cnt);

    Flush();
}