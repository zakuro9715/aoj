#include<iostream>

using namespace std;

int cnt[10001][1261], sum[10001][1261], N, M, R, Q;
int main()
{
 loop:;
  fill((int*)cnt, (int*)cnt + 10001 * 1261, 0);
  fill((int*)sum, (int*)sum + 10001 * 1261, 0);
  cin >> N >> M;
  if(!N)
    return 0;
  cin >> R;
  for(int i = 0; i < R; i++)
  {
    int t, n, m, s;
    cin >> t >> n >> m >> s;
    if(s)
      cnt[m][t]++;
    else
      cnt[m][t]--;
  }
  for(int m = 1; m <= M; m++)
  { 
    for(int i = 1; i <= 1260; i++)
    {
      cnt[m][i] = cnt[m][i - 1] + cnt[m][i];
      sum[m][i] = sum[m][i - 1] + (cnt[m][i] ? 1 : 0);
    }
  }
  cin >> Q;
  for(int i = 0; i < Q; i++)
  {
    int ts, te, m;
    cin >> ts >> te >> m;
    cout << sum[m][te - 1] - sum[m][ts] << endl;
  }
  cout << sum[1][650] << " " << sum[1][550] << endl;
  goto loop;
}
