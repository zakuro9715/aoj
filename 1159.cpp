#include<iostream>
#include<cstring>
using namespace std;

int p[50];
int main()
{
loop:
  memset(p, 0, sizeof p);
  int m, n, t = 0, sm;
  cin >> n >> m;
  sm = m;
  if(!(m || n))
    return 0;
  while(1)
  {
    if(!m)
    {
     m = p[t];
     p[t] = 0;
    }
    else
    {
      p[t]++; 
      m--;
      if(m == 0 && p[t] == sm)
      {
        cout << t << endl;
        break;
      }
    }
    t = (t + 1) % n;
  }
  goto loop;
}
