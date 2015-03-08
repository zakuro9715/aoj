#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int W, H;
map<string> mem[200];
bool check(string s, int n)
{
  return (n + 1) % W != 0 && s[n] == 'I' && s[n - W] == 'J' && s[n - W + 1] == 'O';
}

int col(string s, int m)
{
  int a = 1;
  for(int i = 0; i < m; i++)
  {
    a *= 3;
    a %= 100000;
  }
  return a ;
}

int dp(string s, int n, int m)
{
  if(n == s.length())
    return 0;
  if(check(s, n - 1))
    return col(s, m);
  if(s[n] != '?')
  {
    return dp(s, n + 1, m);
  }
  int ans = 0;
  s[n] = 'J';
  ans += dp(s, n + 1, m - 1);
  s[n] = 'O';
  ans += dp(s, n + 1, m - 1);
  s[n] = 'I';
  ans += dp(s, n + 1, m - 1);
  return ans % 100000;
}

int main()
{
  string s;
  int question = 0;
  cin >> H >> W;
  for(int i = 0; i < H; i++)
  {
    string ts;
    cin >> ts;
    s += ts;
    for(int i = 0; i < ts.length(); i++)
      question += ts[i] == '?';
  }
  cout << dp(s, 0, question) << endl; 
}
