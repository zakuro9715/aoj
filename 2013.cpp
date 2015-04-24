#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int ss(int a, int b, int c)
{
  return a * 3600 + b * 60 + c;
}

int N;
int main()
{
loop:
  int a, b, c, d, e, f;
  vector<pair<int, int>> v;

  scanf("%d", &N);
  if(!N)
    return 0;
  for(int i = 0; i < N; i++)
  {
    scanf("%d:%d:%d %d:%d:%d", &a, &b, &c, &d, &e, &f);
    v.push_back(make_pair(ss(a, b, c), ss(d, e, f)));
  }

  int ans = 0, x = 0;
  priority_queue<int, vector<int>, greater<int>> q;
  q.push(1000000000);
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++)
  {
    while(v[i].first >= q.top())
    {
      q.pop();
      x++;
    }
    if(!x)
      ans++;
    else
      x--;
    q.push(v[i].second);
  }
  printf("%d\n", ans);
  goto loop;
}
