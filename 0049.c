#include<stdio.h>

int _, a, b, c, o;
char s[2];
int main(void)
{
  while(~scanf("%d,%s", &_, s))
  {
    if(s[1] == 'B')
      c++;
    else if(s[0] == 'A')
      a++;
    else if(s[0] == 'B')
      b++;
    else
      o++;
  }
  printf("%d\n%d\n%d\n%d\n", a, b, c, o);
  return 0;
}
