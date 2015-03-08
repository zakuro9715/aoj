#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int froms[100002];
int D, N, M;

int main()
{
 loop:
  cin >> D;
  if(!D)
    return 0;
  cin >> N >> M;
  froms[0] = 0;
  for(int i = 1; i < N; i++)
  {
    int d;
    cin >> d;
    froms[i] = d;
  }
  froms[N] = D;
  sort(froms, froms + N + 1);

  int ans = 0;
  for(int i = 0; i < M; i++)
  {
    int k;
    cin >> k;
    int *p = lower_bound(froms, froms + N + 1, k);
    int *p2 = p - 1;
    ans += min(*p - k, k - *p2);
  }
  cout << ans << endl;
  goto loop;
}
