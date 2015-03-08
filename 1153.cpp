#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<pair<int, int> > v;
vector<int> a, b;
int main()
{
loop:
  int tmp;
  int as = 0, bs = 0, d, n, m;
  a.clear(); b.clear(); v.clear();
  cin >> n >> m;
  if(!(n || m))
    return 0;
  for(int i = 0; i < n; i++)
  {
    cin >> tmp;
    a.push_back(tmp);
    as += tmp;
  }
  for(int i = 0; i < m; i++)
  {
    cin >> tmp;
    b.push_back(tmp);
    bs += tmp;
  }
  d = as - bs;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if((a[i] - b[j]) * 2 == d)
        v.push_back(make_pair(a[i], b[j]));
  sort(v.begin(), v.end());
  if(v.size() == 0)
    cout << -1 << endl;
  else
    cout << v[0].first << " " << v[0].second << endl;
  goto loop;
}
