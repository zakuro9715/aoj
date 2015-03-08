#include<iostream>

using namespace std;

int line[100][1000];

int main()
{
loop:
  for(int i = 0; i < 100; i++)
    for(int j  = 0; j < 1000; j++)
      line[i][j] = -1;
  int n, m, a;
  cin >> n >> m >> a;
  if(!n)
    return 0;
  a--;
  for(int i = 0; i < m; i++)
  {
    int h, p, q;
    cin >> h >> p >> q;
    p--; q--;
    line[p][h] = q;
    line[q][h] = p;
  }
  for(int i = 1000; i > 0; i--)
  {
    if(line[a][i] != -1)
      a = line[a][i];
  }
  cout << a + 1 << endl;
  goto loop;
}
