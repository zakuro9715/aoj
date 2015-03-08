#include<iostream>
#include<algorithm>
using namespace std;

struct team
{
  int ac, wa[10], pe, num;
  bool operator <(const team& t) const
  {
    if(ac != t.ac)
      return ac < t.ac;
    if(pe != t.pe)
      return pe > t.pe;
    return num > t.num;
  }
};

team teams[50];
int main()
{
loop:
  int T, P, R;
  for(int i = 0; i < 50; i++)
    teams[i] = team();
  for(int i = 0; i < 50; i++)
    teams[i].num = i + 1;
  cin >> T >> P >> R;
  if(!T)
    return 0;
  for(int i = 0; i < R; i++)
  {
    int t, p, time;
    string st;
    cin >> t >> p >> time >> st;
    t--; p--;
    if(teams[t].wa[p] == -1)
      continue;
    if(st == "WRONG")
      teams[t].wa[p]++;
    else
    {
      teams[t].ac++;
      teams[t].pe += teams[t].wa[p] * 1200 + time;
      teams[t].wa[p] = -1;
    }
  }
  sort(teams, teams + T);
  reverse(teams, teams + T);
  for(int i = 0; i < T; i++)
    cout << teams[i].num << " " << teams[i].ac << " " << teams[i].pe << endl;
  goto loop;
}
