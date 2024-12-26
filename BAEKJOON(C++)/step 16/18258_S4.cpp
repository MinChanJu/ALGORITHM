#include <string>

namespace fio {
    const short BUFFER_SIZE = 1 << 14;

    char readBuffer[BUFFER_SIZE] {};
    short readIndex = BUFFER_SIZE;
    FILE* inputFile = stdin;

    inline void setInputFile(FILE* file) {
        inputFile = file;
    }

    inline char ReadChar() {
        if (readIndex == BUFFER_SIZE) {
            fread(readBuffer, 1, BUFFER_SIZE, inputFile);
            readIndex = 0;
        }
        return readBuffer[readIndex++];
    }

    inline int ReadInt() {
        int sum = 0;
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

    inline std::string ReadString() {
        std::string result;
        char now = ReadChar();

        while (now >= 33) {
            result += now;
            now = ReadChar();
        }

        return result;
    }

    char writeBuffer[BUFFER_SIZE] {};
    short writeIndex = 0;

    inline void Flush() {
        fwrite(writeBuffer, 1, writeIndex, stdout);
        writeIndex = 0;
    }

    inline void WriteString(std::string str) {
        for (int i = 0; i < str.length(); i++) {
            writeBuffer[writeIndex++] = str[i];
            if (writeIndex == BUFFER_SIZE) Flush();
        }
    }

    inline int GetSize(int n) {
        int size = 1;

        if (n < 0) n = -n;

        while (n >= 10) {
            size++;
            n /= 10;
        }
        return size;
    }

    inline void WriteInt(int n, std::string end) {
        int size = GetSize(n);

        if (n < 0) {
            writeBuffer[writeIndex++] = '-';
            n = -n;
        }

        if (writeIndex + size >= BUFFER_SIZE) Flush();

        for (int i = 0; i < size; i++) {
            writeBuffer[size+writeIndex-i-1] = n%10 + 48;
            n /= 10;
        }
        writeIndex += size;
        WriteString(end);
    }
}

using namespace fio;
using namespace std;

struct Node {
     Node* previous;
     Node* next;
     int data;
};

Node* front = NULL;
Node* back = NULL;
int nodeSize = 0;

Node* makeNode(int n) {
    Node* tmp = new Node();
    tmp->previous = NULL;
    tmp->next = NULL;
    tmp->data = n;
    return tmp;
}

void push(int x) {
    Node* tmp = makeNode(x);
    if (front == NULL) front = tmp;
    else {
        back->next = tmp;
        tmp->previous = back;
    }
    back = tmp;
    nodeSize++;
}

int pop() {
    int tmp = front->data;
    front = front->next;

    if (front != NULL) front->previous = NULL;
    if (front == NULL) back = NULL;
    nodeSize--;
    return tmp;
}

int main() {
    FILE* file = fopen("../input.txt", "r");
    if (!file) file = stdin;
    setInputFile(file);

    int N = ReadInt();

    while (N--) {
        string str = ReadString();
        if (str == "push") push(ReadInt());
        else if (str == "pop") {
            WriteInt(front == NULL ? -1 : front->data, "\n");
            if (front != NULL) pop();
        }
        else if (str == "size") WriteInt(nodeSize, "\n");
        else if (str == "empty") WriteInt(front == NULL ? 1 : 0, "\n");
        else if (str == "front") WriteInt(front == NULL ? -1 : front->data, "\n");
        else if (str == "back") WriteInt(front == NULL ? -1 : back->data, "\n");
    }

    Flush();

    return 0;
}