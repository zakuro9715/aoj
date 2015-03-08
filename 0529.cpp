#include<iostream>
#include<algorithm>
using namespace std;

int P[1001], mem[1001 * 1001], N, M;
int main()
{
loop:
  cin >> N >> M;
  if(!N)
    return 0;
  N++;
  P[0] = 0;
  for(int i = 1; i < N; i++)
    cin >> P[i];
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      mem[N * i + j] = P[i] + P[j];
  sort(mem, mem + N * N);

  int ans = 0;
  for(int i = 0; i < N * N; i++)
  {
    if(mem[i] > M)
      continue;
    ans = max(ans, mem[i] + *(upper_bound(mem, mem + N * N, M - mem[i]) - 1));
  }
  cout << ans << endl;
  goto loop;
}
