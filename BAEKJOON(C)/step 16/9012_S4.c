#include <stdio.h>
#include <string.h>

int main()
{
  int T;
  scanf("%d", &T);

  while (T--)
  {
    char S[51];
    scanf("%s", S);

    short flag = 1;
    int sub = 0;
    for (int i = 0; i < strlen(S); i++)
    {
      if (S[i] == '(') sub++;
      else if (S[i] == ')' && sub > 0) sub--;
      else {
        flag = 0;
        break;
      }
    }

    if (sub != 0) flag = 0;
    
    if (flag) printf("YES\n");
    else printf("NO\n");
  }
  
}