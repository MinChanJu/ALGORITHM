#include <stdio.h>
#include <string.h>

int isPalindrome(char *S);

int main()
{
  int T;
  scanf("%d", &T);

  char S[1001];
  while (T--)
  {
    scanf("%s", S);
    int cnt = isPalindrome(S);
    if (cnt < 0) printf("%d %d\n", 0, -cnt);
    else printf("%d %d\n", 1, cnt);
  }
  
}

int isPalindrome(char *S)
{
  int N = strlen(S), cnt = 0;
  for (int i = 0; i <= N/2; i++)
  {
    cnt++;
    if (S[i] != S[N - i - 1])
      return -cnt;
  }
  return cnt;
}