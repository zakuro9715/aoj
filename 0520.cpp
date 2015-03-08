#include<iostream>
#include<algorithm>
using namespace std;

int poles[101][4];

int gcd(int a, int b)
{
  return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
  return a / gcd(a, b) * b;
}

int dfs(int n)
{
  int a = 1, b = 1;
  if(poles[n][2])
    a = dfs(poles[n][2]);
  if(poles[n][3])
    b = dfs(poles[n][3]);
  int l = lcm(poles[n][0] * a, poles[n][1] * b);
  return l / poles[n][0] + l / poles[n][1];
}


bool notRoot[101];
int main()
{
loop:
  fill(notRoot, notRoot + 101, false);
  int n;
  cin >> n;
  if(!n)
    return 0;

  for(int i = 1; i <= n; i++)
  {
    cin >> poles[i][0] >> poles[i][1] >> poles[i][2] >> poles[i][3];
    notRoot[poles[i][2]] = notRoot[poles[i][3]] = true;
  }
  for(int i = 1; i <= n; i++)
  {
    if(!notRoot[i])
    {
      cout << dfs(i) << endl;
      goto loop;
    }
  }
}
