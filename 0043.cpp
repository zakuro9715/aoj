#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

#define NA 10000000

string str;

char rgb(char v1, char v2)
{
  bool r, g, b;
  r = v1 == 'r' || v2 == 'r';
  b = v1 == 'b' || v2 == 'b';
  g = v1 == 'g' || v2 == 'g';
  
  if(!r)
    return 'r';
  if(!b)
    return 'b';
  return 'g';
}

int dfs(string s, bool isFirst, int n)
{
  int ans = 10000000;
  bool isEnd = true;
  //cout << "s: "<< s << endl;

  if(n > 10)
    return NA;
  if(str == s && !isFirst)
    return ans;
  for(int i = 0; i < s.length(); i++)
    isEnd &= s[0] == s[i];
  if(isEnd)
    return n;

  for(int i = 0; i < s.length() - 1; i++)
  {
    //cout << i << endl;
    if(s[i] != s[i + 1])
    {
      char c1 = s[i], c2 = s[i + 1];
      
      char c = rgb(s[i], s[i + 1]);
      //cout << c1 << c2;
      s[i] = s[i + 1] = c;
      ans = min(ans, dfs(s, false, n + 1));
      s[i] = c1;
      s[i + 1] = c2;
    }
  }

  return ans;
}


int main()
{
  while(1)
  {
    cin >> str;
    if(str[0] == '0')
      break;
    int a = dfs(str, true, 0);
    if(a == NA)
      cout << "NA\n";
    else
      cout << a << endl;
  }
}
