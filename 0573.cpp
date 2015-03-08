#include<iostream>
#include<algorithm>
using namespace std;

int mem[5000][5000], A[5000], B[5000], N, T, S;
int main()
{
  int ans = 0;
  cin >> N >> T >> S;
  for(int i = 1; i <= N; i++)
    cin >> A[i] >> B[i];
    
  for(int n = 1; n <= N; n++)
  {
    for(int t = 1; t <= T; t++)
    {
      mem[n][t] = max(mem[n - 1][t], mem[n][t - 1]);
      if(!(t - B[n] < S && t > S) && t >= B[n])
        mem[n][t] = max(mem[n - 1][t - B[n]] + A[n], mem[n][t]);
    }
  }
  cout << mem[N][T] << endl;
}
