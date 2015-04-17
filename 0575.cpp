#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
int N, M, K, Q;
int d[100000], eu1[100000], du[30][100000], pa[30][100000];
bool done[100000];
vector<P> g[100000], mg[100000];
vector<P> eu;

struct Seg
{
  P d[100010];

  void update(int i, P v)
  {
    d[i] = max(d[i], v);
    if(i)
      update(i / 2, v);
  }
  P query(int a, int b, int i, int l, int r)
  {
    cout << a << " " << b << " " << i << " " << l << " " << r << endl;
    if(r <= a || b <= l)
      return make_pair(INF, INF);
    if(a <= l && r <= b)
      return d[i];
    return min(
      query(a, b, i * 2 + 1, l, (l + r) / 2),
      query(a, b, i * 2 + 2, (l + r) / 2, r)
    );
  }
};

void dfs(int dep, int n, int from)
{
  pa[0][n] = from;
  eu1[n] = eu.size();
  eu.push_back(make_pair(dep, n));
  for(auto e: mg[n])
  {
    if(e.second == from)
      continue;
    dfs(dep + 1, e.second, n);
    eu.push_back(make_pair(dep, n));
  }
}

int dist(int a, int b, int d)
{

}

int main()
{
  cin >> N >> M >> K >> Q;
  for(int i = 0; i < M; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    g[a].push_back(make_pair(c, b));
    g[b].push_back(make_pair(c, a));
  }

  fill(d, d + 100000, INF);
  priority_queue<P, vector<P>, greater<P>> q;
  for(int i = 0; i < K; i++)
  {
    int f;
    cin >> f;
    q.push(make_pair(0, f - 1));
    d[f - 1] = 0;
  }
  while(q.size())
  {
    auto p = q.top(); q.pop();
    int from = p.second;
    for(auto e: g[from])
    {
      int to = e.second, cost = d[from] + e.first;
      if(d[to] > cost)
      {
        d[to] = cost;
        q.push(make_pair(cost, to));
      }
    }
  }

  priority_queue<PP> q2;
  for(auto e: g[0])
    q2.push(make_pair(e, 0));
  done[0] = true;
  while(q2.size())
  {
    auto p = q2.top(); q2.pop();
    int a = p.second;
    auto e = p.first;
    int b = e.second, c = e.first;
    cout << a + 1<< " " << b+ 1 << " " << c << endl;
    if(done[b])
      continue;
    done[b] = true;
    mg[a].push_back(make_pair(c, b));
    mg[b].push_back(make_pair(c, a));
    for(auto e: g[b])
    {
      if(!done[e.second])
        q2.push(make_pair(e, b));
    }
  }
 
  fill((int*)pa, (int*)pa + 3000000, INF);
  fill((int*)du, (int*)du + 3000000, 0);
  dfs(0, 0, INF);

  for(int i = 1; i < 30; i++)
  {
    for(int j = 0; j< N; j++)
    {
      if(pa[i - 1][j] < INF)
        pa[i][j] = pa[i - 1][pa[i - 1][j]];
    }
  }
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < N; j++)
      cout << (pa[i][j] == INF ? 0 : pa[i][j] + 1) << " ";
    cout << endl;
  }
    cout << endl;
  for(int i = 0; i < N; i++)
    du[0][i] = d[i];
  for(int i = 1; i < 30; i++)
  {
      int nn = 0;;
    for(int j = 0; j < N; j++)
    {
      int ii = 1 << (i - 1);
      
      if(j < 100000 && pa[i - 1][j] < 100000)
      {
       if(i < 3)
        cout <<pa[i - 1][j] +  1<< " " << du[i - 1][pa[i - 1][j]] << endl;
        du[i][j] = min(du[i - 1][j], du[i - 1][pa[i - 1][j]]);
      }
      else if(i < 3)
        cout << "Fail" << endl;
    }
    if(nn)
    cout << endl;
  }
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < N; j++)
      cout << (du[i][j] == INF ? 0 : du[i][j]) << " ";
    cout << endl;
  }
  
  Seg s;
  for(int i = 0; i < N; i++)
    s.update(i, eu[eu1[i]]);

  for(int i = 0; i < Q; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    auto h = s.query(a, b, 0, 0, N);
    cout << " " << h.first << " " << h.second << endl; 
  }
}
