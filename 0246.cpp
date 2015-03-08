#include<iostream>
using namespace std;

int m[10];
int N;

int dfs(int n, int s)
{
  if(n == 10)
    return s == 10 ? 1 : 0;
  int a = 0;
  for(int i = 0; i <= m[n]; i++)
  {
    if(s + n * i > 10)
      continue;
    a += dfs(n + 1, s + n * i);
  }
  return a;
}

int main()
{
loop:
  cin >> N;
  if(!N)
    return 0;
  for(int i = 0; i < N; i++)
  {
    int a;
    cin >> a;
    m[a]++;
  }
  cout << dfs(0, 0) << endl;
  goto loop;
}
