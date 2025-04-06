#include <stdio.h>
#include <string.h>

int main()
{
  while (1)
  {
    char S[102];
    fgets(S, sizeof(S), stdin);
    if (S[0] == '.') break;

    int stack[101];
    int idx = 0;
    short flag = 1;
    for (int i = 0; i < strlen(S)-1; i++)
    {
      if (S[i] == '(') stack[idx++] = 1;
      if (S[i] == ')') {
        if (idx > 0 && stack[idx-1] == 1) idx--;
        else flag = 0;
      }
      if (S[i] == '[') stack[idx++] = 2;
      if (S[i] == ']') {
        if (idx > 0 && stack[idx-1] == 2) idx--;
        else flag = 0;
      }

      if (flag == 0) break;
    }

    if (idx != 0) flag = 0;

    if (flag) printf("yes\n");
    else printf("no\n");
  }
}