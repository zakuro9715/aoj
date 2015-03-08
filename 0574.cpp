#include<iostream>
using namespace std;

int N, M, q[5003][5003];
int main()
{
  cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    int a, b, x;
    cin >> a >> b >> x;
    q[a][b]++;
    q[a][b + 1]--;
    q[a + x][b]--;
    q[a + x + 1][b + 1]++;
    q[a + x][b + x + 1]++;
    q[a + x + 1][b + x + 1]--;
  }
  for(int a = 0; a < N; a++)
  {
    for(int b = 0; b <= a; b++)
      cout << q[a][b] << " ";
    cout << endl;
  }
  int d = 0, ans = 0;
  for(int a = 0; a <= N; a++)
  {
    for(int b = 0; b <= N; b++)
    {
      d += q[a][b];
      q[a][b] = d;
    }
  }
  for(int a = 0; a <= N; a++)
  {
    for(int b = 0; b <= a; b++)
      cout << q[a][b] << " ";
    cout << endl;
  }
  for(int b = 0; b <= N; b++)
  {
    d = 0;
    for(int a = b; a <= N; a++)
    { 
      d += q[a][b];
      q[a][b] = d;
    }
  }
  
  for(int a = 0; a <= N; a++)
  {
    for(int b = 0; b <= a; b++)
      cout << q[a][b] << " ";
    cout << endl;
  }
  for(int i = 0; i <= N; i++)
  { 
    d = 0;
    for(int j = i; j <= N; j++)
    {
      d += q[j][j - i];
      q[j][j - i] = d;
      ans += d;
    }
  }
  for(int a = 0; a < N; a++)
  {
    for(int b = 0; b <= a; b++)
      cout << q[a][b] << " ";
    cout << endl;
  }
  cout << ans << endl;
}
