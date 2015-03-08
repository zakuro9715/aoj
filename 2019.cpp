#include<iostream>
using namespace std;

int ways[11];

int main()
{
loop:
  int n, m;
  for(int i = 0; i < 11; i++)
    ways[i] = 0;
  cin >> n >> m;
  if(!n)
    return 0;
  for(int i = 0; i < n; i++)
  {
    int d, p;
    cin >> d >> p;
    ways[p] += d;
  }
  for(int i = 10; i > 0; i--)
  {
    if(ways[i] < m)
    {
      m -= ways[i];
      ways[i] = 0;
    }
    else
    {
      ways[i] -= m;
      m = 0;
    }
  }
  int ans = 0;
  for(int i = 1; i <= 10; i++)
    ans += ways[i] * i;
  cout << ans << endl;
  goto loop;
}
