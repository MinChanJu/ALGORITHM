#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);

  int num[N], stack[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &num[i]);
  }
  
  int ni = 0, si = 0, cnt = 1, flag = 1;
  while (cnt <= N)
  {
    if (ni < N && num[ni] == cnt) {
      ni++;
      cnt++;
    }
    else if (0 < si && stack[si-1] == cnt) {
      si--;
      cnt++;
    }
    else if (ni < N) {
      stack[si++] = num[ni++];
    }
    else {
      flag = 0;
      break;
    }
  }
  
  if (flag) printf("Nice\n");
  else printf("Sad\n");
}