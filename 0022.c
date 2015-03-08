#include<stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int main()
{
loop:;
  int n, m, i, mem = -1 << 30, ans = -1 << 30;
  scanf("%d", &n);
  if(!n)
    return n;

  for(i = 0; i < n; i++)
  {
    scanf("%d", &m);
    mem = max(mem + m, m);
    ans = max(ans, mem);
  }
  printf("%d\n", ans);
  goto loop;
}
