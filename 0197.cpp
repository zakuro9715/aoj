#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  int x, y, tmp;
  while(true)
  {
    cin >> x >> y;
    if(!x && !y)
      break;
    if(x < y)
    {
      tmp = y;
      y = x; 
      x = tmp;
    }
    int i;
    for(i = 0; y; i++)
    {
      x = x % y;
      tmp = y;
      y = x;
      x = tmp;
    }
    printf("%d %d\n", x, i);
  }
}
