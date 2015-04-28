#include<iostream>
#include<vector>
using namespace std;

typedef pair<int, int> P;

vector<P> p[10001];
int c[10001][2];
int N, M, R, Q;

int main()
{
 loop:
  for(int i = 0; i < 10001; i++)
  {
    c[i][0] = -1;
    c[i][1] = 0;
    p[i].clear();
  }
  cin >> N >> M;
  if(!N)
    return 0;
  cin >> R;
  for(int i = 0; i < R; i++)
  {
    int t, n, m, s;
    cin >> t >> n >> m >> s;
    if(s)
    {
      if(c[m][0] == -1)
        c[m][0] = t;
      c[m][1]++;
    }
    else
    {
      if(!(--c[m][1]))
      {
        p[m].push_back(make_pair(c[m][0], t));
        c[m][0] = -1;
      }
    }
  }
  cin >> Q;
  for(int i = 0; i < Q; i++)
  {
    int ts, te, m, a = 0;
    cin >> ts >> te >> m;
    for(auto e: p[m])
    {
      if(e.second < ts || te < e.first)
        continue;
      if(ts <= e.first && e.second <= te)
        a += e.second - e.first;
      else if(ts <= e.first)
        a += te - e.first;
      else if(e.second <= te)
        a += e.second - ts;
      else
        a += te - ts;
    }
    cout << a << endl;
  }
  goto loop;
}
