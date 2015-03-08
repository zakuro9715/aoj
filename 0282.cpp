#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

#define INF 2000000000
typedef pair<int, int> seg;
seg dat[1 << 18 + 1];
int ans[1 << 17];

int n, N, R, L;


void update(int i, seg x)
{
  i += n - 1;
  dat[i] = x;
  while(i > 0)
  {
    i = (i - 1) / 2;
    dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
  }
}

void init()
{
  n = 1;
  while(n < N) n *= 2;
  n *= 2;
  for(int i = 0; i < n * 2 - 1; i++)
    dat[i] = make_pair(INF, INF);
  for(int i = 0; i < N; i++)
    update(i, make_pair(0, i));
}

seg query(int a, int b, int k, int l, int r)
{
  if(a >= r || b <= l)
    return make_pair(INF, INF);
  if(a <= l && b >= r)
    return dat[k];
  seg vr = query(a, b, k, (l + r) / 2, r);
  seg vl = query(a, b, k, l, (l + r) / 2);
  return min(vr, vl);
}


void output()
{
  int m = 0;
  for(int i = 0; i < N; i++)
  {
//    cout << ans[i] << " ";
    m = max(m, ans[i]);
  }
  for(int i = 0; i < N; i++)
  {
    if(ans[i] == m)
    {
      cout << i + 1 << endl;
      return;
    }
  }
}


int main()
{
  int old_t = 0;

  cin >> N >> R >> L;
  init();
  for(int i = 0; i < R; i++)
  {
    int d, t, x;
    cin >> d >> t >> x;
    d--;
    ans[query(0, N, 0, 0, n).second] += t - old_t;
    
    seg s = dat[d + n - 1];
    update(d, make_pair(s.first - x, s.second));
    old_t = t;
  }
  ans[query(0, N, 0, 0, n).second] += L - old_t;

  output();
}
