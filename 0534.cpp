#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int chain(string s)
{
  while(true)
  {
    int cnt = 1;
    char c = 'a';
    bool b = false;
    for(int i = 0; i < s.length(); i++)
    {
      if(c == s[i])
        cnt++;
      else
        cnt = 1;
      c = s[i];
      if(cnt == 4)
      {
        b = true;
        int st = i - 3;
        for(; c == s[i]; i++)
          c = s[i - 1];
        s.erase(st, i - st);
      }
      if(b)
        break;
    }
    if(!b)
      return s.length();
  }
}

int main()
{
  while(true)
  {
    int N;
    cin >> N;
    if(!N)
      return 0;
    string s = "";
    for(int i = 0; i < N; i++)
    {
      char c;
      cin >> c;
      s += c;
    }
    int ans = 1 << 30;
    for(int i = 0 ; i < s.length(); i++)
    {
      char tmp = s[i];
      for(char j = '1'; j <= '3'; j++)
      {
        if(s[i] == j)
          continue;
        s[i] = j;
        ans = min(ans, chain(s));
      }
      s[i] = tmp;
    }
    cout << ans << endl;
  }
}
