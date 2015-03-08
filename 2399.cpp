#include<iostream>
using namespace std;

bool mem[101][100];

int main()
{
loop:
  for(int i = 0; i < 101; i++)
    for(int j = 0; j < 100; j++)
      mem[i][j] = 0;
  int n, m, p;
  cin >> n;
  if(!n)
    return 0;
  for(int i = 0; i < n; i++)
  {
    cin >> m;
    for(int j = 0; j < m; j++)
    {
      cin >> p;
      mem[i][p - 1] = true;
    }
  }
  cin >> m;
  for(int i = 0; i < m; i++)
  {
    cin >> p;
    mem[100][p - 1] = true;
  }
  int ans = -1;
  for(int i = 0; i < n; i++)
  {
    bool b = true;
    for(int j = 0; j < n; j++)
    {
      if(!mem[100][j])
        continue;
      if(!mem[i][j])
        b = false;
    }
    if(b)
    {
      if(ans != -1)
      {
        cout << -1 << endl;
        goto loop;
      }
      ans = i + 1;
    }
  }
  if(ans == -1)
    cout << -1 << endl;
  else
    cout << ans << endl;
  goto loop;
}
