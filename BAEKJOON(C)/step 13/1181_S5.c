#include <stdio.h>
#include <string.h>

typedef struct string
{
  char data[51];
} string;

void mergeSort(string str[], int s, int e);
int compare(string a, string b);

int main()
{
  int N;
  scanf("%d", &N);

  string str[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%s", &str[i].data);
  }
  
  mergeSort(str, 0, N-1);
  string s;

  for (int i = 0; i < N; i++)
  {
    if (strcmp(s.data, str[i].data) ) {
      printf("%s\n", str[i].data);
    }
    s = str[i];
  }
}

void mergeSort(string str[], int s, int e)
{
  if (s == e) return;
  int mid = (s+e)/2;
  
  mergeSort(str, s, mid);
  mergeSort(str, mid+1, e);

  string new[e-s+1];
  int si = s, ei = mid+1, ni = 0;

  while (si <= mid && ei <= e)
  {
    if (compare(str[si], str[ei]) < 0) {
      new[ni++] = str[si++];
    } else {
      new[ni++] = str[ei++];
    }
  }

  while (si <= mid) new[ni++] = str[si++];
  while (ei <= e) new[ni++] = str[ei++];
  
  for (int i = 0; i <= e-s; i++)
  {
    str[s+i] = new[i];
  }
}

int compare(string a, string b)
{
  if (strlen(a.data) != strlen(b.data)) return strlen(a.data)-strlen(b.data);
  return strcmp(a.data, b.data);
}