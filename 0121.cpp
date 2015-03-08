#include<iostream>
#include<queue>
#include<string>
#include<map>
using namespace std;

map<string, int> ans;

void bfs()
{
  queue<string> q;
  q.push("01234567");
  ans["01234567"] = 0;
  while(!q.empty())
  {
    string s = q.front(), ss = "00000000"; q.pop();
    int n;
    for(int i = 0; i < 8; i++)
      if(s[i] == '0')
        n = i;
    for(int i = 0; i < 7; i++)
      ss[i] = s[i];
    if(n % 4 != 3)
    {
      ss[n + 1] = s[n];
      ss[n] = s[n + 1];
      if(ans.find(ss) == ans.end())
      {
        cout << ss << endl;
        q.push(ss);
        ans[ss] = ans[s] + 1;
      }
      ss[n + 1] = s[n + 1];
      ss[n] = s[n];
    }
    if(n % 4)
    {
      ss[n - 1] = s[n];
      ss[n] = s[n - 1];
      if(ans.find(ss) == ans.end())
      {
        cout << ss << endl;
        q.push(ss);
        ans[ss] = ans[s] + 1;
      }
      ss[n - 1] = s[n - 1];
      ss[n] = s[n];
    }
    if(n < 4)
    {
      ss[n + 4] = s[n];
      ss[n] = s[n + 4];
      if(ans.find(ss) == ans.end())
      {
        cout << ss << endl;
        q.push(ss);
        ans[ss] = ans[s] + 1;
      }
      ss[n + 4] = s[n + 4];
      ss[n] = s[n];
    }
    if(n >= 4)
    {
      ss[n - 4] = s[n];
      ss[n] = s[n - 4];
      if(ans.find(ss) == ans.end())
      {
        q.push(ss);
        cout << ss << endl;
        ans[ss] = ans[s] + 1;
      }
      ss[n - 4] = s[n - 4];
      ss[n] = s[n];
    }
  }
}

int main()
{
  bfs();
  string s = "01234567";
  while(cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5] >> s[6] >> s[7])
    cout << ans[s] << endl;
}
