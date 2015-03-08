#include<iostream>
#include<algorithm>
#include<functional>
#define MM 10000
#define MN 500
using namespace std;

int M, N, P[MM], E[MN][2], DP[MN][MM];

int main()
{
  cin >> M >> N;
  M++;
  for(int i = 1; i < M; i++)
    cin >> P[i];
  for(int i = 0; i < N; i++)
    cin >> E[i][0] >> E[i][1];

  sort(P + 1, P + M, greater<int>());
  for(int i = 1; i < M; i++)
    P[i] = P[i - 1] + P[i];
  for(int i = 0; i < M; i++)
    cout << P[i] << " ";
  cout << endl;

  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      DP[i + 1][j] = max(DP[i + 1][j], DP[i][j]);
      DP[i + 1][j + E[i][0]] = max(
          DP[i + 1][j + E[i][0]],
          // 今まで + 増加分 - 箱の値段
          DP[i + 1][j] + P[j + E[i][0]] - P[j - 1] - E[i][1]);
    }
  }
  cout << "i\\j" << endl;
  for(int i = 0; i <= N; i++)
  {
    cout << "   ";
    for(int j = 0; j < M; j++)
      cout << DP[i][j] << " ";
    cout << endl;
  }
}
