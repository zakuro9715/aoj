#include<iostream>
#include<algorithm>

using namespace std;

int D, N, M, x[100001];

int main()
{
  while(true)
  {
    cin >> D;
    if(!D)
      break;
    cin >> N >> M;
    for(int i = 1; i < N; i++)
      cin >> x[i];
    x[N++] = D;
    sort(x, x + N);

    int ans = 0;
    for(int i = 0; i < M; i++)
    {
      int v;
      cin >> v;
      auto b = upper_bound(x, x + N, v);
      auto a = b - 1;
      ans += min(abs(*b - v), abs(*a - v));
    }
    cout << ans << endl;
  }
}
