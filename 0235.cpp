#include<iostream>
#include<vector>

using namespace std;

struct island
{
  bool islast;
  vector<int> to;
  vector<int> time;
};

island islands[20];

int big(int n, int t, int from)
{
  cout << "big";
  if(n && islands[n].to.size() == 1)
    return 0;
  int a = 0;
  for(int i = 0; i < islands[n].time.size(); i++)
  {
    if(islands[n].to[i] == from)
      continue;
    if(islands[n].time[a] < islands[n].time[i])
      a = i;
  }
  return big(islands[n].to[a], islands[n].time[a], n);
}

int dfs(int n, int t, int from)
{
  cout << "from: " << from << " to: " << n << endl;
  if(n && islands[n].to.size() == 1)
    return 0;
  int res = 0;
  for(int i = 0; i < islands[n].to.size(); i++)
  {
    if(islands[n].to[i] == from)
      continue;
    res += dfs(islands[n].to[i], islands[n].time[i], n);
  }
  res += t;

  return res;
}

int main()
{
  int n;
  while(1)
  {
    cin >> n;
    if(!n)
      break;
    for(int i = 0; i < n - 1; i++)
    {
      int a, b, t;
      cin >> a >> b >> t;
      islands[a - 1].to.push_back(b - 1);
      islands[a - 1].time.push_back(t);
      islands[b - 1].to.push_back(a - 1);
      islands[b - 1].time.push_back(t);
    }
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < islands[i].to.size(); j++)
      cout << "from: " << i + 1 << " to: " << islands[i].to[j] << " time: " << islands[i].time[j] << endl;
    }
    cout << dfs(0, islands[0].to[0], -1) * 2 - big(0, islands[0].to[0], -1) << endl;
  }
  return 0;
}
